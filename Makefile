CC=gcc
CCFLAGS=-c -Wall
LDFLAGS=-Wall

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
