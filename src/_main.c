/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:19:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/25 16:31:23 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int ac, char **av)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	input_checker(ac, av);
	init_window(env);
	pc_read_config(env, av[1]);
	mlx_loop_hook(env->mlx, update, env);
	mlx_loop(env->mlx);
	return (0);
}
