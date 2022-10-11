NAME = pipex

CC = gcc

FLAG = -g -Wall -Werror -Wextra 

SRC=	src/parsing.c	\
	src/main.c	\
	src/files.c \
	src/redirexec.c \
	src/utils.c

OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -I include -c $< -o $(<:.c=.o)


INC = include/pipex.h

INC_LIBFT = include/libft.h

LIB = libft.a


all:	$(LIB) $(NAME)

$(NAME):	$(OBJ) $(INC) $(INC_LIBFT)
	$(CC) $(FLAG) $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ) libft.a

fclean:	clean
	rm -f $(NAME)

$(LIB)	:
	make -C ./libft/
	rm -f libft.a
	cp libft/libft.a .


re			: fclean all 


.PHONY: all clean fclean re 


