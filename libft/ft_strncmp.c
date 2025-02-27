/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:21:17 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/15 18:11:51 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* compares up to n characters of the strings s1 and s2, or stops earlier 
if a null character (\0) is encountered in either string. It returns a negative 
value if s1 is less than s2, zero if they are equal, or a positive value if 
s1 is greater than s2. If n is 0, the function returns 0 immediately without 
performing any comparison. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
