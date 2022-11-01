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
// данные вход. (   матрица.     кол во строк.      кол во столбцов.     тип.      ошибки)
void outputMatrix(int **matrix, int lines_number, int columns_number, int type, int er);
// выход матрица. (   матрица.     кол во строк.    кол во столбцов.    тип       ошибки)
void freeMemory(int **matrix, int lines_number, int type);
// свободная память. (матрица.    кол во строк.    тип)

int main(void) {
  int type = 0, lines_number, columns_number;
    // 0 строки столбцы
  int er = inputProperties(&type, &lines_number, &columns_number);
    // входные свойства (& тип, & количество строк, & количество столбцов);
  int stat_matrix[MAXSIZE][MAXSIZE] = {0};
    // статичная матрица
  int **matrix = (int **)stat_matrix;
  if (1 != type) {
    matrix = NULL;
  }
  if (2 == type) {
    matrix = singleAllocation(lines_number, columns_number, &er);
      // одиночное распред. (кол во строк. кол во столбцов. ошибки)
  } else if (3 == type) {
    matrix = doubleAllocation(lines_number, columns_number, &er);
      // двойное распределение(колво строк. колво столбцов. ошибки)
  } else if (4 == type) {
    matrix = multipleAllocation(lines_number, columns_number, &er);
  }  // множ распределение.   (кол во строк. кол во столбцов. ошибки)
  inputValues(matrix, lines_number, columns_number, type, &er);
    // входзна(матрица,количество строк,кол столб, тип, ошибка);
  outputMatrix(matrix, lines_number, columns_number, type, er);
    // множраспр.(матрица.колво строк.колво столбцов. тип. ошибки)
  freeMemory(matrix, lines_number, type);
    // своб пам.(матрица. кол во строк. тип)
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

void inputValues(int **matrix, int lines_number, int columns_number, int type, int *er) {
  for (int i = 0; i < lines_number && 0 == *er; i++) {
    for (int j = 0; j < columns_number && 0 == *er; j++) {
      int *element_address = type == 1 ? (int *)(matrix + columns_number * i + j)
                                       : (int *)(*(matrix + i) + j);
      if (1 != scanf("%d", element_address)) {
        *er = 1;
      }
    }
  }
}

void outputMatrix(int **matrix, int lines_number, int columns_number, int type, int er) {
  if (er) {
    printf("n/a");
  } else {
    for (int i = 0; i < lines_number; i++) {
      for (int j = 0; j < columns_number - 1; j++) {
        int *element_address = type == 1 ? (int *)(matrix + columns_number * i + j)
          : (int *)(*(matrix + i) + j);  // перенос строки тут из за 110 симв
        printf("%d ", *element_address);
      }
      int j = columns_number - 1;
      int *row_address = type == 1 ? (int *)(matrix + columns_number * i + j) : (int *)(*(matrix + i) + j);
      printf("%d", *row_address);
      if (i < lines_number - 1) {
        printf("\n");
      }
    }
  }
}

int **singleAllocation(int lines_number, int columns_number, int *er) {
  int **matrix = NULL;
  matrix = malloc(lines_number * columns_number * sizeof(int) + lines_number * sizeof(int *));
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

void freeMemory(int **matrix, int lines_number, int type) {
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
}
