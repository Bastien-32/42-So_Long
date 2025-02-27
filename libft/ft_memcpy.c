/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:33 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/15 13:19:32 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies the first `n` bytes from `src` to `dest`.
   Does not handle overlapping memory (for this, use `memmove`).
       /!\ Use only: while (i < n) ... i++
       /!\ ((unsigned char *)s)[i] */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main (void)
{
	char src[]="bonjour";
	char *dest = malloc(20 * sizeof(char));

    if (dest == NULL) 
	{
        perror("malloc failed");
        return 1; 
	}
	printf("%s\n", src);
	memcpy(dest, src, 3);
	printf("%s\n", dest);
	ft_memcpy(dest, src, 3);
	printf("%s\n", dest);
	
}
*/