NAME = account

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp Account.hpp
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run