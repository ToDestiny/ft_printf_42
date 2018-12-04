/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:25 by acolas            #+#    #+#             */
/*   Updated: 2018/12/04 16:42:27 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

static int	ft_count_n(int n)
{
	int		count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_ftoa(double d)
{
	char		*val;
	long int	tmp;
	int			len;
	int			neg;

	neg = d < 0 ? -1 : 1;
	len = d < 0 ? 1 : 0;
	d *= neg;
	tmp = (long int)d;
	while (tmp > 0 && len++ >= 0)
		tmp /= 10;
	while (d - (long int)d != 0 && len++ >= 0)
		d *= 10;
	val = ft_strnew(len);
	while (--len >= 0)
	{
		val[len] = (long int)d % 10 + '0';
		d /= 10;
		if (neg == -1 && len == 1)
		{
			val[0] = '-';
			break;
		}
	}
	return (val);
}
