# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giaco <giaco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 21:48:12 by giaco             #+#    #+#              #
#    Updated: 2022/11/27 04:14:08 by giaco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 01:46:37 by egiacomi          #+#    #+#              #
#    Updated: 2022/11/23 02:17:11 by egiacomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################
#				PROGRAMS				#
#########################################
NAME = Cats_Dogs

#########################################
#				COMMANDS				#
#########################################
CC = c++
MKDIR =	mkdir -p
RM = rm -rf

#########################################
#			DIRECTORIES					#
#########################################
SRCS_DIR = srcs/
OBJ_DIR = objs/

#########################################
#			FLAGS COMPILATION			#
#########################################
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++98
# CFLAGS += -fsanitize=address  -Wno-unused
IFLAGS := -I incl/

#########################################
#			FILES PATH					#
#########################################
INC_PATH =	./incl/Animal.hpp		\
			./incl/Dog.hpp			\
			./incl/Cat.hpp			\
			.incl/WrongCat.cpp		\
			.incl/WrongAnimal.cpp	\
			\
			
#########################################
#			SOURCES	FILES				#
#########################################
SRCS = 	Animal.cpp 		\
		Dog.cpp			\
		Cat.cpp			\
		main.cpp		\
		WrongCat.cpp	\
		WrongAnimal.cpp	\
		\

SRC	= $(addprefix $(SRCS_DIR),$(SRCS))

#########################################
#            OBJECT FILES    	        #
#########################################
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

#########################################
#				COLORS					#
#########################################
RED		:="\033[1;31m"
GREEN	:="\033[1;32m"
PURPLE	:="\033[1;35m"
CYAN	:="\033[1;36m"
EOC		:="\033[0;0m"

#########################################
#				RULES					#
#########################################
all : ${NAME}

${OBJ_DIR}%.o : ${SRCS_DIR}%.cpp
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $< 
	
$(NAME) : $(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME)  
	@echo $(GREEN) "[OK COMPILED]" $(EOC) "- $(NAME) created"

clean :
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	@${RM} ${OBJS}
	@${RM} ${OBJ_DIR}
	
fclean : clean
	@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
	@${RM} ${NAME}

re : fclean all

.PHONY : clean fclean re
