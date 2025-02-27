/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:50 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/20 10:04:47 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	callconv(va_list args, const char *format)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar_pf(va_arg(args, int));
	else if (*format == 's')
		i += ft_putstr_pf(va_arg(args, char *));
	else if (*format == 'd')
		i += ft_putnbr_pf(va_arg(args, int));
	else if (*format == 'p')
		i += ft_address_pf(va_arg(args, unsigned long));
	else if (*format == 'i')
		i += ft_putnbr_pf(va_arg(args, int));
	else if (*format == 'u')
		i += ft_putnbr_pos_pf(va_arg(args, unsigned int));
	else if (*format == 'x')
		i += ft_putnbr_base_pf(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		i += ft_putnbr_base_pf(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*format == '%')
	{
		i += write(1, "%", 1);
		format++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			i += callconv(args, format);
		}
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{	
	int	i = 0;

	int test = 42;
	int testneg = -42;
	char *testchar="Banzai";

	//ft_printf(" NULL %s NULL \n", NULL);
	//printf(" NULL %s NULL ", NULL);
	
	ft_printf(" %p %p \n\n", 0, 0);
	//printf(" %p %p ", 0, 0);


	i = ft_printf("Test de %%c :\n");
	i = ft_printf("Hello, 42! My lucky char is %c.", 'a');
	ft_printf("j'ai ecrit %d caracteres.\n", i);
	i = printf("Hello, 42! My lucky char is %c.", 'a');
	printf("j'ai ecrit %d caracteres.\n", i);

	i = ft_printf("\nTest de %%s :\n");
	i = ft_printf("Hello, 42! My lucky string is %s.", testchar);
	ft_printf("j'ai ecrit %d caracteres.\n", i);
	i = printf("Hello, 42! My lucky string is %s.", testchar);
	printf("j'ai ecrit %d caracteres.\n", i);

	i = ft_printf("\nTest de %%p :\n");
	ft_printf("Adresse du test : %p\n", &test);
	printf("Adresse du test : %p\n", &test);
	
	i = ft_printf("\nTest de %%d :\n");
	i = ft_printf("Hello, 42! My lucky number is %d.", test);
	ft_printf("j'ai ecrit %d caracteres.\n", i);
	i = printf("Hello, 42! My lucky number is %d.", test);
	printf("j'ai ecrit %d caracteres.\n", i);
	
	i = ft_printf("\nTest de %%i :\n");
	i = ft_printf("Hello, 42! My lucky number is %i.", test);
	ft_printf("j'ai ecrit %i caracteres.\n", i);
	i = printf("Hello, 42! My lucky number is %i.", test);
	printf("j'ai ecrit %i caracteres.\n", i);

	i = ft_printf("\nTest de %%u :\n");
	i = ft_printf("Hello, 42! My lucky number is %u.", testneg);
	ft_printf("j'ai ecrit %i caracteres.\n", i);
	i = printf("Hello, 42! My lucky number is %u.", testneg);
	printf("j'ai ecrit %i caracteres.\n", i);

	i = ft_printf("\nTest de %%x :\n");
	i = ft_printf("Hello, 42! My lucky number is %x.", test);
	ft_printf("j'ai ecrit %i caracteres.\n", i);
	i = printf("Hello, 42! My lucky number is %x.", test);
	printf("j'ai ecrit %i caracteres.\n", i);

	i = ft_printf("\nTest de %%X :\n");
	i = ft_printf("Hello, 42! My lucky number is %X.", testneg);
	ft_printf("j'ai ecrit %i caracteres.\n", i);
	i = printf("Hello, 42! My lucky number is %X.", testneg);
	printf("j'ai ecrit %i caracteres.\n", i);
	return (0);
}
*/