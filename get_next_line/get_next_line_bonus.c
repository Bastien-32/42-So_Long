/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:02:42 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/28 16:23:49 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*search_bsn_and_stash(int fd, char *str)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr_gnl(str, '\n') == NULL)
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (str)
				free(str);
			return (free(buffer), NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	return (free(buffer), str);
}

char	*write_line(char *str)
{
	int		i;
	int		add_bsn;
	char	*line;

	i = 0;
	add_bsn = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		add_bsn = 1;
	line = ft_substr_gnl(str, 0, i + add_bsn);
	return (line);
}

char	*stash_after_bsn(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[0])
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_substr_gnl(str, i + 1, ft_strlen(str));
	if (!line[0])
	{
		free(str);
		return (free(line), NULL);
	}
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[10000];
	char		*line;

	str[fd] = search_bsn_and_stash(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = write_line(str[fd]);
	str[fd] = stash_after_bsn(str[fd]);
	return (line);
}

/*
#include <stdio.h>

int main(void)
{
	int	fd1;
	int fd2;
	char	*line;

	fd1 = open("fd1.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	fd2 = open("fd2.txt", O_RDONLY);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	close(fd1);
	close(fd2);
	free(line);
}*/
