# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/24 13:05:14 by mlegeay           #+#    #+#              #
#    Updated: 2016/02/04 18:01:54 by pcarre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= *.c

NAME	= bsq

CFLAGS	= -Wall -Werror -Wextra

OBJ	= *.o

all:	$(NAME)

$(NAME):
		gcc -c $(SRC) $(CFLAGS)
			gcc $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME) map4

re:	fclean all
