# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algultse <algultse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 19:29:05 by algultse          #+#    #+#              #
#    Updated: 2024/02/22 12:30:31 by algultse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
MLX = ./mlx_linux/libmlx.a -Imlx_linux

MLXDIR = ./mlx_linux/
LIBFTDIR = ./libft/
SRCDIR = ./srcs/
INCDIR = ./include/
OBJDIR = ./obj/

SRC = colors.c draw_line.c error.c init.c \
	keys.c keys_map.c main.c map.c \
	read.c render.c rotation.c text.c \
	utils.c
OBJS = $(SRC:%.c=$(OBJDIR)%.o)

MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz
LIBFT = -L$(LIBFTDIR) -lft

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -Imlx_linux -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)

re: fclean all

resrcs:
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	make

.PHONY: all clean fclean re resrcs