CC=gcc
CCFLAGS=-c -g -Wall
LDFLAGS=-g -Wall -lm

LINK=$(CC) $(LDFLAGS) -o
COMPILE=$(CC) $(CCFLAGS) -c

# Directories
SRCDIR=./src
OBJDIR=./obj
BINDIR=./bin

# Files
OBJ=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(wildcard $(SRCDIR)/*.c))
BIN=$(BINDIR)/0


all: $(BIN)

$(BIN): $(OBJ)
	$(LINK) $(BIN) $(OBJ)

$(OBJDIR)/%.o:  $(SRCDIR)/%.c
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
