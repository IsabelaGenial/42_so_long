NAME         = so_long

MANDATORY    = $(addprefix ./mandatory/, so_long.c  map.c util_win.c map_utils.c \
											memory.c 	utils_image.c load_img.c \
											manager_win.c	object_map.c	utils.c \
											utils_move.c)
BONUS        = $(addprefix ./BONUS/, so_long_bonus.c)
HEADER       = ./mandatory/so_long.h
HEADER_UTILS = ./libfstonk/libft.h
LIBFT		= ./libfstonk/libft.a
MANDATORY_FILES = $(MANDATORY:%.c=%.o)
CC              = cc
LDLIBS          = -lmlx -lXext -lX11
CFLAGS          = -g3

all: $(NAME)

$(NAME): $(MANDATORY_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(MANDATORY_FILES) $(LIBFT) $(LDLIBS) -o $(NAME)

$(LIBFT):
	make -C ./libfstonk

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -I$(HEADER_UTILS) -c $< -o $@

clean:
	rm -f $(MANDATORY_FILES) $(UTILS_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) map1.ber

gdb: all
	gdb --tui --args ./$(NAME) map1.ber
.PHONY: all clean fclean re