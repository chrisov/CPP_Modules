#
#
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -std=c++17
MAKEFLAGS += -s

INCDIR = ./inc
SRCDIR = ./src
OBJDIR = ./obj
SRCS = $(SRCDIR)/tests.cpp $(SRCDIR)/Account.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

NAME = account

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@echo "\033[33mCompilating $(NAME)...\033[0m"
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled \033[32msuccessfully\033[0m!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@echo "\033[33mRemoving project build...\033[0m"
	rm -f $(OBJDIR)/*.o
	rm -rf $(OBJDIR)
	@echo "All build files removed \033[32msuccessfully\033[0m!"


fclean: clean
	@echo "\033[33mRemoving executable and project build...\033[0m"
	rm -f $(NAME)
	@echo "Executable and project build removed \033[32msuccessfully\033[0m!"

re: fclean all

.PHONY: all clean fclean re
