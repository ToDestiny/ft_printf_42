/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:33:20 by acolas            #+#    #+#             */
/*   Updated: 2017/04/26 16:03:15 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		len1;
	int		len2;

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
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
	}
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
