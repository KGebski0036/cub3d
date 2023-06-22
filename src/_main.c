/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:19:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/22 11:50:06 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int ac, char **av)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	input_checker(ac, av, env);
	init_window(env, WINDOW_W, WINDOW_H);
	mlx_loop_hook(env->mlx, update, env);
	mlx_loop(env->mlx);
	return (0);
}
