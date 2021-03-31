/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceugenia <ceugenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:59:02 by ceugenia          #+#    #+#             */
/*   Updated: 2021/01/23 18:53:54 by ceugenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_print
{
	int		minus;
	int		space;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	char	type;
	int		length;
	int		hard_pre;
}				t_print;

int				ft_printf(const char *format, ...);
t_print			*ft_parse(const char *fmt, int	position, va_list a);
int				ft_flags_parse(const char *fmt, int i, t_print *parse);
int				ft_width_parse(const char *fmt, int i,
								t_print *parse, va_list list);
int				ft_precision_parse(const char *fmt, int i,
									t_print *parse, va_list list);
int				ft_type_parse(const char *fmt, int i, t_print *parse);
int				ft_processor(t_print *parse, va_list list);
int				ft_type_char(t_print *parse, va_list list);
int				ft_type_string(t_print *parse, va_list list);
int				ft_print_fill(int fill, int len);
int				ft_type_decimal(t_print *parse, va_list list);
char			*ft_unsigned_itoa(long int nb);
int				ft_print_u_fill(int fill, int len);
int				ft_handler_u_decimal(t_print *parse, char *str, int fill);
void			ft_test_u_conditions(t_print *parse, int *fill,
										int str_len, char *str);
int				ft_type_unsigned(t_print *parse, va_list list);
int				ft_type_percent(t_print *parse);
char			*ft_itoa_base(unsigned long value, int base);
int				ft_putstr_x_fd(char *s, int fd);
int				ft_type_x(t_print *parse, va_list list);
int				ft_type_x_upper(t_print *parse, va_list list);
int				ft_type_pointer(t_print *parse, va_list list);

#endif
