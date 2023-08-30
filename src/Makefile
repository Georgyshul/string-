# =  // A Recursive assignment expression is evaluated everytime the variable is encountered in the code
# :=  // A simple assignment expression is evaluated only once, at the very first occurrence
# ?=  // Conditional assignment assigns a value to a variable only if it does not have a value 

# @  // Command prefix - dont print command
# $@  // Target
# $(dir $@)  // Directory part of the target
# $<  // First goal of target

CC=gcc

SRC_STRING_DIR = s21_string
SRC_SPRINTF_DIR = s21_sprintf
SRC_SSCANF_DIR = s21_sscanf

TEST_DIR = test

SRC_STRING := $(shell find ${SRC_STRING_DIR} -name "s21_*.c" | sed -e 's/\.\///')
SRC_SPRINTF := $(shell find ${SRC_SPRINTF_DIR} -name "*.c" | sed -e 's/\.\///')
SRC_SSCANF := $(shell find ${SRC_SSCANF_DIR} -name "*.c" | sed -e 's/\.\///')
SRC_TEST := $(shell find ${TEST_DIR} -name "*.c" | sed -e 's/\.\///')

BUILD_DIR = obj
BUILD_TEST_DIR = obj_tests

OBJS_STRING := $(SRC_STRING:%.c=${BUILD_DIR}/%.o)
OBJS_SPRINTF := $(SRC_SPRINTF:%.c=${BUILD_DIR}/%.o)
OBJS_SSCANF := $(SRC_SSCANF:%.c=${BUILD_DIR}/%.o)
OBJS_TEST := $(SRC_TEST:%.c=${BUILD_TEST_DIR}/%.o)

CFLAGS=-Wall -Wextra -Werror -std=c11
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage


all: s21_string.a test

s21_string.a: $(OBJS_STRING) $(OBJS_SPRINTF) $(OBJS_SSCANF)
	@mkdir -p ${BUILD_DIR}
	ar rc s21_string.a $(OBJS_STRING) $(OBJS_SPRINTF) $(OBJS_SSCANF)
	ranlib s21_string.a

${BUILD_DIR}/%.o: %.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@


test: $(OBJS_TEST) s21_string.a
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o test.out
	./test.out

${BUILD_TEST_DIR}/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) -c $< -o $@


gcov_report:
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(SRC_STRING) $(SRC_SPRINTF) $(SRC_SSCANF) $(TEST_DIR)/*.c $(LDFLAGS) -o gcov_main
	./gcov_main
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	rm -Rf *.gcda *.cov *.gcno *.info


codestyle:
	clang-format -i --style=google $(SRC_STRING_DIR)/*.c $(SRC_SPRINTF_DIR)/*.c $(SRC_SSCANF_DIR)/*.c $(TEST_DIR)/*.c
	clang-format -i --style=google s21_string.h $(SRC_SPRINTF_DIR)/*.h $(SRC_SSCANF_DIR)/*.h $(TEST_DIR)/*.h

clean:
	rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt gcov_report gcov_main *.dSYM $(BUILD_DIR) $(BUILD_TEST_DIR)

rebuild: clean all
