#
#
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++17
MAKEFLAGS += -s

SRCDIR = ./src
OBJDIR = ./obj
SRCS = $(SRCDIR)/main.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

NAME = brain

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
	@echo "Project build removed \033[32msuccessfully\033[0m!"


fclean: clean
	@echo "\033[33mRemoving executable $(NAME)...\033[0m"
	rm -f $(NAME)
	@echo "Executable $(NAME) removed \033[32msuccessfully\033[0m!"

re: fclean all

.PHONY: all clean fclean re
