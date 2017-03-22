# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 21:27:58 by rishchen          #+#    #+#              #
#    Updated: 2017/03/21 22:10:13 by rishchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c additionalfunc.c brains.c changes.c createbd.c draw.c validator.c\
	  fuct_win_help.c get_next_line.c projections.c rotate.c

INC = -I fdf.h

OBJ = $(SRC:.c=.o)

LIBOBJ = make -C libft/

CFLAGS = -c -Wall -Werror -Wextra

MLXCFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBINC = -L./libft -lft

all: $(NAME)

obj: $(OBJ)

$(NAME) : liball obj
		gcc  $(LIBINC) $(OBJ) $(MLXCFLAGS) -o $(NAME)
%.o: %.c
		gcc $(CFLAGS) -o $@ $<

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

liball:
		@make -C libft/ all

libclean:
		@make -C libft/ clean

libfclean:
		@make -C libft/ fclean

libre: libfclean liball
