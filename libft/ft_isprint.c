/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:21 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/12 21:57:33 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns 1 if the character `c` is between ' ' and
the second-to-last character in the ASCII table, or 0 if it is not */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main()
{
	printf("%s\n%s\n%s\n%s\n%s\n%s\n",
		ft_isprint(' ')? "ok" : "fail",
		ft_isprint('a')? "ok" : "fail",
		ft_isprint('K')? "ok" : "fail",
		ft_isprint('8')? "ok" : "fail",
		ft_isprint('$')? "ok" : "fail",
		!ft_isprint('\n')? "ok" : "fail");
}
*/