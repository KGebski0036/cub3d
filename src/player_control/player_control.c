/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:37:12 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 18:04:20 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	player_control(int key, t_env *env)
{
	double	player_cos;
	double	player_sin;
	double	new_x;
	double	new_y;

	player_cos = cos(pc_get_player_angle(key, env)) * MOVMENT_SPEED;
	player_sin = sin(pc_get_player_angle(key, env)) * MOVMENT_SPEED;
	new_x = pc_get_new_x_pos(key, env, player_cos);
	new_y = pc_get_new_y_pos(key, env, player_sin);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		pc_check_colision(env, new_y, new_x);
	if (key == KEY_LEFT)
		env->player.rotation -= ROTATION_SPEED;
	if (key == KEY_RIGHT)
		env->player.rotation += ROTATION_SPEED;
	return (0);
}

void	pc_check_colision(t_env *env, double new_y, double new_x)
{
	if (env->map.bit_map[(int)floor(new_y)][(int)floor(new_x)] != '1')
	{
		env->player.pos.x = new_x;
		env->player.pos.y = new_y;
	}
}

double	pc_get_player_angle(int key, t_env *env)
{
	if (key == KEY_W || key == KEY_S)
		return (degree_to_radians(env->player.rotation));
	else
		return (degree_to_radians(env->player.rotation + 90));
}

double	pc_get_new_x_pos(int key, t_env *env, double player_cos)
{
	if (key == KEY_W || key == KEY_D)
		return (env->player.pos.x + player_cos);
	else
		return (env->player.pos.x - player_cos);
}

double	pc_get_new_y_pos(int key, t_env *env, double player_sin)
{
	if (key == KEY_W || key == KEY_D)
		return (env->player.pos.y + player_sin);
	else
		return (env->player.pos.y - player_sin);
}
