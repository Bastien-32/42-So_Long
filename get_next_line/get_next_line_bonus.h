/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:21:44 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/28 16:23:18 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*search_bsn_and_stash(int fd, char *str);
char	*write_line(char *str);
char	*stash_after_bsn(char *str);
char	*get_next_line(int fd);

//size_t	ft_strlen(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *str, int start, size_t len);
char	*ft_strchr_gnl(const char *s, int c);
//void	*ft_calloc(size_t nmemb, size_t size);

#endif