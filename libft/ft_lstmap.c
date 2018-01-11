/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <acolas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 19:59:44 by acolas            #+#    #+#             */
/*   Updated: 2017/05/06 19:59:46 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*first;
	t_list		*new;
	t_list		*current;

	first = NULL;
	while (lst)
	{
		new = f(lst);
		if (!first)
		{
			first = new;
			current = first;
		}
		else
		{
			current->next = new;
			current = current->next;
		}
		lst = lst->next;
	}
	return (first);
}
