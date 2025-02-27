/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:05:47 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/15 18:10:28 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* applies the function f to each character of the string s to create 
a new resulting string, where each character is modified based on its 
index and initial value. The function f takes two parameters: the character’s
index and the character itself. ft_strmapi returns a pointer to the new string. 
If memory allocation fails, it returns NULL. */

#include "libft.h"
/*
char	ft_upper(unsigned int i, char c)
{
	(void) i;
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>

int main (void)
{
	char *str = "Hello la compagnie 42!";
	char *dest;
	dest = ft_strmapi(str, ft_upper);
	if (dest)
	{
		printf("%s\n", dest);
		free(dest);
	}
}
*/