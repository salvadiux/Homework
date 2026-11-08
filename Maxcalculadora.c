
#include <stdio.h>

#define MAX 3
#define TOTAL 5

double precargadas[TOTAL][3][3] = {
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

int menu();
int leer(double m[3][3], int *filas, int *columnas);
int mostrar(double m[3][3], int filas, int columnas);
int mostrarMatrices();

int sumar(double a[3][3], double b[3][3], double r[3][3], int f, int c);
int restar(double a[3][3], double b[3][3], double r[3][3], int f, int c);
int escalar(double a[3][3], double esc, double r[3][3], int f, int c);
int multiplicar(double a[3][3], double b[3][3], double r[3][3], int f1, int c1, int c2);

double determinante(double a[3][3], int n);

int transpuesta(double a[3][3], double r[3][3], int f, int c);
int inversa(double a[3][3], double r[3][3], int n);
int sumaFilas(double a[3][3], int f, int c);

int main() {
    int opcion;
    int f1, c1, f2, c2;
    double a[3][3], b[3][3], resultado[3][3];
    double esc, det;

    do {
        opcion = menu();

        switch(opcion) {

            case 1:
                leer(a, &f1, &c1);
                leer(b, &f2, &c2);

                if(f1 == f2 && c1 == c2) {
                    sumar(a, b, resultado, f1, c1);
                    mostrar(resultado, f1, c1);
                } else {
                    printf("Las dimensiones deben ser iguales.\n");
                }
                break;

            case 2:
                leer(a, &f1, &c1);
                leer(b, &f2, &c2);

                if(f1 == f2 && c1 == c2) {
                    restar(a, b, resultado, f1, c1);
                    mostrar(resultado, f1, c1);
                } else {
                    printf("Las dimensiones deben ser iguales.\n");
                }
                break;

            case 3:
                leer(a, &f1, &c1);

                printf("Ingresa el escalar: ");
                scanf("%lf", &esc);

                escalar(a, esc, resultado, f1, c1);
                mostrar(resultado, f1, c1);
                break;

            case 4:
                leer(a, &f1, &c1);
                leer(b, &f2, &c2);

                if(c1 == f2) {
                    multiplicar(a, b, resultado, f1, c1, c2);
                    mostrar(resultado, f1, c2);
                } else {
                    printf("Las dimensiones no permiten la multiplicacion.\n");
                }
                break;

            case 5:
                leer(a, &f1, &c1);

                if(f1 == c1) {
                    det = determinante(a, f1);
                    printf("Determinante: %.2lf\n", det);
                } else {
                    printf("La matriz debe ser cuadrada.\n");
                }
                break;

            case 6:
                leer(a, &f1, &c1);

                transpuesta(a, resultado, f1, c1);
                mostrar(resultado, c1, f1);
                break;

            case 7:
                leer(a, &f1, &c1);

                if(f1 == c1) {
                    if(inversa(a, resultado, f1)) {
                        mostrar(resultado, f1, f1);
                    } else {
                        printf("La matriz no tiene inversa.\n");
                    }
                } else {
                    printf("La matriz debe ser cuadrada.\n");
                }
                break;

            case 8:
                leer(a, &f1, &c1);
                sumaFilas(a, f1, c1);
                break;

            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }

    } while(opcion != 0);

    return 0;
}

int menu() {
    int opc;

    printf("\nOPERACIONES CON MATRICES\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion con un escalar\n");
    printf("4. Multiplicacion de matrices\n");
    printf("5. Determinante\n");
    printf("6. Matriz transpuesta\n");
    printf("7. Matriz inversa\n");
    printf("8. Suma de elementos por fila\n");
    printf("0. Salir\n");
    printf("Selecciona: ");

    scanf("%d", &opc);

    return opc;
}

int mostrarMatrices() {
    int i, j, k;

    for(k = 0; k < TOTAL; k++) {
        printf("\nMatriz %d:\n", k + 1);

        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                printf("%8.2lf", precargadas[k][i][j]);
            }
            printf("\n");
        }
    }

    return 1;
}

