NAME    = Polymorphisme
SRCS    = main.cpp\
			Cat.cpp\
			Dog.cpp\
			Brain.cpp\
			Animal.cpp\
			WrongCat.cpp\
			WrongAnimal.cpp

CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re