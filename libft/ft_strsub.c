/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:44:25 by acolas            #+#    #+#             */
/*   Updated: 2017/05/02 17:44:27 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*dst;

	if (s)
	{
		i = 0;
		dst = (char *)malloc(len + 1);
		if (dst == 0)
			return (NULL);
		while (i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
