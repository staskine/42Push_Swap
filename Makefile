# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 14:51:07 by sataskin          #+#    #+#              #
#    Updated: 2024/03/29 10:55:18 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCE = 	main.c \
			error_handling.c \
			push_swap.c \
			push_utils.c \
			free_push_swap.c \
			checkers.c \
			sorting.c \
			sorting_functions.c \
			commands_a.c \
			commands_b.c \
			commands_both.c \
			radix.c
			
OBJECT = $(SOURCE:.c=.o)

LIBFT = libft/libft.a

HEADER = push_swap.h 

LIBFT_HEADER = libft/libft.h

all: makelibft $(NAME)

makelibft:
	@cd libft && make

%.o:%.c
	@cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

$(NAME): $(OBJECT)
	@cc -Wall -Wextra -Werror $(OBJECT) $(LIBFT) -o $(NAME)
	@echo push_swap made

clean:
	@make clean -C ./libft
	@rm -f $(OBJECT)
	@echo push_swap clean

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo push_swap fclean

re: fclean all

debug:
	@cc -Wall -Wextra -Werror -g3 -fsanitize=address $(OBJECT) $(LIBFT) -o $(NAME)
.PHONY: clean fclean all re makelibft