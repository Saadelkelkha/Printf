/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:24:54 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/11/04 10:24:59 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_puthex_upper(unsigned int nb, int *count);
void	ft_puthex(unsigned int nb, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putnbrhex(unsigned long nb, char *s, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(long nb, int *count);
void	ft_putchar(char c, int *count);

#endif
