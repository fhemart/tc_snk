/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:05:13 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:49:51 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static int	update_newgame(t_game_data *gdata)
{
	if ((char)gdata->last_key == K_ENTER)
	{
		gdata->curr_screen = GM_INGAME;
		return (SUCCESS);
	}
	return (FAILURE);
}

static int	update_dir(t_game_data *gdata)
{
	static long		keys[8] = {K_UP, (long)'w', K_DOWN, (long)'s', \
							K_RIGHT, (long)'d', K_LEFT, (long)'a'};
	static t_vec2	(*f[4])(void) = {vec2_up, vec2_down, vec2_right, vec2_left};
	t_vec2			v2;
	int				i;

	i = -1;
	while (++i < 8)
	{
		if (gdata->last_key == keys[i])
		{
			v2 = f[i / 2]();
			if (!vec2_isopposite(gdata->dir, v2))
			{
				gdata->dir = v2;
				if (i != gdata->last_dir)
					gdata->force_update = TRUE;
				gdata->last_dir = i;
			}
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

static int	update_gameover(t_game_data *gdata)
{
	if ((char)gdata->last_key == K_ENTER)
	{
		gdata->curr_screen = GM_NEWGAME;
		set_newgame(gdata);
		return (SUCCESS);
	}
	return (FAILURE);
}

void		input_update(t_tc_win *win, t_game_data *gdata)
{
	static int	(*action[3])(t_game_data *gdata) = {update_newgame, \
													update_dir, \
													update_gameover};
	long		key;

	key = 0;
	read(0, &key, 4);
	gdata->last_key = key;
	if ((action[gdata->curr_screen](gdata) == FAILURE
	&& (char)gdata->last_key == 'q')
		|| win->resised == 1)
		gdata->status = ST_SUCCESS;
	else
		draw_update(win, gdata);
}
