CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Ex00
SRCS = main.cpp \
		ScalarConverter.cpp \
		convert.cpp
HEADER = ScalarConverter.hpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all