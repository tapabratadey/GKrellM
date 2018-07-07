NAME= system_monitor
CC= clang++
CFLAGS= -Wall -Wextra -Werror
INC = -I./includes -I./interfaces

INTERPATH = ./interfaces/
INTER = IMonitorModule.interface.hpp
INTERR = $(patsubst %, $(INTERPATH)%, $(INTER))


CLSPATH = ./includes/
CLS = GenericModule.class.hpp OSModule.class.hpp

CLSR = $(patsubst %, $(CLSPATH)%, $(CLS))

DEPS = $(INTERR) $(CLSR)

SRCPATH = sources/
SRC  =	GenericModule.class.cpp OSModule.class.cpp \
		main.cpp

SRCS = $(patsubst %, $(SRCPATH)%, $(SRC))

OBJECT = $(SRCS:.cpp=.o)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $(INC) -g -c -o $@ $<

$(NAME): $(OBJECT)
	@$(CC) $(CFLAGS) $(INC) $(OBJECT) -o $@
	echo "Finished!"

all: $(NAME)

clean:
	@echo "Cleanning..."
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
