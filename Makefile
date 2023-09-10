NAME         = so_long

MANDATORY    = $(addprefix ./mandatory/, so_long.c  map.c)
BONUS        = $(addprefix ./BONUS/, so_long_bonus.c)
#MAPS         = map1.ber map2.ber map3.ber
HEADER       = $(./mandatory/, so_long.h) $(./minilibx_linux/, mlx.h)
HEADER_UTILS = $(./GNL/, get_next_line.h) $(./Printf/, ft_printf.h)
SRC_UTILS    = $(addprefix ./Printf/, ft_puthex.c ft_putnbr.c \
              ft_type.c ft_printf.c ft_putchar.c ft_putlong.c \
              ft_putptr.c ft_putstr.c) $(addprefix ./GNL/, get_next_line.c \
              get_next_line_utils.c) $(addprefix ./minilibx_linux/, mlx_clear_window.c   \
			    mlx_destroy_window.c  mlx_flush_event.c  mlx_hook.c  mlx_int_do_nothing.c  \
				mlx_int_set_win_event_mask.c  mlx_key_hook.c  mlx_loop_hook.c   mlx_new_image.c  \
				mlx_put_image_to_window.c  mlx_set_font.c mlx_destroy_display.c  mlx_expose_hook.c \
				mlx_get_color_value.c  mlx_init.c mlx_int_get_visual.c   mlx_int_str_to_wordtab.c   \
				mlx_lib_xpm.c   mlx_mouse.c  mlx_new_window.c  mlx_rgb.c  mlx_string_put.c mlx_destroy_image.c  \
				mlx_ext_randr.c    mlx_get_data_addr.c   mlx_int_anti_resize_win.c  mlx_int_param_event.c \
				mlx_int_wait_first_expose.c   mlx_loop.c      mlx_mouse_hook.c  mlx_pixel_put.c   mlx_screen_size.c \
				mlx_xpm.c)
MANDATORY_FILES = $(MANDATORY:%.c=%.o)
UTILS_FILES     = $(SRC_UTILS:%.c=%.o)
CC              = cc
LDLIBS          = -lmlx -lXext -lX11
CFLAGS          = -g3

all: $(NAME)

$(NAME): $(MANDATORY_FILES) $(UTILS_FILES)
	$(CC) $(CFLAGS) -I $(HEADER) $(HEADER_UTILS) $(MANDATORY_FILES) $(MAPS) $(UTILS_FILES) $(LDLIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(MANDATORY_FILES) $(UTILS_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
