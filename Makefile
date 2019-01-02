# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 14:42:35 by acolas            #+#    #+#              #
#    Updated: 2018/12/17 14:19:04 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = src

DIR_O = obj

HEADER = includes

SOURCES = ft_printf.c \
	ft_check_format.c \
	ft_get_arg.c \
	ft_get_format.c \
	ft_itoa_base.c \
	ft_print_arg.c \
	ft_print_wchar.c \
	ft_print_zero_arg.c \
	ft_ftoa.c \
	ft_get_float.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY : clean fclean re all
