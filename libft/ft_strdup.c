/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:43:26 by acolas            #+#    #+#             */
/*   Updated: 2017/04/26 16:11:25 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc(sizeof(*dest) * len + 1);
	if (dest == 0)
		return (0);
	while (len > 0)
	{
		dest[i] = str[i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
