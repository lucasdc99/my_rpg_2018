##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile for do_op
##

.RECIPEPREFIX +=

CC		:= gcc

NAME		:= my_rpg
FILES		:= main create_window display button get init_menu draw callback destroy event parser get_next_line init_sprite transform_2d init_choose_heroes init_options init_how_to\
                   options init_text move_rect choose_heroes init_game init_house useful init_player init_house1 init_inventory inventory init_objects init_quest init_forest

SRC_NAMES 	:= $(addsuffix .c, $(FILES))
SRC		:= $(addprefix src/, $(SRC_NAMES))

CINC		:= -I include/
CFLAGS		:= -W -Wextra -Wall -g
LDFLAGS		:= -L./lib/my -lmy -L./lib/printf -lprintf -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

OBJ             := $(SRC:src/%.c=obj/%.o)

RED             := \033[0;31m
CYAN            := \033[0;36m
GOLD            := \033[0;33m
GREEN           := \033[0;32m
WHITE           := \033[0;0m

PREFIX		:= $(CYAN) "[$(NAME)]"

all:		createdir $(NAME)

obj/%.o: src/%.c
        @$(CC) -c $(CFLAGS) $(CINC) -o $@ $^
        @echo "$(PREFIX) $(GREEN)$^ $(GOLD)=> $(GREEN)$@"

$(NAME):        $(OBJ)
        @make -sC lib/my
        @make -sC lib/printf
        @echo "$(GOLD)Compiling...$(WHITE)\r"
        @gcc $(OBJ) -o $(NAME) $(CINC) $(CFLAGS) $(LDFLAGS)
        @echo "$(GOLD)Compiled !$(WHITE)"
        @echo "$(RED)Delete $(GOLD)$(PWD)/obj/*.o$(WHITE)"
        @rm -rf $(OBJ)
        @rmdir obj

clean:
        @echo "$(RED)Delete $(GOLD)$(PWD_PATH)/obj/*.o$(WHITE)"
        @rm -rf $(OBJ)

fclean:         clean
        @make -sC lib/my fclean
        @make -sC lib/printf fclean
        @echo "$(RED)Delete $(GOLD)$(PWD)/$(NAME)$(WHITE)"
        @rm -rf $(NAME)

re:             fclean all clean

createdir:
        @mkdir -p obj
