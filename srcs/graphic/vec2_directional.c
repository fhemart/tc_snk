/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_directional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:11:58 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:12:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_vec2		vec2_left(void)
{
	return ((t_vec2){-1, 0});
}

t_vec2		vec2_right(void)
{
	return ((t_vec2){1, 0});
}

t_vec2		vec2_up(void)
{
	return ((t_vec2){0, -1});
}

t_vec2		vec2_down(void)
{
	return ((t_vec2){0, 1});
}
