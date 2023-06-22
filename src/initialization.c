/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/22 13:12:41 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	input_checker(int ac, char **av, t_env *env)
{
	(void)ac;
	(void)av;
	(void)env;
	print_instructions();
	return (0);
}

void	print_instructions(void)
{
	return ;
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
