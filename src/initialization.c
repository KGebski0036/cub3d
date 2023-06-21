/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/21 17:22:21 by kgebski          ###   ########.fr       */
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
	if (!env->window)
		error("Window init failed\n", env);
	env->img = 0;
	mlx_key_hook(env->window, key_press, env);
	mlx_hook(env->window, 17, 0, close_window, env);
}
