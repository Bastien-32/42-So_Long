/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:58 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/13 11:05:42 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assigns the character c to a string n times and returns s.
   /!\ (unsigned char)c
   /!\ ((unsigned char *)s)[i]  */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int main()
{
	int		i;
	char	*str;
	
	i = 4;
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (1);
	ft_memset(str, 'i', i);
	str[i] = '\0';
	printf(" premier caractere : %c\n", str[0]);
	printf(" dernier caractere : %c\n", str[i - 1]);
	printf(" '\\0' : %c\n", str[i]);
}
*/