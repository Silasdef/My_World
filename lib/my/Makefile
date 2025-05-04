##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile test
##
SRC = my_isneg.c my_showmem.c my_strcmp.c my_str_isprintable.c \
	my_strncpy.c \
	my_is_prime.c my_showstr.c my_strcpy.c my_str_isupper.c my_strstr.c \
	my_compute_power_rec.c \
	my_putchar.c my_show_word_array.c my_strdup.c my_strlen.c \
	my_str_to_word_array.c \
	my_compute_square_root.c  my_put_nbr.c my_sort_int_array.c \
	my_str_isalpha.c my_strlowcase.c my_strupcase.c my_find_prime_sup.c \
	my_putstr.c my_strcapitalize.c \
	my_str_islower.c my_strncat.c my_swap.c my_getnbr.c my_revstr.c \
	my_strcat.c my_intlen.c \
	my_str_isnum.c my_strncmp.c \
	concat_params.c fifth_arg_type.c first_arg_type.c flags.c \
	fourth_arg_type.c handle_zero_precision.c my_printf.c \
	second_arg_type.c third_arg_type.c put.c tools_flags.c tools_functions.c \
	print_arg_functions.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	cp my.h "../../include/"
	ar rc $(NAME) $(OBJ)
	cp libmy.a "../"

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
