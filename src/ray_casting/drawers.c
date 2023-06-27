/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:02:35 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/27 19:40:08 by kgebski          ###   ########.fr       */
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

unsigned int	my_mlx_pixel_get(t_texture texture, t_vec2 point)
{
	char	*dst;
	int		line_l;
	int		bpp;

	line_l = texture.line_length;
	bpp = texture.bits_per_pixel;
	dst = texture.addr + ((int)point.y * line_l + (int)point.x * (bpp / 8));
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
				my_mlx_pixel_put(env, my_mlx_pixel_get(env->sky, point), point);
			else if (point.y <= (int)floor(env->window_half_size.y + wallHeight))
			{
				double i_inc = ((double)texture.height / (wallHeight * 2));
				// if (wallHeight > env->window_half_size.y && i == 0)
				// {
				// 	i = floor(((double)(wallHeight) - env->window_half_size.y) / 6);
				// }
				unsigned int color = my_mlx_pixel_get(texture, (t_vec2){texture_pos, floor(i)});
				my_mlx_pixel_put(env, color, (t_vec2){point.x, point.y});
				i+=i_inc;
			}
			else
			{
				t_vec2 p;
				p.x = point.x;
				p.y = point.y - env->window_half_size.y;
				my_mlx_pixel_put(env, my_mlx_pixel_get(env->floor, p), point);
			}
			point.y++;
		}
		point.x++;
		ray_angle += env->raycast_increment;
	}
	//exit(1);
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
	// printf("ray-> x: %f y: %f \n", round(ray.x), round(ray.y));
	// printf("block cords: x: %i y: %i\n\n", (int)floor(ray.x), (int)floor(ray.y));
	if (round(ray.y * 256) == floor(ray.y) * 256 && floor(ray.y) != 0 && env->map.bit_map[(int)floor(ray.y) - 1][(int)floor(ray.x)] != '1')
		return (env->map.north);
	if (round((ray.x) * 256) == floor(ray.x) * 256 )
		return (env->map.west);
	if (round((ray.y) * 256) == (floor(ray.y) + 1) * 256 && env->map.bit_map[(int)floor(ray.y)] != 0 && env->map.bit_map[(int)floor(ray.y) + 1][(int)floor(ray.x)] != '1')
		return (env->map.south);
	else
		return (env->map.east);
}
