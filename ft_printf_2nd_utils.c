/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2nd_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:28:57 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/27 04:57:13 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_dec_hex_low(unsigned int nb)
{
	size_t	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_dec_hex_low(nb / 16);
		len += ft_dec_hex_low(nb % 16);
	}
	if (nb >= 0 && nb <= 9)
		len += ft_putchar(nb + '0');
	if (nb > 9 && nb <= 15)
	{
		len += ft_putchar(nb - 10 + 'a');
	}
	return (len);
}

size_t	ft_dec_hex_up(unsigned int nb)
{
	size_t	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_dec_hex_up(nb / 16);
		len += ft_dec_hex_up(nb % 16);
	}
	if (nb >= 0 && nb <= 9)
		len += ft_putchar(nb + '0');
	if (nb > 9 && nb <= 15)
	{
		len += ft_putchar(nb - 10 + 'A');
	}
	return (len);
}
