# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:22:50 by lilefebv          #+#    #+#              #
#    Updated: 2024/11/08 16:15:01 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FLAGS      = -Wall -Wextra -Werror
CC         = cc
NAME       = libft.a
LISTC      = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
LISTO      = $(LISTC:.c=.o)
LISTCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c
LISTOBONUS = $(LISTCBONUS:.c=.o)


%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(LISTO)
	ar -rsc $@ $?

clean :
	rm -f $(LISTO) $(LISTOBONUS)

fclean : clean
	rm -f libft.a

re : fclean all

bonus : $(LISTO) $(LISTOBONUS)
	ar -rsc $(NAME) $?

.PHONY: all clean fclean re bonus
