CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

s21_matrix.a: clean
	$(CC) $(CFLAGS) -c s21_*.c helpers.c
	ar rcs s21_matrix.a *.o

test: s21_matrix.a
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
	$(CC) unit_test.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

test2: s21_matrix.a
	$(CC) $(CFLAGS) -c unit_test2.c -o unit_test2.o
	$(CC) unit_test2.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

test3: s21_matrix.a
	$(CC) $(CFLAGS) -c unit_test3.c -o unit_test3.o
	$(CC) unit_test3.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

gcov_report: s21_matrix.a
	$(CC) $(FLAGS) --coverage unit_test.c s21_*.c s21_matrix.a $(TEST_LIBS) -o gcov_test
	./gcov_test
	lcov -t "s21_matrix" -o s21_matrix.info -c -d .
	genhtml -o report s21_matrix.info
	open ./report/index.html

clean:
	rm -rf test main *.o *.a *.gcno *.gcda *.info report gcov_test s21_matrix *.gcov *.dYSM report s21_matrix

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	rm .clang-format
