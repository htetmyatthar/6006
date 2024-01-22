CC = clang
CFLAGS = -Wall -Wextra -fsanitize=address -g
# for math.h library
# LDFLAGS = -lm

TARGET = max_heap
SRC_FILES = main.c utils.c dynamic_array.c
OBJ_FILES = $(SRC_FILES:.c=.o)

TARGET_D = dynamic_array_test
SRC_FILES_D = dynamic_array_test.c dynamic_array.c
OBJ_FILES_D = $(SRC_FILES_D:.c=.o)

$(TARGET): $(OBJ_FILES)
	@echo "Linking object files"
	$(CC) $^ $(CFLAGS) -o $@ 
	@echo "Deleting all object files"
	rm -f $(OBJ_FILES)

$(TARGET_D): $(OBJ_FILES_D)
	@echo "Linking object files"
	$(CC) $^ $(CFLAGS) -o $@ 
	@echo "Deleting all object files"
	rm -f $(OBJ_FILES_D)

%.o: %.c
	@echo "Compiling object files"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files and executable"
	rm -f $(OBJ_FILES) $(TARGET) $(OBJ_FILES_D) $(TARGET_D)

run:
	@echo "Running the main executable if exits."
	./$(TARGET)

test:
	@echo "Running the test executables if exits."
	./$(TARGET_D)
