/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:58:23 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 17:31:09 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_u_fill(int fill, int len)
{
	int length;

	length = 0;
	while (len-- > 0)
	{
		ft_putchar_fd(fill, 1);
		length++;
	}
	return (length);
}

int		ft_handler_u_decimal(t_print *parse, char *str, int fill)
{
	int length;

	length = 0;
	if (!parse->minus)
		length += ft_print_u_fill(fill, parse->width);
	if (parse->precision > 0)
		length += ft_print_u_fill('0', parse->precision);
	if (parse->dot && !parse->precision && str[0] == '0' && !parse->hard_pre)
		length += ft_putstr_fd("", 1);
	else
		length += ft_putstr_fd(str, 1);
	if (parse->minus)
		length += ft_print_u_fill(fill, parse->width);
	return (length);
}

void	ft_test_u_conditions(t_print *parse, int *fill, int str_len, char *str)
{
	if (parse->zero)
		*fill = '0';
	if (parse->dot && parse->precision >= 0)
		*fill = ' ';
	if (parse->dot && parse->precision == 0 && str[0] == '0')
		str_len = 0;
	if (parse->precision > str_len)
		parse->precision = parse->precision - str_len;
	else if (str[0] == '0' && parse->precision == 1)
	{
		parse->precision = 0;
		parse->hard_pre = 1;
	}
	else
		parse->precision = 0;
	if (parse->width > parse->precision + str_len)
		parse->width = parse->width - parse->precision - str_len;
	else if (!(str[0] == '0' && parse->precision == 0 && parse->dot
			&& !parse->hard_pre))
		parse->width = 0;
}

int		ft_type_unsigned(t_print *parse, va_list list)
{
	int		len;
	int		str_len;
	char	*str;
	int		fill;
	long	num;

	num = va_arg(list, unsigned int);
	fill = ' ';
	str = ft_unsigned_itoa(num);
	str_len = (int)ft_strlen(str);
	if (parse->precision < 0)
	{
		parse->precision = 0;
		parse->dot = 0;
	}
	ft_test_u_conditions(parse, &fill, str_len, str);
	len = ft_handler_u_decimal(parse, str, fill);
	return (len);
}
