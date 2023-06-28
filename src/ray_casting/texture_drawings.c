/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_drawings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:54:18 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 14:54:55 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//! Fix this
int draw_texture(t_vec2 point, int wallHeight, int texture_pos, t_texture texture, t_env *env)
{
	double y_inc = wallHeight * 2 / (double)texture.height + 0.1;
	double y = env->window_half_size.y - wallHeight;
	int i = 0;
	
	while (i < texture.height)
	{
		unsigned int color = my_mlx_pixel_get(texture, (t_vec2){texture_pos, i});
		my_mlx_pixel_put(env, color, (t_vec2){point.x, y});
		y += y_inc;
		i++;
	}
	return (int)wallHeight;
}

t_texture	pc_get_correct_side(t_env *env, t_vec2 ray)
{
	if (round(ray.y * 256) == floor(ray.y) * 256 && floor(ray.y) != 0 && env->map.bit_map[(int)floor(ray.y) - 1][(int)floor(ray.x)] != '1')
		return (env->map.north);
	if (round((ray.x) * 256) == floor(ray.x) * 256 )
		return (env->map.west);
	if (round((ray.y) * 256) == (floor(ray.y) + 1) * 256 && env->map.bit_map[(int)floor(ray.y)] != 0 && env->map.bit_map[(int)floor(ray.y) + 1][(int)floor(ray.x)] != '1')
		return (env->map.south);
	else
		return (env->map.east);
}