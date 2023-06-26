/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:07:33 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/24 17:30:10 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void pc_print_map(t_env *env)
{
	int	i;
	int	j;
	
	i = 0;
	while (env->map.bit_map[i])
	{
		j = 0;
		while (env->map.bit_map[i][j])
		{
			if (env->player.pos.y == i && env->player.pos.x == j)
			{
				if (env->player.rotation == 0)
					ft_printf("🔝");
				if (env->player.rotation == 90)
					ft_printf("🔜");
				if (env->player.rotation == 180)
					ft_printf("🔚");
				if (env->player.rotation == 270)
					ft_printf("🔙");
			}
			else if (env->map.bit_map[i][j] == '0')
				ft_printf("⬛");
			else if (env->map.bit_map[i][j] == '1')
				ft_printf("🟦");
			else if (env->map.bit_map[i][j] == 'F')
				ft_printf("🟩");
			j++;
		}
		i++;
		ft_printf("\n");
	}
}