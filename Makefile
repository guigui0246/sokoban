##
## EPITECH PROJECT, 2022
## Sokoban
## File description:
## Make file for sokoban
##

CC	= gcc

SRC	=	main.c \
		get_from_file.c \
		load_2d_arr_from_file.c \
		mem_alloc_2d_array.c \
		display.c \
		mem_dup_2d_array.c \
		rm_map.c \
		check_win.c \
		check_lose.c \
		check_move.c \
		find_char_in_arr.c \
		up.c \
		down.c \
		left.c \
		right.c \
		put_back.c \
		main2.c

OBJ	= $(SRC:.c=.o)

VPATH	= .:./include:./lib

LIB = my

LIB_DIR = ./lib

INCLUDE_DIR	= ./include

NAME	= my_sokoban

TEST_NAME	= FUNCTION_NAME

TEST_DIR	= ./tests

all: make_lib $(NAME)

make_lib:
	make re -i -C $(LIB_DIR)/$(LIB)/

$(NAME):
	cc -c $(SRC) -I$(INCLUDE_DIR) -L$(LIB_DIR) -l$(LIB) -lncurses
	cc $(OBJ) -o $(NAME) -I$(INCLUDE_DIR) -L$(LIB_DIR) -l$(LIB) -lncurses

clean:
	rm -f $(OBJ)
	rm -f $(MAIN:.c=.o)
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME).out
	rm -f $(NAME)
	rm -f $(LIB)
	rm -f $(LIB2)
	rm -f unit_tests

re: fclean all

tests_run:
	gcc $(SRC) $(TEST_DIR)/$(TEST_NAME) \
	-o $(NAME)-test.out -I$(INCLUDE_DIR) \
	-L$(LIB_DIR) -l$(LIB) -lncurses --coverage -lcriterion
	./$(NAME)-test.out
	gcovr --exclude tests/
	gcovr --exclude tests/ -b

.PHONY: tests_run re clean fclean all make_lib
