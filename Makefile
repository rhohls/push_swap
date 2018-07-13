# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 07:04:12 by rhohls            #+#    #+#              #
#    Updated: 2018/07/12 07:27:34 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ifeq (name_C) dont make
#
# have seperate cpy cmds
#
# for clean dont cpy and run in each folder

NAME_C = checker
CHK_DIR = ./checker
NAME_P = push_swap
PSHSWP_DIR = ./pushswap_ai

$(NAME_C):
	make -C $(CHK_DIR)
	cp $(CHK_DIR)/$(NAME_C) ./

$(NAME_C):
	make -C ./checker
	cp $(PSHSWP_DIR)/$(NAME_C) ./

all: $(NAME_C) $(NAME_P)

clean:

fclean: clean

re: fclean all

.PHONY: re fclean clean all
