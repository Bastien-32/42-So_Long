/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:21:04 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/13 12:17:44 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates through and counts each character in the string s 
   until it encounters the null character (\0) */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}
int	main (int argc, char *argv[])
{
	size_t	t;
	if (argc != 2)
	{
		write (1, "Error", 5);
		return (0);
	}
	t = ft_strlen(argv[1]);
	ft_putnbr (t);
	return (0);
}
*/