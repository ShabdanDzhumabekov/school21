/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:55 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/21 16:43:58 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_parse(const char *fmt, int i, t_print *parse)
{
	int	length;

	length = 0;
	while (fmt[i] == '-' || fmt[i] == ' ' || fmt[i] == '0')
	{
		if (fmt[i] == ' ')
			parse->space = 1;
		else if (fmt[i] == '-')
			parse->minus = 1;
		else if (fmt[i] == '0')
			parse->zero = 1;
		i++;
		length++;
	}
	return (length);
}
