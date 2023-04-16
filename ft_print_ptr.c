/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:24 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/24 16:53:34 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_dec_hex_lowpo(unsigned long long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar ('-');
		nb = -nb;
	}
	if (nb >= 16)
	{
		len += ft_dec_hex_lowpo(nb / 16);
		len += ft_dec_hex_lowpo(nb % 16);
	}
	if (nb >= 0 && nb <= 9)
		len += ft_putchar(nb + '0');
	if (nb > 9 && nb <= 15)
	{
		len += ft_putchar(nb - 10 + 'a');
	}
	return (len);
}

size_t	ft_print_ptr(unsigned long long nb)
{
	size_t	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_dec_hex_lowpo(nb);
	return (len);
}
