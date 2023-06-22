/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:53:17 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/22 20:11:01 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	dummy_filling(t_env *env)
{
	env->map.bit_map = calloc(10, sizeof(char *));
	env->map.bit_map[0] = ft_strdup("111111111");
	env->map.bit_map[1] = ft_strdup("100000001");
	env->map.bit_map[2] = ft_strdup("100000001");
	env->map.bit_map[3] = ft_strdup("100000001");
	env->map.bit_map[4] = ft_strdup("100000001");
	env->map.bit_map[5] = ft_strdup("100000001");
	env->map.bit_map[6] = ft_strdup("100000001");
	env->map.bit_map[7] = ft_strdup("100000001");
	env->map.bit_map[8] = ft_strdup("111111111");
	env->map.bit_map[9] = 0;

	env->player.pos.y = 5;
	env->player.pos.x = 5;
}

