/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_snk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:03:14 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:52:02 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void		exit_snk(t_game_data *gdata, t_tc_win *win)
{
	restore_tc_attr(win);
	exec_tc_cap(TC_CURSOR_SHOW);
	tc_clear_screen(win->windows_attr.ws_row);
	move_cursor(0,0);
	if (gdata->status == ST_SUCCESS)
	{
		ft_lstdel(&gdata->snk, ft_memdel);
		ft_putstr("Thanks for playing.\n");
	}
	reset_sigwinch_handler();
}
