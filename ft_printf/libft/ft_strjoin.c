/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 08:49:39 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/08 18:04:39 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	len_new_string;

	if (!s1 || !s2)
		return (NULL);
	len_new_string = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = ft_calloc(len_new_string, 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, len_new_string);
	ft_strlcat(new_string, s2, len_new_string);
	return (new_string);
}
