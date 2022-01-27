NAME			=	fractol
SRCS_DIR		=	./srcs/
OBJS_DIR		=	./objs/
HEADERS_DIR		=	./includes/
SRCS			=	$(wildcard $(SRCS_DIR)*.c)

HEADERS			=	$(wildcard $(HEADERS_DIR)*.h)
OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -O2 -g -fsanitize=address
LDFLAGS			=	-L$(LIBMLX_DIR) -lmlx -framework OpenGL -framework Appkit -O2
RM				=	rm -f
LIBMLX			=	$(addprefix $(LIBMLX_DIR), libmlx.a)
LIBMLX_DIR		=	./mlx/

all:	$(NAME)


$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(HEADERS)  
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -Imlx -c $< -o $@


$(OBJS_DIR):
	mkdir objs
$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBMLX)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo ""
	@echo "\x1b[1;36m \x1b[0;36m DONE ☆*:.｡.o(≧▽≦)o.｡.:*☆\033[0m"
	@echo ""

clean:
		$(RM) -r $(OBJS_DIR)

fclean: clean
		$(RM) $(NAME)

re:	fclean $(OBJS_DIR) all

.PHONY:	all clean fclean re
