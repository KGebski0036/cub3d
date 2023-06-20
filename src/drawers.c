/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:02:35 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/03 15:47:15 by kgebski          ###   ########.fr       */
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
