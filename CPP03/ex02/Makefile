NAME    = ClapTrap
SRCS    = main.cpp\
		  	ClapTrap.cpp\
			FragTrap.cpp\
			ScavTrap.cpp
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