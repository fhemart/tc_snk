/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:12:08 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:12:13 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_vec2		vec2_div(t_vec2 v2, int div)
{
	v2.x /= div;
	v2.y /= div;
	return (v2);
}

t_vec2		vec2_add(t_vec2 a, t_vec2 b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec2		vec2_addint(t_vec2 v2, int i)
{
	v2.x += i;
	v2.y += i;
	return (v2);
}
