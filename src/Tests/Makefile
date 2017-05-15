CC=gcc
#SOURCES= mont.c tmp.c
SOURCES=main.c
BENCHSOURCES=bench.c mont_fpe.c vec_dsw.c
CFLAGS= -msse3 -g
LIBS= -ldgk -lgmp -lm 
LIBPATH=-L.
INCPATH=-I../.
BIN=test

all:
	$(CC) $(CFLAGS)  $(SOURCES) -o $(BIN) $(INCPATH)  $(LIBPATH) $(LIBS) 
