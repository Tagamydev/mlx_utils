# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samusanc <samusanc@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 01:22:18 by samusanc          #+#    #+#              #
#    Updated: 2024/08/09 17:42:42 by samusanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libmlx_utils.a
COMMIT_D	:= $(shell date)
COMMIT_U	:= ${USER}
CFLAGS		= -Wall -Wextra -Werror
INC			= -I./includes/
INC			+= -I./ft_math/
INC			+= -I/usr/include -O3 -I./minilibx-linux/ 
CC			= gcc $(CFLAGS)

SRCS		= ./ft_putPixel.c
O_DIR		= ./objects/
OBJS		= $(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INC) -g -c $< -o $(O_DIR)/$(<:.c=.o)
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

#===================================================================================================================
#												Git Submodule Workflow
#===================================================================================================================

submodules: .submodule-init #.libft
	@echo "All submodules loaded..."

.submodule-init:
	@git submodule update --init --recursive
	@git submodule update --recursive --remote
	@touch .submodule-init

.T-Engine:
	@make -sC ./T-Engine/ all
	@touch .T-Engine

#===================================================================================================================
#									Git Submodule Workflow 4 ADD COMMIT and PUSH
#===================================================================================================================

add: fclean .submodule-init
	@make -sC ./T-Engine/ add
	@-git pull
	@git add .

#===================================================================================================================

.mandatory: .T-Engine .mlx $(OBJS)
	ar rcs $(NAME) $(OBJS) -L./minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	@touch .mandatory

.mlx:
	@make -sC ./minilibx-linux/ all
	@touch .mlx

re: fclean all

fclean: clean
	@echo "cleaning binaries..."
	@make -sC ./T-Engine/ fclean
	@rm -f $(NAME)
	@rm -rf .mandatory
	@rm -rf .submodule-init
	@rm -rf .clean
	@rm -rf .mlx
	@rm -rf .T-Engine

clean: .clean
	@echo "objects removed!"

.clean:
	@echo "cleaning objects..."
	@make -sC ./minilibx-linux/ clean
	@make -sC ./T-Engine/ clean
	@rm -f $(OBJS)
	@rm -rf $(O_DIR)
	@touch .clean

.PHONY: all title clean fclean re submodules add
