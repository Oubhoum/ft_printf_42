/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:30:39 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/29 15:38:27 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	handel_25_line(va_list ptr, const char format)
{
	size_t	lenght;

	lenght = 0;
	if (format == 'c')
		lenght += ft_putchar(va_arg(ptr, int));
	else if (format == 'd' || format == 'i')
		lenght += ft_putnbr(va_arg(ptr, int));
	else if (format == 's')
		lenght += ft_putstr(va_arg(ptr, char *));
	else if (format == '%')
		lenght += ft_putchar('%');
	else if (format == 'u')
		lenght += ft_put_unsigned_int(va_arg(ptr, unsigned int));
	else if (format == 'x')
		lenght += ft_dec_hex_low(va_arg(ptr, int));
	else if (format == 'X')
		lenght += ft_dec_hex_up(va_arg(ptr, int));
	else if (format == 'p')
		lenght += ft_print_ptr(va_arg(ptr, unsigned long long));
	else
		lenght += ft_putchar(format);
	return (lenght);
}

int	ft_printf(const char *format, ...)
{
	size_t	lenght;
	va_list	ptr;

	lenght = 0;
	va_start (ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			lenght += handel_25_line(ptr, *format);
		}
		else
			lenght += ft_putchar(*format);
		format++;
	}
	va_end(ptr);
	return (lenght);
}
