/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsome.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <sel-kelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:51:31 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/11/02 17:03:47 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr(long nb, int *count)
{
	long	n;
	char	*s;

	n = nb;
	s = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		(*count)++;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		n = n % 10;
	}
	(*count)++;
	write(1, &s[n], 1);
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*count)++;
	}
}

void	ft_putnbrhex(unsigned long nb, char *s, int *count)
{
	if (nb >= 16)
	{
		ft_putnbrhex(nb / 16, s, count);
		nb = nb % 16;
	}
	(*count)++;
	write(1, &s[nb], 1);
}
