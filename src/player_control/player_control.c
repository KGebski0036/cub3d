/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:37:12 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/25 17:26:55 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	player_control(int key, t_env *env)
{
	if (key == KEY_W)
	{
		double playerCos = cos(degree_to_radians(env->player.rotation)) * MOVMENT_SPEED;
		double playerSin = sin(degree_to_radians(env->player.rotation)) * MOVMENT_SPEED;
		double newX = env->player.pos.x + playerCos;
		double newY = env->player.pos.y + playerSin;


		if(env->map.bit_map[(int)floor(newY)][(int)floor(newX)] != '1') {
			env->player.pos.x = newX;
			env->player.pos.y = newY;
		}
	}
	if (key == KEY_S)
	{
		double playerCos = cos(degree_to_radians(env->player.rotation)) * MOVMENT_SPEED;
		double playerSin = sin(degree_to_radians(env->player.rotation)) * MOVMENT_SPEED;
		double newX = env->player.pos.x - playerCos;
		double newY = env->player.pos.y - playerSin;


		if(env->map.bit_map[(int)floor(newY)][(int)floor(newX)] != '1') {
			env->player.pos.x = newX;
			env->player.pos.y = newY;
		}
	}
	if (key == KEY_A)
	{
		double playerCos = cos(degree_to_radians(env->player.rotation + 90)) * MOVMENT_SPEED;
		double playerSin = sin(degree_to_radians(env->player.rotation + 90)) * MOVMENT_SPEED;
		double newX = env->player.pos.x - playerCos;
		double newY = env->player.pos.y - playerSin;


		if(env->map.bit_map[(int)floor(newY)][(int)floor(newX)] != '1') {
			env->player.pos.x = newX;
			env->player.pos.y = newY;
		}
	}
	if (key == KEY_D)
	{
		double playerCos = cos(degree_to_radians(env->player.rotation + 90)) * MOVMENT_SPEED;
		double playerSin = sin(degree_to_radians(env->player.rotation + 90)) * MOVMENT_SPEED;
		double newX = env->player.pos.x + playerCos;
		double newY = env->player.pos.y + playerSin;


		if(env->map.bit_map[(int)floor(newY)][(int)floor(newX)] != '1') {
			env->player.pos.x = newX;
			env->player.pos.y = newY;
		}
	}
	if (key == KEY_LEFT)
		env->player.rotation -= ROTATION_SPEED;
	if (key == KEY_RIGHT)
		env->player.rotation += ROTATION_SPEED;
	return (0);
}
