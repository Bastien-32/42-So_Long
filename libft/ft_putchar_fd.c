/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:00:56 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/13 11:15:19 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Writes the character c to the file descriptor fd. 
	This is the same function as ft_putchar, 
	except we replace in write the standard output descriptor 1 by fd.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("output.txt", O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("Erreur d'ouverture du fichier");
		return (1);
	}
	ft_putchar_fd('\n', 1); 
	ft_putchar_fd('C', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	
	return (0);
}
*/