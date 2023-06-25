/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:02:35 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/25 18:37:26 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_env* med, int color, t_vec2 point)
{
	char	*dst;
	int		line_l;
	int		bpp;

	line_l = med->line_length;
	bpp = med->bits_per_pixel;
	dst = med->img_addr + ((int)point.y * line_l + (int)point.x * (bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_env* med, t_vec2 point)
{
	char	*dst;
	int		line_l;
	int		bpp;

	line_l = med->line_length;
	bpp = med->bits_per_pixel;
	dst = med->sky_addr + ((int)point.y * line_l + (int)point.x * (bpp / 8));
	return (*(unsigned int *)dst);
}

int	update(t_env *env)
{
	clock_t				start;
	clock_t				end;
	static unsigned int	frames = 0;
	static clock_t		delta = 0;
	static char *		result = 0;

	start = clock();
	render(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img, 0, 0);
	end = clock();
	frames++;
	delta += end - start;
	if ((delta/(double)CLOCKS_PER_SEC) > 1)
	{
		if (result)
			free(result);
		result = ft_itoa(frames);
		frames = 0;
		delta = 0;
		// system("clear");
		// ft_debug("char	*str", "char	*str2", env);
	}
	mlx_string_put(env->mlx, env->window, 10, 20, 0xFFFFFF, "FPS:");
	if (result)
		mlx_string_put(env->mlx, env->window, 40, 20, 0xFFFFFF, result);
	return (0);
}

void render(t_env *env)
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

		distance = get_distance_to_wall(env, ray, rayCos, raySin);
		distance = distance * cos(degree_to_radians(ray_angle - env->player.rotation));

		int wallHeight = (int)floor(env->window_half_size.y / distance);

		point.y = 0;
		while (point.y < env->window_size.y)
		{
			if (point.y < (int)floor(env->window_half_size.y - wallHeight))
				my_mlx_pixel_put(env, my_mlx_pixel_get(env, point), point);
			else if (point.y < (int)floor(env->window_half_size.y + wallHeight))
				my_mlx_pixel_put(env, 0x00FF00, point);
			else
				my_mlx_pixel_put(env, 0x0000FF, point);

			point.y++;
		}
		point.x++;
		ray_angle += env->raycast_increment;
	}

}

double get_distance_to_wall(t_env *env, t_vec2 ray, double rayCos, double raySin)
{
	int is_wall;

	is_wall = 0;
	while (!is_wall)
	{
		ray.x += rayCos;
		ray.y += raySin;
		is_wall = env->map.bit_map[(int)floor(ray.y)][(int)floor(ray.x)] == '1';
	}
	return (sqrt(pow(env->player.pos.x - ray.x, 2) + pow(env->player.pos.y - ray.y, 2)));
}
