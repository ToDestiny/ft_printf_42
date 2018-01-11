/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:22:38 by acolas            #+#    #+#             */
/*   Updated: 2017/04/29 17:22:40 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int		i;
	unsigned int		len;
	char				*dst;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		dst = (char *)malloc(len + 1);
		if (dst == 0)
			return (0);
		while (i < len)
		{
			dst[i] = (*f)(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
