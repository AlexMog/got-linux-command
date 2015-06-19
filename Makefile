BINNAME=got

NAME=	bin/$(BINNAME)

PREFIX=	/usr/local

PKGDIR= packaging/

PKGNAME=got.deb

SRCDIR=	src/

MANNAME=got.1

MAN=	man/$(MANNAME)

SRC=	$(SRCDIR)main.c \
	$(SRCDIR)rand_utils.c

OBJ=	$(SRC:.c=.o)

RM=	rm -f

CC=	gcc

CFLAGS=	-W -Wall -Wextra -pedantic -Iinclude

LDFLAGS=-o $(NAME)

CP=	cp

$(NAME):$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(PKGNAME)
	$(RM) $(PKGDIR)$(PREFIX)/games/$(BINNAME)
	$(RM) $(PKGDIR)$(PREFIX)/man/man1/$(MANNAME)

install:all
	install -m 755 $(NAME) $(PREFIX)/games
	install -m 644 $(MAN) $(PREFIX)/man/man1

package:all
	$(CP) $(NAME) $(PKGDIR)$(PREFIX)/games/
	$(CP) $(MAN) $(PKGDIR)$(PREFIX)/man/man1/
	dpkg-deb --build packaging
	mv packaging.deb $(PKGNAME)

.PHONY: clean fclean all install