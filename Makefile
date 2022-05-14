##
## EPITECH PROJECT, 2021
## MY_HUNTER
## File description:
## It's the Makefile of my_hunter project
##

LIB	=	lib/my_strlen.c      \
		lib/my_atoi.c	\
		lib/my_putchar.c     \
		lib/my_put_nbr.c     \
		lib/my_putstr.c      \
		lib/my_strcmp.c      \
		lib/my_strncat.c     \
		lib/my_strncpy.c     \
		lib/my_printf.c	\
		lib/new_put_nbr.c	\
		lib/str_to_array.c	\
		lib/my_tab.c 	\

SRC =	src/generator/*.c \
		src/menu/*.c	\
		src/gestion/*.c	\
		src/main.c	\
		src/globales_funct.c	\
		src/game/*.c	\
		src/audios/*.c	\
		src/ath/*.c	\
		src/enemys/*.c	\
		src/saves/*.c	\
		src/quests/*.c	\
		src/particles/*.c

OBJ = $(LIB:.c=.o)

CFLAGS	=	-Werror -Wall -pedantic -g3

CSFMLFLAG = -lcsfml-graphics -lcsfml-system  -lcsfml-window -lcsfml-audio

NAME = my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc libmy.a $(OBJ)
	@echo ">>> Library compiled."
	@gcc -g3 -o ${NAME} $(SRC) $(CFLAGS) $(CSFMLFLAG) -L. libmy.a
	@echo ">>> Executable \"${NAME}\" created."
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@find -name "vgcore.*" -delete
	@rm -f libmy.a
	@echo ">>> All files was clean."

re: fclean all
