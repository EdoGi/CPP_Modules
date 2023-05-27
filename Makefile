#####################################
##                                 ##
##  #############################  ##
##  ## MY GENERIC CPP MAKEFILE ##  ##
##  #############################  ##
##                                 ##
#####################################

NAME = prog

# SHELL=/bin/bash

#--------------------------------------------------------#
#                         COLORS                         #
#--------------------------------------------------------#

RED		:= "\033[1;31m"
GREEN	:= "\033[1;32m"
PURPLE	:= "\033[1;35m"
CYAN	:= "\033[1;36m"
GREY	:= "\033[1;37;40m"
EOC		:= "\033[0;0m"

#-------------------------------------------------------#
#                      DIRECTORIES                      #
#-------------------------------------------------------#

SRCS_DIR = srcs/
OBJS_DIR = objs/

#--------------------------------------------------------#
#                        COMMANDS                        #
#--------------------------------------------------------#

CXX = c++
MKDIR = mkdir -p
RM = rm -rf

#---------------------------------------------------------#
#                          FLAGS                          #
#---------------------------------------------------------#

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# LDFLAGS =
FSAN = -fsanitize=address -g3 -Wno-unused

#-------------------------------------------------------#
#                         FILES                         #
#-------------------------------------------------------#

# SRC_FILES := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
SRC_FILES = main.cpp 	\
PmergeMe.cpp		\
\

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(SRC_FILES:.cpp=.o))
DEPS := $(OBJS:.o=.d)

#--------------------------------------------------------#
#                        INCLUDES                        #
#--------------------------------------------------------# 

INC_DIRS =  incl/
INC_FLAGS := $(addprefix -I, $(INC_DIRS))
CXXFLAGS += $(INC_FLAGS) -MMD -MP

#-------------------------------------------------------#
#                        LIBRARY                        #
#-------------------------------------------------------#

LIB_NAME = 
LIB_DIR =  
LDFLAGS = -L$(LIB_DIR) -l$(LIB_NAME)

#-------------------------------------------------------#
#                         RULES                         #
#-------------------------------------------------------#

# default : help

.DELETE_ON_ERROR:
all : $(NAME) # Builds the executable file.
	
$(NAME) : $(OBJS) # Builds the executable file.
	@echo $(CYAN)"\n🔨 Compiling... 🔨\n"$(EOC)
	@sleep 0.2
	@echo $(RED)$(ASCII)$(EOC)
	@sleep 0.2
	@$(CXX) $(CXXFLAGS) $^ $(INC_FLAGS) -o $@
	@echo $(GREEN)"Compilation Succeed ✅"$(EOC)

${OBJS_DIR}%.o : ${SRCS_DIR}%.cpp
	@$(MKDIR) $(@D)
	@$(CXX) $(CXXFLAGS) $(INC_FLAGS) -o $@ -c $<

fsan : $(OBJS) # Builds the executable file.
	$(CXX) $(CXXFLAGS) $(FSAN) $(INC_FLAGS) $^ -o $(addprefix fsan_, $(NAME))
	
-include $(DEPS)

#--------------------------------------------------------#
#                     PHONY COMMANDS                     #
#--------------------------------------------------------#

help: # Show help for each of the Makefile recipes.
	@grep -E '^[a-zA-Z0-9 -]+:.*#'  Makefile | sort | while read -r l; do printf "\033[1;32m$$(echo $$l | cut -f 1 -d':')\033[00m:$$(echo $$l | cut -f 2- -d'#')\n"; done

clean : # Cleans all object files.
	@echo $(GREY)"\n🧹 Cleaning 🧹"$(EOC)
	@sleep 0.2
	@$(RM) $(OBJS)
	@echo $(PURPLE)"\n✨ Successfully cleaned ✨"$(EOC)

fclean : # Cleans all object files and removes the executable file.
	@echo $(GREY)"\n🧹 Cleaning Objects files and Executable 🧹"$(EOC)
	@sleep 0.2
	@$(RM) $(OBJS) $(OBJS_DIR) $(NAME) $(addprefix fsan_, $(NAME))
	@echo $(PURPLE)"\n✨ Successfully super cleaned ✨"$(EOC)

re : fclean all # Performs a clean build by removing all files and rebuilding the executable.

.PHONY : all clean fclean re fsan help

#---------------------------------------------------------#
#                        ASCII ART                        #
#---------------------------------------------------------#

CUBE = \
"        __________________________\n" \
"       / _____________________  /|\n" \
"      / / ___________________/ / |\n" \
"     / / /| |               / /  |\n" \
"    / / / | | Compiling    / / . |\n" \
"   / / /| | |    your     / / /| |\n" \
"  / / / | | |   project  / / / | |\n" \
" / / /  | | |           / / /| | |\n" \
"/ /_/___| | |__________/ / / | | |\n" \
"/_______| | |___________/ /  | | |\n" \
"| ______| | |__________ | |  | | |\n" \
"| | |   | | |_________| | |__| | |\n"  \
"| | |   | |___________| | |____| |\n" \
"| | |   / / __________| | |_  / /\n" \
"| | |  / / /          | | |/ / /\n" \
"| | | / / /   please  | | | / /\n" \
"| | |/ / /      wait  | | |/ /\n" \
"| | | / /        ...  | | ' /\n" \
"| | |/_/______________| |  /\n" \
"| |___________________| | /\n" \
"|_______________________|/\n"

ASCII = \
"     ____________________\n" \
"   /_________________    |\n" \
"  |    ____________ /|   |\n" \
"  |   | |__________|_|   |\n" \
"  |   |/_________________|\n" \
"  |_____________________/\n\n"