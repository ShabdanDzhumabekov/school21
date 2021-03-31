/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:23:05 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 17:46:54 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		*new_struct(void)
{
	t_print *p;

	if (!(p = (t_print*)malloc(sizeof(t_print))))
		return (NULL);
	p->space = 0;
	p->zero = 0;
	p->length = 0;
	p->dot = 0;
	p->precision = 0;
	p->type = 0;
	p->width = 0;
	p->minus = 0;
	p->hard_pre = 0;
	return (p);
}

t_print		*ft_parse(const char *fmt, int position, va_list list)
{
	t_print *p;

	p = new_struct();
	if (!p)
		return (NULL);
	p->length = ft_flags_parse(fmt, position, p);
	p->length += ft_width_parse(fmt, p->length + position, p, list);
	p->length += ft_precision_parse(fmt, p->length + position, p, list);
	p->length += ft_type_parse(fmt, p->length + position, p);
	if (!p->type)
	{
		free(p);
		return (NULL);
	}
	return (p);
}
