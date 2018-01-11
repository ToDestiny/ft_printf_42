/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:24:08 by acolas            #+#    #+#             */
/*   Updated: 2017/12/10 21:11:42 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fm, ...)
{
	size_t	ret;
	va_list	args;

	ret = 0;
	va_start(args, fm);
	if (!*fm)
		return (END);
	ret = ft_check_fm(&args, fm, ret);
	va_end(args);
	if (ret > INT_MAX)
		return (ERROR);
	else
		return ((int)ret);
}

void	free_list(t_print **list)
{
	if ((*list)->buf != NULL)
		free((*list)->buf);
	if ((*list)->prefix != NULL)
		free((*list)->prefix);
	if ((*list) != NULL)
	{
		free((*list));
		(*list) = NULL;
	}
}

int		ft_if_percent(va_list *args, const char **fm,
		t_print **list, size_t *ret)
{
	if (*(*fm) == '\0')
		return (OK);
	else if (*(*fm) == '%')
	{
		write(1, "%", 1);
		(*ret)++;
	}
	else
	{
		*list = ft_new_list(*list);
		*fm = ft_get_format(*list, *fm);
		*ret = go_push_it(*list, args, *ret);
		free_list(list);
	}
	return (END);
}

size_t	ft_check_fm(va_list *args, const char *fm, size_t ret)
{
	t_print *list;

	list = NULL;
	while (*fm)
	{
		while (*fm && *fm != '%')
		{
			write(1, fm++, 1);
			ret++;
		}
		if (*fm && *fm++ == '%')
		{
			if (ft_if_percent(args, &fm, &list, &ret))
				return (ret);
		}
		if (*fm)
			fm++;
	}
	return (ret);
}

size_t	go_push_it(t_print *list, va_list *args, size_t ret)
{
	ft_get_arg(list, args);
	if (*(list->buf) == '0' && (UOCT(list->conversion))
		&& list->dot && !(list->precision) && SHARP(list->flag))
	{
		ft_putchar('0');
		ret++;
	}
	else if (STRING(list->conversion) && list->dot && !(list->precision)
		&& list->width)
		ft_print_num_wchar_zero(list, &ret);
	else if (*(list->buf) == '0' && SYMB(list->conversion)
		&& list->dot && list->width && ZERO(list->flag) && !MINUS(list->flag))
		ft_print_null_char(list, &ret);
	else if (*(list->buf) == '0' && NUM(list->conversion)
		&& list->dot && !(list->precision) && list->width)
		ft_print_num_wchar_zero(list, &ret);
	else if (*(list->buf) == '0' && (NUM(list->conversion))
		&& list->dot && !(list->precision) && !list->width)
		;
	else
		ft_print_arg(list, &ret);
	return (ret);
}
