/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:53:16 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/20 15:32:33 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_char(t_print *parse, va_list list)
{
	int	width;
	int	length;

	length = 0;
	width = parse->width;
	if (!parse->minus)
	{
		while (width-- > 1)
		{
			ft_putchar_fd(' ', 1);
			length++;
		}
		ft_putchar_fd(va_arg(list, int), 1);
		length++;
		return (length);
	}
	ft_putchar_fd(va_arg(list, int), 1);
	length++;
	while (width-- > 1)
	{
		ft_putchar_fd(' ', 1);
		length++;
	}
	return (length);
}
