/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:22:07 by badal-la          #+#    #+#             */
/*   Updated: 2025/01/27 17:52:41 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_address_pf(unsigned long nb);

int	ft_putnbr_pf(int n);

int	ft_putnbr_base_pf(unsigned int nb, char *base);

int	ft_putnbr_addr_ptr_pf(unsigned long nb, char *base);

int	ft_putnbr_pos_pf(unsigned int n);

int	ft_putchar_pf(char c);

int	ft_putstr_pf(char *s);

int	ft_strlen_pf(char *str);

int	ft_printf(const char *format, ...);

#endif