/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:47:53 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/27 20:07:45 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	if (!texture->img)
		return (pc_error("XMP to img failed", env));
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
}
