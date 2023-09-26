CC = g++
CFLAGS = -g -Wall


OUT = bin/Prueba

EXT :=
ifeq ($(OS), Windows_NT)
	EXT = .exe
else
	EXT = .out
endif

OBJDIR = ./obj
BINDIR = ./bin

.PHONY: all
all: ./bin/$(OUT)$(EXT)

./bin/$(OUT)$(EXT): ./Main.cpp
	$(CC) $(CFLAGS) Main.cpp -o ./$(OUT)$(EXT)
.PHONY: clean
clean:
	rm -rf *.out
