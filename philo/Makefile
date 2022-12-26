# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 12:46:22 by vde-vasc          #+#    #+#              #
#    Updated: 2022/12/26 13:00:00 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRC	=	src/philosophers.c

OBJ	=	${SRC:.c=.o}

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

############# COLOR ##################
GREEN	=	\033[0;32m

RED	=	\033[0;31m

BLUE	=	\033[0;34m

END	=	\033[0m

#####################################

.c.o:
	${CC} ${CFLAGS} $< -o $@

all:	$(NAME)

$(NAME): ${OBJ}
	echo "${RED} Let's go, philosophers!!${END}"
	${CC} ${CFLAGS} ${OBJ} -o $(NAME)

clean:
	rm -rf *.o

fclean:	clean
	rm -rf $(NAME)

re: fclean all

