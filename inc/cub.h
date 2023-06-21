/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:24:18 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/21 17:36:18 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "color_and_keys.h"
# define WINDOW_W 1200
# define WINDOW_H 900

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

//    --=[ window_menager.c ]=--    //
void	error(char *str, t_env *env);
int		close_window(t_env *env);
int		key_press(int key, t_env *env);

//       --=[ drawers.c ]=--       //
void	my_mlx_pixel_put(t_env *med, int color, t_vec2 point);

//    --=[ initialization.c ]=--    //
int		input_checker(int ac, char **av, t_env *env);
void	print_instructions(void);
void	init_window(t_env *env, int window_width, int window_height);


#endif
