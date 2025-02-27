/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:07:54 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/15 19:07:42 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes the content of the node lst using the provided del function and 
	frees the node itself. Does not affect other nodes in the list. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
