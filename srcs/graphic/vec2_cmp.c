/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:11:18 by fhemart           #+#    #+#             */
/*   Updated: 2018/10/19 22:12:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_bool		vec2_isopposite(t_vec2 v1, t_vec2 v2)
{
	return (v1.x == -v2.x && v1.y == -v2.y);
}

t_bool		vec2_isequ(t_vec2 v1, t_vec2 v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}

t_bool		vec2_isinside(t_vec2 check, t_vec2 inside)
{
	if (check.x > 0 && check.x < (inside.x - 1)
	&& check.y > 0 && check.y < (inside.y - 1))
		return (TRUE);
	return (FALSE);
}
