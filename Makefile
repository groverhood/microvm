
HEADERS = $(inc/m86def.h inc/m86as.h inc/m86cpu.h inc/m86fproto.h)
INCLUDE_DIRECTORY = ./inc
CC = gcc
OPT = -O4

all: mas mvm

mas: mas.o
	$(CC) build-microvm/mas.o -o build-microvm/mas

mas.o: src/mas/main.c $(HEADERS)
	$(CC) -I $(INCLUDE_DIRECTORY) -c src/mas/main.c -o build-microvm/mas.o $(OPT)

mvm: mvm.o m86.o
	$(CC) build-microvm/mvm.o build-microvm/m86.o -o build-microvm/mvm

mvm.o: src/microvm/main.c $(HEADERS)
	$(CC) -I $(INCLUDE_DIRECTORY) -c src/microvm/main.c -o build-microvm/mvm.o $(OPT)

m86.o: src/microvm/m86.c $(HEADERS)
	$(CC) -I $(INCLUDE_DIRECTORY) -c src/microvm/m86.c -o build-microvm/m86.o $(OPT)

clean:
	rm build-microvm/*