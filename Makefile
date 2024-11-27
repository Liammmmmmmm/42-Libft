# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:22:50 by lilefebv          #+#    #+#              #
#    Updated: 2024/11/27 13:25:08 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Library name
NAME       = libft.a
HEADER     = libft.h

# Colors
GREEN      = \033[0;32m
NC         = \033[0m

# Compiler and flags
CC         = cc
CFLAGS     = -Wall -Wextra -Werror
AR         = ar -rsc

# Source files
SRC        = fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c fd/ft_putstr_fd.c       \
             memory/ft_bzero.c memory/ft_calloc.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c  \
             ft_split.c ft_atoi.c  ft_isalnum.c ft_isalpha.c ft_isascii.c         \
             ft_isdigit.c ft_isprint.c ft_itoa.c          \
               ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c    \
             ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c    \
             ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c                 \
             ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
             ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c 
             ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstdelmiddle.c

# Object files directory
OBJ_DIR    = .obj/
OBJ        = $(SRC:%.c=$(OBJ_DIR)%.o)

%.o : %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
    @echo "$(GREEN)Compiling $<...$(NC)"
    @$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(LISTO)
	@echo "$(GREEN)Creating library $(NAME)...$(NC)"
	$(AR) $@ $?

clean :
	@echo "$(GREEN)Cleaning object files...$(NC)"
    @rm -rf $(OBJ_DIR)

fclean : clean
	@echo "$(GREEN)Removing library $(NAME)...$(NC)"
    @rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re