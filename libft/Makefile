# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 18:00:37 by rishchen          #+#    #+#              #
#    Updated: 2016/12/14 18:13:26 by rishchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

HEADER = libft.h

SRC = ft_atoi.c\
	  ft_strlen.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_strdup.c\
	  ft_strcpy.c\
	  ft_strcmp.c\
	  ft_strncpy.c\
	  ft_memchr.c\
	  ft_bzero.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_memccpy.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_strchr.c\
	  ft_strncmp.c\
	  ft_strnstr.c\
	  ft_strstr.c\
	  ft_strrchr.c\
	  ft_strlcat.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strncpy.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putnbr.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_det_mat.c\
	  ft_sort_mas.c\
	  ft_reverse_string.c\
	  ft_rev_mat.c\
	  ft_pow.c

OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean	all
