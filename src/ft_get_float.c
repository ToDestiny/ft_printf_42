/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:18:51 by acolas            #+#    #+#             */
/*   Updated: 2018/12/17 15:50:43 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_get_float(t_print *list, va_list *args)
{
	double			digit;
	long double		num;
	char			*nb;

	digit = 0;
	if (FLOAT(list->conversion) && (list->size == 'l'))
		digit = va_arg(*args, long);
	else if (FLOAT(list->conversion) && (list->size == 'L'))
		digit = va_arg(*args, double);
	else
		digit = va_arg(*args, double);
	(digit < 0) ? list->sign = 1 : 0;
	digit = (digit < 0) ? (-digit) : digit;
	if (list->precision)
		num = float_to_int(list, digit, list->precision);
	else 
		num = float_to_int(list, digit, 6);
	nb = ft_ftoa(num);
	printf("dot : %d\n", list->dot);
	list->buf = float_output(list, nb, list->dot, ft_strlen(nb));
}
