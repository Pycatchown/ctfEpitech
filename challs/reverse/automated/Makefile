CC	= g++

CFLAGS	+= -O0 -W -Wall -Wextra -Iincludes -std=c++17
LDFLAGS	+=

SRC	= $(addprefix sources/, \
	  	main.cpp)

OBJ	= $(SRC:.cpp=.o)

NAME	= auto

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	# strip $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean re
