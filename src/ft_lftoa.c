/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:25 by acolas            #+#    #+#             */
/*   Updated: 2018/12/17 12:16:34 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

char		*ft_strnew(size_t size);
size_t		ft_strlen(const char *str);	

char		*float_output(char	*val, int dot, int end)
{	
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
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

long		float_to_int(long double d, int prec)
{
	int neg;
	int i;

	i = 0;
	neg = d < 0 ? -1 : 1;
	d *= neg;
	while (i < prec)
	{
		d *= 10;
		i++;
	}
	d += 0.5;
	d *= neg;
	list->dot = i;
	return ((long int)d);
}

char		*ft_ftoa(long double d)
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
