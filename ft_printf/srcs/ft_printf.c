/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:47:16 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 18:47:28 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_proc(const char *fmt, va_list ap)
{
	t_print *p;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			p = ft_parse(fmt, i + 1, ap);
			if (!p)
				return (-1);
			count += ft_processor(p, ap);
			i += p->length;
			free(p);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, fmt);
	count = ft_parse_proc(fmt, ap);
	if (count == -1)
		return (-1);
	va_end(ap);
	return (count);
}
