# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:22:50 by lilefebv          #+#    #+#              #
#    Updated: 2024/11/05 13:43:19 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
CC    = cc
LISTC = ft_isalpha.c ft_memset.c
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