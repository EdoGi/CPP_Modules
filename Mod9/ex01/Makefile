# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 21:48:12 by giaco             #+#    #+#              #
#    Updated: 2023/04/29 04:40:41 by egiacomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################
#				PROGRAMS				#
#########################################
NAME = RPN

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
CFLAGS = -Wall -Wextra -Werror -std=c++98 -c -MMD -MP
# CFLAGS += -fsanitize=address  -Wno-unused
# -L/usr/lib/x86_64-linux-gnu/ -lasan -> Add this end of line : `@$(CC) $^ -o $@`
IFLAGS := -I include/

#########################################
#			FILES PATH					#
#########################################
# INC_PATH = ./include/BitcoinExchange.hpp
			
#########################################
#			SOURCES	FILES				#
#########################################
SRCS =	main.cpp			\
		RPN.cpp \
		\

SRC	= $(addprefix $(SRCS_DIR),$(SRCS))

#########################################
#            OBJECT FILES    	        #
#########################################
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS = ${OBJS:.o=.d}

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

-include ${DEPS}

${OBJ_DIR}%.o : ${SRCS_DIR}%.cpp
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $< 
	
$(NAME) : $(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $^ -o $@
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
