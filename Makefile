NAME         = so_long

MANDATORY    = $(addprefix ./mandatory/, so_long.c  map.c)
BONUS        = $(addprefix ./BONUS/, so_long_bonus.c)
HEADER       = ./mandatory/so_long.h
HEADER_UTILS = ./GNL/get_next_line.h
HEADER_2 =	./Printf/ft_printf.h
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
	$(CC) $(CFLAGS) $(MANDATORY_FILES) $(UTILS_FILES)  $(LDLIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -I$(HEADER_UTILS) -I $(HEADER_2) -c $< -o $@

clean:
	rm -f $(MANDATORY_FILES) $(UTILS_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
