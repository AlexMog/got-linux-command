NAME=	bin/got

PREFIX=	/usr/local

SRCDIR=	src/

MAN=	man/got.1

SRC=	$(SRCDIR)main.c \
	$(SRCDIR)rand_utils.c

OBJ=	$(SRC:.c=.o)

RM=	rm -f

CC=	gcc

CFLAGS=	-W -Wall -Wextra -pedantic -Iinclude

LDFLAGS=-o $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

install:all
	install -m 755 $(NAME) $(PREFIX)/games
	install -m 644 $(MAN) $(PREFIX)/man/man1

.PHONY: clean fclean all install