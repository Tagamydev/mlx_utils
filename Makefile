# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2024/08/11 12:52:26 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libmlx_utils.a
COMMIT_D	:= $(shell date)
COMMIT_U	:= ${USER}

# SUBMODULE CHECKLIST
#	[] includes
#	[] libraries
#	[] all
#	[] fclean
#	[] clean

#=============================== INCLUDES ===============================#

# LOCAL INCLUDES
INC			= -I./includes/
# SUBMODULES INCLUDES
INC			+= -I./T-Engine/
INC			+= -I./T-Engine/includes/
INC			+= -I./T-Engine/ft_math/
INC			+= -I./T-Engine/ft_math/includes/
INC			+= -I./libft/
# MLX INCLUDES
INC			+= -I/usr/include -O3 -I./minilibx-linux/ 

#============================== LIBRARIES ===============================#

# SUBMODULES .a LIBRARIES
SUBMODLIB	= ./libft/libft.a
SUBMODLIB	+= ./T-Engine/libT_Engine.a

#================================= GCC ==================================#

# GCC WITH LIBS AND INCLUDES
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc $(CFLAGS) $(INC)

# SRCS
SRCS		= \
		./putPixel.c \
		./openImg.c \
		./freeImg.c

O_DIR		= ./objects/
OBJS		= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -g -c $< -o $(O_DIR)/$(<:.c=.o)
	@echo ""

all: title submodules $(NAME)
	@echo "===================================="
	@echo "Add the libmlx_utils.a to your Makefile,"
	@echo " and the mlx_utils.h header to your includes..."

$(NAME): .mandatory
	@echo "mlx_utils compilation done..."

title:
	@echo "===================================="
	@echo "				mlx_utils"
	@echo "===================================="
	@echo "made by: samusanc aka Tagamydev"
	@echo "Github: https://github.com/Tagamydev/mlx_utils"
	@echo ""

#============================= SUBMODULES =============================#

submodules: .submodule-init .make_submodules
	@echo "All submodules loaded..."

.submodule-init:
	@git submodule update --init --recursive
	@git submodule update --recursive --remote
	@touch .submodule-init

.make_submodules: 
	@make -sC ./T-Engine/ all
	@make -sC ./libft/ all
	@touch .make_submodules

#============================= GIT RULES ==============================#

add: fclean .submodule-init
	@-git pull
	@git add .

commit: add
	@echo "" >> .TODO
	@cp .TODO .TODO.tmp
	sed -i '1s/^/$(COMMIT_D) by $(COMMIT_U)\n/' .TODO.tmp
	echo "======================= end of git description" >> .TODO.tmp
	git commit -F .TODO.tmp 
	@rm -rf .TODO.tmp

push: commit
	git push

#======================= MANDATORY AND BONUS =========================#

.mandatory: .mlx submodules $(OBJS)
	ar rcs $(NAME) $(OBJS) $(SUBMODLIB)
	@touch .mandatory

.mlx:
	@make -sC ./minilibx-linux/ all
	@touch .mlx

re: fclean all

fclean: clean submodule_fclean
	@echo "cleaning binaries..."
	@rm -f $(NAME)
	@rm -rf .mandatory
	@rm -rf .submodule-init
	@rm -rf .make_submodules
	@rm -rf .submodule_clean
	@rm -rf .clean
	@rm -rf .mlx

submodule_fclean:
	@make -sC ./T-Engine/ fclean
	@make -sC ./libft/ fclean

clean: .clean
	@echo "objects removed!"

.clean: .mlx .submodule-init .submodule_clean
	@echo "cleaning objects..."
	@rm -f $(OBJS)
	@rm -rf $(O_DIR)
	@touch .clean

.submodule_clean:
	@make -sC ./minilibx-linux/ clean
	@make -sC ./T-Engine/ clean
	@make -sC ./libft/ clean
	@touch .submodule_clean

.PHONY: all clean fclean re title submodules submodule_fclean add commit push
