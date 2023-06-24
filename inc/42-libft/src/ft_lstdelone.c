/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:25:06 by cjackows          #+#    #+#             */
/*   Updated: 2023/06/24 18:47:57 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/**
 * @brief Takes as parameter a node and frees the memory of the node’s
 * content using the function ’del’ given as a parameter and free the node.
 * The memory of ’next’ must not be freed.
 *
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del((void *)(lst->content));
	free(lst);
}
