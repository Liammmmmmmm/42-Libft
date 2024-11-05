# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:22:50 by lilefebv          #+#    #+#              #
#    Updated: 2024/11/05 16:50:55 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
CC    = cc
LISTC = ft_isalpha.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c
LISTO = $(LISTC:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

all : libft.a

libft.a : $(LISTO)
	ar -rsc $@ $?


clean :
	rm -f $(LISTO)

fclean : clean
	rm -f libft.a

re : fclean all

.PHONY: all clean fclean re