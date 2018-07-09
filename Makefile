NAME= ft_gkrellm
CC= clang++
CFLAGS= -Wall -Wextra -Werror -std=c++98
INC = -I./includes -I./interfaces -I./includes/minilibx/
MINILIBX = -L ./includes/minilibx -lmlx -framework OpenGL -framework Appkit -L/usr/lib ./includes/minilibx/libmlx.a

INTERPATH = ./interfaces/
INTER = IMonitorModule.interface.hpp IMonitorDisplay.interface.hpp
INTERR = $(patsubst %, $(INTERPATH)%, $(INTER))


CLSPATH = ./includes/
CLS = 	GenericModule.class.hpp OSModule.class.hpp DateTimeModule.class.hpp \
		CPUModule.class.hpp RAMModule.class.hpp Network.class.hpp \
		Uptime.class.hpp Battery.class.hpp \
		Ncurses.class.hpp \
		Minilibx.class.hpp MlxImage.class.hpp Graph.class.hpp \
		BaseBase.class.hpp

CLSR = $(patsubst %, $(CLSPATH)%, $(CLS))

DEPS = $(INTERR) $(CLSR)

SRCPATH = sources/
SRC  =	GenericModule.class.cpp OSModule.class.cpp DateTimeModule.class.cpp \
		CPUModule.class.cpp RAMModule.class.cpp Network.class.cpp \
		Uptime.class.cpp Battery.class.cpp \
		BaseBase.class.cpp Ncurses.class.cpp \
		Minilibx.class.cpp MlxImage.class.cpp Graph.class.cpp \
		IMonitorModule.interface.cpp \
		main.cpp

SRCS = $(patsubst %, $(SRCPATH)%, $(SRC))

OBJECT = $(SRCS:.cpp=.o)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $(INC) -g -c -o $@ $<

$(NAME): $(OBJECT)
	@$(CC) $(CFLAGS) $(INC) $(MINILIBX) $(OBJECT) -o $@ -lncurses
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
