/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:04:47 by ceugenia          #+#    #+#             */
/*   Updated: 2020/11/08 20:09:42 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		degree_len(int n)
{
	int len;
	int degree;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	if (len == 1)
		return (1);
	if (len)
	{
		degree = 1;
		while (len && len != 1)
		{
			degree *= 10;
			len--;
		}
	}
	else
	{
		degree = 0;
	}
	return (degree);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		degree;

	if (!n)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n *= (-1);
	}
	degree = degree_len(n);
	while (degree)
	{
		ft_putchar_fd((n / degree) + '0', fd);
		n %= degree;
		degree /= 10;
	}
}
