CC = clang
CFLAGS = -Wall -Wextra -fsanitize=address -g

TARGET = breath_first_search
SRC_FILES = main.c utils.c graph.c
OBJ_FILES = $(SRC_FILES:.c=.o)

$(TARGET): $(OBJ_FILES)
	@echo "Linking object files"
	$(CC) $^ $(CFLAGS) -o $@
	@echo "Deleting all object files"
	rm -f $(OBJ_FILES)

%.o: %.c
	@echo "Compiling object files"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files and executable"
	rm -f $(OBJ_FILES) $(TARGET)

run:
	@echo "Running the main executable if exits"
	./$(TARGET)
