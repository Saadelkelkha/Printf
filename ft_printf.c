/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:23:33 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/11/04 10:23:44 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	c_ptr;

	c_ptr = (unsigned long) ptr;
	if (c_ptr == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_putnbrhex(c_ptr, "0123456789abcdef", count);
}

void	ft_puthex(unsigned int nb, int *count)
{
	ft_putnbrhex(nb, "0123456789abcdef", count);
}

void	ft_puthex_upper(unsigned int nb, int *count)
{
	ft_putnbrhex(nb, "0123456789ABCDEF", count);
}

void	ft_check_print(const char format, va_list *ap, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(*ap, int), count);
	else if (format == 's')
		ft_putstr(va_arg(*ap, char *), count);
	else if (format == 'p')
		ft_putptr(va_arg(*ap, void *), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr((long) va_arg(*ap, int), count);
	else if (format == 'u')
		ft_putnbr((long) va_arg(*ap, unsigned int), count);
	else if (format == 'x')
		ft_puthex(va_arg(*ap, unsigned int), count);
	else if (format == 'X')
		ft_puthex_upper(va_arg(*ap, unsigned int), count);
	else if (format == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				va_end(ap);
				return (count);
			}
			ft_check_print(*format, &ap, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(ap);
	return (count);
}
