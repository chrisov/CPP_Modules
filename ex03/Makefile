#
#
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -std=c++17
SPECIALFLAGS = -Wshadow -Wno-shadow
MAKEFLAGS += -s

INCDIR = ./inc
SRCDIR = ./src
OBJDIR = ./obj
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/ClapTrap.cpp \
	 $(SRCDIR)/ScavTrap.cpp $(SRCDIR)/FragTrap.cpp \
	 $(SRCDIR)/DiamondTrap.cpp

OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

NAME = diamondtrap

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@printf "[.]   📦 Compiling \033[33mMLX42\033[0m...\r"
	$(CPP) $(CPPFLAGS) $(SPECIALFLAGS) $(OBJS) -o $(NAME)
	@echo "🚀 \033[33m$(NAME)\033[0m compiled \033[32msuccessfully\033[0m!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) $(SPECIALFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o
	rm -rf $(OBJDIR)

fclean: clean
	@printf "[.]   🧹 Removing \033[33m$(NAME)\033[0m build...\r"
	rm -f $(NAME)
	printf "[✅]  🧹 Removed \033[33m$(NAME)\033[0m build...  \n"

re: fclean all

.PHONY: all clean fclean re
