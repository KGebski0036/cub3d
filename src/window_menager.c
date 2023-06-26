/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_menager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:02:34 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/26 12:04:42 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_window(t_env *env)
{
	if (env->window)
		mlx_destroy_window(env->mlx, env->window);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->sky)
		mlx_destroy_image(env->mlx, env->sky);
	if (env->map.bit_map)
		pc_clear_2d_table(env->map.bit_map);
	//! mlx_destroy_display(env->mlx); // this is working onlu on linux
	free(env);
	ft_putstr_fd("\nExit\n", 2);
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
		close_window(env);
	else
		player_control(key, env);
	return (0);
}

void pc_clear_2d_table(char **tab)
{
	int i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}
