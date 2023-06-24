/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:04:28 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/24 14:37:38 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void pc_read_config(t_env *env, char *path)
{
	int		fd;
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
	pc_get_texture(env, file_lines);
}

void pc_get_texture(t_env *env, t_list **file_lines)
{
	t_list	*el;
	int		i;

	el = *file_lines;
	(void)env;
	while (el->next)
	{
		i = 0;
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
		else if(el->content[i] != '\n')
			ft_printf("%s Config file contain forbidden option> %s%s",
				ERROR, el->content, NC);
		el = el->next;
	}
	ft_printf("\n");
}

int is_config_option(char *str)
{
	return (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
			|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
			|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2));
}

int is_map(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != 1 && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}