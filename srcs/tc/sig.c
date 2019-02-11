/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:41:51 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:42:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void		intercept_sigwinch(int sig)
{
	t_tc_win	*windows_ptr;

	windows_ptr = gs_tc_win(FT_STGET, NULL);
	if (sig == SIGWINCH)
		windows_ptr->resised = TRUE;
}

int			reset_sigwinch_handler(void)
{
	if (signal(SIGWINCH, SIG_DFL) == SIG_ERR)
		return (FAILURE);
	return (SUCCESS);
}

int			tc_clear_screen(int nbline)
{
	while (nbline != -1)
	{
		if (move_cursor(nbline--, 1) == FAILURE \
			|| exec_tc_cap(TC_DEL) == FAILURE \
			|| exec_tc_cap(TC_DELTOEND) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
