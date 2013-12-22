#    Copyright (C) 2013 LEVY-FALK Hugo
#
#    This program is free software; you can redistribute it and/or
#    modify it under the terms of the GNU Lesser General Public
#    License as published by the Free Software Foundation; either
#    version 2.1 of the License, or (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
#    Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public
#    License along with this program; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
.PHONY: clean, mrproper, archive
.SUFFIXES:

#variables
CC = gcc
EXEC = example/Menu
DEBUG = no
ifeq ($(DEBUG),yes)
	CFLAGS = -Wall -Wextra -Wunreachable-code -Wwrite-strings -Wstrict-prototypes
else
	CFLAGS =
endif

#création de l'exécutable
all: main.o menu.o
	mkdir example
	$(CC) $^ -o $(EXEC) $(CFLAGS)
	@echo "\033[31mMakefile: \033[32m \t> un exemple a été créé à partir du fichier src/main.c à cet endroit : $(EXEC)\n\t\t> 'make mrproper' pour réinitialiser le répertoire. \033[0m \n"

main.o: src/menu.h src/color.h

%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

# clean
clean:
	rm -rf *.o

# mrproper
mrproper: clean
	rm -rf Menu example Menu_API Menu_API.tar.gz 

#création d'une archive
archive:
	mkdir Menu_API
	cp -r ./COPYING Menu_API
	cp -r ./doc Menu_API
	cp -r ./Makefile Menu_API
	cp -r ./README.md Menu_API
	cp -r ./src Menu_API
	tar -czvf Menu_API.tar.gz ./Menu_API
	rm -r Menu_API
