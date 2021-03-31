/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:18:01 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/08 19:35:43 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		ind;

	if (!s || !f)
		return (NULL);
	new_s = ft_calloc(ft_strlen(s) + 1, sizeof(*s));
	if (!new_s)
		return (NULL);
	ind = 0;
	while (s[ind])
	{
		new_s[ind] = f(ind, s[ind]);
		ind++;
	}
	new_s[ind] = '\0';
	return (new_s);
}
