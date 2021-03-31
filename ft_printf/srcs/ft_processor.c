/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:47:25 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/21 18:53:43 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_processor(t_print *parse, va_list list)
{
	int		length;

	length = 0;
	if (parse->type == 'c')
		length += ft_type_char(parse, list);
	else if (parse->type == 's')
		length += ft_type_string(parse, list);
	else if (parse->type == 'd' || parse->type == 'i')
		length += ft_type_decimal(parse, list);
	else if (parse->type == 'u')
		length += ft_type_unsigned(parse, list);
	else if (parse->type == '%')
		length += ft_type_percent(parse);
	else if (parse->type == 'x')
		length += ft_type_x(parse, list);
	else if (parse->type == 'X')
		length += ft_type_x_upper(parse, list);
	else if (parse->type == 'p')
		length += ft_type_pointer(parse, list);
	return (length);
}
