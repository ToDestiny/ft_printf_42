/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:43:44 by acolas            #+#    #+#             */
/*   Updated: 2017/05/05 17:43:46 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iterative_factorial(int n)
{
	int		i;
	int		res;

	i = 1;
	res = 1;
	if (n < 0 || n > 12)
	{
		i = 0;
		return (i);
	}
	else if (n == 0)
	{
		i = 1;
		return (i);
	}
	while (i <= n)
	{
		res = res * i;
		i++;
	}
	return (res);
}
