/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:32:00 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/20 15:32:47 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_parse(const char *fmt, int i, t_print *parse)
{
	int length;

	length = 0;
	if (ft_strchr("cspdiuxX%", fmt[i]))
	{
		parse->type = fmt[i];
		length++;
	}
	return (length);
}
