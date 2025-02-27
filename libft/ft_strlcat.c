/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:34:54 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/14 13:03:39 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_strlcat appends the string src to the end of dst, ensuring the total 
length does not exceed size, including the null-terminating character (\0). 
The function returns the total length the resulting string would have had 
if size were sufficiently large (initial length of dst plus length of src). 
If size is less than or equal to the initial length of dst, 
it returns size + the length of src. The function ensures that dst 
is always null-terminated. */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size == 0 || size <= i)
		return (ft_strlen(src) + size);
	while ((j < (size - i - 1)) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
/*
#include <stdio.h>

int	main (void)
{
	char *src = " la team";
	char dest[18] = "Bonjour";
	int i = ft_strlcat(dest, src, 12);
	printf("%s\n", dest);
	printf("%d", i);
	return (0);
}
*/