/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:11:26 by ceugenia          #+#    #+#             */
/*   Updated: 2020/10/30 22:31:13 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_d;
	unsigned char	c_d;

	s_d = (unsigned char*)s;
	c_d = (unsigned char)c;
	while (n-- > 0)
	{
		if (*s_d == c_d)
			return (s_d);
		s_d++;
	}
	return (NULL);
}
