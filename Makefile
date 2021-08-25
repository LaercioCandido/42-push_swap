NAME = push_swap
LIBFT = libft.a

LIBFT_PATH = ./libraries/libft/
INCLUDES = ./includes

SRC = ./source/

FILES = $(SRC)push_swap.c
OBJECTS = push_swap.o

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

test: $(NAME)
	cp ./tools/checker_linux .
	bash ./tools/tester.sh

visual: $(NAME)
	cp ./tools/pyviz.py .
	python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

clean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	$(RM) checker_linux
	$(RM) pyviz.py

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re 
