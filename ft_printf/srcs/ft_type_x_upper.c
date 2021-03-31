/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:10:58 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 17:33:26 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_x_upper(t_print *parse, va_list list)
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
	len = ft_handler_u_decimal(parse, str, fill);
	return (len);
}
