/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:14:11 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/22 16:04:36 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_not_dot(char *str, int width)
{
	int		length;
	int		len;

	length = 0;
	len = ft_strlen(str);
	while (width-- > len)
	{
		ft_putchar_fd(' ', 1);
		length++;
	}
	length += ft_putstr_fd(str, 1);
	return (length);
}

int	ft_print_with_dot(char *str, int width, int precision)
{
	int		length;
	int		len;
	int		i;

	i = 0;
	length = 0;
	len = ft_strlen(str);
	while (width > precision || (precision > len && len < width))
	{
		ft_putchar_fd(' ', 1);
		length++;
		width--;
	}
	if (precision > len)
		length += ft_putstr_fd(str, 1);
	else
		while (precision-- > 0)
		{
			ft_putchar_fd(str[i], 1);
			length++;
			i++;
		}
	return (length);
}

int	ft_print_with_m_dot(char *str, int width, int precision)
{
	int		length;
	int		len;
	int		i;

	i = 0;
	length = 0;
	len = ft_strlen(str);
	if (precision > len)
		length += ft_putstr_fd(str, 1);
	else
		while (precision > 0)
		{
			ft_putchar_fd(str[i], 1);
			length++;
			width--;
			precision--;
			i++;
		}
	while (width > precision || (precision > len && len < width))
	{
		ft_putchar_fd(' ', 1);
		length++;
		width--;
	}
	return (length);
}

int	ft_print_not_m_dot(char *str, int width)
{
	int		length;
	int		len;

	length = 0;
	len = ft_strlen(str);
	length += ft_putstr_fd(str, 1);
	while (width-- > len)
	{
		ft_putchar_fd(' ', 1);
		length++;
	}
	return (length);
}

int	ft_type_string(t_print *parse, va_list list)
{
	int		length;
	char	*str;

	str = va_arg(list, char*);
	if (!str)
		str = ft_strdup("(null)");
	length = 0;
	if (parse->precision < 0)
		parse->dot = 0;
	if (!parse->minus)
	{
		if (!parse->dot)
			length += ft_print_not_dot(str, parse->width);
		else
			length += ft_print_with_dot(str, parse->width, parse->precision);
		return (length);
	}
	if (parse->dot)
		length += ft_print_with_m_dot(str, parse->width, parse->precision);
	else
		length += ft_print_not_m_dot(str, parse->width);
	return (length);
}
