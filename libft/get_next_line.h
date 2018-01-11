/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 14:31:21 by acolas            #+#    #+#             */
/*   Updated: 2017/09/05 15:42:01 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# define BUFF_SIZE 10
# include "libft.h"

# define ERROR -1
# define OK 1
# define END 0

typedef struct		s_type
{
	char			*content;
	int				rd;
	int				fd;
	struct s_type	*next;
}					t_type;

int					get_next_line(const int fd, char **line);

#endif
