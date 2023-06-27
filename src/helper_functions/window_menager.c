/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_menager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/27 16:58:47 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int key, t_env *env)
{
	if (key == KEY_ESC)
	{
		pc_free_stuff(env, 0);
		close_window(env, 0);
	}
	else
		player_control(key, env);
	return (0);
}

int	close_window(t_env *env, int failure)
{
	if (env->window)
		mlx_destroy_window(env->mlx, env->window);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	exit(failure);
}
