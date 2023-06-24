/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_keys.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:21:41 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/22 21:42:07 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_AND_KEYS_H
# define COLOR_AND_KEYS_H

// *	---=[ Printf Macros ]=---
# define ERROR "\e[48;5;160m[ ERROR ]\e[0m \e[38;5;196m"
# define P_DEBUG "\e[48;5;202m              [ DEBUGGING ]            \e[0m"
# define INFO "\e[48;5;39m[ INFORMATION ]\e[0m \e[38;5;123m"
# define T_DEBUG "\e[38;5;202m"
# define BLUE "\e[38;5;123m"
# define DARKBLUE "\e[38;5;33m"
# define BLUE_B "\e[48;5;39m"
# define GREEN "\033[1;32m"
# define NC "\033[0m"
# define BOLD "\e[1m"
# define ITALIC "\e[3m"
# define UNDERLINE "\e[4m"
# define STRIKETHROUGH "\e[9m"
# define RED "\e[38;5;160m"

# ifndef KEYS
#  define KEY_ESC = 53
#  define KEY_LEFT = 123
#  define KEY_RIGHT = 124
#  define KEY_W = 13
#  define KEY_A = 0
#  define KEY_S = 1
#  define KEY_D = 2
# endif
#endif