int leer(double m[3][3], int *filas, int *columnas) {
    int opcion, matriz, i, j;

    printf("\n1. Ingresar matriz\n");
    printf("2. Seleccionar matriz precargada\n");
    printf("Selecciona: ");
    scanf("%d", &opcion);

    if(opcion == 2) {
        mostrarMatrices();

        do {
            printf("\nSelecciona una matriz (1-%d): ", TOTAL);
            scanf("%d", &matriz);
        } while(matriz < 1 || matriz > TOTAL);

        *filas = 3;
        *columnas = 3;

        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                m[i][j] = precargadas[matriz - 1][i][j];
            }
        }

    } else {
        do {
            printf("Numero de filas (1-3): ");
            scanf("%d", filas);
        } while(*filas < 1 || *filas > 3);

        do {
            printf("Numero de columnas (1-3): ");
            scanf("%d", columnas);
        } while(*columnas < 1 || *columnas > 3);

        for(i = 0; i < *filas; i++) {
            for(j = 0; j < *columnas; j++) {
                printf("Elemento [%d][%d]: ", i + 1, j + 1);
                scanf("%lf", &m[i][j]);
            }
        }
    }

    return 1;
}

int mostrar(double m[3][3], int filas, int columnas) {
    int i, j;

    printf("\nResultado:\n");

    for(i = 0; i < filas; i++) {
        for(j = 0; j < columnas; j++) {
            printf("%10.2lf", m[i][j]);
        }
        printf("\n");
    }

    return 1;
}

int sumar(double a[3][3], double b[3][3], double r[3][3], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }

    return 1;
}

int restar(double a[3][3], double b[3][3], double r[3][3], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            r[i][j] = a[i][j] - b[i][j];
        }
    }

    return 1;
}

int escalar(double a[3][3], double esc, double r[3][3], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            r[i][j] = a[i][j] * esc;
        }
    }

    return 1;
}

int multiplicar(double a[3][3], double b[3][3], double r[3][3], int f1, int c1, int c2) {
    for(int i = 0; i < f1; i++) {
        for(int j = 0; j < c2; j++) {
            r[i][j] = 0;

            for(int k = 0; k < c1; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return 1;
}

double determinante(double a[3][3], int n) {
    double det = 0;

    if(n == 1) {
        det = a[0][0];
    }

    else if(n == 2) {
        det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }

    else if(n == 3) {
        det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
            - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
            + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    }

    return det;
}

int transpuesta(double a[3][3], double r[3][3], int f, int c) {
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            r[j][i] = a[i][j];
        }
    }

    return 1;
}

int inversa(double a[3][3], double r[3][3], int n) {
    double menor[3][3], cofactores[3][3];
    double det;
    int f, c, i, j, x, y;

    det = determinante(a, n);

    if(det > -0.000000001 && det < 0.000000001) {
        return 0;
    }

    if(n == 1) {
        r[0][0] = 1.0 / a[0][0];
        return 1;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            x = 0;

            for(f = 0; f < n; f++) {
                if(f != i) {
                    y = 0;

                    for(c = 0; c < n; c++) {
                        if(c != j) {
                            menor[x][y] = a[f][c];
                            y++;
                        }
                    }

                    x++;
                }
            }

            cofactores[i][j] = determinante(menor, n - 1);

            if((i + j) % 2 != 0) {
                cofactores[i][j] = -cofactores[i][j];
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            r[j][i] = cofactores[i][j] / det;
        }
    }

    return 1;
}

int sumaFilas(double a[3][3], int f, int c) {
    double suma;

    for(int i = 0; i < f; i++) {
        suma = 0;

        for(int j = 0; j < c; j++) {
            suma += a[i][j];
        }

        printf("Suma de la fila %d: %.2lf\n", i + 1, suma);
    }

    return 1;
}
