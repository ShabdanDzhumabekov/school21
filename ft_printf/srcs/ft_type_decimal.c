/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:31:20 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 17:16:07 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_fill(int fill, int len)
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

int		ft_handler_decimal(t_print *parse, char *str, int is_neg, int fill)
{
	int length;

	length = 0;
	if (is_neg == 1 && fill == '0')
	{
		ft_putchar_fd('-', 1);
		length++;
	}
	if (!parse->minus)
		length += ft_print_fill(fill, parse->width);
	if (is_neg == 1 && fill != '0')
	{
		ft_putchar_fd('-', 1);
		length++;
	}
	if (parse->precision > 0)
		length += ft_print_fill('0', parse->precision);
	if (parse->dot && !parse->precision && str[0] == '0' && !parse->hard_pre)
		length += ft_putstr_fd("", 1);
	else
		length += ft_putstr_fd(str, 1);
	if (parse->minus)
		length += ft_print_fill(fill, parse->width);
	return (length);
}

void	ft_test_conditions(t_print *parse, int *fill, char *str, int is_neg)
{
	int str_len;

	str_len = (int)ft_strlen(str);
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
		parse->hard_pre = 1;
		parse->precision = 0;
	}
	else
		parse->precision = 0;
	if (parse->width > parse->precision + str_len + is_neg)
		parse->width = parse->width - parse->precision - is_neg - str_len;
	else if (!(str[0] == '0' && parse->precision == 0 && parse->dot
			&& !parse->hard_pre))
		parse->width = 0;
}

int		ft_type_decimal(t_print *parse, va_list list)
{
	int		len;
	int		str_len;
	char	*str;
	int		is_negative;
	int		fill;

	fill = ' ';
	is_negative = 0;
	str = ft_itoa(va_arg(list, int));
	if (str[0] == '-')
	{
		str = ft_strdup(str + 1);
		is_negative = 1;
	}
	str_len = (int)ft_strlen(str);
	if (parse->precision < 0)
	{
		parse->precision = 0;
		parse->dot = 0;
	}
	ft_test_conditions(parse, &fill, str, is_negative);
	len = ft_handler_decimal(parse, str, is_negative, fill);
	return (len);
}
