/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:25 by acolas            #+#    #+#             */
/*   Updated: 2018/12/17 18:07:53 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnew(size_t size);
size_t		ft_strlen(const char *str);	

int			digit_int(long int num)
{
	int 	len;
	long	temp;

	len = 0;
	temp = 1;
	while (temp <= num)
	{
		len++;
		temp *= 10;
	}
	return len;
}

char		*float_output(char	*val, int dot, int end)
{	
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;;
	if (!dot)
	{
		tmp = ft_strnew(ft_strlen(val) + 3);
		tmp[j++] = '0';
		tmp[j++] = '.';
	}
	else
		tmp = ft_strnew(ft_strlen(val) + 1);
	while (val[i] != '\0')
	{
		tmp[j++] = val[i];
		if (i == dot - 1 && end > 0)
			tmp[j++] = '.';
		if (i >= end)
		{
			tmp[j] = '\0';
			break;
		}
		i++;
	}
	return (tmp);
}

long		float_to_int(t_print *list, long double d, int prec)
{
	int neg;
	int i;

	i = 0;
	neg = d < 0 ? -1 : 1;
	d *= neg;
	list->dot = digit_int((int)d);
	while (i < prec)
	{
		d *= 10;
		i++;
	}
	d += 0.5;
	d *= neg;
	return ((long int)d);
}

char		*ft_ftoa(t_print *list, double d)
{
	char		*val;
	long int	tmp;
	int			len;
	int			neg;
	int			i;

	i = list->precision;
	neg = d < 0 ? -1 : 1;
	len = d < 0 ? 1 : 0;
	d *= neg;
	tmp = (long int)d;
	while (tmp > 0 && len++ >= 0)
		tmp /= 10;	
	while (d - (long int)d != 0 && len++ >= 0 && i-- > 0)
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
