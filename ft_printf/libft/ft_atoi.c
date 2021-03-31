/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:23:51 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/05 20:21:08 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char a)
{
	if (a == ' ' || a == '\t' || a == '\n' || a == '\v' ||
			a == '\r' || a == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				is_negative;
	unsigned int	result;

	is_negative = 0;
	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		is_negative++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (int)(*str) - 48;
		if (result > 2147483648 && result != 2147483648)
			return (((is_negative % 2) != 0) ? 0 : -1);
		else if (result == 2147483648 && (is_negative % 2) == 0)
			return (0);
		str++;
	}
	if (is_negative % 2 != 0)
		return (-1 * result);
	return (result);
}
