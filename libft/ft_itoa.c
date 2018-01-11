/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:24:31 by acolas            #+#    #+#             */
/*   Updated: 2017/05/04 17:40:00 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ft_itoa(int n)
{
	int				num;
	char			*str;
	int				count;

	num = n;
	count = ft_count_n(n);
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		str[count - 1] = -(num % 10) + '0';
		num = -(num / 10);
		count--;
	}
	while (num > 0)
	{
		str[count - 1] = (num % 10) + '0';
		num = num / 10;
		count--;
	}
	return (str);
}
