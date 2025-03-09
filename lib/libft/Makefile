# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emurillo <emurillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 16:54:42 by emurillo          #+#    #+#              #
#    Updated: 2025/02/28 16:55:07 by emurillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I.
NAME = libft.a
PRINTF_DIR = printf
GNL_DIR = get_next_line
LIBFT_DIR = libft_functions/
LIBFT_SOURCES = $(LIBFT_DIR)ft_atoi.c $(LIBFT_DIR)ft_isascii.c $(LIBFT_DIR)ft_memcmp.c $(LIBFT_DIR)ft_strchr.c $(LIBFT_DIR)ft_strlen.c $(LIBFT_DIR)ft_substr.c $(LIBFT_DIR)ft_bzero.c \
		  $(LIBFT_DIR)ft_isdigit.c $(LIBFT_DIR)ft_memcpy.c $(LIBFT_DIR)ft_strdup.c $(LIBFT_DIR)ft_strncmp.c $(LIBFT_DIR)ft_tolower.c $(LIBFT_DIR)ft_calloc.c \
		  $(LIBFT_DIR)ft_isprint.c $(LIBFT_DIR)ft_memmove.c $(LIBFT_DIR)ft_strjoin.c $(LIBFT_DIR)ft_strnstr.c $(LIBFT_DIR)ft_toupper.c\
		  $(LIBFT_DIR)ft_isalnum.c $(LIBFT_DIR)ft_itoa.c $(LIBFT_DIR)ft_memset.c $(LIBFT_DIR)ft_strlcat.c $(LIBFT_DIR)ft_strrchr.c \
		  $(LIBFT_DIR)ft_isalpha.c $(LIBFT_DIR)ft_memchr.c $(LIBFT_DIR)ft_split.c $(LIBFT_DIR)ft_strlcpy.c $(LIBFT_DIR)ft_strtrim.c $(LIBFT_DIR)ft_putchar_fd.c \
		  $(LIBFT_DIR)ft_putstr_fd.c $(LIBFT_DIR)ft_putendl_fd.c $(LIBFT_DIR)ft_putnbr_fd.c $(LIBFT_DIR)ft_strmapi.c $(LIBFT_DIR)ft_striteri.c

PRINTF_SOURCES = $(PRINTF_DIR)/ft_checkflags.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_putchar_fd_int.c \
				$(PRINTF_DIR)/ft_putnbr_pf.c $(PRINTF_DIR)/ft_putpointer.c $(PRINTF_DIR)/ft_putstr_fd_int.c \

GNL_SOURCES = $(GNL_DIR)/get_next_line_utils.c $(GNL_DIR)/get_next_line.c

BONUSSOURCES = $(LIBFT_DIR)ft_lstnew_bonus.c $(LIBFT_DIR)ft_lstadd_front_bonus.c $(LIBFT_DIR)ft_lstsize_bonus.c $(LIBFT_DIR)ft_lstlast_bonus.c \
			   $(LIBFT_DIR)ft_lstadd_back_bonus.c $(LIBFT_DIR)ft_lstdelone_bonus.c $(LIBFT_DIR)ft_lstclear_bonus.c $(LIBFT_DIR)ft_lstiter_bonus.c \
			   $(LIBFT_DIR)ft_lstmap_bonus.c

SOURCES = $(LIBFT_SOURCES) $(PRINTF_SOURCES) $(GNL_SOURCES)

OBJECTS = $(SOURCES:.c=.o)

BONUSOBJECTS = $(BONUSSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all $(BONUSOBJECTS)
	ar crs $(NAME) $(BONUSOBJECTS)

.PHONY: all clean fclean re
