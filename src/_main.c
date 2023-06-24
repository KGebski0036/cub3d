/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:19:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/24 17:55:51 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	main(int ac, char **av)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	input_checker(ac, av);
	//init_window(env, WINDOW_W, WINDOW_H);
	pc_read_config(env, av[1]);
	//mlx_loop_hook(env->mlx, update, env);
	//mlx_loop(env->mlx);
	return (0);
}
