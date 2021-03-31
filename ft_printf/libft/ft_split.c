/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:08:35 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/11 23:11:01 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && !(*str == c))
		{
			count++;
			while (*str && !(*str == c))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !(str[i] == c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !(str[i] == c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s1, char c)
{
	char	*s;
	char	**new_s;
	int		i;

	if (!s1)
		return (NULL);
	s = (char *)s1;
	new_s = (char**)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && !(*s == c))
		{
			new_s[i] = malloc_word(s, c);
			i++;
			while (*s && !(*s == c))
				s++;
		}
	}
	new_s[i] = NULL;
	return (new_s);
}
