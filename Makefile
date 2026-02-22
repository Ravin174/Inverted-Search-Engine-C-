# [cite: 2] Compiler
CC = gcc

# [cite: 2] Compiler flags (-g for debugging, -Wall for all warnings)
CFLAGS = -g -Wall

# [cite: 2] Target executable name
TARGET = inverted_search

# [cite: 2] List of all source files
SRCS = main.c \
       create_database.c \
       display_database.c \
       read_and_validate.c \
       search.c \
       store_word.c \
       save_database.c \
       update_database.c

# [cite: 3] List of object files (automatically replaces .c with .o)
OBJS = $(SRCS:.c=.o)

# [cite: 3] Default rule to build the project
all: $(TARGET)

# [cite: 3] Rule to link the object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# [cite: 3] Rule to compile .c files to .o files
%.o: %.c inverted_search.h
	$(CC) $(CFLAGS) -c $< -o $@

# [cite: 3] Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# [cite: 3] Rule to rebuild from scratch
rebuild: clean all