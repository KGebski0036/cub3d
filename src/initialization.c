/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/23 16:03:38 by kgebski          ###   ########.fr       */
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

void	init_window(t_env *env, int window_width, int window_height)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		error("Mlx init failed\n", env);
	env->window_size.y = window_height;
	env->window_size.x = window_width;
	env->window = mlx_new_window(env->mlx, window_width, \
		window_height, "PentaCode Cub3D");
	env->img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H);
	if (!env->img)
		error("Img init failed\n", env);
	env->img_addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
	&env->line_length, &env->endian);
	if (!env->window)
		error("Window init failed\n", env);
	mlx_key_hook(env->window, key_press, env);
	mlx_hook(env->window, 17, 0, close_window, env);
}
