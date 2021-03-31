/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:04:13 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 18:50:16 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static int		ft_numlen(unsigned long a, int base)
{
	int			i;

	i = 0;
	while (a)
	{
		a /= base;
		i += 1;
	}
	return (i);
}

char			*ft_itoa_base(unsigned long value, int base)
{
	int				size;
	long			nbr;
	char			*result;
	char			*ref_base;

	nbr = value;
	ref_base = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_numlen(nbr, base);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = (value < 0 ? '-' : '0');
	if (value < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}
