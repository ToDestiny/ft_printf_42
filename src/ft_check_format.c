/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2018/01/11 16:26:46 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_sign(t_print *list)
{
	if (list->sign == 1)
		*(list->prefix) = '-';
	else if (PLUS(list->flag))
		*(list->prefix) = '+';
	else if (SPACE(list->flag))
		*(list->prefix) = ' ';
}

void	ft_check_prefix(t_print *list)
{
	char *tmp;

	if (DECIMAL(list->conversion))
		ft_check_sign(list);
	else if (UOCT(list->conversion) && SHARP(list->flag) && *list->buf != '0')
		*(list->prefix) = '0';
	else if (UHEX(list->conversion) && SHARP(list->flag) && *list->buf != '0')
	{
		tmp = ft_strdup(list->prefix);
		free(list->prefix);
		list->prefix = (list->conversion == 'x') ?
			ft_strjoin(tmp, "0x") : ft_strjoin(tmp, "0X");
		free(tmp);
	}
	else if (list->conversion == 'p')
	{
		tmp = ft_strdup(list->prefix);
		free(list->prefix);
		list->prefix = ft_strjoin(tmp, "0x");
		free(tmp);
	}
	return ;
}

void	ft_check_size(t_print *list)
{
	if (list->z == 1)
		list->size = 'z';
	else if (list->j == 1)
		list->size = 'j';
	else if (list->l > 0)
	{
		if (((list->l) % 2) == 0)
			list->size = 'L';
		else
			list->size = 'l';
	}
	else if ((list->h) > 0)
	{
		if (((list->h) % 2) == 0)
			list->size = 'H';
		else
			list->size = 'h';
	}
}

t_print	*ft_new_list(t_print *list)
{
	if (!(list = (t_print*)ft_memalloc(sizeof(t_print))))
		return (NULL);
	list->prefix = ft_strnew(2);
	list->buf = NULL;
	return (list);
}
