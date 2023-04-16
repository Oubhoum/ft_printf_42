/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:36:42 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/27 04:55:19 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar(char c);
size_t	ft_putnbr(int nb);
size_t	ft_putstr(char *str);
size_t	ft_put_unsigned_int(unsigned int nb);
size_t	ft_dec_hex_low(unsigned int nb);
size_t	ft_dec_hex_up(unsigned int nb);
size_t	ft_print_ptr(unsigned long long nb);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif