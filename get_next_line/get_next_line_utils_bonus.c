/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:39:54 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/28 16:21:53 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
} */

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (free(s1), NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (free(s1), dest);
}

char	*ft_substr_gnl(char *str, int start, size_t len)
{
	char		*dest;
	size_t		i;

	i = 0;
	if (!str)
		return (NULL);
	if ((size_t)start >= len)
	{
		dest = malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	dest = malloc((len + 1) * sizeof(char));
	while (str[start + i] && i < len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*dest;
	size_t		i;
	size_t		len;

	i = 0;
	len = nmemb * size;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
} */
