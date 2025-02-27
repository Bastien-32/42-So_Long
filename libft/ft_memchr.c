/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:14:37 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/12 22:25:37 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Searches the character `c` in the first `n` bytes of `s`
   and returns a pointer to the address of this character.
   Does not stop at a '\0' and returns NULL if the character is not found.
       /!\ Cast as: (unsigned char)c
                    ((unsigned char *)s)[i]
       /!\ Returns (NULL) at the end if 'c' not found */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main (void)
{
	int c = 'p';
	char *str = "ilop";
	char *d = ft_memchr(str, c, 4);
	printf("%p\n", d);
	printf("%p", &str[3]);
}
*/