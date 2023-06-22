/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:24:18 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/22 19:55:46 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "mlx.h"
# include "libft.h"
# include "color_and_keys.h"
# include "structs.h"
# define WINDOW_W 1200
# define WINDOW_H 900

//    --=[ window_menager.c ]=--    //
void	error(char *str, t_env *env);
int		close_window(t_env *env);
int		key_press(int key, t_env *env);

//       --=[ drawers.c ]=--       //
void	my_mlx_pixel_put(t_env *med, int color, t_vec2 point);
int		update(t_env *env);

//    --=[ initialization.c ]=--    //
int		input_checker(int ac, char **av, t_env *env);
void	print_instructions(void);
void	init_window(t_env *env, int window_width, int window_height);

//tmp
void	ft_debug(char	*str, char	*str2, t_env	*env);
void	dummy_filling(t_env *env);

#endif
