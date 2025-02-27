/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:50 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/05 09:37:19 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_lstadd_front adds the node new to the end of 
   the linked list pointed by lst. */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

/*
#include <stdio.h>

int main (void)
{
	char	*last_value;
	char	*second_value;
	char	*first_value;

	first_value = "Hello";
	second_value = " la";
	last_value = " team";
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	node0 = ft_lstnew(first_value);
	node1 = ft_lstnew(second_value);
	node2 = ft_lstnew(last_value);
	ft_lstadd_back(&node0, node1);
	ft_lstadd_back(&node0, node2);
	while (node0)
	{
		printf("%s", (char *)node0->content);
		node0 = node0->next;
	}
	
}
*/