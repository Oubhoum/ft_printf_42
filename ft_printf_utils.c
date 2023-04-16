/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:35:08 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/27 04:56:38 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static	size_t	ft_25_lines(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		len += ft_putchar(nbr + 48);
	return (len);
}

size_t	ft_putnbr(int nb)
{
	size_t	lenght;
	char	*cr;

	lenght = 0;
	if (nb == -2147483648)
	{
		cr = (char *)malloc(((sizeof(char)) * 12) + 1);
		if (!cr)
			return (0);
		ft_memcpy(cr, "-2147483648\0", 12);
		lenght = ft_putstr(cr);
		free(cr);
		return (lenght);
	}
	lenght += ft_25_lines(nb);
	return (lenght);
}

size_t	ft_putstr(char *str)
{
	size_t	lenght;

	lenght = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		lenght = lenght + ft_putchar(*str);
		str++;
	}
	return (lenght);
}

size_t	ft_put_unsigned_int(unsigned int nb)
{
	size_t	lenght;

	lenght = 0;
	if (nb >= 10)
	{
		lenght += ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		lenght += ft_putchar(nb + 48);
	return (lenght);
}
