# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 23:18:07 by mavileo           #+#    #+#              #
#    Updated: 2019/12/06 06:41:27 by mavileo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=    ft_atoi.c       		\
		ft_check_convers.c      \
		ft_count_convers.c      \
		ft_isdigit.c    \
		ft_itoa_base.c       \
		ft_loop.c    	\
		ft_newlist.c     \
		ft_precision.c     \
		ft_print_nb.c     \
		ft_print_c.c     \
		ft_print_s.c     \
		ft_print_x.c     \
		ft_print_u.c     \
		ft_print_p.c     \
		ft_print_pc.c     \
		ft_printf.c  \
		ft_putchar.c  \
		ft_putnbr.c      \
		ft_putstr.c     \
		ft_strdup.c     \
		ft_putunsign.c    \
		ft_strlen.c     \
		ft_type.c    \
		ft_which_type.c    \
		ft_lstclear.c    \

NAME= libftprintf.a

OBJETS= ${SRC:.c=.o}


gcc=gcc -Werror -Wall -Wextra

%.o: %.c
	${gcc} -o $@ -c $<

$(NAME):    ${OBJETS}
			ar -rc ${NAME} $^
			ranlib ${NAME}

all: ${NAME}

re: fclean all

clean:
		rm -f ${OBJETS}

fclean: clean
		rm -f ${NAME}

.PHONY: all clean fclean re