/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:41:59 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/14 13:03:27 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* concatenates two strings s1 and s2, allocating enough memory 
to hold both strings, including the null-terminating character (\0). 
It returns a new string containing the content of s1 followed by s2. 
If memory allocation fails, it returns NULL. */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int main(void)
{
	char	*s1 = "Bonjour";
	char	*s2 = " la team 42";
	char	*dest = ft_strjoin(s1, s2);
	printf("%s\n", dest);
	
}
*/