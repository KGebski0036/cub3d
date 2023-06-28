/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:04:28 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/28 18:19:42 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pc_read_map_file(t_env *env, char *path)
{
	int		fd;
	int		offset;
	t_list	**file_lines;
	char	*line;

	fd = open(path, O_RDONLY);
	file_lines = ft_calloc(1, sizeof(t_list *));
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(file_lines, ft_lstnew(line));
		line = get_next_line(fd);
	}
	ft_lstadd_back(file_lines, ft_lstnew(line));
	offset = pc_get_texture(env, file_lines);
	if (offset == ft_lstsize(*file_lines) - 1)
	{
		free(file_lines);
		return (pc_error("Config did not contain map", env));
	}
	else
		pc_map_validation(env, file_lines, offset - 1);
	ft_lstclear(file_lines, free);
	free(file_lines);
}

int	pc_get_texture(t_env *env, t_list **file_lines)
{
	t_list	*el;
	int		offset;
	int		i;

	el = *file_lines;
	offset = 0;
	while (el->next)
	{
		i = 0;
		offset++;
		while (el->content[i] == ' ')
			i++;
		if (!el->content[i] || el->content[i] == '\n')
		{
			el = el->next;
			continue ;
		}
		else if (ft_strlen(el->content) > 4 && is_config(el->content + i))
			pc_add_config_option(env, el->content);
		else if (is_map(el->content))
			break ;
		else
			pc_error("Config file contain forbidden option", env);
		el = el->next;
	}
	ft_printf("\n");
	return (offset);
}

int	is_config(char *str)
{
	return (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
		|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2));
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ' && str[i] != '\n'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (0);
		i++;
	}
	return (1);
}

void	pc_add_config_option(t_env *env, char *option)
{
	char			*tmp;
	unsigned int	color;
	t_texture		*texture;

	if (!ft_strncmp(option, "F ", 2) || !ft_strncmp(option, "C ", 2))
	{
		color = pc_decode_color(env, option);
		if (!ft_strncmp(option, "F ", 2))
			env->map.floor = color;
		else
			env->map.ceiling = color;
		ft_printf("New color added: %s%s%s", GREEN, option, NC);
	}
	else
	{
		if (!ft_strncmp(option, "NO ", 3))
			texture = &env->map.north;
		if (!ft_strncmp(option, "SO ", 3))
			texture = &env->map.south;
		if (!ft_strncmp(option, "WE ", 3))
			texture = &env->map.west;
		if (!ft_strncmp(option, "EA ", 3))
			texture = &env->map.east;
		option += 2;
		while (*(++option) == ' ')
			;
		tmp = ft_strtrim(option, " \n");
		pc_init_one_texture(env, texture, tmp);
		free(tmp);
		ft_printf("New texture added: %s%s%s", GREEN, option, NC);
	}
}

unsigned int	pc_decode_color(t_env *env, char *option)
{
	unsigned int	result;
	char			*tmp;
	int				i;
	int				k;

	i = 0;
	k = 0;
	result = 0;
	while (k < 3)
	{
		option += i;
		i = 0;
		while (!ft_isdigit(*(++option)))
			;
		while (ft_isdigit(option[i]))
			i++;
		tmp = ft_substr(option, 0, i);
		if (!ft_isnumber(tmp) || ft_atoi(tmp) < 0 || ft_atoi(tmp) > 255)
			pc_error("One of color argument is not a valid number", env);
		result <<= 8;
		result += ft_atoi(tmp);
		free(tmp);
		k++;
	}
	return (result);
}