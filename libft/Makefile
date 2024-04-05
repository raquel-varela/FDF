# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 16:32:34 by rvarela           #+#    #+#              #
#    Updated: 2024/04/05 16:35:48 by rvarela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = 		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_atoi_hex.c ft_strncpy.c \
			ft_printf/ft_printf.c ft_printf/ft_printf_auxf.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

#Create libft.a
all: $(NAME)

#create .o files; also default compilation
# $< first prerequisite aka .c; $@ output/target file aka .o;\
-I. include header files that are in the current directory
%.o.: %.c
	cc $(FLAGS) -c $< -I. -o $@

#create and index library (ar - archive, -r insert files by replacement,\
 -c create the archve, -s index the files
#Mandatory part
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

#Bonus part
bonus: $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)

#Clean generated .o files
clean:
	rm -f $(OBJ) $(OBJ_BONUS)

#Force clean all files generated on all - Remove static library
fclean: clean
	rm -f $(NAME)

#reset environment - remove everything and recompile
re: fclean all

#targets declared as .PHONY will force the command even if there is\
 a subdirectory or file with it's name
.PHONY: all bonus clean fclean re