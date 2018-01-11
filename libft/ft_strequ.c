/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:04:08 by acolas            #+#    #+#             */
/*   Updated: 2017/05/02 17:04:10 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;

	if (s1 && s2)
	{
		i = 0;
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		while (len1 > 0 || len2 > 0)
		{
			if (s1[i] == s2[i])
			{
				i++;
				len1--;
				len2--;
			}
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
