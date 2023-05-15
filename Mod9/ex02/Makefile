# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giaco <giaco@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 14:30:58 by giaco             #+#    #+#              #
#    Updated: 2023/05/15 14:38:26 by giaco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################
#				PROGRAMS				#
#########################################
NAME = PmergeMe

#########################################
#				COMMANDS				#
#########################################
CXX = c++
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
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -MP
CXXFLAGS += -g3 -fsanitize=address -Wno-unused
IFLAGS := -I incl/

#########################################
#			FILES PATH					#
#########################################
INC_PATH = ./incl/PmergeMe.hpp

#########################################
#			SOURCES	FILES				#
#########################################
SRCS = 	main.cpp 		\
		PmergeMe.cpp	\
		\
	
SRC	= $(addprefix $(SRCS_DIR),$(SRCS))

#########################################
#            OBJECT FILES    	        #
#########################################
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

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
all:	${NAME}

# allows to include all dependencies files created
# in case 
-include $(DEPS) 

${OBJ_DIR}%.o : ${SRCS_DIR}%.cpp
	@$(MKDIR) $(@D)
	$(CXX) $(CXXFLAGS) $(IFLAGS) -o $@ -c $< 

$(NAME): $(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CXX) $(CXXFLAGS) $(OBJS) $(IFLAGS) -o $(NAME)  
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		@${RM} ${OBJ_DIR}

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re