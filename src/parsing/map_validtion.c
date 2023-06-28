/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validtion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:08:12 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 18:13:47 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pc_check_map(char **map, t_vec2 p_pos, t_vec2 size, t_env *env)
{
	int	result;

	result = pc_fill(map, size, (int)p_pos.y, (int)p_pos.x);
	pc_print_map(env);
	pc_fill_edges(map, (int)size.y, (int)size.x);
	return (result);
}

int	pc_fill(char **map, t_vec2 size, int row, int col)
{
	int	i;

	i = 0;
	if (row < 0 || col < 0 || row >= (int)size.y || col >= (int)size.x)
		return (0);
	if (map[row][col] == 'F' || map[row][col] != '0')
	{
		if (map[row][col] == '\0')
			return (0);
		return (1);
	}
	map[row][col] = 'F';
	i += pc_fill(map, size, row - 1, col);
	i += pc_fill(map, size, row + 1, col);
	i += pc_fill(map, size, row, col - 1);
	i += pc_fill(map, size, row, col + 1);
	if (i != 4)
		return (0);
	return (1);
}

void	pc_fill_edges(char **map, int height, int wight)
{
	int	i;

	i = 0;
	while (i < wight - 1)
		map[0][i++] = '1';
	i = 0;
	while (i < height)
		map[i++][0] = '1';
	i = 0;
	while (i < height)
	{
		map[i][ft_strlen(map[i]) - 1] = '1';
		i++;
	}
}
