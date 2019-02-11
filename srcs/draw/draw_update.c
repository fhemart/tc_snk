/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:25:10 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:49:14 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static void	draw_newgame(t_game_data *gdata)
{
	draw_highscore(gdata);
	draw_words2_center(&gdata->screen, "SNAKE", "PRESS ENTER", 118);
}

static void	draw_ingame(t_game_data *gdata)
{
	int		framerate;

	update_snk(gdata);
	draw_snk(gdata->snk, gdata->score + 1, \
			gdata->curr_screen, gdata->screen.anchor);
	if (gdata->curr_screen == GM_NEWGAME)
		return ;
	draw_score(&gdata->screen, gdata->score);
	write_to_pos(vec2_add(gdata->food.pos, gdata->screen.anchor), "@", 203);
	gdata->frame.end = gdata->frame.start;
	framerate = gdata->dir.x ? FRAMERATE_H : FRAMERATE_V;
	gdata->frame.end.tv_nsec += (framerate) * gdata->speed;
	gdata->frame.end.tv_sec += (double)gdata->frame.end.tv_nsec / 10000000000;
	gdata->frame.end.tv_nsec = gdata->frame.end.tv_nsec % 10000000000;
	gdata->force_update = FALSE;
}

static void	draw_gameover(t_game_data *gdata)
{
	draw_highscore(gdata);
	draw_snk(gdata->snk, gdata->score + 1, \
			gdata->curr_screen, gdata->screen.anchor);
	draw_words2_center(&gdata->screen, "GAME OVER", "PRESS ENTER", 196);
}

void		draw_update(t_tc_win *win, t_game_data *gdata)
{
	static void		(*action[3])(t_game_data*) = {draw_newgame, \
												draw_ingame, \
												draw_gameover};
	t_framerate		*frame;

	frame = &gdata->frame;
	clock_gettime(CLOCK_MONOTONIC, &frame->start);
	if (!((double)frame->start.tv_sec + 1.0e-9 * (double)frame->start.tv_nsec
		>= (double)frame->end.tv_sec + 1.0e-9 * (double)frame->end.tv_nsec)
		&& gdata->force_update == FALSE)
		return ;
	if (tc_clear_screen(win->windows_attr.ws_row) == FAILURE)
	{
		ft_putstr("Clear failed\n");
		gdata->status = ST_FAILURE;
		return ;
	}
	draw_canvas(&gdata->screen);
	action[gdata->curr_screen](gdata);
	draw_quit(&gdata->screen);
}
