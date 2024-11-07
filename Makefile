# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:22:50 by lilefebv          #+#    #+#              #
#    Updated: 2024/11/07 17:00:34 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
CC    = cc
NAME= libft.a
LISTC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LISTO = $(LISTC:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(LISTO)
	ar -rsc $@ $?


clean :
	rm -f $(LISTO)

fclean : clean
	rm -f libft.a

re : fclean all

.PHONY: all clean fclean re
