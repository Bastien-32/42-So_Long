/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:40:47 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/05 13:33:31 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes all the nodes of the linked list 
   pointed to by lst. At the end, *lst is set to NULL. */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
// code sans avoir à déréférencer la liste
/* void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*temp;
	t_list		*current;

	if (!lst || !del)
		return ;
	current = *list;
	while (current)
	{
		temp = current->next;
		ft_lstdelone(current, del);
		current = temp;
	}
	*lst = NULL;
} 
*/