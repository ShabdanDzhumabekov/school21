/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:16:06 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/20 15:20:16 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	c_d;
	size_t			i;

	ptr = (unsigned char*)b;
	c_d = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ptr[i] = c_d;
		i++;
	}
	return (b);
}
