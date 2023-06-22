#include "cub.h"

void	ft_debug(char	*str, char	*str2, t_env	*env)
{
	printf("%s %s%s@%s\n%s", P_DEBUG, T_DEBUG,UNDERLINE, str2, NC);
	printf("%s--------------------------------------- %s%s\n", T_DEBUG, str, NC);	
	if(env->mlx)
	{
		printf("%smlx			|%s ",T_DEBUG,NC);
				printf("%p\n", env->mlx);//, NC
	}
	if(env->window){
		printf("%swin			|%s ",T_DEBUG,NC);
				printf("%p\n" ,env->window);//, NC
	}
	// if(env->win_width){
	// 	printf("%swin_width		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->win_width);//, NC
	// }
	// if(env->win_height){
	// 	printf("%swin_height		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->win_height);//, NC
	// }
	// if(env->win_title){
	// 	printf("%swin_title		|%s ",T_DEBUG,NC);
	// 			printf("%s\n" ,env->win_title);//, NC
	// }
	if(env->img){
		printf("%simg			|%s ",T_DEBUG,NC);
				printf("%p\n" ,env->img);//, NC
	}
	if(env->img_addr){
		printf("%simg_addr		|%s ",T_DEBUG,NC);
				printf("%s\n" ,env->img_addr);//, NC
	}
	// if(env->img_bpp){
	// 	printf("%simg_bpp		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->img_bpp);//, NC
	// }
	// if(env->img_bytespp){
	// 	printf("%simg_bytespp		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->img_bytespp);//, NC
	// }
	// if(env->img_line_length){
	// 	printf("%simg_line_length	|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->img_line_length);//, NC
	// }
	// if(env->img_endian){
	// 	printf("%simg_endian		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->img_endian);//, NC
	// }
	// if(env->img_width){
	// 	printf("%simg_width		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->img_width);//, NC
	// }
	// if(env->img_height){
	// 	printf("%simg_height		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->img_height);//, NC
	// }
	// if(env->fractal_type){
	// 	printf("%sfractal_type		|%s ",T_DEBUG,NC);
	// 			printf("%c\n" ,env->fractal_type);//, NC
	// }
	// if(env->x_min){
	// 	printf("%sx_min			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->x_min);//, NC
	// }
	// if(env->x_max){
	// 	printf("%sx_max			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->x_max);//, NC
	// }
	// if(env->x_range){
	// 	printf("%sx_rane			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->x_range);//, NC
	// }
	// if(env->y_min){
	// 	printf("%sy_min			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->y_min);//, NC
	// }
	// if(env->y_max){
	// 	printf("%sy_max			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->y_max);//, NC
	// }
	// if(env->y_range){
	// 	printf("%sy_range		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->y_range);//, NC
	// }
	// if(env->x_mappd){
	// 	printf("%sx_mappd		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->x_mappd);//, NC
	// }
	// if(env->y_mappd){
	// 	printf("%sy_mappd		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->y_mappd);//, NC
	// }
	// if(env->zoomfactor){
	// 	printf("%szoomfactor		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->zoomfactor);//, NC
	// }
	// if(env->zoom_current){
	// 	printf("%szoom_current		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->zoom_current);//, NC
	// }
	// if(env->movefactor){
	// 	printf("%smovefactor		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->movefactor);//, NC
	// }
	// if(env->i){
	// 	printf("%si			|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->i);//, NC
	// }
	// if(env->mouse_press_x){
	// 	printf("%smouse_press_x		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mouse_press_x);//, NC
	// }
	// if(env->mouse_press_y){
	// 	printf("%smouse_press_y		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mouse_press_y);//, NC
	// }
	// if(env->mouse_release_x){
	// 	printf("%smouse_release_x	|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mouse_release_x);//, NC
	// }
	// if(env->mouse_release_y){
	// 	printf("%smouse_release_y	|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mouse_release_y);//, NC
	// }
	// if(env->mouse_button){
	// 	printf("%smouse_button		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mouse_button);//, NC
	// }
	// if(env->max_iter){
	// 	printf("%smax_iter		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->max_iter);//, NC
	// }
	// if(env->min_iter){
	// 	printf("%smin_iter		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->min_iter);//, NC
	// }
	// if(env->iter){
	// 	printf("%siter			|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->iter);//, NC
	// }
	// if(env->iterstep){
	// 	printf("%siterstep		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->iterstep);//, NC
	// }
	// if(env->julia_x){
	// 	printf("%sjulia_x		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->julia_x);//, NC
	// }
	// if(env->julia_y){
	// 	printf("%sjulia_y		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->julia_y);//, NC
	// }
	// if(env->r_start){
	// 	printf("%sr_start		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->r_start);//, NC
	// }
	// if(env->r_min){
	// 	printf("%sr_min			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->r_min);//, NC
	// }
	// if(env->a_mappd){
	// 	printf("%sa_mappd		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->a_mappd);//, NC
	// }
	// if(env->b_mappd){
	// 	printf("%sb_mappd		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->b_mappd);//, NC
	// }
	// if(env->r_mappd){
	// 	printf("%sr_mappd		|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->r_mappd);//, NC
	// }
	// if(env->factor){
	// 	printf("%sfactor			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->factor);//, NC
	// }
	// if(env->line){
	// 	printf("%sline			|%s ",T_DEBUG,NC);
	// 			printf("%f\n" ,env->line);//, NC
	// }
	// if(env->maxcolor){
	// 	printf("%smaxcolor		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->maxcolor);//, NC
	// }
	// if(env->mincolor){
	// 	printf("%smincolor		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mincolor);//, NC
	// }
	// if(env->mincolor_t){
	// 	printf("%smincolor_t		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mincolor_t);//, NC
	// }
	// if(env->mincolor_r){
	// 	printf("%smincolor_r		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mincolor_r);//, NC
	// }
	// if(env->mincolor_g){
	// 	printf("%smincolor_g		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mincolor_g);//, NC
	// }
	// if(env->mincolor_b){
	// 	printf("%smincolor_b		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->mincolor_b);//, NC
	// }
	// if(env->maxcolor_t){
	// 	printf("%smincolor_t		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->maxcolor_t);//, NC
	// }
	// if(env->maxcolor_r){
	// 	printf("%smincolor_r		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->maxcolor_r);//, NC
	// }
	// if(env->maxcolor_g){
	// 	printf("%smaxcolor_g		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->maxcolor_g);//, NC
	// }
	// if(env->maxcolor_b){
	// 	printf("%smaxcolor_b		|%s ",T_DEBUG,NC);
	// 			printf("%d\n" ,env->maxcolor_b);//, NC
	// }
	// if(env->color_palette){
	// 	printf("%scolor_palette		|%s ",T_DEBUG,NC);
	// 			printf("%c\n" ,env->color_palette);//, NC
	// }
	// if(env->inside_set_str){
	// 	printf("%sinside_set_str		|%s ",T_DEBUG,NC);
	// 			printf("%s\n" ,env->inside_set_str);//, NC
	// }
	// if(env->outside_set_str){
	// 	printf("%soutside_set_str	|%s ",T_DEBUG,NC);
	// 			printf("%s\n" ,env->outside_set_str);//, NC
	// }
}