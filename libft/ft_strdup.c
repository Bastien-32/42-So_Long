/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:35:00 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/14 13:02:45 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates enough memory to copy the source string s, 
including the null-terminating character (\0). 
It then copies each character from s into the newly allocated memory space. 
The function returns a pointer to this newly duplicated string. 
In case of memory allocation failure, it returns NULL.
Use strlcopy for duplicate s to dest.
	/!\ +1 to strlen in malloc to include '\0'. */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*dest;

	slen = ft_strlen(s) + 1;
	dest = (char *)malloc((slen) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, slen);
	return (dest);
}
/* 
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	char	src[] = "Bonjour";
	char	*dest;
	
	dest = ft_strdup(src);
	if (dest == NULL)
	{
		ft_putstr("Erreur d'allocation de memoire");
		return (1);
	}
	ft_putstr(dest);
	ft_putstr("\n");
	free(dest);
}
 */