##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Makefile
##

CFLAGS = -W -Wall -Wextra -g3 -I./include

C_LIB = -I./include -L./lib/my -lmy

SRC = my_ls.c			\
	ls_l.c				\
	flags_management.c	\
	management.c		\
	printer.c			\

OBJ = $(SRC:.c=.o)

NAME = my_ls

all	: $(NAME)

$(NAME)	:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(C_LIB)

clean	:
	rm -f $(OBJ)
	make clean -C lib/my

fclean	:	clean
	make fclean -C lib/my
	rm -f $(NAME)

re	:	fclean all