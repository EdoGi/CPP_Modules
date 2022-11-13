# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 01:01:51 by egiacomi          #+#    #+#              #
#    Updated: 2022/11/13 04:33:42 by egiacomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = la_bagarre

SRCS =	HumanA.cpp	\
		HumanB.cpp	\
		Weapon.cpp	\
		main.cpp	\
		\
		
OBJS = ${SRCS:.cpp=.o}

CC = c++
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++98

all : ${NAME}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o:%.cpp
	${CC} ${CFLAGS} -o $@ -c $<

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean re