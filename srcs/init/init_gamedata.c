/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gamedata.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:03:23 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:54:21 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static t_canvas	new_canvas(int sizex, int sizey, int anchorx, int anchory)
{
	return ((t_canvas){(t_vec2){sizex, sizey}, (t_vec2){anchorx, anchory}});
}

void			init_gamedata(t_game_data *gdata, t_tc_win *win)
{
	int		prev_hscore;
	int		pad_x;
	int		pad_y;

	prev_hscore = gdata->highscore;
	ft_bzero(gdata, sizeof(*gdata));
	pad_x = win->windows_attr.ws_col - SNK_MIN_X;
	pad_y = win->windows_attr.ws_row - (SNK_MIN_Y - 4);
	gdata->screen = new_canvas(SNK_MIN_X, SNK_MIN_Y - 4, pad_x / 2, pad_y / 2);
	gdata->highscore = prev_hscore;
	gdata->status = ST_CONTINUE;
	set_newgame(gdata);
}
