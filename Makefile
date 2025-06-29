# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 14:22:50 by lilefebv          #+#    #+#              #
#    Updated: 2025/06/13 16:25:42 by lilefebv         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Library name
NAME     = libft.a

# STYLE
GREY     = \033[0;30m
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
PURPLE   = \033[0;35m
CYAN     = \033[0;36m
WHITE    = \033[0;37m

BOLD     = \033[1m
UNDER    = \033[4m
REV      = \033[7m
BLINK    = \033[5m

NC       = \033[0;0m
ERASE    = \033[2K\r
ERASE2   = $(ERASE)\033[F$(ERASE)

# Compiler and flags
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -o3
AR       = ar -rsc

# Includes
INCLUDES = -I includes/

# Source files
SRC_DIR  = srcs/
SRCS     = fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c fd/ft_putstr_fd.c                                                                                                                                                                                            \
           memory/ft_bzero.c memory/ft_calloc.c memory/ft_memchr.c memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c                                                                                                                                 \
           lists/ft_lstnew_bonus.c lists/ft_lstadd_front_bonus.c lists/ft_lstsize_bonus.c lists/ft_lstlast_bonus.c lists/ft_lstadd_back_bonus.c lists/ft_lstdelone_bonus.c lists/ft_lstclear_bonus.c lists/ft_lstiter_bonus.c lists/ft_lstmap_bonus.c lists/ft_lstdelmiddle.c   \
           char/ft_tolower.c char/ft_toupper.c char/ft_isalnum.c char/ft_isspace.c char/ft_isalpha.c char/ft_isascii.c char/ft_isdigit.c char/ft_isprint.c                                                                                                                                        \
           str/ft_str_tolower.c str/ft_atoi.c str/ft_atoi_base.c str/ft_atof.c str/ft_itoa.c str/ft_split.c str/ft_count_words.c str/ft_free_tab.c str/ft_free_tab_int.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c str/ft_strjoin.c str/ft_strjoin_free.c str/ft_strjoin_free_buff.c str/ft_strlcat.c str/ft_strlcpy.c str/ft_strlen.c str/ft_sstrlen.c str/ft_strmapi.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c str/ft_substr.c \
		   printf/ft_printf.c                                                                                                                                                                                                                     \
		   get_next_line/get_next_line.c                                                          \
		   params_to_string/params_to_string.c params_to_string/types.c params_to_string/more_types.c  \
		   vector/vector.c  \
		   read_bin/read_file.c read_bin/bin_utils.c read_bin/read_8_bits.c read_bin/read_16_bits.c read_bin/read_32_bits.c read_bin/read_64_bits.c \
		   read_bin/read_16_bits_little.c read_bin/read_32_bits_little.c read_bin/read_64_bits_little.c \
		   utils/get_cpu_time.c \
		   maths/abs.c

# Object files directory
OBJ_DIR  = .obj/
OBJ      = $(SRCS:%.c=$(OBJ_DIR)%.o)

# Remake all if modified
REMAKE   = includes/libft.h includes/ft_printf.h includes/get_next_line.h includes/read_bin.h Makefile

# Variables for progress bar
TOTAL_FILES		:=	$(words $(SRCS))
MODIFIED_FILES  := $(shell if [ -f $(NAME) ]; then                                                             \
                        if [ `for file in $(REMAKE); do find $$file -newer $(NAME); done | wc -l` -gt 0 ]; then \
                            echo $(TOTAL_FILES);                                                                 \
                        else                                                                                      \
                            for file in $(SRCS); do \
                                obj_file=$(OBJ_DIR)$${file%.c}.o; \
                                if [ $(SRC_DIR)$$file -nt $(NAME) ] || [ ! -f $$obj_file ]; then \
                                    echo $$file; \
                                fi; \
                            done | wc -l; \
                        fi;                                                                                         \
                    else                                                                   \
                        for file in $(SRCS); do                                         \
                            obj_file=$(OBJ_DIR)$${file%.c}.o; \
                            if [ ! -f $$obj_file ] || [ $(SRC_DIR)$$file -nt $$obj_file ]; then \
                                echo $$file; \
                            fi; \
                        done | wc -l; fi)
COMPILED_FILES	:=	0
PERCENT			:=	0
BAR_WIDTH		:=	41

REPEAT_CHAR		=	$(if $(filter-out 0,$2),$(shell seq 1 $2 | xargs -I@ printf "$1"),)

# Pattern rule for object files
$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(REMAKE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)
	@$(eval COMPILED_FILES := $(shell expr $(COMPILED_FILES) + 1))
	@if [ $(MODIFIED_FILES) -ne 0 ]; then                                                                               \
		$(eval PERCENT := $(shell echo $$(($(COMPILED_FILES) * 100 / $(MODIFIED_FILES)))))                               \
		$(eval PROGRESS := $(shell echo $$(($(PERCENT) * $(BAR_WIDTH) / 100))))                                           \
		$(eval EMPTY := $(shell echo $$(($(BAR_WIDTH) - $(PROGRESS)))))                                                    \
		printf "$(ERASE2)$(GREEN)[Compiling] $(NC)$(shell echo $< | sed 's|^srcs/||')\n";                                   \
		printf "\n$(YELLOW)[$(call REPEAT_CHAR,⣿,$(PROGRESS))$(call REPEAT_CHAR, ,$(EMPTY))]${NC} ${NC}${PERCENT}%%${NC}\r"; \
	fi

all : start_message $(NAME)

start_message:
	@if [ ! -f $(NAME) ] || [ $(MODIFIED_FILES) != 0 ]; then                                                \
		echo "\n$(YELLOW)╔══════════════════════════════════════════════╗$(NC)";                             \
		echo "$(YELLOW)║       Starting $(YELLOW)$(BOLD)$(NAME)$(YELLOW) compilation...        ║$(NC)";       \
		echo "$(YELLOW)╚══════════════════════════════════════════════╝$(NC)\n\n";                             \
	fi

end_message:
	@echo "$(GREEN)\n╔══════════════════════════════════════════════╗$(NC)"
	@echo "$(GREEN)║$(NC)       _____                                  $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)      /     \                                 $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)      vvvvvvv  /|__/|                         $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)         I   /O,O   |                         $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)         I /_____   |      /|/|               $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)        J|/^ ^ ^ \  |    /00  |    _//|       $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)         |^ ^ ^ ^ |W|   |/^^\ |   /oo |       $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)          \m___m__|_|    \m_m_|   \mm_|       $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(NC)                                              $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(BLUE)  Your libft has been successfully compiled!  $(GREEN)║$(NC)"
	@echo "$(GREEN)║$(BLUE) Totoro ensures your libft is ready for prod. $(GREEN)║$(NC)"
	@echo "$(GREEN)╚══════════════════════════════════════════════╝$(NC)"

$(NAME) : $(OBJ)
	@echo "\n\n$(GREEN)[Creating library] $(NC)$(NAME)"
	@$(AR) $@ $?
	@make --no-print-directory end_message

clean :
	@echo "$(RED)[Removing] $(NC)object files"
	@rm -rf $(OBJ_DIR)

fclean : clean
	@if [ -f $(NAME) ]; then                         \
        echo "$(RED)[Removing] $(NC)library $(NAME)"; \
        rm -f $(NAME);                                \
    fi

re : fclean
	@make --no-print-directory all

.PHONY: all clean fclean re start_message end_message

