
#include <stdio.h>
#include <math.h>

#define MAX 10
#define TOTAL 5

double precargadas[TOTAL][MAX][MAX] = {
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    },
    {
        {2, 0, 1},
        {3, 1, 2},
        {1, 2, 1}
    },
    {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 3}
    },
    {
        {4, 2, 1},
        {0, 3, 2},
        {1, 1, 2}
    },
    {
        {5, 1, 2},
        {2, 4, 0},
        {3, 1, 6}
    }
};

void menu();
void mostrarMatrices();
void ingresarMatriz(double A[MAX][MAX], int *filas, int *columnas);
void seleccionarMatriz(double A[MAX][MAX], int *filas, int *columnas);
void obtenerMatriz(double A[MAX][MAX], int *filas, int *columnas);
void mostrarMatriz(double A[MAX][MAX], int filas, int columnas);

void suma();
void resta();
void escalar();
void multiplicacion();
void determinante();
void transpuesta();
void inversa();
void sumaFilas();

double sumarFila(double A[MAX][MAX], int fila, int columnas);
double calcularDeterminante(double A[MAX][MAX], int n);

int main() {
    int opcion;

    do {
        menu();

        printf("\nSelecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                suma();
                break;
            case 2:
                resta();
                break;
            case 3:
                escalar();
                break;
            case 4:
                multiplicacion();
                break;
            case 5:
                determinante();
                break;
            case 6:
                transpuesta();
                break;
            case 7:
                inversa();
                break;
            case 8:
                sumaFilas();
                break;
            case 0:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
        }

    } while (opcion != 0);

    return 0;
}

void menu() {
    printf("\nOPERACIONES CON MATRICES\n");
    printf("1. Suma de matrices\n");
    printf("2. Resta de matrices\n");
    printf("3. Multiplicacion por escalar\n");
    printf("4. Multiplicacion de matrices\n");
    printf("5. Determinante\n");
    printf("6. Matriz transpuesta\n");
    printf("7. Matriz inversa\n");
    printf("8. Suma de elementos por fila\n");
    printf("0. Salir\n");
}

void mostrarMatrices() {
    int i, j, k;

    printf("\nMATRICES PRECARGADAS\n");

    for (k = 0; k < TOTAL; k++) {
        printf("\nMatriz %d:\n", k + 1);

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%8.2lf", precargadas[k][i][j]);
            }
            printf("\n");
        }
    }
}

void ingresarMatriz(double A[MAX][MAX], int *filas, int *columnas) {
    int i, j;

    do {
        printf("Numero de filas (1-%d): ", MAX);
        scanf("%d", filas);
    } while (*filas < 1 || *filas > MAX);

    do {
        printf("Numero de columnas (1-%d): ", MAX);
        scanf("%d", columnas);
    } while (*columnas < 1 || *columnas > MAX);

    printf("\nIngresa los elementos de la matriz:\n");

    for (i = 0; i < *filas; i++) {
        for (j = 0; j < *columnas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &A[i][j]);
        }
    }
}

void seleccionarMatriz(double A[MAX][MAX], int *filas, int *columnas) {
    int opcion, i, j;

    mostrarMatrices();

    do {
        printf("\nSelecciona una matriz (1-%d): ", TOTAL);
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > TOTAL);

    *filas = 3;
    *columnas = 3;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            A[i][j] = precargadas[opcion - 1][i][j];
        }
    }

    printf("\nMatriz %d seleccionada.\n", opcion);
}

void obtenerMatriz(double A[MAX][MAX], int *filas, int *columnas) {
    int opcion;

    printf("\n1. Ingresar matriz manualmente\n");
    printf("2. Seleccionar matriz precargada\n");
    printf("Selecciona: ");
    scanf("%d", &opcion);

    if (opcion == 2) {
        seleccionarMatriz(A, filas, columnas);
    } else {
        ingresarMatriz(A, filas, columnas);
    }
}

void mostrarMatriz(double A[MAX][MAX], int filas, int columnas) {
    int i, j;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("%10.2lf", A[i][j]);
        }
        printf("\n");
    }
}

