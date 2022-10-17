# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 15:31:56 by hwichoi           #+#    #+#              #
#    Updated: 2022/10/17 16:31:39 by hwichoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c\
	   so_long_utils.c\
	   event.c\
	   image.c\
	   map.c\
	   map_chk.c\
	   get_next_line/get_next_line.c\
	   get_next_line/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -framework Appkit -framework OpenGL mlx/libmlx.a

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
