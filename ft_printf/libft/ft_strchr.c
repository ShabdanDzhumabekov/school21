/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:11:05 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/05 20:32:47 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_d;
	char			*s_d;

	s_d = (char*)s;
	c_d = (unsigned char)c;
	while (*s_d)
	{
		if (*s_d == c_d)
			return (s_d);
		s_d++;
	}
	if (*s_d == c_d)
		return (s_d);
	return (NULL);
}
