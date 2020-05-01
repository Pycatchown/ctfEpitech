CC	= gcc

CFLAGS	+= -W -Wall -Wextra -Iincludes
LDFLAGS	+=

SRC	= $(addprefix sources/, \
	  	vm.c \
		operators.c \
		functions.c)

OBJ	= $(SRC:.c=.o)

NAME	= vm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	strip $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re
