# ✦ Calculadora de Matrices

<p align="center">
  <img src="assets/banner.png" width="100%" alt="Calculadora de matrices - Proyecto en C">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Lenguaje-C-8B5CF6?style=for-the-badge&logo=c&logoColor=white">
  <img src="https://img.shields.io/badge/Estado-Finalizado-A855F7?style=for-the-badge">
  <img src="https://img.shields.io/badge/Proyecto-Académico-6D28D9?style=for-the-badge">
</p>

<p align="center">
  <i>Un pequeño proyecto de programación dedicado al cálculo y manipulación de matrices.</i>
</p>

---

## ✧ Sobre el proyecto

Este programa fue desarrollado en **lenguaje C** como un proyecto académico para trabajar con matrices y aplicar diferentes operaciones del álgebra lineal.

Cuenta con un menú interactivo desde el cual se pueden seleccionar matrices precargadas o ingresar valores manualmente para realizar los cálculos.

La idea es mantener un programa sencillo de utilizar, con funciones independientes para cada operación.

## ♡ Características

- Suma de matrices.
- Resta de matrices.
- Multiplicación por escalar.
- Multiplicación entre matrices.
- Cálculo de determinantes.
- Obtención de matrices transpuestas.
- Cálculo de matrices inversas.
- Suma de elementos por fila.
- Cinco matrices precargadas.
- Ingreso manual de matrices.
- Manejo de matrices de hasta 10 × 10.

## ⌘ Operaciones disponibles

| Opción | Operación |
|:---:|---|
| 1 | Suma de matrices |
| 2 | Resta de matrices |
| 3 | Multiplicación por escalar |
| 4 | Multiplicación de matrices |
| 5 | Determinante |
| 6 | Matriz transpuesta |
| 7 | Matriz inversa |
| 8 | Suma de elementos por fila |
| 0 | Salir |

## ✦ Métodos utilizados

| Operación | Procedimiento |
|---|---|
| Suma | Adición de elementos correspondientes |
| Resta | Sustracción de elementos correspondientes |
| Escalar | Multiplicación de cada elemento |
| Multiplicación | Producto de filas por columnas |
| Determinante | Eliminación por pivotes |
| Transpuesta | Intercambio de filas y columnas |
| Inversa | Método de Gauss-Jordan |
| Suma por fila | Acumulación de elementos |

## ⚙️ Tecnologías

- Lenguaje C
- Biblioteca `stdio.h`
- Biblioteca `math.h`
- Compilador GCC

## 🚀 Instalación y ejecución

### 1. Clonar el repositorio

```bash
git clone https://github.com/Salvadiux/calculadora-matrices.git
```

### 2. Entrar a la carpeta

```bash
cd calculadora-matrices
```

### 3. Compilar

```bash
gcc main.c -o matrices -lm
```

### 4. Ejecutar

En Linux:

```bash
./matrices
```

En Windows:

```bash
matrices.exe
```

> Es necesario tener instalado GCC para compilar el programa.

## 📂 Estructura del proyecto

```text
calculadora-matrices/
│
├── assets/
│   └── banner.png
│
├── main.c
│
└── README.md
```

## ✧ Consideraciones

- Las matrices ingresadas manualmente pueden tener dimensiones de 1 a 10.
- Las matrices precargadas tienen dimensiones de 3 × 3.
- La suma y resta requieren matrices de las mismas dimensiones.
- La multiplicación requiere que las columnas de la primera matriz coincidan con las filas de la segunda.
- El determinante y la inversa solamente se pueden calcular en matrices cuadradas.
- Las matrices sin inversa generan un mensaje de error.

## ♡ Propósito académico

Este proyecto busca reforzar los conocimientos de programación estructurada mediante el uso de:

- Variables y tipos de datos.
- Arreglos bidimensionales.
- Funciones.
- Ciclos `for` y `do-while`.
- Condicionales `if` y `else`.
- Estructuras `switch`.
- Operaciones matemáticas.

---

<p align="center">
  <b>✦ Desarrollado con C y un poquito de creatividad. ✦</b>
  <br>
  <i>Elegance is control.</i>
  <br><br>
  <img src="https://img.shields.io/badge/Made_with-C-7C3AED?style=flat-square">
  <img src="https://img.shields.io/badge/By-Salvadiux-A855F7?style=flat-square">
</p>
