/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_snk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:41:15 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:56:29 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static void		set_gameover(t_game_data *gdata)
{
	gdata->force_update = TRUE;
	if (gdata->highscore < gdata->score)
		gdata->highscore = gdata->score;
	gdata->curr_screen = GM_GAMEOVER;
}

void			set_newgame(t_game_data *gdata)
{
	t_snk_part	part;

	gdata->score = 0;
	gdata->dir = vec2_up();
	part.pos = vec2_div(gdata->screen.size, 2);
	ft_lstdel(&gdata->snk, ft_memdel);
	gdata->snk = ft_lstnew(&part, sizeof(t_snk_part));
	update_speed(gdata);
	spawn_food(gdata);
}

static void		give_pos_toprevparts(t_list *snk)
{
	if (!snk->next)
		return ;
	give_pos_toprevparts(snk->next);
	snk_part(snk->next)->pos = snk_part(snk)->pos;
}

static t_bool	is_deadly_pos(t_game_data *gdata, t_vec2 pos)
{
	t_list	*snk;

	if (!vec2_isinside(pos, gdata->screen.size))
		return (TRUE);
	snk = gdata->snk;
	while (snk)
	{
		if (vec2_isequ(snk_part(snk)->pos, pos))
			return (TRUE);
		snk = snk->next;
	}
	return (FALSE);
}

void			update_snk(t_game_data *gdata)
{
	t_vec2		new_pos;

	new_pos = vec2_add(snk_part(gdata->snk)->pos, gdata->dir);
	if (vec2_isequ(new_pos, gdata->food.pos))
		return (eat_food(gdata));
	give_pos_toprevparts(gdata->snk);
	if (is_deadly_pos(gdata, new_pos))
	{
		snk_part(gdata->snk)->pos = new_pos;
		return (set_gameover(gdata));
	}
	snk_part(gdata->snk)->pos = new_pos;
}
