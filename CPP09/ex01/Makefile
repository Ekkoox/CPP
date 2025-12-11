NAME    = Calculator
SRCS    = main.cpp\
			RPN.cpp
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

PEAR = ⚽️
APPLE = 🍎
CHERRY = 🍒
WATERMELON = 🍉

game:
	echo "Welcome to the C++ game slot machine"
	echo "Number of win ; 1"
	echo "if you win to the first try you have a cookie for free (if the machin is working)"
	echo "second try is negotiable (see condidtions with the owner)"
	echo "a winning combination is 3 same fruits"
	echo "we have ; $(CHERRY) $(APPLE) $(WATERMELON) $(PEAR)"
	echo ""
	echo "===========SLOT MACHINE==============="
	@for number in 1 2 3; do \
		sleep 1; \
		num=$$(shuf -i 1-4 -n 1); \
		if [ $$num -eq 1 ]; then \
			echo -n "$(CHERRY) "; \
		elif [ $$num -eq 2 ]; then \
			echo -n "$(APPLE) "; \
		elif [ $$num -eq 3 ]; then \
			echo -n "$(WATERMELON) "; \
		else \
			echo -n "$(PEAR) "; \
		fi; \
	done; \
	echo ""