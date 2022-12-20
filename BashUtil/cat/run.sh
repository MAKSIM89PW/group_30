#!/bin/bash

# Part 1

./s21_cat s21_cat.c  >> s21_cat.txt
cat s21_cat.c >> cat.txt
diff s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat s21_cat.c text.txt >> s21_cat.txt
cat s21_cat.c text.txt >> cat.txt
diff s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat s21_cat.c text.txt s21_cat.h >> s21_cat.txt
cat s21_cat.c text.txt s21_cat.h >> cat.txt
diff s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

# Part 2

./s21_cat -n s21_cat.c >> s21_cat.txt
cat -n s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -b s21_cat.c >> s21_cat.txt
cat -b s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -n s21_cat.c >> s21_cat.txt
cat -n s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -s s21_cat.c >> s21_cat.txt
cat -s s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -e s21_cat.c >> s21_cat.txt
cat -e s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

# Part 3

./s21_cat -n s21_cat.c text.txt >> s21_cat.txt
cat -n s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -b s21_cat.c text.txt >> s21_cat.txt
cat -b s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -n s21_cat.c text.txt >> s21_cat.txt
cat -n s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -s s21_cat.c text.txt >> s21_cat.txt
cat -s s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -e s21_cat.c text.txt >> s21_cat.txt
cat -e s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

# Part 4

./s21_cat -be s21_cat.c >> s21_cat.txt
cat -be s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bn s21_cat.c >> s21_cat.txt
cat -bn s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bs s21_cat.c >> s21_cat.txt
cat -bs s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bt s21_cat.c >> s21_cat.txt
cat -bt s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -ne s21_cat.c >> s21_cat.txt
cat -ne s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -ns s21_cat.c >> s21_cat.txt
cat -ns s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -nt s21_cat.c >> s21_cat.txt
cat -nt s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -es s21_cat.c >> s21_cat.txt
cat -es s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -et s21_cat.c >> s21_cat.txt
cat -et s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -st s21_cat.c >> s21_cat.txt
cat -st s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

# Part 5

./s21_cat -be s21_cat.c text.txt >> s21_cat.txt
cat -be s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bn s21_cat.c text.txt >> s21_cat.txt
cat -bn s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bs s21_cat.c text.txt >> s21_cat.txt
cat -bs s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bt s21_cat.c text.txt >> s21_cat.txt
cat -bt s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -ne s21_cat.c text.txt >> s21_cat.txt
cat -ne s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -ns s21_cat.c text.txt >> s21_cat.txt
cat -ns s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -nt s21_cat.c text.txt >> s21_cat.txt
cat -nt s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -es s21_cat.c text.txt >> s21_cat.txt
cat -es s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -et s21_cat.c text.txt>> s21_cat.txt
cat -et s21_cat.c text.txt>> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -st s21_cat.c text.txt>> s21_cat.txt
cat -st s21_cat.c text.txt>> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

# Part 6

./s21_cat -bet s21_cat.c >> s21_cat.txt
cat -bet s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bes s21_cat.c s21_cat.h s21_cat.c >> s21_cat.txt
cat -bes s21_cat.c s21_cat.h s21_cat.c >> cat.txt
diff s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bent s21_cat.c s21_cat.h s21_cat.c text.txt >> s21_cat.txt
cat -bent s21_cat.c s21_cat.h s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bes s21_cat.c >> s21_cat.txt
cat -bes s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bens s21_cat.c text.txt >> s21_cat.txt
cat -bens s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bns s21_cat.c >> s21_cat.txt
cat -bns s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bnt s21_cat.c >> s21_cat.txt
cat -bnt s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bst s21_cat.c >> s21_cat.txt
cat -bst s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -nes s21_cat.c >> s21_cat.txt
cat -nes s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -nst s21_cat.c >> s21_cat.txt
cat -nst s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -net s21_cat.c text.txt >> s21_cat.txt
cat -net s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -est s21_cat.c >> s21_cat.txt
cat -est s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

# Part 7

./s21_cat -nvest s21_cat.c >> s21_cat.txt
cat -nevst s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bvest s21_cat.c >> s21_cat.txt
cat -besvt s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -benvt s21_cat.c >> s21_cat.txt
cat -bevnt s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -benvs s21_cat.c >> s21_cat.txt
cat -bevns s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bnvst s21_cat.c >> s21_cat.txt
cat -bnst s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -bnvst s21_cat.c >> s21_cat.txt
cat -bnvst s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat --number-nonblank s21_cat.c text.txt >> s21_cat.txt
cat -b s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat --number s21_cat.c text.txt >> s21_cat.txt
cat -n s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat --squeeze-blank s21_cat.c text.txt >> s21_cat.txt
cat -s s21_cat.c text.txt >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt
