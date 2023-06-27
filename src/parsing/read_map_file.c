/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:04:28 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/27 16:21:52 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//! Potential leak with file_lines and file not containing any map
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
	(void)env;
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
		else if (ft_strlen(el->content) > 4 && is_config_option(el->content + i))
			ft_printf("New config option: %s%s%s", GREEN, el->content, NC);
		else if (is_map(el->content))
			break;
		else
			ft_printf("%s Config file contain forbidden option> %s%s",
				pc_error, el->content, NC);
		el = el->next;
	}
	ft_printf("\n");
	return (offset);
}

int	is_config_option(char *str)
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
