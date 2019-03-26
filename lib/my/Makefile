##
## EPITECH PROJECT, 2018
## Makefile for lib
## File description:
## lib makefile
##

.RECIPEPREFIX +=

CC          := gcc

FILES       :=  my_compute_power_rec my_compute_square_root my_find_prime_sup my_isneg my_revstr my_show_word_array my_showmem \
                my_showstr my_sort_int_array my_str_isalpha my_str_islower my_str_isnum my_str_isupper \
                my_strcapitalize my_strcat my_strcmp my_strcpy my_strlowcase my_strncat my_strncmp \
                my_strncpy my_strstr my_strupcase my_swap my_strdup my_free my_contains my_memset my_intostring

SRC_NAMES   := $(addsuffix .c, $(FILES))
SRC         := $(addprefix src/, $(SRC_NAMES))

OBJ         := $(SRC:src/%.c=%.o)

CINC        := -I./include/

CFLAGS      := -Wall -Wextra -Werror -pedantic -std=c99 -O3

NAME        := libmy.a

RED         := \033[0;31m
CYAN        := \033[0;36m
GOLD        := \033[0;33m
GREEN       := \033[0;32m
WHITE       := \033[0;0m

PWD			:= "lib/my/"
PREFIX      := $(CYAN) "[LIB] "

all:        $(NAME)

%.o: src/%.c
        @$(CC) -c $(CLFAGS) $(CINC) -o $@ $^
        @echo -e "$(PREFIX) $(GREEN)$^ $(GOLD)=> $(GREEN)$@"

$(NAME):    $(OBJ)
        @echo -e "$(PREFIX)$(GOLD)Compiling...$(WHITE)"
        @ar rc $(NAME) $(OBJ)
        @echo -e "$(PREFIX)$(GOLD)Compiled !$(WHITE)"

clean:
        @echo -e "$(PREFIX)$(RED)Delete $(GOLD)$*.o$(WHITE)"
        @rm -rf $(OBJ)

fclean:     clean
        @echo -e "$(PREFIX)$(RED)Delete $(GOLD)$ ../$(NAME)$(WHITE)"
        @rm -rf $(NAME)

re:         fclean all
