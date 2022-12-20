NAME = s21_cat
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -std=c11
SOURSES = s21_cat.c
OBJECTS = s21_cat.o

.PHONY: s21_cat

all: $(NAME)

s21_cat: $(OBJECTS)
	$(CC) $(OBJECTS) -o s21_cat

s21_cat.o: s21_cat.c
	$(CC) $(CC_FLAGS) -c s21_cat.c -g

clean:
	rm -rf *.o s21_cat a.out

test: s21_cat
	sh run.sh
	 
leaks: s21_cat
	leaks --atExit -- ./s21_cat -benst test_file/all_flag_tests/*

check: s21_cat
	cppcheck --enable=all --suppress=missingIncludeSystem . *.c *.h
	cp ../../materials/linters/CPPLINT.cfg ./
#	python3 ./../../materials/linters/cpplint.py --extensions=c *.c *.h
	rm -f CPPLINT.cfg