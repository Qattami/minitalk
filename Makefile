# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 18:10:57 by iqattami          #+#    #+#              #
#    Updated: 2024/03/20 07:00:42 by iqattami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = client.c server.c utils.c

BONUS = client_bonus.c server_bonus.c utils.c


OBJ = $(SRCS:.c=.o)
OBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBONUS): $(BONUS)
	${CC} ${CFLAGS} -c ${BONUS}
		ar rc $(NAME) $(OBONUS)

bonus: $(OBONUS)
	

clean:
	rm -f $(OBJ) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all