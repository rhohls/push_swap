# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 11:19:09 by rhohls            #+#    #+#              #
#    Updated: 2018/07/16 09:32:55 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ps_checker 
SRCS = ./src/
OBJF = ./objs/
CCF = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a

MAIN ?= main.c
MAINT ?= main_test.c

FILES = *.c
OBJS = $(FILES: .c=.o)

$(NAME): compile
	make -C libft
	gcc -o $(NAME) $(SRCS)$(OBJS) $(LIBFT)
	#$(OBJF)$(OBJS)

compile: $(OBJ)
	gcc -c $(SRCS)$(FILES)
#	@mv $(SRCS)$(OBJS) $(OBJF)
	mv *.o $(OBJF)


all: $(NAME)

clean:
	/bin/rm -f $(OBJF)*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all test clean



