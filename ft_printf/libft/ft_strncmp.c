/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:59:20 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/07 07:07:40 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *s1_ptr;
	unsigned char *s2_ptr;

	s1_ptr = (unsigned char*)s1;
	s2_ptr = (unsigned char*)s2;
	while (*s1_ptr && *s2_ptr && n > 0)
	{
		if (*s1_ptr != *s2_ptr)
		{
			return (*s1_ptr - *s2_ptr);
		}
		s1_ptr++;
		s2_ptr++;
		n--;
	}
	if ((*s1_ptr || *s2_ptr) && n > 0)
	{
		return (*s1_ptr - *s2_ptr);
	}
	return (0);
}
