/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:49:56 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/22 20:23:14 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCT_H

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}	t_color;

typedef struct s_texture
{
	t_color	***matx;
	int		height;
	int		width;
}	t_texture;

typedef struct s_map
{
	char		**bit_map;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_color		ceiling;
	t_color		floor;
}	t_map;

typedef struct s_player
{
	t_vec2	pos;
}	t_player;

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

	t_map			map;
	t_player		player;
}	t_env;

#endif
