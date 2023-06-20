/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/03 15:47:23 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

int	close_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->window);
    mlx_destroy_image(env->mlx, env->img);
	free(env);
	exit(0);
}

int	error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

int	key_press(int key, t_env *env)
{
	if (key == 53)
	{
        close_window(env);
		exit(0);
	}
	return (0);
}
