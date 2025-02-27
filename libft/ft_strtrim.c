/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:14:57 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/15 18:13:11 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* removes all characters specified in set from the beginning and end 
of the string s1, creating a new string with the “trimmed” portion of s1. 
It returns a pointer to this new string, excluding any leading and trailing 
characters found in set. If memory allocation fails, it returns NULL. */

#include "libft.h"

int	ft_strchrtrim(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*dest;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchrtrim(set, s1[start]))
		start++;
	while (end > start && ft_strchrtrim(set, s1[end - 1]))
		end--;
	dest = (char *)malloc((end - start + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < end - start)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
	char	*s = "   Hello, world   !   ";
	char	*set = " ";
	char	*dest = ft_strtrim(s, set);
	printf("%s\n", dest);
	free(dest);
}
*/