/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:23:38 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/20 18:25:37 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision_parse(const char *fmt, int i, t_print *parse, va_list list)
{
	int	length;

	length = 0;
	if (fmt[i] == '.')
	{
		length++;
		i++;
		parse->dot = 1;
		if (fmt[i] == '*')
		{
			parse->precision = va_arg(list, int);
			length++;
		}
		else
		{
			while (ft_isdigit(fmt[i]))
			{
				parse->precision *= 10;
				parse->precision += (int)(fmt[i] - '0');
				length++;
				i++;
			}
		}
	}
	return (length);
}
