/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:02:35 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/22 13:13:58 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

void	my_mlx_pixel_put(t_env* med, int color, t_vec2 point)
{
	char	*dst;
	int		line_l;
	int		bpp;

	line_l = med->line_length;
	bpp = med->bits_per_pixel;
	dst = med->img_addr + ((int)point.y * line_l + (int)point.x * (bpp / 8));
	*(unsigned int *)dst = color;
}

int	update(t_env *env)
{
	clock_t				start;
	clock_t				end;
	static unsigned int	frames = 0;
	static clock_t		delta = 0;
	static char *		result = "100";
	
	start = clock();
	mlx_clear_window(env->mlx, env->window);
	//TODO Operations
	end = clock();
	frames++;
	delta += end - start;
	if ((delta/(double)CLOCKS_PER_SEC) * 1000.0 > 0.2)
	{
		result = ft_itoa(frames * 5);
		frames = 0;
		delta = 0;
		//system("clear");
		//ft_debug("char	*str", "char	*str2", env);
	}
	mlx_string_put(env->mlx, env->window, 10, 20, 0xFFFFFF, "FPS:");
	mlx_string_put(env->mlx, env->window, 40, 20, 0xFFFFFF, result);
	return (0);
}
