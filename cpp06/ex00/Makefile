CXX = c++
CXXGLAGS = -Wall -Wextra -Werror -std=c++17 -I$(INCDIR) -g

NAME = convert

SRCDIR = srcs
INCDIR = inc
OBJDIR = obj

SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/ScalarConverter.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

GREEN=\033[0;32m
RED=\033[0;31m
NC=\033[0m

all: $(NAME)
	@echo "$(GREEN)Build successful$(NC)"

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking object files$(NC)"
	$(CXX) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@echo "$(GREEN)Compiling $<$(NC)"
	$(CXX) $(CXXGLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(RED)Cleaning up$(NC)"
	rm -rf $(OBJDIR)
	rm -rf *.dSYM

fclean: clean
	@echo "$(RED)Force cleaning$(NC)"
	rm -f $(NAME)

re: fclean all
	@echo "$(GREEN)Rebuild complete$(NC)"

.PHONY: all clean fclean re