/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:25:01 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:25:03 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static char	*get_frameborders(t_vec2 pos, t_canvas *canvas)
{
	static char		c[5];

	if (pos.x == 0)
	{
		if (pos.y == 0)
			return (ft_strcpy(c, SNK_BDR_UP_L));
		else if (pos.y == canvas->size.y - 1)
			return (ft_strcpy(c, SNK_BDR_DO_L));
		return (ft_strcpy(c, SNK_BDR_SIDE));
	}
	else if (pos.x == canvas->size.x - 1)
	{
		if (pos.y == 0)
			return (ft_strcpy(c, SNK_BDR_UP_R));
		else if (pos.y == canvas->size.y - 1)
			return (ft_strcpy(c, SNK_BDR_DO_R));
		return (ft_strcpy(c, SNK_BDR_SIDE));
	}
	else if (pos.y == 0 || pos.y == canvas->size.y - 1)
		return (ft_strcpy(c, SNK_BDR_TOP));
	return (NULL);
}

void		draw_canvas(t_canvas *canvas)
{
	t_vec2		i;
	char		*c;

	i.y = -1;
	while (++i.y < canvas->size.y)
	{
		i.x = -1;
		while (++i.x < canvas->size.x)
		{
			if ((c = get_frameborders(i, canvas)))
				write_to_pos(vec2_add(i, canvas->anchor), c, 120);
		}
	}
}
