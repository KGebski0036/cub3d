/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:24:18 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/24 17:43:39 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
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
void	input_checker(int ac, char **av);
void	print_instructions(void);
void	init_window(t_env *env, int window_width, int window_height);

//   --=[ read_config_file.c ]=--   //
void	pc_read_config(t_env *env, char *path);
int		pc_get_texture(t_env *env, t_list **file_lines);
int		is_config_option(char *str);
int		is_map(char *str);

//       --=[ read_map.c ]=--       //
void	read_map(t_env *env, t_list	**file_lines, int offset);
int		pc_count_map_height(t_list	**file_lines);
int		pc_count_map_wight(t_list **file_lines);
void	pc_get_map(t_env *env, t_list *el, char ***map);
void	pc_get_player(t_env *env, int j, int i, char c);

//       --=[ helpers.c ]=--       //
void	pc_print_map(t_env *env);

//    --=[ map_validator.c ]=--    //
int		pc_check_map_valid(char **map, t_vec2 player_pos, int height, int wight, t_env *env);
int		pc_fill(char **map, int height, int wight, int row, int col);

//tmp
void	ft_debug(char	*str, char	*str2, t_env	*env);


#endif
