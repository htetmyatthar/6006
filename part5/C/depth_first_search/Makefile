CC = clang
#dwarf version of clang v5, uses v4 for valgrind compatibility
CFLAGS = -gdwarf-4 -Wall -Wextra
DBFLAGS = -glldb

TARGET = depth_first_search
SRC_FILES = main.c utils.c graph.c
OBJ_FILES = $(SRC_FILES:.c=.o)

$(TARGET): $(OBJ_FILES)
	@echo "Linking object files"
	$(CC) $(CFLAGS) $(DBFLAGS) $^ -o $@
	@echo "Deleting all object files"
	rm -f $(OBJ_FILES)

%.o: %.c
	@echo "Compiling object files"
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< -o $@

clean:
	@echo "Removing object files and executable"
	rm -f $(OBJ_FILES) $(TARGET)

run:
	@echo "Running the main executable if exits"
	./$(TARGET)

valgrind:
	@echo "Memcheck using valgrind."
	valgrind --leak-check=full ./$(TARGET)