void suma() {
    double A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int f1, c1, f2, c2;
    int i, j;

    printf("\nSUMA DE MATRICES\n");

    obtenerMatriz(A, &f1, &c1);
    obtenerMatriz(B, &f2, &c2);

    if (f1 != f2 || c1 != c2) {
        printf("\nError: Las dimensiones deben ser iguales.\n");
        return;
    }

    for (i = 0; i < f1; i++) {
        for (j = 0; j < c1; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nResultado:\n");
    mostrarMatriz(R, f1, c1);
}

void resta() {
    double A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int f1, c1, f2, c2;
    int i, j;

    printf("\nRESTA DE MATRICES\n");

    obtenerMatriz(A, &f1, &c1);
    obtenerMatriz(B, &f2, &c2);

    if (f1 != f2 || c1 != c2) {
        printf("\nError: Las dimensiones deben ser iguales.\n");
        return;
    }

    for (i = 0; i < f1; i++) {
        for (j = 0; j < c1; j++) {
            R[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("\nResultado:\n");
    mostrarMatriz(R, f1, c1);
}

void escalar() {
    double A[MAX][MAX], R[MAX][MAX];
    double k;
    int filas, columnas;
    int i, j;

    printf("\nMULTIPLICACION POR ESCALAR\n");

    obtenerMatriz(A, &filas, &columnas);

    printf("\nIngresa el escalar: ");
    scanf("%lf", &k);

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            R[i][j] = A[i][j] * k;
        }
    }

    printf("\nResultado:\n");
    mostrarMatriz(R, filas, columnas);
}

void multiplicacion() {
    double A[MAX][MAX], B[MAX][MAX], R[MAX][MAX] = {0};
    int f1, c1, f2, c2;
    int i, j, k;

    printf("\nMULTIPLICACION DE MATRICES\n");

    obtenerMatriz(A, &f1, &c1);
    obtenerMatriz(B, &f2, &c2);

    if (c1 != f2) {
        printf("\nError: Las columnas de A deben coincidir con las filas de B.\n");
        return;
    }

    for (i = 0; i < f1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultado:\n");
    mostrarMatriz(R, f1, c2);
}

double calcularDeterminante(double A[MAX][MAX], int n) {
    double det = 1, factor, temp;
    int i, j, k, pivote;

    for (i = 0; i < n; i++) {
        pivote = i;

        for (j = i + 1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(A[pivote][i])) {
                pivote = j;
            }
        }

        if (fabs(A[pivote][i]) < 1e-10) {
            return 0;
        }

        if (pivote != i) {
            for (k = 0; k < n; k++) {
                temp = A[i][k];
                A[i][k] = A[pivote][k];
                A[pivote][k] = temp;
            }

            det = -det;
        }

        det *= A[i][i];

        for (j = i + 1; j < n; j++) {
            factor = A[j][i] / A[i][i];

            for (k = i + 1; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    return det;
}

void determinante() {
    double A[MAX][MAX], copia[MAX][MAX];
    double det;
    int filas, columnas;
    int i, j;

    printf("\nDETERMINANTE\n");

    obtenerMatriz(A, &filas, &columnas);

    if (filas != columnas) {
        printf("\nError: La matriz debe ser cuadrada.\n");
        return;
    }

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            copia[i][j] = A[i][j];
        }
    }

    det = calcularDeterminante(copia, filas);

    printf("\nDeterminante = %.4lf\n", det);
}

void transpuesta() {
    double A[MAX][MAX], T[MAX][MAX];
    int filas, columnas;
    int i, j;

    printf("\nMATRIZ TRANSPUESTA\n");

    obtenerMatriz(A, &filas, &columnas);

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            T[j][i] = A[i][j];
        }
    }

    printf("\nMatriz original:\n");
    mostrarMatriz(A, filas, columnas);

    printf("\nMatriz transpuesta:\n");
    mostrarMatriz(T, columnas, filas);
}

void inversa() {
    double A[MAX][MAX], I[MAX][MAX * 2];
    double pivote, factor, temp;
    int filas, columnas;
    int i, j, k, fila;

    printf("\nMATRIZ INVERSA\n");

    obtenerMatriz(A, &filas, &columnas);

    if (filas != columnas) {
        printf("\nError: La matriz debe ser cuadrada.\n");
        return;
    }

    for (i = 0; i < filas; i++) {
        for (j = 0; j < filas; j++) {
            I[i][j] = A[i][j];
            I[i][j + filas] = (i == j) ? 1 : 0;
        }
    }

    for (i = 0; i < filas; i++) {
        fila = i;

        for (j = i + 1; j < filas; j++) {
            if (fabs(I[j][i]) > fabs(I[fila][i])) {
                fila = j;
            }
        }

        if (fabs(I[fila][i]) < 1e-10) {
            printf("\nError: La matriz no tiene inversa.\n");
            return;
        }

        if (fila != i) {
            for (k = 0; k < 2 * filas; k++) {
                temp = I[i][k];
                I[i][k] = I[fila][k];
                I[fila][k] = temp;
            }
        }

        pivote = I[i][i];

        for (j = 0; j < 2 * filas; j++) {
            I[i][j] /= pivote;
        }

        for (k = 0; k < filas; k++) {
            if (k != i) {
                factor = I[k][i];

                for (j = 0; j < 2 * filas; j++) {
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
    }

    printf("\nMatriz inversa:\n");

    for (i = 0; i < filas; i++) {
        for (j = filas; j < 2 * filas; j++) {
            printf("%10.4lf", I[i][j]);
        }
        printf("\n");
    }
}

double sumarFila(double A[MAX][MAX], int fila, int columnas) {
    double suma = 0;
    int j;

    for (j = 0; j < columnas; j++) {
        suma += A[fila][j];
    }

    return suma;
}

void sumaFilas() {
    double A[MAX][MAX];
    int filas, columnas;
    int i;

    printf("\nSUMA DE ELEMENTOS POR FILA\n");

    obtenerMatriz(A, &filas, &columnas);

    for (i = 0; i < filas; i++) {
        printf("\nSuma de la fila %d: %.2lf",
               i + 1, sumarFila(A, i, columnas));
    }

    printf("\n");
}
