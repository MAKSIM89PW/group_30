#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int inputProperties(int *type, int *lines_number, int *columns_number);
// свойства вход
int **singleAllocation(int lines_number, int columns_number, int *er);
// одиночное распределение.(колво строк.     колво столбцов.  ошибки)
int **doubleAllocation(int lines_number, int columns_number, int *er);
// двойное распределение. (кол во строк.    кол во столбцов.    ошибки)
int **multipleAllocation(int lines_number, int columns_number, int *er);
// множественное распределение.(кол во строк.кол во столбцов.   ошибки)
void inputValues(int **matrix, int lines_number, int columns_number, int type, int *er);
// данные вход. (   матрица.     кол во строк.      кол во столбцов.     тип. ошибки)
void outputMatrix(int **matrix, int *rmaxs, int *cmins, int lines_number, int columns_number, int type, int er);
// выход матрица. (   матрица.     кол во строк.    кол во столбцов.    тип       ошибки)
void freeMemory(int **matrix, int *rmaxs, int *cmins, int lines_number, int type);
// свободная память. (матрица.    кол во строк.    тип)

void minMax(int **matrix, int lines_number, int columns_number, int **rmaxs,
            int **cmins, int *er, int type);

int main(void) {
  int type = 0, lines_number, columns_number;
  int er = inputProperties(&type, &lines_number, &columns_number);
  int stat_matrix[MAXSIZE][MAXSIZE] = {0};
  int **matrix = (int **)stat_matrix;
  if (1 != type) {
    matrix = NULL;
  }
  if (2 == type) {
    matrix = singleAllocation(lines_number, columns_number, &er);
  } else if (3 == type) {
    matrix = doubleAllocation(lines_number, columns_number, &er);
  } else if (4 == type) {
    matrix = multipleAllocation(lines_number, columns_number, &er);
  }
  inputValues(matrix, lines_number, columns_number, type, &er);
  int *rmaxs = NULL, *cmins = NULL;
  minMax(matrix, lines_number, columns_number, &rmaxs, &cmins, &er, type);
  outputMatrix(matrix, rmaxs, cmins, lines_number, columns_number, type,
               er);
  freeMemory(matrix, rmaxs, cmins, lines_number, type);
}

int inputProperties(int *type, int *lines_number, int *columns_number) {
  int er = 0;
  if (1 != scanf("%d", type) || *type < 1 || *type > 4) {
    er = 1;
  }
  if (er || 1 != scanf("%d", lines_number) || *lines_number <= 0 ||
      (1 == *type && *lines_number > MAXSIZE)) {
    er = 1;
  }
  if (er || 1 != scanf("%d", columns_number) || *columns_number <= 0 ||
      (1 == *type && *columns_number > MAXSIZE)) {
    er = 1;
  }
  return er;
}

void inputValues(int **matrix, int lines_number, int columns_number, int type,
                 int *er) {
  for (int i = 0; i < lines_number && 0 == *er; i++) {
    for (int j = 0; j < columns_number && 0 == *er; j++) {
      int *element_address = type == 1
                                 ? (int *)(matrix + columns_number * i + j)
                                 : (int *)(*(matrix + i) + j);
      if (1 != scanf("%d", element_address)) {
        *er = 1;
      }
    }
  }
}

void outputMatrix(int **matrix, int *rmaxs, int *cmins, int lines_number,
                  int columns_number, int type, int er) {
  if (er) {
    printf("n/a");
  } else {
    for (int i = 0; i < lines_number; i++) {
      for (int j = 0; j < columns_number - 1; j++) {
        int *element_address = type == 1
                                   ? (int *)(matrix + columns_number * i + j)
                                   : (int *)(*(matrix + i) + j);
        printf("%d ", *element_address);
      }
      int j = columns_number - 1;
      int *row_address = type == 1 ? (int *)(matrix + columns_number * i + j)
                                   : (int *)(*(matrix + i) + j);
      printf("%d", *row_address);
      printf("\n");
    }
    for (int i = 0; i < lines_number - 1; i++) {
      printf("%d ", rmaxs[i]);
    }
    printf("%d\n", rmaxs[lines_number - 1]);
    for (int i = 0; i < columns_number - 1; i++) {
      printf("%d ", cmins[i]);
    }
    printf("%d", cmins[columns_number - 1]);
  }
}

int **singleAllocation(int lines_number, int columns_number, int *er) {
  int **matrix = NULL;
  matrix = malloc(lines_number * columns_number * sizeof(int) +
                  lines_number * sizeof(int *));
  if (NULL == matrix) {
    *er = 1;
  }
  int *beginning = NULL != matrix ? (int *)(matrix + lines_number) : NULL;
  for (int i = 0; i < lines_number && 0 == *er; i++) {
    matrix[i] = beginning + columns_number * i;
  }
  return matrix;
}

int **doubleAllocation(int lines_number, int columns_number, int *er) {
  int **matrix = NULL;
  int *values = NULL;
  matrix = malloc(lines_number * sizeof(int *));
  values = malloc(lines_number * columns_number * sizeof(int));
  if (NULL == matrix || NULL == values) {
    *er = 1;
  }
  for (int i = 0; i < lines_number && 0 == *er; i++) {
    matrix[i] = values + columns_number * i;
  }
  return matrix;
}

int **multipleAllocation(int lines_number, int columns_number, int *er) {
  int **matrix = NULL;
  matrix = malloc(lines_number * sizeof(int *));
  if (NULL == matrix) {
    *er = 1;
  }
  for (int i = 0; i < lines_number; i++) {
    matrix[i] = *er == 0 ? malloc(columns_number * sizeof(int)) : NULL;
    if (NULL == matrix[i]) {
      *er = 1;
    }
  }
  return matrix;
}

void freeMemory(int **matrix, int *rmaxs, int *cmins, int lines_number,
                int type) {
  if (2 == type) {
    free(matrix);
  } else if (3 == type) {
    free(matrix[0]);
    free(matrix);
  } else if (4 == type) {
    for (int i = 0; i < lines_number; i++) {
      free(matrix[i]);
    }
    free(matrix);
  }
  free(rmaxs);
  free(cmins);
}

void minMax(int **matrix, int lines_number, int columns_number, int **rmaxs,
            int **cmins, int *er, int type) {
  if (0 == *er) {
    *rmaxs = malloc(lines_number * sizeof(int));
    *cmins = malloc(columns_number * sizeof(int));
  }
  if (NULL == *rmaxs || NULL == *cmins) {
    *er = 1;
  } else {
    for (int i = 0; i < lines_number; i++) {
      int *element_address = type == 1 ? (int *)(matrix + columns_number * i)
                                       : (int *)(*(matrix + i));
      (*rmaxs)[i] = *element_address;
    }
    for (int i = 0; i < columns_number; i++) {
      int *element_address =
          type == 1 ? (int *)(matrix + i) : (int *)(*matrix + i);
      (*cmins)[i] = *element_address;
    }
    for (int i = 0; i < lines_number; i++) {
      for (int j = 0; j < columns_number; j++) {
        int *element_address = type == 1
                                   ? (int *)(matrix + columns_number * i + j)
                                   : (int *)(*(matrix + i) + j);
        if (*element_address > (*rmaxs)[i]) {
          (*rmaxs)[i] = *element_address;
        }
        if (*element_address < (*cmins)[j]) {
          (*cmins)[j] = *element_address;
        }
      }
    }
  }
}
