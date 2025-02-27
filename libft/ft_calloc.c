/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:58:24 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/28 16:21:28 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* malloc an array with nmemb elements of size 'size' and assigns 0 
   (not '0') to each byte created with using bzero after malloc */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	slen;
	char	*dest;

	slen = nmemb * size;
	dest = (char *)malloc((slen) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, slen);
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
	char	*dest;

	dest = ft_calloc(6, 3);
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