/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kelk <sel-kelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:55:31 by sel-kelk          #+#    #+#             */
/*   Updated: 2026/11/05 12:13:18 by sel-kelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../ft_printf.h"

typedef struct s_flags
{
	int	left_pad;
	int	width;
	int	sign;
	int	hashtag;
	int	bzero;
	int	digits;
	int	right_pad;
	int	space;
	int dot;
} t_flags;


#endif
