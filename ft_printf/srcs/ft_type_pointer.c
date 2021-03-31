/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:16:38 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 18:25:47 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_minus_pointer(t_print *parse, char *str)
{
	int length;

	length = 0;
	while (parse->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		length++;
	}
	length += ft_putstr_fd("0x", 1);
	length += ft_putstr_x_fd(str, 1);
	return (length);
}

int		ft_type_pointer(t_print *parse, va_list list)
{
	int				length;
	char			*str;
	unsigned long	arg;

	length = 0;
	arg = (unsigned long)va_arg(list, void*);
	if (!arg && parse->dot && !parse->precision)
		str = ft_strdup("");
	else
		str = ft_itoa_base(arg, 16);
	parse->width = parse->width - (int)ft_strlen(str) - 2;
	if (!parse->minus)
	{
		length += ft_minus_pointer(parse, str);
		return (length);
	}
	length += ft_putstr_fd("0x", 1);
	length += ft_putstr_x_fd(str, 1);
	while (parse->width-- > 0)
	{
		ft_putchar_fd(' ', 1);
		length++;
	}
	return (length);
}
