/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:35:57 by acolas            #+#    #+#             */
/*   Updated: 2018/11/19 20:59:03 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_float(t_print *list, size_t *ret)
{
	printf("Test 2345\n");
	ft_putstr(list->buf);
	ret += ft_strlen(list->buf);
}

