/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:04:28 by kgebski           #+#    #+#             */
/*   Updated: 2023/06/23 17:07:13 by kgebski          ###   ########.fr       */
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
		if (el->content[i])
		el = el->next;
	}

}
int is_config_option(char c1, char c2)
{
	return c == 'N'
}
