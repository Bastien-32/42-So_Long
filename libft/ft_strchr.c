/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:46 by badal-la          #+#    #+#             */
/*   Updated: 2024/11/15 13:21:35 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* searches for the character c in a null-terminated string s 
and returns the address of its position if found, 
or NULL if the character is not present. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
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

/*
#include <unistd.h>

void	print_address_hex(void *ptr)
{
	char		hex_digits[] = "0123456789abcdef";
	unsigned long	address = (unsigned long)ptr;
	char		buffer[20];
	int		i = 19;

	buffer[i--] = '\0';  // Ajout du caractère nul pour marquer la fin
	if (address == 0)
		buffer[i--] = '0';

	// Conversion de l'adresse en hexadécimal
	while (address > 0)
	{
		buffer[i--] = hex_digits[address % 16];
		address /= 16;
	}

	// Préfixe "0x" pour indiquer l'hexadécimal
	buffer[i--] = 'x';
	buffer[i] = '0';

	// Affichage de l'adresse avec write
	write(1, &buffer[i], 20 - i - 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	char *result = ft_strchr(argv[1], argv[2][0]);

	if (result != NULL)
	{
		write(1, "Adresse du caractère trouvé : ", 30);
		write(1, "\n", 1);
		print_address_hex(result);
		write(1, "\n", 1);
		print_address_hex(&argv[1][1]);
	}
	else
	{
		write(1, "Character not found\n", 20);
	}
	return (0);
}
*/