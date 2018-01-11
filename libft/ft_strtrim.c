/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:24:07 by acolas            #+#    #+#             */
/*   Updated: 2017/04/29 17:24:09 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const			*end;
	char const			*beg;
	char				*dst;
	unsigned int		i;

	if (s)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		beg = (s + i);
		end = (s + i);
		while (s[i])
		{
			if (s[i] >= 33 && s[i] <= 126)
				end = s + i;
			i++;
		}
		if ((end - beg) > 0)
			end++;
		dst = ft_strsub(s, beg - s, end - beg);
		return (dst);
	}
	return (0);
}
