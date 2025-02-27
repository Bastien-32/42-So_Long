LIBC = ft_printf.c \
	ft_putnbr_addr_ptr_pf.c ft_address_pf.c ft_putnbr_base_pf.c ft_strlen_pf.c\
	ft_putchar_pf.c ft_putnbr_pos_pf.c ft_putnbr_pf.c ft_putstr_pf.c \

SRC = ${LIBC}

OBJS = ${SRC:.c=.o}


NAME = libftprintf.a 

CC = gcc

FLAGS = -Wall -Werror -Wextra

%.o: %.c
		${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar -rsc ${NAME} ${OBJS}

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re