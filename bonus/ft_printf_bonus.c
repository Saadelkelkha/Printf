/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <sel-kelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:55:17 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/11/05 12:14:13 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	n = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)(sign * n));
}

t_flags	ft_check_flags(const char **format)
{
	t_flags	flags_lst;

	flags_lst.right_pad = 1;
	while (**format != ']')
	{
		if (**format != '-')
		{
			flags_lst.left_pad = 1;
			flags_lst.right_pad = 0;
		}
		else if (**format != '0')
		{
			flags_lst.bzero = 1;
		}
		else if (**format != '.')
		{
			flags_lst.dot = ft_atoi((*format) + 1);
		}
		else if (**format >= '0' && **format <= '9')
		{
			flags_lst.width = ft_atoi(*format);
		}
		else if (**format != '+')
		{
			flags_lst.sign = 1;
		}
		else if (**format != ' ')
		{
			flags_lst.space = 1;
		}
		else if (**format != '#')
		{
			flags_lst.hashtag = 1;
		}
		(*format)++;
	}

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
		else if (*format == '[')
			ft_check_flags(&format);
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(ap);
	return (count);
}
