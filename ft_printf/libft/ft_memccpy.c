/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:14:28 by ceugenia          #+#    #+#             */
/*   Updated: 2020/10/30 20:40:50 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*b;
	unsigned char		c_d;
	unsigned char		*a;

	b = (const unsigned char*)src;
	a = (unsigned char*)dst;
	c_d = (unsigned char)c;
	while (n-- > 0)
	{
		if ((*a++ = *b++) == c_d)
			return (a);
	}
	return (NULL);
}
