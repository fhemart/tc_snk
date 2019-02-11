/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools_p1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:24:48 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:24:50 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

void		draw_snk(t_list *snk, int pcount, int curr_screen, t_vec2 anchor)
{
	static int		dcol[6] = {196, 196, 160, 124, 88, 52};
	static int		lcol[6] = {154, 148, 184, 142, 100, 58};
	int				lerp;
	int				col;
	int				i;

	i = 1;
	while (snk)
	{
		lerp = (double)i++ / pcount * 5;
		col = curr_screen == GM_INGAME ? lcol[lerp] : dcol[lerp];
		write_to_pos(vec2_add(snk_part(snk)->pos, anchor), "#", col);
		snk = snk->next;
	}
}

void		draw_score(t_canvas *screen, int gscore)
{
	char	*score;
	t_vec2	pos;

	score = ft_static_itoa(gscore);
	pos.x = (screen->size.x / 2) - (ft_strlen(score) / 2) + screen->anchor.x;
	pos.y = screen->anchor.y - 1;
	move_cursor(pos.y, pos.x);
	ft_putstr("\e[1;38;5;");
	ft_putstr("183");
	ft_putstr("m");
	ft_putstr(score);
}

void		draw_words2_center(t_canvas *screen, char *word1, char *word2, \
								short c)
{
	t_vec2		pos;

	if (word1)
	{
		pos.x = (screen->size.x / 2) - (ft_strlen(word1) / 2);
		pos.y = (screen->size.y / 2) - 1;
		write_to_pos(vec2_add(pos, screen->anchor), word1, c);
	}
	if (!word2)
		return ;
	pos.x = (screen->size.x / 2) - (ft_strlen(word2) / 2);
	pos.y = screen->size.y / 2;
	write_to_pos(vec2_add(pos, screen->anchor), word2, 103);
}

void		draw_highscore(t_game_data *gdata)
{
	t_vec2		pos;
	t_canvas	*screen;

	screen = &gdata->screen;
	pos.x = screen->size.x / 2 - (ft_strlen(HSCORE) / 2) + screen->anchor.x;
	pos.y = screen->anchor.y - 2;
	write_to_pos(pos, HSCORE, 220);
	draw_score(&gdata->screen, gdata->highscore);
}

void		draw_quit(t_canvas *screen)
{
	t_vec2	pos;

	pos.x = (screen->size.x) - (ft_strlen("'q' to quit") + 1);
	pos.x += screen->anchor.x;
	pos.y = screen->size.y + screen->anchor.y;
	write_to_pos(pos, "'q' to quit", 189);
}
