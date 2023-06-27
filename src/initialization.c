/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/27 14:23:06 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pc_init_window(t_env *env)
{
	pc_init_atributes(env);
	env->mlx = mlx_init();
	if (!env->mlx)
		error("Mlx init failed\n", env);
	env->window = mlx_new_window(env->mlx, env->window_size.x,
			env->window_size.y, "PentaCode Cub3D");
	if (!env->window)
		error("Window init failed\n", env);
	env->img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H);
	if (!env->img)
		error("Img init failed\n", env);
	env->img_addr = mlx_get_data_addr(env->img, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	pc_init_textures(env);
	mlx_hook(env->window, 2, 1, key_press, env);
	mlx_hook(env->window, 17, 1, close_window, env);
}

void	pc_init_atributes(t_env *env)
{

	env->window_size.y = WINDOW_H;
	env->window_size.x = WINDOW_W;
	env->window_half_size.y = WINDOW_H / 2;
	env->window_half_size.x = WINDOW_W / 2;
	env->half_fov = FOV / 2;
	env->raycast_increment = (double)FOV / (double)WINDOW_W;
	env->raycast_precision = RAY_PRECISION;
	env->player.pos.x = -1;
	env->player.pos.y = -1;
	env->map.bit_map = 0;
}

void	pc_init_textures(t_env *env)
{
	pc_init_one_texture(env, &env->sky, "textures/sky.xpm");
	pc_init_one_texture(env, &env->floor, "textures/sand_floor.xpm");
	pc_init_one_texture(env, &env->map.north, "textures/Grey_Brick.xpm");
	pc_init_one_texture(env, &env->map.south, "textures/Wooden-wall.xpm");
	pc_init_one_texture(env, &env->map.west, "textures/wall_metal.xpm");
	pc_init_one_texture(env, &env->map.east, "textures/wall_mossy.xpm");
}

void	pc_init_one_texture(t_env *env, t_texture *texture, char *file_path)
{
	texture->img = mlx_xpm_file_to_image(env->mlx, file_path, &texture->width,
			&texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
}
