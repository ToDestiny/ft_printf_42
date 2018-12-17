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

NAME = libprintf.a
SRC_DIR = ./src
SRC = ft_printf.c \
	ft_check_format.c \
	ft_get_arg.c \
	ft_get_format.c \
	ft_itoa_base.c \
	ft_print_arg.c \
	ft_print_wchar.c \
	ft_print_zero_arg.c \
	ft_ftoa.c \
	ft_get_float.c \

CC = gcc
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra -c -fsanitize=address -g
RM = rm -f
DIR_LIB	= libft
LIBFT	= $(DIR_LIB)/libft.a

all : $(NAME)

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) -c $(addprefix $(SRC_DIR)/,$(SRC))
	@ar -rc $(NAME) $(OBJ) ./libft/*.o

$(LIBFT):
	@make -C $(DIR_LIB)

clean:
	@make clean -C $(DIR_LIB)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(DIR_LIB) 
	@$(RM) $(NAME) $(HEADER)

re: fclean all

.PHONY : clean fclean re all
