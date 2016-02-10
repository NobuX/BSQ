# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/25 22:41:12 by pcarre            #+#    #+#              #
#    Updated: 2015/08/27 15:29:00 by hben-elh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc -Wall -Werror -Wextra -o bsq
SRC = main.c ft_list_bsq.c advanced_ft_bsq.c

all:
	$(GCC) $(SRC)

clean:
	rm -f bsq

fclean: clean 
	rm -f bsq_map.txt

re: fclean all
