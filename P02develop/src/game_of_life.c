#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <unistd.h>

#define dimx 25
#define dimy 80

int input(int **a);
int batch_input(int **a);
// int file_input(int **a, char type);
int picture(int **a);
int new_state(int **a, int **b, int **c);
int modify(int a, int b);
int near_calc(int **a, int **b);
int extension(int **a, int **b);
int around(int **a, int i, int j);
int newday(int **a, int **b);
int next();
unsigned sleep(unsigned seconds);
int rand();
int rand_input(int **a);


int main() {
    int i;
    int *life1 = (int*) malloc(dimx * dimy * sizeof(int));
    int **plife1 = (int**) malloc(dimx * sizeof(int*));
    for (i = 0; i < dimx; i++) plife1[i] = life1 + dimy * i;

    int *near = (int*) malloc(dimx * dimy * sizeof(int));
    int **pnear = (int**) malloc(dimx * sizeof(int*));
    for (i = 0; i < dimx; i++) pnear[i] = near + dimy * i;

    int *life2 = (int*) malloc(dimx * dimy * sizeof(int));
    int **plife2 = (int**) malloc(dimx * sizeof(int*));
    for (i = 0; i < dimx; i++) plife2[i] = life2 + dimy * i;

    int *life1_ext = (int*) malloc((dimx + 2) * (dimy + 2 ) * sizeof(int));
    int **plife1_ext = (int**) malloc((dimx + 2) * sizeof(int*));
    for (i = 0; i < dimx + 2; i++) plife1_ext[i] = life1_ext + (dimy + 2) * i;

    input(plife1);
    int cont = 1;
    printf("Пауза в секундах:");
    int p;
    scanf("%d", &p);
    while (cont == 1) {
        sleep(p);
        extension(plife1, plife1_ext);
        near_calc(plife1_ext, pnear);
        new_state(plife1, pnear, plife2);
        picture(plife2);
        newday(plife1, plife2);
        if (next() == 1) {
            cont = 1;
        } else {
            cont = 0;
        }
    }

    free(plife1);
    free(plife2);
    free(life1);
    free(life2);
    free(pnear);
    free(near);
    free(plife1_ext);
    free(life1_ext);
    return 0;
}

int input(int **a) {
    FILE *fin;
    char c;
    int type;

    printf("Тип ввода (1 - 5  файлы, 6 - мешанина):");
    scanf("%d", &type);
        if (type == 6) {
            rand_input(a);
        } else {
                switch (type) {
                    case 1 :
                        fin = fopen("1.txt", "r");
                        break;
                    case 2 :
                        fin = fopen("2.txt", "r");
                        break;
                    case 3 :
                        fin = fopen("3.txt", "r");
                        break;
                    case 4 :
                        fin = fopen("4.txt", "r");
                        break;
                    default :
                        fin = fopen("5.txt", "r");
                }
            for (int m = 0; m < dimx; m++) {
                for (int n = 0; n < dimy; n++) {
                    fscanf(fin, "%d%c", &a[m][n], &c);
                }
            }
            fclose(fin);
        }
    return 0;
}

int rand_input(int **a) {
        for (int i = 0; i < dimx; i++) {
            for (int j = 0; j < dimy; j++) {
                a[i][j] = round(rand()%100/50);
            }
        }
    return 0;
}

int picture(int **a) {
    printf("\033[0d\033[2J");
    for (int m = 0; m < dimx; m++) {
        printf("\n");
        for (int n = 0; n < dimy; n++) {
            if (a[m][n] == 1) {
                printf("▣");
            } else {
                printf("▢");
            }
        }
    }
    printf("\n");
    return 0;
}

int new_state(int **a, int **b, int **c) {
    for (int i=0; i < dimx; i++) {
        for (int j=0; j < dimy; j++) {
            c[i][j] = modify(a[i][j], b[i][j]);
        }
    }
    return 0;
}

int modify(int a, int b) {
    int trans[2][9] = { { 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                        { 0, 0, 1, 1, 0, 0, 0, 0, 0 }};
    return trans[a][b];
}

int near_calc(int **a, int **b) {
        for (int i=1; i < dimx + 1; i++) {
            for (int j=1; j < dimy + 1; j++) {
                b[i - 1][j - 1] = around(a, i, j);
            }
        }
    return 0;
}

int extension(int **a, int **b) {
    for (int i=0; i < dimx; i++) {
        for (int j=0; j < dimy; j++) {
            b[i + 1][j + 1] = a[i][j];
        }
    }
    for (int i=0; i < dimx; i++) {
        b[i + 1][0] = a[i][dimy - 1];
        b[i + 1][dimy + 1] = a[i][0];
    }
    for (int j=0; j < dimy; j++) {
        b[0][j + 1] = a[dimx - 1][j];
        b[dimx + 1][j + 1] = a[0][j];
    }
    b[0][0] = a[dimx - 1][dimy - 1];
    b[dimx + 1][dimy + 1] = a[0][0];
    b[0][dimy + 1] = a[dimx - 1][0];
    b[dimx + 1][0] = a[0][dimy - 1];
return 0;
}

int around(int **a, int i, int j) {
                int sum = 0;
                for (int m = -1; m < 2; m++) {
                    for (int n = -1; n < 2; n++) {
                        sum = sum + a[i + m][j + n];
                    }
                }
                return sum - a[i][j];
}

int newday(int **a, int **b) {
    for (int i = 0; i < dimx; i++) {
            for (int j = 0; j < dimy; j++) {
                a[i][j] = b[i][j];
            }
        }
    return 0;
}

int next() {
    int day = 0;
    day++;
    if (day < 100) {
        return 1;
    } else {
        return 0;
    }
}
