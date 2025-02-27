/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:23 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/12 21:40:00 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns 1 if the character c is either a digit or an alphabetical 
character from the ASCII table, or 0 if it is not */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main()
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n",
		!ft_isalnum(' ')? "ok" : "fail",
		ft_isalnum('a')? "ok" : "fail",
		ft_isalnum('K')? "ok" : "fail",
		ft_isalnum('8')? "ok" : "fail",
		!ft_isalnum('$')? "ok" : "fail",
		!ft_isalnum('\n')? "ok" : "fail");
}
*/