NAME			=	fractol
SRCS_DIR		=	./srcs/
OBJS_DIR		=	./objs/
HEADERS_DIR		=	./includes/
SRCS			=	$(wildcard $(SRCS_DIR)*.c)
HEADERS			=	$(wildcard $(HEADERS_DIR)*.h)
OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -O3 #-g -fsanitize=address
LDFLAGS			=	-L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework Appkit -O3
RM				=	rm -f
LIBMLX			=	$(addprefix $(LIBMLX_DIR), libmlx.a)
LIBMLX_DIR		=	./mlx/

all:  $(LIBMLX) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)  $(LIBMLX) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -Imlx -c $< -o $@


$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(NAME): $(OBJS)  $(LIBMLX)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo ""
	@echo "\x1b[1;36m \x1b[0;36m DONE ☆*:.｡.o(≧▽≦)o.｡.:*☆\033[0m"
	@echo ""

clean:
		$(RM) -r $(OBJS_DIR)
		make -C $(LIBMLX_DIR) fclean

fclean: clean
		$(RM) $(NAME)
		make -C $(LIBMLX_DIR) fclean

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

re: fclean $(OBJS_DIR) all

.PHONY: all clean fclean re
