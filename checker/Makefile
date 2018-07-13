# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 07:04:12 by rhohls            #+#    #+#              #
#    Updated: 2018/07/12 07:04:14 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
SRCS = ./src/
OBJF = ./obj/
CCF = -Wall -Werror -Wextra
LIBFT = ../libft/libft.a

MAIN ?= main.c
MAINT ?= main_test.c

FILES = *.c
OBJS = $(FILES: .c=.o)

$(NAME): compile
	make -C ../libft
	gcc -o $(NAME) $(OBJF)*.o $(LIBFT) #$(MAIN)
	#$(OBJF)$(OBJS)

compile: $(OBJ)
	gcc -c $(SRCS)$(FILES)
#	@mv $(SRCS)$(OBJS) $(OBJF)
	mv *.o $(OBJF)

test: compile
	gcc -o $(NAME) $(OBJF)*.o $(LIBFT) #$(MAINT)
	./$(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJF)*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all test clean



