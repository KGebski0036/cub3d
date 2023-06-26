/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:19:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/26 18:35:32 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_env	*env;

	input_checker(ac, av);
	env = (t_env *)malloc(sizeof(t_env));
	pc_init_window(env);
	pc_read_config(env, av[1]);
	mlx_loop_hook(env->mlx, update, env);
	mlx_loop(env->mlx);
	return (0);
}
