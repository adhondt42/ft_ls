# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adhondt <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 17:52:09 by adhondt           #+#    #+#              #
#    Updated: 2018/04/23 17:53:55 by adhondt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIB = libft/libft.a

SRC = initialize_data.c ltools.c ltoolsii.c ft_ls.c print_tools.c side_tools.c \
	  sort.c llisting.c \

all : $(NAME)

$(NAME) :
	make -C libft all
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

clean :
	make -C libft clean

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
