/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:37:18 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 23:03:21 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static t_bool	is_unavailable(t_vec2 pos, t_game_data *gdata)
{
	t_list *snk;

	snk = gdata->snk;
	while (snk)
	{
		if (vec2_isequ(snk_part(snk)->pos, pos))
			return (TRUE);
		snk = snk->next;
	}
	return (FALSE);
}

t_snk_part		*snk_part(t_list *snk)
{
	return (snk->content);
}

void			spawn_food(t_game_data *gdata)
{
	t_vec2		new_pos;
	void		*haha;

	haha = malloc(1);
	new_pos.x = ((unsigned int)haha) % (gdata->screen.size.x - 2);
	new_pos.y = (((unsigned int)haha) * 2 / 4) % (gdata->screen.size.y - 2);
	new_pos.x += 1;
	new_pos.y += 1;
	free(haha);
	while (is_unavailable(new_pos, gdata) == TRUE)
	{
		new_pos.y += new_pos.x / gdata->screen.size.x;
		new_pos.x = (new_pos.x + 1) % gdata->screen.size.x;
	}
	gdata->food.pos = new_pos;
}

void			update_speed(t_game_data *gdata)
{
	double		score;

	score = (gdata->score / 5) + 1;
	gdata->speed = (1.0 / score);
}

void			eat_food(t_game_data *gdata)
{
	t_list		*new;

	new = ft_lstnew(&gdata->food, sizeof(t_snk_part));
	new->next = gdata->snk;
	gdata->snk = new;
	gdata->score++;
	spawn_food(gdata);
	update_speed(gdata);
}
