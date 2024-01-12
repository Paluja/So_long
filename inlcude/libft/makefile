# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 16:55:21 by pjimenez          #+#    #+#              #
#    Updated: 2024/01/11 17:16:04 by pjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a

PRINTF = Printf/libftprintf.a

RM = rm -f

FILES = ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strncmp.c ft_strrchr.c ft_bzero.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(LIB)

$(LIB): $(PRINTF) $(OBJS)
	@cp	$(PRINTF) $(LIB)
	@ar rcs $(PRINTF) $(OBJS)
	@ar rcs $(LIB) $(OBJS)	

$(PRINTF):
	make -C Printf/ all
$(OBJS): $(FILES)
	@gcc $(FLAGS) -c $(FILES)


	
clean:
	make -C Printf/ clean
	@$(RM) -rf $(OBJS)
	
fclean: clean
	make -C Printf/ fclean
	@$(RM) -f $(LIB)
	
re: fclean all

.PHONY: all clean fclean re