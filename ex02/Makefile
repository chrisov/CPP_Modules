#
#
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -std=c++17 -g -Wfatal-errors
MAKEFLAGS += -s

INCDIR = ./inc
SRCDIR = ./src
OBJDIR = ./obj
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/Utils.cpp $(SRCDIR)/Exceptions.cpp

OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

NAME = PmergeMe

$(NAME): $(OBJDIR) $(OBJS)
	@printf "[.]   📦 Compiling '\033[33m$(NAME)\033[0m'...\r"
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "🚀 '\033[33m$(NAME)\033[0m' compiled \033[32msuccessfully\033[0m!"
	@echo "\ne.g.: ./PmergeMe \`jot -r 30 1 100 | tr '\\\n' ' '\`\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	rm -f $(OBJDIR)/*.o
	rm -rf $(OBJDIR)

fclean: clean
	@printf "[.]   🧹 Removing '\033[33m$(NAME)\033[0m' build...\r"
	rm -f $(NAME)
	printf "[✅]  🧹 Removed '\033[33m$(NAME)\033[0m' build...  \n"

re: fclean all

.PHONY: all clean fclean re
