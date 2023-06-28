/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:02:35 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 15:23:02 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pc_frame_update(t_env *env)
{
	pc_render_frame(env);
	return (0);
}

void	pc_render_frame(t_env *env)
{
	pc_raycasting(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
}

void	pc_raycasting(t_env *env)
{
	t_vec2 point;
	t_vec2 ray;
	double distance;

	double ray_angle = env->player.rotation - env->half_fov;
	point.x = 0;
	while (point.x < env->window_size.x)
	{
		ray = env->player.pos;

		double rayCos = cos(degree_to_radians(ray_angle)) / env->raycast_precision;
		double raySin = sin(degree_to_radians(ray_angle)) / env->raycast_precision;

		distance = get_distance_to_wall(env, &ray, rayCos, raySin);
		distance = distance * cos(degree_to_radians(ray_angle - env->player.rotation));

		int wallHeight = (int)floor(env->window_half_size.y / distance);
		t_texture texture = pc_get_correct_side(env, ray);
		double texture_pos = floor((int)(texture.width * (ray.x + ray.y)) % texture.width);

		point.y = 0;
		double i = 0;
		while (point.y < env->window_size.y)
		{
			if (point.y <= (int)floor(env->window_half_size.y - wallHeight))
			{
				if (env->map.ceiling == 0)
					my_mlx_pixel_put(env, my_mlx_pixel_get(env->sky, point), point);
				else
					my_mlx_pixel_put(env, env->map.ceiling, point);
			}
			else if (point.y <= (int)floor(env->window_half_size.y + wallHeight))
			{
				double i_inc = ((double)texture.height / (wallHeight * 2));
				if (wallHeight > env->window_half_size.y && i == 0)
				{
					i = (((double)(wallHeight) - env->window_half_size.y) * i_inc);
				}
				unsigned int color = my_mlx_pixel_get(texture, (t_vec2){texture_pos, floor(i)});
				my_mlx_pixel_put(env, color, (t_vec2){point.x, point.y});
				i+=i_inc;
			}
			else
			{
				if (env->map.floor == 0)
				{
					t_vec2 p;
					p.x = point.x;
					p.y = point.y - env->window_half_size.y;
					my_mlx_pixel_put(env, my_mlx_pixel_get(env->floor, p), point);
				}	
				else
					my_mlx_pixel_put(env, env->map.floor, point);

			}
			point.y++;
		}
		point.x++;
		ray_angle += env->raycast_increment;
	}
}

double get_distance_to_wall(t_env *env, t_vec2 *ray, double rayCos, double raySin)
{
	int is_wall;

	is_wall = 0;
	while (!is_wall)
	{
		ray->x += rayCos;
		ray->y += raySin;
		is_wall = env->map.bit_map[(int)floor(ray->y)][(int)floor(ray->x)] == '1';
	}
	return (sqrt(pow(env->player.pos.x - ray->x, 2) + pow(env->player.pos.y - ray->y, 2)));
}
