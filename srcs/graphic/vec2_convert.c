/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:11:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:37:46 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_vec2			new_vec2(int x, int y)
{
	return ((t_vec2){x, y});
}

t_vec2			linear2vec2(int linear_pos, int max_x)
{
	t_vec2			v2;

	v2.x = linear_pos / max_x;
	v2.y = linear_pos % max_x;
	return (v2);
}

int				vec2_to_linear(t_vec2 v2, int max_x)
{
	int				linear_pos;

	linear_pos = v2.x + (v2.y * max_x);
	return (linear_pos);
}
