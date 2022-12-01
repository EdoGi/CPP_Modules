# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giaco <giaco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 21:48:12 by giaco             #+#    #+#              #
#    Updated: 2022/11/29 01:37:03 by giaco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################
#				PROGRAMS				#
#########################################
NAME = Bureaucrat00

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
CFLAGS = -Wall -Wextra -Werror -std=c++98
# CFLAGS += -fsanitize=address  -Wno-unused
IFLAGS := -I incl/

#########################################
#			FILES PATH					#
#########################################
INC_PATH =	./incl/Bureaucrat.hpp		\
			\
			
#########################################
#			SOURCES	FILES				#
#########################################
SRCS = 	Bureaucrat.cpp 		\
		main.cpp		\
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
