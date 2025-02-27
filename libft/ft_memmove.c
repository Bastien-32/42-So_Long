/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:42 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/12 22:41:00 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copies the first `n` bytes from `src` to `dest`.
   Handles memory overlap.
       /!\ Use: while (i < n) ... i++
       /!\ And: while (n != 0) ... n--
       /!\ ((unsigned char *)s)[i] */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (n != 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}

/*
#include <stdio.h>
#include <stdlib.h>

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
	dest = ft_memmove(dest, src, 3);
	printf("%s\n", dest);
	dest = memmove(dest, src, 3);
	printf("%s\n", dest);
}
*/