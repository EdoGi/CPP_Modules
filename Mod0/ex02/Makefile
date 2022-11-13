NAME		= Account

INCLUDES	=	Account.hpp	\

SRCS		=	test.cpp		\
				Account.cpp		\

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