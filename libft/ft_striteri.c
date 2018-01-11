/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:35:04 by acolas            #+#    #+#             */
/*   Updated: 2017/05/02 16:35:09 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		i;
	unsigned int		len;

	if (s)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			(*f)(i, (s + i));
			i++;
		}
	}
}
