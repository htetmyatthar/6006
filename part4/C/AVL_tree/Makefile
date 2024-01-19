CC = gcc
CFLAGS = -Wall -Wextra -g
# for math.h library
# LDFLAGS = -lm

TARGET = avl_tree
SRC_FILES = main.c utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

VALFLAGS = -s --leak-check=full

$(TARGET): $(OBJ_FILES)
	@echo "Linking object files"
	$(CC) $^ -o $@ #$(LDFLAGS)
	@echo "Deleting all object files"
	rm -f $(OBJ_FILES)

%.o: %.c
	@echo "Compiling object files"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files and executable"
	rm -f $(OBJ_FILES) $(TARGET)

run:
	@echo "Running the executable if exits."
	./$(TARGET)

valgrind:
	@echo "Running memory checks."
	valgrind $(VALFLAGS) ./$(TARGET)
