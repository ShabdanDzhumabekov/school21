/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:16:38 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 17:33:15 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_x_fd(char *s, int fd)
{
	int len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			ft_putchar_fd(*s + 32, fd);
		else
			ft_putchar_fd(*s, fd);
		s++;
		len++;
	}
	return (len);
}

int		ft_handler_x(t_print *parse, char *str, int fill)
{
	int length;

	length = 0;
	if (!parse->minus)
		length += ft_print_u_fill(fill, parse->width);
	if (parse->precision > 0)
		length += ft_print_u_fill('0', parse->precision);
	if (parse->dot && !parse->precision && str[0] == '0' && !parse->hard_pre)
		length += ft_putstr_x_fd("", 1);
	else
		length += ft_putstr_x_fd(str, 1);
	if (parse->minus)
		length += ft_print_u_fill(fill, parse->width);
	return (length);
}

int		ft_type_x(t_print *parse, va_list list)
{
	int		len;
	int		str_len;
	char	*str;
	int		fill;
	long	num;

	num = va_arg(list, unsigned int);
	fill = ' ';
	str = ft_itoa_base(num, 16);
	str_len = (int)ft_strlen(str);
	if (parse->precision < 0)
	{
		parse->precision = 0;
		parse->dot = 0;
	}
	ft_test_u_conditions(parse, &fill, str_len, str);
	len = ft_handler_x(parse, str, fill);
	return (len);
}
