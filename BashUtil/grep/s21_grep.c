#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 2048
#define STRMAX 1024

struct flags {
  int e, i, v, c, l, n, h, s, f, o;
};

void flagsParsing(int argc, char** argv, struct flags* flags, char* ef_arg);
void initFlags();
void addEArg(char* ef_arg, char* optarg, int* ef_counter);
void addFArg(char* ef_arg, char* optarg, int* ef_counter, int flag_s);
void searchAndPrint(char* name, struct flags flags, char* ef_arg,
                    int number_of_files);

int main(int argc, char* argv[]) {
  char ef_arg[BUFSIZE] = {0};
  struct flags flags = {0};
  flagsParsing(argc, argv, &flags, ef_arg);
  int file_to_read;
  char* regular_expr;
  if (flags.f == 1 || flags.e == 1) {
    file_to_read = optind;
    regular_expr = ef_arg;
  } else {
    file_to_read = optind + 1;
    regular_expr = argv[optind];
  }
  int number_of_files = argc - file_to_read;
  for (; argv[file_to_read]; file_to_read++)
    searchAndPrint(argv[file_to_read], flags, regular_expr, number_of_files);
}

void searchAndPrint(char* name, struct flags flags, char* regular_expr,
                    int number_of_files) {
  FILE* fp;
  if ((fp = fopen(name, "r")) == NULL) {
    if (!flags.s)
      fprintf(stderr, "s21_grep: %s: No such file or directory\n", optarg);
  } else {
    regex_t regex = {0};
    if (flags.i)
      regcomp(&regex, regular_expr, REG_EXTENDED | REG_ICASE | REG_NEWLINE);
    else
      regcomp(&regex, regular_expr, REG_EXTENDED | REG_NEWLINE);
    char line[BUFSIZE] = {0};
    int line_counter = 0;
    int success_counter = 0;
    regmatch_t regmat[1] = {0};
    char result_o[BUFSIZE];
    if (flags.v) flags.o = 0;
    while (!feof(fp)) {
      line_counter++;
      fgets(line, BUFSIZE, fp);
      int status = regexec(&regex, line, 1, regmat, 0);
      if (flags.v) status = (status) ? 0 : 1;
      if (!status && line[0] != 0) {
        if (number_of_files > 1 && !flags.c && !flags.l && !flags.h)
          printf("%s:", name);
        if (flags.n && !flags.c && !flags.l) printf("%d:", line_counter);
        if (flags.o) {
          char* ptr = line;
          while (status == 0) {
            int len = regmat[0].rm_eo - regmat[0].rm_so;
            memcpy(result_o, ptr + regmat[0].rm_so, len);
            result_o[len] = 0;
            if (!flags.l && !flags.c) {
              printf("%s\n", result_o);
            }
            ptr += regmat[0].rm_eo;
            status = regexec(&regex, ptr, 1, regmat, REG_NOTBOL);
          }
        }
        success_counter++;
        if (!flags.c && !flags.l && !flags.o) {
          printf("%s", line);
          if (line[strlen(line) - 1] != '\n') printf("\n");
        }
        line[0] = '\0';
      }
    }
    if (number_of_files > 1 && flags.c && !flags.h) printf("%s:", name);
    if (flags.c && flags.l && success_counter) success_counter = 1;
    if (flags.c) printf("%d\n", success_counter);
    if (flags.l && success_counter) printf("%s\n", name);
    regfree(&regex);
    fclose(fp);
  }
}

void flagsParsing(int argc, char** argv, struct flags* flags, char* ef_arg) {
  int c;
  int ef_counter = 0;
  while ((c = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    if (c == 'e') {
      flags->e = 1;
      addEArg(ef_arg, optarg, &ef_counter);
    }
    if (c == 'i') flags->i = 1;
    if (c == 'v') flags->v = 1;
    if (c == 'c') flags->c = 1;
    if (c == 'l') flags->l = 1;
    if (c == 'n') flags->n = 1;
    if (c == 'h') flags->h = 1;
    if (c == 's') flags->s = 1;
    if (c == 'f') {
      flags->f = 1;
      addFArg(ef_arg, optarg, &ef_counter, flags->s);
    }
    if (c == 'o') flags->o = 1;
  }
}

void addEArg(char* ef_arg, char* optarg, int* ef_counter) {
  if (*optarg == '\0') {
    optarg[0] = '.';
    optarg[1] = '\0';
  }
  if (*ef_counter) {
    char ch[2] = "|";
    strcat(ef_arg, ch);
    strcat(ef_arg, optarg);
  } else {
    strcat(ef_arg, optarg);
  }
  *ef_counter += 1;
}

void addFArg(char* ef_arg, char* optarg, int* ef_counter, int flag_s) {
  FILE* fp;
  if ((fp = fopen(optarg, "r")) == NULL) {
    if (!flag_s)
      fprintf(stderr, "s21_grep: %s: Noo such file or directory", optarg);
    exit(1);
  }
  while (!feof(fp)) {
    if (*ef_counter) {
      char ch[2] = "|";
      strcat(ef_arg, ch);
      int len = strlen(ef_arg);
      fgets(ef_arg + len, STRMAX, fp);
      if (ef_arg[len] == '\n') ef_arg[len] = '.';
      if (ef_arg[len] == '\0') ef_arg[len - 1] = 'g';
      if (ef_arg[strlen(ef_arg) - 1] == '\n') ef_arg[strlen(ef_arg) - 1] = '\0';
    } else {
      fgets(ef_arg, STRMAX, fp);
      if (ef_arg[0] == '\n')
        ef_arg[0] = '.';
      else if (ef_arg[strlen(ef_arg) - 1] == '\n')
        ef_arg[strlen(ef_arg) - 1] = '\0';
    }
    *ef_counter += 1;
  }
  fclose(fp);
}
