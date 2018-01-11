/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2017/12/10 21:14:40 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num_wchar_zero(t_print *list, size_t *ret)
{
	if (!ZERO(list->flag))
	{
		while ((list->width)--)
		{
			ft_putchar(' ');
			(*ret)++;
		}
	}
	else
		while ((list->width)--)
		{
			ft_putchar('0');
			(*ret)++;
		}
}

void	ft_print_null_char(t_print *list, size_t *ret)
{
	(*ret) += list->width;
	list->width--;
	while (list->width--)
		ft_putchar('0');
	ft_putchar('\0');
}
