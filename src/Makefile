GCC_FLAGS = -Wall -Werror -Wextra -std=c11
SANITAIZER = -g -fsanitize=address
TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
EXE = test.out

SRC_STRING_DIR = ./s21_string_funcs
SRC_STDIO_DIR = ./s21_stdio_funcs
TEST_DIR = ./tests
OBJ_DIR = ./objs
TEST_OBJ_DIR = ./tests/objs
BUILD_PATH = ./

SRC_C_FILES := $(wildcard $(SRC_STRING_DIR)/*.c $(SRC_STDIO_DIR)/*.c)
OBJS_C_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_C_FILES:.c=.o)))

TEST_C_FILES := $(wildcard $(TEST_DIR)/tests.c  $(TEST_DIR)/s21_string_funcs/test_*.c $(TEST_DIR)/s21_stdio_funcs/handles/test_*.c $(TEST_DIR)/s21_stdio_funcs/test_*.c)
OBJS_TEST_FILES := $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_C_FILES:.c=.o)))

HEADERS = s21_string.h

.PHONY: all rebuild test gcov_report clean format check_format edit_format

all: format s21_string.a

rebuild: clean all

test: $(OBJS_TEST_FILES) s21_string.a tests.o
	gcc $(OBJS_TEST_FILES) $(OBJS_C_FILES) $(TEST_FLAGS) -o $(EXE)
	./$(EXE)

valgrind: $(OBJS_TEST_FILES) s21_string.a tests.o
	gcc $(OBJS_TEST_FILES) $(OBJS_C_FILES) $(TEST_FLAGS) -o $(EXE)
	valgrind --leak-check=full --track-origins=yes ./$(EXE)

$(EXE): $(OBJS_TEST_FILES) s21_string.a
	gcc $(GCC_FLAGS) $(OBJS_TEST_FILES) $(OBJS_C_FILES) $(TEST_FLAGS) -o $@

s21_string.a: $(OBJS_C_FILES)
	ar rcs $@ $^
	ranlib $@

tests.o: tests/tests.c $(HEADERS)
	gcc $(GCC_FLAGS) $(TEST_FLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/tests.o: $(TEST_DIR)/tests.c $(HEADERS) | $(TEST_OBJ_DIR)
	gcc $(GCC_FLAGS) $(TEST_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_STRING_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	gcc $(GCC_FLAGS) $(TEST_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_STDIO_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	gcc $(GCC_FLAGS) $(TEST_FLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/s21_string_funcs/%.c $(HEADERS) | $(TEST_OBJ_DIR)
	gcc $(GCC_FLAGS) $(TEST_FLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/s21_stdio_funcs/handles/%.c $(HEADERS) | $(TEST_OBJ_DIR)
	gcc $(GCC_FLAGS) $(TEST_FLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/s21_stdio_funcs/%.c $(HEADERS) | $(TEST_OBJ_DIR)
	gcc $(GCC_FLAGS) $(TEST_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(TEST_OBJ_DIR):
	mkdir -p $@


gcov_report: s21_string.a
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) --coverage $(TEST_C_FILES) $(SRC_C_FILES) s21_string.a -L. s21_string.a $(TEST_FLAGS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov -t "Report" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/
	xdg-open $(BUILD_PATH)report/index.html

clean:
	rm -rf *.a *.o *.out *.info *.gcno *.gcov *.gcda
	rm -rf $(OBJ_DIR) $(TEST_OBJ_DIR) report report_filtered
	rm -f $(EXE)
	rm -f vgcore.*
	rm -f s21_string.h.

format: check_format edit_format

check_format:
	clang-format -style=Google -n $(SRC_C_FILES) $(TEST_C_FILES) $(HEADERS)

edit_format:
	clang-format -style=Google -i $(SRC_C_FILES) $(TEST_C_FILES) $(HEADERS)
