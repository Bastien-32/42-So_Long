/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:29:17 by badal-la          #+#    #+#             */
/*   Updated: 2024/12/04 19:40:16 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compares the memory blocks `s1` and `s2`, byte by byte, up to `n` bytes.
   Note: `strncmp` compares two character strings.
   	/!\ convert s1 & s2 in  (unsigned char *) */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
