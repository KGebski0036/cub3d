/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:24:18 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/03 15:22:03 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "libft/libft.h"
# define WINDOW_W 700
# define WINDOW_H 700



typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_env
{
	void			*mlx;
	void			*window;
	void			*img;
	char			*img_addr;
	t_vec2			window_size;

	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_env;

//        --=[ _main.c ]=--        //
int		error(char *str);
int		close_window(t_env *mediator);
int		key_press(int key, t_env *mediator);

//       --=[ drawers.c ]=--       //
void	my_mlx_pixel_put(t_env *med, int color, t_vec2 point);

//    --=[ initialization.c ]=--    //



#endif