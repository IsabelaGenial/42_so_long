NAME         = so_long

MANDATORY    = $(addprefix ./mandatory/, map.c so_long.c util_win.c)
BONUS        = $(addprefix ./BONUS/, so_long_bonus.c)
#MAPS         = map1.ber map2.ber map3.ber
HEADER       = $(addprefix ./mandatory/, so_long.h)
HEADER_UTILS = $(addprefix ./GNL/, get_next_line.h) $(addprefix ./Printf/, ft_printf.h)
SRC_UTILS    = $(addprefix ./Printf/, ft_puthex.c ft_putnbr.c \
              ft_type.c ft_printf.c ft_putchar.c ft_putlong.c \
              ft_putptr.c ft_putstr.c) $(addprefix ./GNL/, get_next_line.c \
              get_next_line_utils.c)
MANDATORY_FILES = $(MANDATORY:%.c=%.o)
UTILS_FILES     = $(SRC_UTILS:%.c=%.o)
CC              = cc
LDLIBS          = -lmlx -lXext -lX11
CFLAGS          = -g3

all: $(NAME)

$(NAME): $(MANDATORY_FILES) $(UTILS_FILES)
	$(CC) $(CFLAGS) $(MANDATORY_FILES) $(MAPS) $(UTILS_FILES)  $(LDLIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(MANDATORY_FILES) $(UTILS_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
