# src/Makefile
# hist 

SHELL=		/bin/sh
INSTALL=	/usr/local/lib
AR=			ar
AROPTS=		rcs
LIB=		libhist.a

SRC=		hist.c
OBJ=		$(SRC:.c=.o)
VERSION=	0.0.1a
OPTS=		-DVERSION=\"$(VERSION)\" #-DNDEBUG

CC =		gcc
## Position independent code is not necessary for archives.
CFLAGS=		-std=c99 -fPIC -pedantic-errors -g -Wall -Werror -O1

.SUFFIXES: .c .o

all: archive 

archive: $(OBJ)
	@echo -ne \\t Adding $(OBJ) to $(LIB) ..
	@$(AR) $(AROPTS) $(LIB) $(OBJ)
	@echo " done."

.c.o:
	@echo -ne \\t Compiling $< ..
	@$(CC) -c $(OPTS) $(CFLAGS) $<
	@echo " done."

install:
	@echo -ne \\t Installing executable to $(INSTALL) ..
	@${SUDO} cp $(LIB) $(INSTALL)
	@echo " done."

clean:
	@echo -ne \\t Removing object files ..
	@rm -f $(LIB) *.o
	@echo " done."

.PHONY: clean all
