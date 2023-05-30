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

OBJDIR = ../../obj
BINDIR = ../../bin

.PHONY: all
all: $(OBJDIR)/$(LIB).o $(BINDIR)/$(OUT)$(EXT)

$(BINDIR)/$(OUT)$(EXT): $(OBJDIR)/$(LIB).o main.cpp
	$(CC) $(CFLAGS) main.cpp $(OBJDIR)/$(LIB).o -o $(BINDIR)/$(OUT)$(EXT)

.PHONY: prueba
prueba: $(OBJDIR)/$(LIB).o $(BINDIR)/$(OUT)-prueba$(EXT)

.PHONY: lib
lib: $(OBJDIR)/$(LIB).o

$(BINDIR)/$(OUT)-prueba$(EXT): $(OBJDIR)/$(LIB).o main.cpp
	$(CC) $(CFLAGS) main.cpp $(OBJDIR)/$(LIB).o -o $(BINDIR)/$(OUT)-prueba$(EXT) -D __PRUEBA__

$(OBJDIR)/$(LIB).o: ./$(LIB)/$(LIB).cpp
	$(CC) $(CFLAGS) -c ./$(LIB)/$(LIB).cpp -o $(OBJDIR)/$(LIB).o

.PHONY: clean
clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*
