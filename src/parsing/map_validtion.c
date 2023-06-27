/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validtion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:08:12 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/26 19:01:45 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pc_check_map(char **map, t_vec2 p_pos, int height, int wight, t_env *env)
{
	int	result;

	result = pc_fill(map, height, wight, (int)p_pos.y, (int)p_pos.x);
	pc_print_map(env);
	return (result);
}

int	pc_fill(char **map, int height, int wight, int row, int col)
{
	int	i;

	i = 0;
	if (row < 0 || col < 0 || row >= height || col >= wight)
		return (0);
	if (map[row][col] == 'F' || map[row][col] != '0')
	{
		if (map[row][col] == '\0')
			return (0);
		return (1);
	}
	map[row][col] = 'F';

	i += pc_fill(map, height, wight, row -1, col);
	i += pc_fill(map, height, wight, row +1, col);
	i += pc_fill(map, height, wight, row, col - 1);
	i += pc_fill(map, height, wight, row, col + 1);

	if (i != 4)
		return (0);
	return (1);
}
