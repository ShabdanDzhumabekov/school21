/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:20:48 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/04 15:22:05 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_d;
	char	*found;
	char	c_d;

	s_d = (char*)s;
	c_d = (unsigned char)c;
	found = NULL;
	if (c_d == '\0')
		return (ft_strchr(s, '\0'));
	while ((s_d = ft_strchr(s, c)) != NULL)
	{
		found = s_d;
		s = s_d + 1;
	}
	return (char*)found;
}
