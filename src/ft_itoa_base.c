/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2017/12/10 21:23:11 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f(size_t value, size_t base, char *str, size_t *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value >= base)
		f(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

char	*ft_itoa_base(ssize_t value, size_t base)
{
	size_t	i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (END);
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}

char	*ft_low(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str[i++] |= ' ';
	return (str);
}
