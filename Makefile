CC    =  gcc
CFLAGS  =   -Werror -Wall -Wextra
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
HEADER  =  fractol.h
NAME  =  fractol
SRC  =  visual.c basic_math.c main.c

OBJECTS =  $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJECTS) -I $(HEADER) $(MLX_FLAGS) -o $(NAME)
	@echo ""
	@echo "\x1b[1;36m \x1b[0;36m DONE ☆*:.｡.o(≧▽≦)o.｡.:*☆\033[0m"
	@echo ""

%.o:    %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus