#include <stdio.h>

#define TOTAL 5

double precargadas[TOTAL][3][3] = {
    {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
    {{2, 0, 1}, {3, 1, 2}, {1, 2, 1}},
    {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}},
    {{4, 2, 1}, {0, 3, 2}, {1, 1, 2}},
    {{5, 1, 2}, {2, 4, 0}, {3, 1, 6}}
};

int menu() {
    int opc;
    printf("\nOPERACIONES CON MATRICES\n");
    printf("1. Suma\n2. Resta\n3. Multiplicacion con escalar\n4. Multiplicacion de matrices\n");
    printf("5. Determinante\n6. Matriz transpuesta\n7. Matriz inversa\n8. Suma por fila\n0. Salir\nSelecciona: ");
    scanf("%d", &opc);
    return opc;
}

void mostrar(double m[3][3], int f, int c) {
    printf("\nResultado:\n");
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) printf("%10.2lf", m[i][j]);
        printf("\n");
    }
}

void mostrarMatrices() {
    for(int k = 0; k < TOTAL; k++) {
        printf("\nMatriz %d:\n", k + 1);
        mostrar(precargadas[k], 3, 3);
    }
}

void leer(double m[3][3], int *f, int *c) {
    int opc, mat;
    printf("\n1. Ingresar matriz\n2. Matriz precargada\nSelecciona: ");
    scanf("%d", &opc);

    if(opc == 2) {
        mostrarMatrices();
        do { printf("\nSelecciona una matriz (1-%d): ", TOTAL); scanf("%d", &mat); } while(mat < 1 || mat > TOTAL);
        *f = 3; *c = 3;
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) m[i][j] = precargadas[mat - 1][i][j];
    } else {
        do { printf("Filas (1-3): "); scanf("%d", f); } while(*f < 1 || *f > 3);
        do { printf("Columnas (1-3): "); scanf("%d", c); } while(*c < 1 || *c > 3);
        for(int i = 0; i < *f; i++) 
            for(int j = 0; j < *c; j++) {
                printf("Elemento [%d][%d]: ", i + 1, j + 1);
                scanf("%lf", &m[i][j]);
            }
    }
}

void suma_resta(double a[3][3], double b[3][3], double r[3][3], int f, int c, int signo) {
    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++) r[i][j] = a[i][j] + (signo * b[i][j]);
}

void escalar(double a[3][3], double esc, double r[3][3], int f, int c) {
    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++) r[i][j] = a[i][j] * esc;
}

void multiplicar(double a[3][3], double b[3][3], double r[3][3], int f1, int c1, int c2) {
    for(int i = 0; i < f1; i++) {
        for(int j = 0; j < c2; j++) {
            r[i][j] = 0;
            for(int k = 0; k < c1; k++) r[i][j] += a[i][k] * b[k][j];
        }
    }
}

double determinante(double a[3][3], int n) {
    if(n == 1) return a[0][0];
    if(n == 2) return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
         - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
         + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

void transpuesta(double a[3][3], double r[3][3], int f, int c) {
    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++) r[j][i] = a[i][j];
}

int inversa(double a[3][3], double r[3][3], int n) {
    double menor[3][3], cofactores[3][3], det = determinante(a, n);
    int x, y;

    if(det > -1e-9 && det < 1e-9) return 0; // No tiene inversa

    if(n == 1) { r[0][0] = 1.0 / a[0][0]; return 1; }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            x = 0;
            for(int f = 0; f < n; f++) {
                if(f == i) continue;
                y = 0;
                for(int c = 0; c < n; c++) {
                    if(c != j) menor[x][y++] = a[f][c];
                }
                x++;
            }
            cofactores[i][j] = determinante(menor, n - 1) * ((i + j) % 2 == 0 ? 1 : -1);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) r[j][i] = cofactores[i][j] / det;

    return 1;
}

void sumaFilas(double a[3][3], int f, int c) {
    for(int i = 0; i < f; i++) {
        double suma = 0;
        for(int j = 0; j < c; j++) suma += a[i][j];
        printf("Suma de la fila %d: %.2lf\n", i + 1, suma);
    }
}

int main() {
    int opcion, f1, c1, f2, c2;
    double a[3][3], b[3][3], res[3][3], esc;

    while((opcion = menu()) != 0) {
        if(opcion >= 1 && opcion <= 8) leer(a, &f1, &c1);
        if(opcion == 1 || opcion == 2 || opcion == 4) leer(b, &f2, &c2);

        switch(opcion) {
            case 1:
            case 2:
                if(f1 == f2 && c1 == c2) {
                    suma_resta(a, b, res, f1, c1, opcion == 1 ? 1 : -1);
                    mostrar(res, f1, c1);
                } else printf("Las dimensiones deben ser iguales.\n");
                break;
            case 3:
                printf("Ingresa el escalar: "); scanf("%lf", &esc);
                escalar(a, esc, res, f1, c1); mostrar(res, f1, c1);
                break;
            case 4:
                if(c1 == f2) { multiplicar(a, b, res, f1, c1, c2); mostrar(res, f1, c2); } 
                else printf("Las dimensiones no permiten multiplicacion.\n");
                break;
            case 5:
                if(f1 == c1) printf("Determinante: %.2lf\n", determinante(a, f1));
                else printf("La matriz debe ser cuadrada.\n");
                break;
            case 6:
                transpuesta(a, res, f1, c1); mostrar(res, c1, f1);
                break;
            case 7:
                if(f1 == c1 && inversa(a, res, f1)) mostrar(res, f1, f1);
                else printf(f1 == c1 ? "La matriz no tiene inversa.\n" : "La matriz debe ser cuadrada.\n");
                break;
            case 8:
                sumaFilas(a, f1, c1);
                break;
            default:
                printf("Opcion no valida.\n");
        }
    }
    printf("Saliendo del programa...\n");
    return 0;
}
