/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:12 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/12 21:56:18 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns 1 if the character `c` is a digit 
in the ASCII table, or 0 if it is*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main()
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n",
		!ft_isdigit(' ')? "ok" : "fail",
		!ft_isdigit('a')? "ok" : "fail",
		!ft_isdigit('K')? "ok" : "fail",
		ft_isdigit('8')? "ok" : "fail",
		!ft_isdigit('$')? "ok" : "fail",
		!ft_isdigit('\n')? "ok" : "fail");
}
*/