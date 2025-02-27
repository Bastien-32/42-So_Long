/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:52:37 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/16 11:08:21 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* traverses a linked list pointed to by lst and returns the total number 
of nodes in the list. */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int main (void)
{
	char	*last_value;
	char	*second_value;
	char	*first_value;
	int		nlist;

	first_value = "Hello";
	second_value = " la";
	last_value = " team";
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	node0 = ft_lstnew(first_value);
	node1 = ft_lstnew(second_value);
	node2 = ft_lstnew(last_value);
	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node2, node0);
	nlist = ft_lstsize(node2);
	printf("%d", nlist);
}
*/