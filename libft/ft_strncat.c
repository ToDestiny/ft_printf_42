/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:12:42 by acolas            #+#    #+#             */
/*   Updated: 2017/04/27 12:12:43 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		j;
	int			len;

	i = 0;
	j = ft_strlen(dest);
	len = ft_strlen(src);
	while (len > 0 && i < n)
	{
		dest[j] = src[i];
		i++;
		j++;
		len--;
	}
	dest[j] = '\0';
	return (dest);
}
