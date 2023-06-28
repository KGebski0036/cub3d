/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_drawings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:54:18 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 17:35:02 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_texture	pc_get_correct_side(t_env *env, t_vec2 ray)
{
	if (round(ray.y * 256) == floor(ray.y) * 256 && floor(ray.y) != 0
		&& env->map.bit_map[(int)floor(ray.y) - 1][(int)floor(ray.x)] != '1')
		return (env->map.north);
	if (round((ray.x) * 256) == floor(ray.x) * 256)
		return (env->map.west);
	if (round((ray.y) * 256) == (floor(ray.y) + 1) * 256
		&& env->map.bit_map[(int)floor(ray.y)] != 0
		&& env->map.bit_map[(int)floor(ray.y) + 1][(int)floor(ray.x)] != '1')
		return (env->map.south);
	else
		return (env->map.east);
}
