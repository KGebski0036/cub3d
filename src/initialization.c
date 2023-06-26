/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/26 15:13:01 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	input_checker(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		print_instructions();
	if (ft_strlen(av[1]) < 4 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		print_instructions();
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_instructions();
	close(fd);
}

void	print_instructions(void)
{
	printf("%sPlese provide as an argument one of the map from maps folder \
example:%s ./cub3d maps/cube.cub%s\n", ERROR, GREEN, NC);
	exit(0);
}

void	init_window(t_env *env)
{
	init_atributes(env);
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

void init_atributes(t_env *env)
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

void pc_init_textures(t_env *env)
{
	env->sky.img = mlx_xpm_file_to_image(env->mlx, "textures/sky.xpm", &env->sky.width, &env->sky.height);
	env->sky.addr = mlx_get_data_addr(env->sky.img, &env->sky.bits_per_pixel, &env->sky.line_length, &env->sky.endian);
	
	env->floor.img = mlx_xpm_file_to_image(env->mlx, "textures/sand_floor.xpm", &env->floor.width, &env->floor.height);
	env->floor.addr = mlx_get_data_addr(env->floor.img, &env->floor.bits_per_pixel, &env->floor.line_length, &env->floor.endian);
	
	env->map.north.img = mlx_xpm_file_to_image(env->mlx, "textures/Grey_Brick.xpm", &env->map.north.width, &env->map.north.height);
	env->map.north.addr = mlx_get_data_addr(env->map.north.img, &env->map.north.bits_per_pixel, &env->map.north.line_length, &env->map.north.endian);
}