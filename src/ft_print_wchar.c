/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2017/12/10 21:16:27 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_push_char(t_print *list, char *s)
{
	char	*str;
	char	*tmp;
	char	*tmp_ptr;
	size_t	len;

	tmp = NULL;
	len = ((list->precision < ft_strlen(s)) && list->dot) ?
		list->precision : ft_strlen(s);
	tmp = ft_strnew(len);
	tmp_ptr = tmp;
	str = NULL;
	while (len-- && *s)
		*tmp_ptr++ = *s++;
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

char	*ft_push_wchar(wchar_t *wchar, t_print *list)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	size_t	len;

	len = 0;
	str = ft_strnew(0);
	while (*wchar)
	{
		len += ft_wchar_len(*wchar);
		if (list->precision >= len || !list->precision)
		{
			tmp = ft_strdup(str);
			tmp2 = ft_handle_wchar(*wchar);
			free(str);
			str = ft_strjoin(tmp, tmp2);
			free(tmp);
			free(tmp2);
		}
		else
			break ;
		wchar++;
	}
	return (str);
}

int		ft_wchar_len(wchar_t wchar)
{
	if (wchar <= 0x007F)
		return (1);
	else if (wchar <= 0x07FF)
		return (2);
	else if (wchar <= 0x0FFFF)
		return (3);
	else if (wchar <= 0x10FFFF)
		return (4);
	return (END);
}

char	*ft_handle_wchar(wchar_t wchar)
{
	char	*str;
	int		len;

	len = ft_wchar_len(wchar);
	str = ft_strnew(len);
	if (len == 1)
		str[0] = wchar;
	else
		str[0] = (wchar >> (6 * (len - 1))) | (240 << (4 - len));
	while (--len)
	{
		str[len] = (wchar & 63) | 128;
		wchar >>= 6;
	}
	return (str);
}
