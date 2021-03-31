/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:47:02 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/21 16:54:16 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_percent(t_print *parse)
{
	int	width;
	int	length;
	int	fill;

	length = 0;
	fill = ' ';
	if (parse->zero && !parse->minus)
		fill = '0';
	width = parse->width;
	if (!parse->minus)
	{
		while (width-- > 1)
		{
			ft_putchar_fd(fill, 1);
			length++;
		}
		ft_putchar_fd(parse->type, 1);
		length++;
		return (length);
	}
	ft_putchar_fd(parse->type, 1);
	length++;
	length += ft_print_fill(fill, width - 1);
	return (length);
}
