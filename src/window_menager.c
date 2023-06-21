/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_menager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/21 17:36:53 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_window(t_env *env)
{
	if (env->window)
		mlx_destroy_window(env->mlx, env->window);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	free(env);
	ft_putstr_fd("Exit\n", 2);
	exit(0);
}

void	error(char *str, t_env *env)
{
	ft_putstr_fd(str, 2);
	close_window(env);
}

int	key_press(int key, t_env *env)
{
	if (key == KEY_ESC)
	{
		close_window(env);
	}
	return (0);
}

