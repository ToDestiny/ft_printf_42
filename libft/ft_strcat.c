/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:01:13 by acolas            #+#    #+#             */
/*   Updated: 2017/04/27 12:01:23 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = ft_strlen(dest);
	len = ft_strlen(src);
	while (len > 0)
	{
		dest[j] = src[i];
		i++;
		j++;
		len--;
	}
	dest[j] = '\0';
	return (dest);
}
