/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validtion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:08:12 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 15:06:15 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pc_check_map(char **map, t_vec2 p_pos, int height, int wight, t_env *env)
{
	int	result;

	result = pc_fill(map, height, wight, (int)p_pos.y, (int)p_pos.x);
	pc_fill_edges(map, height, wight);
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

	i += pc_fill(map, height, wight, row - 1, col);
	i += pc_fill(map, height, wight, row + 1, col);
	i += pc_fill(map, height, wight, row, col - 1);
	i += pc_fill(map, height, wight, row, col + 1);

	if (i != 4)
		return (0);
	return (1);
}

void	pc_fill_edges(char **map, int height, int wight)
{
	int i;
	
	i = 0;
	while (i < wight)
		map[0][i++] = '1';
	i = 0;
	while (i < wight)
		map[height - 1][i++] = '1';
	i = 0;
	while (i < height)
		map[i++][0] = '1';
	i = 0;
	while (i < height)
		map[i++][wight - 2] = '1';
}