NAME = Animal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) Animal.hpp Dog.hpp Cat.hpp Brain.hpp WrongAnimal.hpp WrongCat.hpp
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
