/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:36:02 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/07 08:15:03 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_length;
	size_t	remaining_size;
	size_t	copy_length;

	s_length = ft_strlen(src);
	remaining_size = dstsize;
	while (*dst && remaining_size > 0)
	{
		dst++;
		remaining_size--;
	}
	if (remaining_size > 0)
	{
		copy_length = remaining_size - 1;
		if (s_length < copy_length)
			copy_length = s_length;
		ft_memcpy(dst, src, copy_length);
		dst[copy_length] = '\0';
	}
	return (dstsize - remaining_size + s_length);
}
