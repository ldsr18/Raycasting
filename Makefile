NAME    = cub3d
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = 	src/main.c \
			src/player.c

OBJS    = $(SRCS:.c=.o)

MLX_DIR = includes/minilibx-linux
MLX     = $(MLX_DIR)/libmlx.a
FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(FLAGS)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
