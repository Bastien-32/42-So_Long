/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:10:00 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/14 13:00:28 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applies the given function f to each element 
   of the linked list pointed by lst. */

#include "libft.h"
/*
void	ft_upper(void *str)
{
	char	*ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr -= 32;
		ptr++;
	}
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>

int main (void)
{
	char	first_value[] = "Hello";
	char	second_value[] = " la";
	char	last_value[] = " team";

	t_list	*node0 = ft_lstnew(first_value);
	t_list	*node1 = ft_lstnew(second_value);
	t_list	*node2 = ft_lstnew(last_value);

	ft_lstadd_front(&node2, node1);
	ft_lstadd_front(&node2, node0);

	ft_lstiter(node2, ft_upper);
	while (node2)
	{
		printf("%s",(char *)node2->content);
		node2 = node2->next;
	}
	return 0;
}
*/
