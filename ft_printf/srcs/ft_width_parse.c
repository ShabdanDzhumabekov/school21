/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:48:08 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 17:46:38 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_width(const char *fmt, int i, t_print *parse)
{
	int length;

	length = 0;
	while (ft_isdigit(fmt[i]))
	{
		parse->width *= 10;
		parse->width += (int)(fmt[i] - '0');
		length++;
		i++;
	}
	return (length);
}

int	ft_width_parse(const char *fmt, int i, t_print *parse, va_list list)
{
	int	length;

	length = 0;
	if (fmt[i] == '*')
	{
		parse->width = va_arg(list, int);
		if (parse->width < 0)
		{
			parse->width *= -1;
			parse->minus = 1;
			parse->zero = 0;
		}
		else if (parse->width > 0 && parse->minus)
			parse->zero = 0;
		length++;
	}
	else
		length += ft_num_width(fmt, i, parse);
	return (length);
}
