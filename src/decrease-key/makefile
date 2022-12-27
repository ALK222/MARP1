CC = g++
CFLAGS = -g -Wall

LIB = williams-heap

OUT = Williams-decrease

EXT :=
ifeq ($(OS), Windows_NT)
	EXT = .exe
else
	EXT = .out
endif

OBJDIR = ./obj
BINDIR = ./bin

.PHONY: all
all: ./obj/$(LIB).o ./bin/$(OUT)$(EXT)

./bin/$(OUT)$(EXT): ./obj/$(LIB).o main.cpp
	$(CC) $(CFLAGS) main.cpp $(OBJDIR)/$(LIB).o -o $(BINDIR)/$(OUT)$(EXT)

.PHONY: prueba
prueba: ./obj/$(LIB).o ./bin/$(OUT)-prueba$(EXT)

./bin/$(OUT)-prueba$(EXT): ./obj/$(LIB).o main.cpp
	$(CC) $(CFLAGS) main.cpp $(OBJDIR)/$(LIB).o -o $(BINDIR)/$(OUT)-prueba$(EXT) -D __PRUEBA__

./obj/$(LIB).o: ./$(LIB)/$(LIB).cpp
	$(CC) $(CFLAGS) -c ./$(LIB)/$(LIB).cpp -o $(OBJDIR)/$(LIB).o

.PHONY: clean
clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*
