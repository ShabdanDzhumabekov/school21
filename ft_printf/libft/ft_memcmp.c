/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:57:20 by ceugenia          #+#    #+#             */
/*   Updated: 2020/10/31 16:29:19 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sd1;
	unsigned char	*sd2;
	size_t			i;

	sd1 = (unsigned char*)s1;
	sd2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*sd1 != *sd2)
			return (*sd1 - *sd2);
		sd1++;
		sd2++;
		i++;
	}
	return (0);
}
