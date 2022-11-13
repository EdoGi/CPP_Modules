# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 00:24:04 by giaco             #+#    #+#              #
#    Updated: 2022/11/13 00:15:28 by egiacomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = motorola

SRCS = 	PhoneBook.cpp	\
		Contact.cpp		\
		main.cpp		\
		\

INCLUDES =	PhoneBook.hpp	\
			Contact.hpp		\
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