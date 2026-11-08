# Homework
#include <stdio.h>
int menu();
int leer(double m[3][3]);
int mostrar(double m[3][3]);
int sumar(double a[3][3], double b[3][3], double res[3][3]);
int restar(double a[3][3], double b[3][3], double res[3][3]);
int escalar(double a[3][3], double esc, double res[3][3]);
int multiplicar(double a[3][3], double b[3][3], double res[3][3]);
double determinante(double a[3][3]);
int transpuesta(double a[3][3], double res[3][3]);
int inversa(double a[3][3], double res[3][3]);
int main() {
    int opcion;
    opcion = menu();
   
return 0;}




int menu() {
    int opc;
    printf("      CALCULADORA DE MATRICES  \n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion con un escalar\n");
    printf("4. Multiplicacion de matrices\n");
    printf("5. Determinante\n");
    printf("6. Matriz transpuesta\n");
    printf("7. Matriz inversa\n");
    printf("10. Salir\n");
    scanf("%d", &opc);
    return opc;
}
