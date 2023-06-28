/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:26:01 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/28 18:46:46 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pc_raycasting(t_env *env)
{
	t_vec2		point;
	t_vec2		ray;
	double		ray_angle;
	int			wall_height;
	t_texture	texture;
	double 		texture_pos;

	ray_angle = env->player.rotation - env->half_fov;
	point.x = 0;
	while (point.x < env->window_size.x)
	{
		ray = env->player.pos;
		wall_height = pc_calculate_wall_height(env, &ray);
		texture = pc_get_correct_side(env, ray);
		texture_pos = floor((int)(texture.width * (ray.x + ray.y)) % texture.width);
		pc_draw_column(env, point);
		point.x++;
		ray_angle += env->raycast_increment;
	}
}

int	pc_calculate_wall_height(t_env *env, t_vec2 *ray)
{
	double	distance;
	double	ray_cos;
	double	ray_sin;

	ray_cos = cos(degree_to_radians(ray_angle)) / env->raycast_precision;
	ray_sin = sin(degree_to_radians(ray_angle)) / env->raycast_precision;
	distance = get_distance_to_wall(env, ray, ray_cos, ray_sin);
	distance *= cos(degree_to_radians(ray_angle - env->player.rotation));
	wall_height = (int)floor(env->window_half_size.y / distance);
	return (wall_height);
}

void	pc_draw_column(t_env *env, t_vec2 point, int wall_height)
{
	point.y = 0;
	while (point.y < env->window_size.y)
	{
		if (point.y <= (int)floor(env->window_half_size.y - wall_height))
		{
			if (env->map.ceiling == 0)
				my_mlx_pixel_put(env, my_mlx_pixel_get(env->sky, point), point);
			else
				my_mlx_pixel_put(env, env->map.ceiling, point);
		}
		else if (point.y <= (int)floor(env->window_half_size.y + wall_height))
			pc_draw_wall(env, point);
		else
		{
			if (env->map.floor == 0)
				pc_draw_floor_texture(env, point);
			else
				my_mlx_pixel_put(env, env->map.floor, point);
		}
		point.y++;
	}
}

void	pc_draw_floor_texture(t_env *env, t_vec2 point)
{
	t_vec2	p;

	p.x = point.x;
	p.y = point.y - env->window_half_size.y;
	my_mlx_pixel_put(env, my_mlx_pixel_get(env->floor, p), point);
}

void	pc_draw_wall(t_env *env, t_vec2 *point)
{	
	double			i;
	double			i_inc;
	unsigned int	color;

	i = 0;
	i_inc = ((double)texture.height / (wall_height * 2));
	if (wall_height > env->window_half_size.y && i == 0)
	{
		i = (((double)(wall_height) - env->window_half_size.y) * i_inc);
	}
	color = my_mlx_pixel_get(texture, (t_vec2){texture_pos, floor(i)});
	my_mlx_pixel_put(env, color, (t_vec2){point.x, point.y});
	i += i_inc;
}
