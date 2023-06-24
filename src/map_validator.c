/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:08:12 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/24 17:54:18 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pc_check_map_valid(char **map, t_vec2 player_pos, int height, int wight, t_env *env)
{
	int	result;

	result = pc_fill(map, height, wight, (int)player_pos.y, (int)player_pos.x);
	pc_print_map(env);
	return (result);
}

int pc_fill(char **map, int height, int wight, int row, int col)
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
