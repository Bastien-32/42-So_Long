/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:43:28 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/12 21:43:55 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert an ASCII character string (char) into an integer value (int).
Need to account for whitespace and a single + or - sign */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	return ((int)result);
}
/*
#include <unistd.h>
void	ft_putnbr(int nb)
{
	char 	c;
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
int	main(void)
{
char	numb[] = "-2147483648";
ft_putnbr(ft_atoi(numb));
return (0);
}
*/