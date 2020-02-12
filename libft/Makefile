# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/12 10:39:05 by lvan-bei          #+#    #+#              #
#    Updated: 2019/01/24 18:57:35 by lvan-bei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLGS = -Wall -Werror -Wextra
SRC = ft_bzero.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_strndup.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_atoi.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_freentab.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_strlenword.c\
	  ft_strnword.c\
	  get_next_line.c\
	  ft_sqrt.c\
	  ft_power.c\
	  ft_split_whitespace.c\

OBJ =  $(SRC:.c=.o)
INC = libft.h

.PHONY: clean fclean

$(NAME):
	gcc $(CFLGS) -c $(SRC) -I $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
