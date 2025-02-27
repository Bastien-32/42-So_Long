/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:40:15 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/13 11:20:15 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* write a string s to a given file descriptor fd
 followed by a newline character (\n) 
 This is the same function as ft_putstr with /n added, 
 except we replace in write the standard output descriptor 1 by fd*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*s = "toudou bein";
	int fd = open("output.txt", O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		perror("Erreur d'ouverture du fichier");
		return (1);
	}
	ft_putendl_fd("\n", fd); 
	ft_putendl_fd(s, fd);
	ft_putendl_fd("\n", fd);
	close(fd);
	
	return (0);
}
*/