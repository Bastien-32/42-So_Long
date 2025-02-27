/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:16:00 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/12 21:58:57 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts an integer `n` into a null-terminated ASCII string 
and returns the string. Handles both positive and negative numbers. */

#include "libft.h"

static int	ft_lenn(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = ft_lenn(nb);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (n == 0)
		str[0] = '0';
	while (nb > 0)
	{
		i--;
		str[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int main (void)
{
	int n = 2147483647;
	char *s = ft_itoa(n);
	printf("%s\n", s);
	free(s);
}
*/
/* attention a bien traiter n == 0 et ne pas oublier de transformer n en long
 ft_lenn -> ne pas oublier la premiere condition*/