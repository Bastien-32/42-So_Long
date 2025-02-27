/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:05 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/17 12:02:26 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assigns the character 0 (not '0') to a string s n times and returns s.
   /!\ cast s to (unsigned char) */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
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
	ft_bzero(str, i);
	str[i] = '\0';
	printf(" premier caractere : %c\n", str[0]);
	printf(" dernier caractere : %c\n", str[i - 1]);
	printf(" '\\0' : %c\n", str[i]);
}
*/