CC = gcc
CFLAGS = -Wall -Wextra `sdl2-config --cflags` -Iinclude
LDFLAGS = `sdl2-config --libs` -lm

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
EXECUTABLE = main

# Automatically find all source and header files
SOURCES := $(wildcard $(SRCDIR)/*.c) main.c
HEADERS := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(SOURCES:%.c=$(OBJDIR)/%.o)

# Ensure necessary directories exist
$(shell mkdir -p $(OBJDIR) $(BINDIR) $(patsubst %,$(OBJDIR)/%,$(shell find $(SRCDIR) -type d)))

all: $(BINDIR)/$(EXECUTABLE)

# Link all object files into the final executable
$(BINDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile each .c file into a .o file
$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)  # Ensure obj/src/ exists
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)/$(EXECUTABLE)
