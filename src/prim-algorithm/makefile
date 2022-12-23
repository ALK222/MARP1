CC = g++
CFLAGS = -g -Wall

EXT :=
ifeq ($(OS), Windows_NT)
	EXT = .exe
else
	EXT = .out
endif

OBJDIR = ./obj
BINDIR = ./bin

.PHONY: all
all: ./obj/graph.o ./bin/Prim-algo$(EXT)

./bin/Prim-algo$(EXT): ./obj/graph.o main.cpp
	$(CC) $(CFLAGS) main.cpp $(OBJDIR)/graph.o -o $(BINDIR)/Prim-algo$(EXT)

.PHONY: prueba
prueba: ./obj/graph.o ./bin/Prim-algo-prueba$(EXT)

./bin/Prim-algo-prueba$(EXT): ./obj/graph.o main.cpp
	$(CC) $(CFLAGS) main.cpp $(OBJDIR)/graph.o -o $(BINDIR)/Prim-algo-prueba$(EXT) -D __PRUEBA__

./obj/graph.o: ./graph/graph.cpp
	$(CC) $(CFLAGS) -c ./graph/graph.cpp -o $(OBJDIR)/graph.o

.PHONY: clean
clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*
