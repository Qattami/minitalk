# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 18:10:57 by iqattami          #+#    #+#              #
#    Updated: 2024/03/15 13:57:28 by iqattami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c client.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

testing:
	cc server.c -o server
	cc client.c -o client 	
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all  