/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:07:33 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 18:28:05 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pc_print_map(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (env->map.bit_map[i])
	{
		j = 0;
		while (env->map.bit_map[i][j])
		{
			if (floor(env->player.pos.y) == i && floor(env->player.pos.x) == j)
				pc_print_player(env);
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

void	pc_print_player(t_env *env)
{
	if (env->player.rotation == 270)
		ft_printf("🔝");
	if (env->player.rotation == 0)
		ft_printf("🔜");
	if (env->player.rotation == 90)
		ft_printf("🔚");
	if (env->player.rotation == 180)
		ft_printf("🔙");
}

t_texture	*pc_choose_side(t_env *env, char *option)
{
	if (!ft_strncmp(option, "NO ", 3))
		return (&env->map.north);
	if (!ft_strncmp(option, "SO ", 3))
		return (&env->map.south);
	if (!ft_strncmp(option, "WE ", 3))
		return (&env->map.west);
	if (!ft_strncmp(option, "EA ", 3))
		return (&env->map.east);
	return (0);
}
