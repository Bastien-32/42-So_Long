/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:04:56 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/13 11:21:09 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* write a number n to a given file descriptor fd 
 This is the same function as ft_putnbr, except we replace
in write the standard output descriptor 1 by fd*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	nb = 5874;
	int fd = open("output.txt", O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("Erreur d'ouverture du fichier");
		return (1);
	}
	ft_putnbr_fd(nb, fd);
	close(fd);
	
	return (0);
}
*/
