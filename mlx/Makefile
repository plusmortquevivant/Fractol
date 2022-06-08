NAME	=	libmlx.a

SRCS	=	mlx_shaders.c \
			mlx_new_window.m \
			mlx_init_loop.m \
			mlx_new_image.m \
			mlx_xpm.c \
			mlx_int_str_to_wordtab.c

SRCS	+=	mlx_png.c \
			mlx_mouse.m

OBJ1	=	$(SRCS:.c=.o)

OBJS	=	$(OBJ1:.m=.o)

CC		=	gcc

CFLAGS	+=	-O3 -w

# add to match string put with X11 in size and position
CFLAGS	+=	-DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(NAME) $(OBJS) *~
	rm -f mlx_app

fclean: clean

re: clean all
