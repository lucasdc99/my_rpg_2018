##
## EPITECH PROJECT, 2018
## Makefile for lib
## File description:
## lib makefile
##

.RECIPEPREFIX +=

CC          := gcc

FILES       :=  my_getnbr my_put_nbr my_putchar my_putstr my_strlen\
                my_put_float display_nbr display_other display_str \
                my_put_nbrbase other printf my_malloc

SRC_NAMES   := $(addsuffix .c, $(FILES))
SRC         := $(addprefix src/, $(SRC_NAMES))

OBJ         := $(SRC:src/%.c=%.o)

CINC        := -I./include/

CFLAGS      := -Wall -Wextra -Werror -pedantic -std=c99

NAME        := libprintf.a

RED         := \033[0;31m
CYAN        := \033[0;36m
GOLD        := \033[0;33m
GREEN       := \033[0;32m
WHITE       := \033[0;0m

PWD			:= "lib/printf/"
PREFIX      := $(CYAN) "[LIBPRINTF] "

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

re:         fclean all clean
