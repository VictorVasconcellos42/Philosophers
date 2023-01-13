# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 12:46:22 by vde-vasc          #+#    #+#              #
#    Updated: 2023/01/13 18:54:26 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRC	=	src/philosophers.c src/validate.c src/error.c

OBJ	=	${SRC:.c=.o}

CC	=	cc

CFLAGS	=	-g -Wall -Wextra -Werror -pthread

############# COLOR ##################

GREEN	=	\033[0;32m

RED	=	\033[0;31m

BLUE	=	\033[0;34m

END	=	\033[0m

#####################################

all:	$(NAME) ${OBJ}

.c.o:
	@${CC} ${CFLAGS} $< -c -o $@
	@echo "${BLUE}OBJECTS CREATED!!!${END}"

$(NAME): ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o $(NAME)
	@echo "${GREEN}Let's go, philosophers!!${END}"

clean:
	@rm -rf ${OBJ}
	@echo "${RED}Cleaning....!!${END}"

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

