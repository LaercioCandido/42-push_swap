
NAME		= push_swap

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g
RM			= /bin/rm -f

DIR_SRCS	= source
DIR_OBJS	= objs
SUBDIRS		= aux_libft main sorting stack

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiled "$<" successfully!"

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)
			@echo "created push_swap executable file successfully!"

test:		$(NAME)
			cp ./tools/checker_linux .
			bash ./tools/tester.sh

fclean:
			@rm -f $(NAME)
			@rm -f $(OBJECTS) $(NAME) screen_shot.bmp

clean:
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)
			@echo "Cleanup completed!"

fclean: 	clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re