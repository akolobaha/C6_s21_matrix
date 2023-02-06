CC = gcc
CFLAGS = #-Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

s21_matrix.a: clean
	$(CC) $(CFLAGS) -c s21_*.c helpers.c
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
	$(CC) unit_test.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

test2: s21_matrix.a
	$(CC) $(CFLAGS) -c tests.c -o tests.o
	$(CC) tests.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

gcov_report: s21_matrix.a
	$(CC) $(FLAGS) --coverage unit_tests.c s21_*.c s21_matrix.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	gcov s21_*.gcda
	gcovr -b
	gcovr --html-details -o report.html
	open report.html

clean:
	rm -rf s21_matrix
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.html
	rm -rf *.css
	rm -rf main
	rm -rf gcov_test

main: s21_matrix.a
	$(CC) $(CFLAGS) -g main.c s21_matrix.a -o main
	./main

lint:
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h

format:
	clang-format -i *.c *.h
	clang-format -n *.c *.h