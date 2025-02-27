/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:54:36 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/20 10:32:49 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_address_pf(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_putnbr_addr_ptr_pf(nb, "0123456789abcdef");
	return (i);
}
