# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 13:08:28 by rhohls            #+#    #+#              #
#    Updated: 2018/07/17 13:12:15 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker
PUSHSWAP = push_swap

# Path
SRC_PATH = ./src/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
LIB_PATH = ./libft/

# Files
SRC_FILE =	inits.c        \
			print_stuff.c  \
			st_push.c      \
			st_rotate.c	   \
			compare.c      \
			instructions.c \
			returns.c      \
			st_revrotate.c \
			st_swap.c	   \

OBJ_FILE = $(SRC_FILE:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

#Compile
CCFLAGS = -Wall -Werror -Wextra
CC = gcc $(CCFLAGS)

LIBF = -L $(LIB_PATH)libft.a

#Make Commands
all: $(CHECK) $(PUSHSWAP)

$(CHECK): $(OBJ) $(INC_PATH) ./src_check/checker.c
	@make -C./libft/
	@$(CC) -o $@ $(LIBF) $(OBJ) ./src_check/checker.c 

$(PUSHSWAP): $(OBJ) $(INC_PATH) ./src_push/push_swap.c
	@make -C./libft/
	@$(CC)  -o $@ $(LIBF) $(LFT) $(OBJ) ./src_push/push_swap.c

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	/bin/rm -rf $(OBJ)

fclean: clean fcleanlib
	@rm -f $(CHECK)
	@rm -f $(PUSHSWAP)

cleanlib:
	@make clean -C $(LIB_PATH)

fcleanlib:
	@make fclean -C $(LIB_PATH)

re : fclean all

.PHONY: re fclean clean all
