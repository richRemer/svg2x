CC = gcc
CFLAGS = -g -Wall
SRCDIR = src
BUILDDIR = build
BINDIR = bin
TARGET = $(BINDIR)/svg2x
VPATH = $(SRCDIR)

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
HEADERS = $(wildcard $(SRCDIR)/*.h)

$(BUILDDIR)/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall -o $@

clean:
	-rm -f $(BUILDDIR)/*.o
	-rm -f $(TARGET)
