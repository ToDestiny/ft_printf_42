/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:46:07 by acolas            #+#    #+#             */
/*   Updated: 2018/12/17 19:42:30 by acolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <wchar.h>
# include <stdlib.h>

# define FLAG(fm) (fm == '#'|| fm == '0'|| fm == '-' || fm == '+' || fm == 32)
# define LDECIMAL(fm) (fm == 'd'|| fm == 'i')
# define DECIMAL(fm) (fm == 'd'|| fm == 'D' || fm == 'i'|| fm == 'f')
# define UDECIMAL(fm) (fm == 'u'|| fm == 'U')
# define FLOAT(fm) (fm == 'f')
# define UOCT(fm) (fm == 'o'|| fm == 'O')
# define UHEX(fm) (fm == 'x'|| fm == 'X')
# define USHORT(fm) (fm == 'o'|| fm == 'u'|| fm == 'x'|| fm == 'X')
# define ULONG(fm) (fm == 'U'|| fm == 'O')
# define UNSIGN(fm) (UDECIMAL(fm) || UOCT(fm) || UHEX(fm) || fm == 'p')
# define NUM(fm) (DECIMAL(fm) || UDECIMAL(fm) || UOCT(fm) || UHEX(fm))
# define STRING(fm) (fm == 's'|| fm == 'S')
# define SYMB(fm) (fm == 'c'|| fm == 'C')
# define CONVERSE(fm) (NUM(fm) || STRING(fm) || SYMB(fm) || fm == 'p')
# define SHARP(x) (x & 0x01)
# define ZERO(x) (x & 0x01 << 1)
# define MINUS(x) (x & 0x01 << 2)
# define PLUS(x) (x & 0x01 << 3)
# define SPACE(x) (x & 0x01 << 4)
# define ERROR -1
# define OK 1
# define END 0

typedef struct	s_print
{
	int		flag;
	size_t	width;
	size_t	precision;
	char	size;
	int		sign;
	char	*buf;
	char	*prefix;
	char	conversion;
	size_t	len_p;
	size_t	len_w;
	int		l;
	int		h;
	int		z;
	int		j;
	int		dot;
}				t_print;

int				ft_printf(const char *fm, ...);
size_t			ft_check_fm(va_list *args, const char *fm, size_t ret);
int				ft_if_percent(va_list *args, const char **fm,
		t_print **list, size_t *ret);
const char		*ft_get_format(t_print *list, const char *fm);
void			ft_get_flag(t_print *list, char fm);
t_print			*ft_new_list(t_print *list);
void			ft_get_size(t_print *list, char fm);
void			ft_check_size(t_print *list);
size_t			go_push_it(t_print *list, va_list *args, size_t ret);
void			ft_get_digit(t_print *list, va_list *args);
void			ft_print_arg(t_print *list, size_t *ret);
void			ft_print_num_zero(t_print *list, size_t *ret);
void			ft_get_unsigned(t_print *list, va_list *args);
void			ft_get_char(t_print *list, va_list *args);
void			ft_check_prefix(t_print *list);
void			ft_get_arg(t_print *list, va_list *args);
size_t			ft_print_left(t_print *list, size_t ret);
size_t			ft_print_right(t_print *list, size_t ret);
void			ft_print_right_post(t_print *list, size_t *ret);
void			ft_check_converse(t_print *list, const char **fm);
char			*ft_handle_wchar(wchar_t wchar);
char			*ft_push_wchar(wchar_t *wchar, t_print *list);
int				ft_wchar_len(wchar_t wchar);
char			*ft_push_char(t_print *list, char *s);
void			ft_get_string(t_print *list, va_list *args);
char			*ft_itoa_base(ssize_t value, size_t base);
void			f(size_t value, size_t base, char *str, size_t *i);
char			*ft_low(char *str);
void			ft_print_num_wchar_zero(t_print *list, size_t *ret);
void			ft_print_null_char(t_print *list, size_t *ret);
void			ft_print_right_pref(t_print *list, size_t *ret);
void			free_list(t_print **list);
void			ft_get_float(t_print *list, va_list *args);
char			*ft_ftoa(double d, int i);
int				ft_iterative_power(int n, int power);
char			*ft_itoa(int n);
char			*ft_strcat(char *dest, const char *src);
char			*float_output(char *val, int dot, int end, int i);
long			float_to_int(t_print *list, long double d, int prec);

#endif
