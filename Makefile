# Todd Hickam: Created for PSU CS_333 Winter Term 2022 - 2023

CC = gcc
DEBUG = -g
CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls \
-Wmissing-declarations -Wold-style-definition -Wmissing-prototypes \
-Wdeclaration-after-statement -Wno-return-local-addr \
-Wuninitialized -Wextra -Wunused -Wunsafe-loop-optimizations

# make file (), versus .env variables {}
PRIMEC = primesMT
WRITE = write
PRIMEH = primesMT
OUT = $(PRIMEC)
TAR_FILE = ${LOGNAME}_$(MAIN).tar.gz
DIR = $(shell basename $(PWD))

all: $(PRIMEC)

$(PRIMEC): $(PRIMEC).o $(WRITE).o
	$(CC) $(CFLAGS) -o $(OUT) $(PRIMEC).o $(WRITE).o -lm -pthread
	chmod og-rx $(OUT)

# -c: produce .o but do NOT link
$(PRIMEC).o: $(PRIMEC).c $(PRIMEH).h
	$(CC) $(CFLAGS) -c $(PRIMEC).c

$(WRITE).o: $(WRITE).c $(WRITE).h
	$(CC) $(CFLAGS) -c $(WRITE).c

bash b test:
	bash testPrimes.bash

# clean up the compiled files and editor chaff
clean cls:
	rm -f $(OUT) primes.txt *.gz *.o *~ \#*

ci:
	if [ ! -d RCS ] ; then mkdir RCS; fi
	ci -t-none -m"lazy-checkin" -l *.[ch] ?akefile *.bash

# Will Clean and Make the .tar.gz for Canvas, placed in upper directory, $ cd ..
canvas:
	make clean
	 rm *.txt ; cd .. ; tar --exclude-backups --exclude-vcs -c -a -f ./${LOGNAME}-$(DIR)-psush.tar.gz $(DIR)
