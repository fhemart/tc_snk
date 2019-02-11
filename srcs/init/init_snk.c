/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_snk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:42:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:10:44 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_tc_win		*gs_tc_win(int gs, t_tc_win *windows)
{
	static t_tc_win	*windows_ptr;

	if (gs == FT_STSET)
		windows_ptr = windows;
	else if (gs == FT_STGET)
		return (windows_ptr);
	return (NULL);
}

static int		set_tc_data(t_tc_win *win)
{
	if (!win)
		return (FAILURE);
	win->attr_snk.c_lflag &= ~(ICANON | ECHO);
	win->attr_snk.c_cc[VMIN] = 0;
	win->attr_snk.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &win->attr_snk) == -1)
		return (FAILURE);
	return (SUCCESS);
}

static int		get_windows_size(t_term_ws *windows)
{
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, windows) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int		init_windows(t_tc_win *win)
{
	char *term_name;

	term_name = getenv("TERM");
	if (!win \
		|| !term_name \
		|| get_term_attr(&win->attr_backup) == FAILURE \
		|| get_term_attr(&win->attr_snk) == FAILURE \
		|| !tgetent(NULL, term_name) \
		|| get_windows_size(&win->windows_attr) == FAILURE)
		return (FAILURE);
	gs_tc_win(FT_STSET, win);
	return (SUCCESS);
}

int				init_snk(t_tc_win *win)
{
	ft_bzero(win, sizeof(*win));
	if (init_windows(win) == FAILURE \
		|| signal(SIGWINCH, intercept_sigwinch) == SIG_ERR \
		|| set_tc_data(win) == FAILURE \
		|| exec_tc_cap(TC_CLEAR) == FAILURE)
	{
		restore_tc_attr(win);
		signal(SIGWINCH, SIG_DFL);
		return (FAILURE);
	}
	win->resised = 0;
	return (SUCCESS);
}
