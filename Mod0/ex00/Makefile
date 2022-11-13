# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 17:41:09 by giaco             #+#    #+#              #
#    Updated: 2022/11/13 00:15:32 by egiacomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = 	megaphone.cpp
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