/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:25 by acolas            #+#    #+#             */
/*   Updated: 2018/11/20 18:33:48 by acolas           ###   ########.fr       */
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

char		*ft_dtoa(double n)
{
	size_t ipart;
	float fpart;
	char *str;
	char *str2;
	int i;

	i = 0;
	ipart = 0;
	ipart = (int)n;
	i = ft_count_n(n);
	fpart = n - (double)ipart;
	str = ft_itoa(ipart);
 	str[i] = '.';
	fpart = fpart * ft_iterative_power(10, 6);
	str2 = ft_itoa(fpart);
	str = ft_strcat(str, str2);

	printf("str = %s", str);
	return (str);
}
