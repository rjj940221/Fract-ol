# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/09/28 14:05:22 by arnovan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
LIBFTI		=	-I libft/includes
LIBFTL		=	-L. -lft
MLXI		=	
MLXL		=	-L/usr/lib -lmlx -framework OpenGL -framework AppKit
INC			=	-I include $(MLXI) $(LIBFTI)
LIBS		=	-lm $(MLXL) $(LIBFTL)
CFLAGS		=	-Wall -Wextra -Werror -Wno-unused-result -g3 $(INC)
LFLAGS		=	$(INC) $(LIBS)
CC			=	gcc
LD			=	gcc

INCLUDE		=	$(shell find include -name "*.h")
SRC			=	$(shell find src -name "*.c")
OBJ			=	$(SRC:src/%.c=build/%.o)

all: lft fractol

build/%.o: src/%.c $(INCLUDE)
	@echo "\033[92m    CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

fractol: $(OBJ)
	@echo "\033[92m    LD    $(NAME)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME)

lft:
	@make -s -C libft all

clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -rf build
	@make -s -C libft clean

fclean: clean
	@echo "\033[92m    RM    $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make -s -C libft fclean

re: fclean all
