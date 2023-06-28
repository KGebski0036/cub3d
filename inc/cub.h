/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:24:18 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 18:18:04 by kgebski          ###   ########.fr       */
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
# include "keys.h"
# include "structs.h"

# define WINDOW_W 1200
# define WINDOW_H 900
# define FOV 60
# define RAY_PRECISION 512
# define MOVMENT_SPEED 0.2
# define ROTATION_SPEED 10

/*
└── src/_main.c   */
/*   └── exit/ - exit.c */
void			pc_error(char *str, t_env *env);
void			pc_free_stuff(t_env *env);

/*   └── ray_casting/ - fps_counter.c | !additional! */
void			pc_fps_counter(t_env *env);
/*   				└── pixels_drawings.c */
/*   				└── textu_drawings.c */
/*   				└── pixels_drawings.c */
void			my_mlx_pixel_put(t_env *med, int color, t_vec2 point);
unsigned int	my_mlx_pixel_get(t_texture texture, t_vec2 point);

//       --=[ helpers.c ]=--       //
void			pc_print_map(t_env *env);
void			pc_print_player(t_env *env);
//    --=[ initialization/input_validation.c ]=--    //
void			pc_input_checker(int ac, char **av);

//    --=[ initialization/initialization.c ]=--    //
void			pc_init_window(t_env *env);
void			pc_init_atributes(t_env *env);

//    --=[ initialization/textures.c ]=--    //
void			pc_init_textures(t_env *env);
void			pc_init_one_texture(t_env *env, t_texture *texture,
					char *file_path);

//    --=[ window_menager.c ]=--    //
int				key_press(int key, t_env *env);
int				pc_close_window(t_env *env, int failure);

//       --=[ drawers.c ]=--       //
int				pc_frame_update(t_env *env);
void			pc_render_frame(t_env *env);
void			pc_raycasting(t_env *env);
double			get_distance_to_wall(t_env *env, t_vec2 *ray,
					double rayCos, double raySin);
t_texture		pc_get_correct_side(t_env *env, t_vec2 ray);

//   --=[ parsing/read_map_file.c ]=--   //
void			pc_read_map_file(t_env *env, char *path);
int				pc_get_texture(t_env *env, t_list **file_lines);
int				is_config(char *str);
int				is_map(char *str);
void			pc_add_config_option(t_env *env, char *option);
unsigned int	pc_decode_color(t_env *env, char *option);

//       --=[ read_map.c ]=--       //
void			pc_map_validation(t_env *env, t_list **file_lines, int offset);
int				pc_count_map_height(t_list **file_lines, t_env *env);
int				pc_count_map_wight(t_list **file_lines);
void			pc_get_map(t_env *env, t_list *el, char ***map);
void			pc_get_player(t_env *env, int j, int i, char c);

//    --=[ map_validator.c ]=--    //
int				pc_check_map(char **map, t_vec2 p_pos, t_vec2 size, t_env *env);
int				pc_fill(char **map, t_vec2 size, int row, int col);
void			pc_fill_edges(char **map, int height, int wight);

//        --=[ utils.c ]=--        //
double			degree_to_radians(double degree);

//    --=[ player_control.c ]=--    //
int				player_control(int key, t_env *env);
void			pc_check_colision(t_env *env, double new_y, double new_x);
double			pc_get_player_angle(int key, t_env *env);
double			pc_get_new_x_pos(int key, t_env *env, double player_cos);
double			pc_get_new_y_pos(int key, t_env *env, double player_sin);

#endif
