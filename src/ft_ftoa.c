/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:25 by acolas            #+#    #+#             */
/*   Updated: 2018/11/19 18:58:34 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

char	*ft_ftoa(float n, int precision)
{
	int i;
	int ipart;
	float fpart;
	char res[1000];

	if (precision == 0)
		precision = 6;
	ipart = (int)n;
	fpart = n - (float)ipart;
	i = ft_itoa_base(ipart, res, 0);
	if (precision != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_iterative_power(10, precision);

		ft_itoa_base((int)fpart, res + i + 1, precision);
	}
	return (res[]);
}
