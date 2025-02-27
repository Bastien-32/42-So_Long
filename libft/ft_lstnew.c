/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:40 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/15 18:51:50 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstnew creates a new linked list element, 
   initializes its content with content, and sets next to NULL. 
   It returns a pointer to the element or NULL if the allocation fails. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>

int	main(void)
{
	int		value = 42;
	t_list	*new_node;

	new_node = ft_lstnew(&value);
	if (new_node)
		printf("Nœud créé avec le contenu : %d\n", *(int *)(new_node->content));
	free(new_node);
	return (0);
}
*/