# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:05:55 by pjimenez          #+#    #+#              #
#    Updated: 2024/01/12 17:01:15 by pjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= mondongo
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= MLX42/MLX42.a

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIB 	:= include/so_long.a
LIBS	:= -ldl -lglfw3 -pthread -lm $(LIBMLX)/libmlx42.a
LIBFT = include/libft/libft.a
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(HEADERS) $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@cp $(LIBFT) $(LIB)
	@ar rcs $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(LIB)

clean:
	@rm -f $(OBJS)
	@make -C libft/ clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx