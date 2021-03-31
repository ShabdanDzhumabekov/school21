/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:28:17 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/05 21:28:30 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		len;

	len = ft_strlen(src);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	return (ft_strcpy(new, (char *)src));
}
