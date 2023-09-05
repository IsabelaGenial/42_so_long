NAME			=	so_long

MANDATORY		=	$(addprefix ./mandatory/, map.c	so_long.c	util_win.c)
BONUS			=	$(addprefix ./BONUS/,	so_long_bonus.c)
MAPS			=	$(addprefix ./maps/, map1.ber	map2.ber	map3.ber)
HEADER			=	$(addprefix ./mandatory/, so_long.h)
HEADER_UTILS	=	$(addprefix ./GNL/, get_next_line.h), $(addprefix ./Printf/, ft_printf.h).
SRC_UTILS		=	$(addprefix ./Printf/, ft_puthex.c ft_putnbr.c \
						ft_type.c	ft_printf.c	ft_putchar.c	ft_putlong.c \
						ft_putptr.c	ft_putstr.c) $(addprefix ./GNL/, get_next_line.c	\
						get_next_line_utils.c)
MANDATORY_FILES		=	$(MANDATORY:%.c=%.o)
UTILS_FILES			=	$(SRC_UTILS:%.c=%.o)
BONUS				=	$(BONUS:%.c=%.o)
FLAGS_MLX			=	-g3 -lmlx -lXext -lx11
CC					=	gcc

all: $(NAME)

%.o: %.c
	cc  $(FLAGS_MLX) -c $< -o $@

$(NAME): $(MANDATORY_FILES) $(UTILS_FILES)
	$(CC) $(FLAGS_MLX) $(MANDATORY_FILES) $(UTILS_FILES) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -rf $(MANDATORY_FILES) $(MANDATORY_FILES) $(UTILS_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re