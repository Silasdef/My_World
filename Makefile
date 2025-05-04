##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile for my_ls
##

SRC = 	main.c       \
		clic_event.c \
		draw_map.c   \
		destroy.c    \
		menu.c		 \
		sound.c	     \
		button_in_game.c	 \
		get_size.c   \

NAME =my_world

LCNAME = unit_tests

CFLAGS = -Iinclude -Llib/my/ -lmy -lcsfml-graphics -lcsfml-window \
    -lcsfml-system -lcsfml-audio -lm

LCFLAGS = --coverage -lcriterion

OBJ		=	$(SRC:.c=.o)

all:	$(OBJ)
	$(MAKE) -C lib/my all
	gcc -o $(NAME) $(SRC) $(CFLAGS)

libmy.a:
	$(MAKE) -C lib/my

clean:
	$(MAKE) -C lib/my clean
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	$(MAKE) -C lib/my fclean
	rm -f $(NAME)
	rm -f $(LCNAME)
	rm -f libmy.a

re:		fclean all

debug:
		gcc -o $(NAME) $(SRC) $(CFLAGS) -g
		valgrind --leak-check=full ./my_radar

unit_tests:
	gcc -o unit_tests tests/test_printf.c \
	-Iinclude/. -L. -lmy -lcriterion --coverage

tests_run:
	./$(LCNAME)
