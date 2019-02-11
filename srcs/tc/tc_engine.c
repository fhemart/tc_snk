/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:23:08 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:23:27 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

int			move_cursor(int x, int y)
{
	char	*cursor_move;
	char	*capa;

	if ((!(cursor_move = tgetstr(TC_CURSOR_MOVE, NULL))))
		return (FAILURE);
	if (!(capa = tgoto(cursor_move, y, x)))
		return (FAILURE);
	ft_putstr(capa);
	return (SUCCESS);
}

void		write_to_pos(t_vec2 v2, char *c, short color)
{
	move_cursor(v2.y, v2.x);
	if (color >= 0)
	{
		ft_putstr("\e[1;38;5;");
		ft_putstr(ft_static_itoa(color));
		ft_putstr(";m");
	}
	ft_putstr(c);
	ft_putstr("\x1B[0m");
}

int			get_term_attr(t_term_attr *attr)
{
	if (!attr || tcgetattr(STDIN_FILENO, attr) == -1)
		return (FAILURE);
	return (SUCCESS);
}

int			restore_tc_attr(t_tc_win *win)
{
	if (!win)
		return (FAILURE);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &win->attr_backup) == -1)
		return (FAILURE);
	return (SUCCESS);
}

int			exec_tc_cap(char *cap)
{
	char			*formated_cap;

	if (!(formated_cap = tgetstr(cap, NULL)))
		return (FAILURE);
	ft_putstr(formated_cap);
	return (SUCCESS);
}
