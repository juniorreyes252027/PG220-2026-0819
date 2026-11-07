/* reto.h - PG220 | Matricula 2026-0819 | Desorden de una agenda de viajes */
#ifndef RETO_H
#define RETO_H

/* Constantes de capacidad y dominio */
#define MAX_UNIDADES 20
#define MAX_MUESTRAS 8
#define TAM_NOMBRE   16      /* 15 caracteres + '\0' */
#define MAX_LONG_NOMBRE 15
#define VALOR_MIN    0
#define VALOR_MAX    100
#define ID_MIN       1
#define ID_MAX       9999

/* Configuracion anidada de cada unidad */
typedef struct {
    int tipo;   /* 0 o 1 */
    int p;      /* 0..100 */
} Config;

/* Registro de una unidad */
typedef struct {
    int  id;
    char nombre[TAM_NOMBRE];
    Config config;
    int  score;
    int  estado;   /* 1 si score == 0, si no 0 */
} Registro;

/* Cuenta las parejas i<j que cumplen la regla; devuelve el score.
   Convierte nombre a mayusculas y devuelve el estado por referencia. */
int calcular(const int x[], int m, int tipo, int p, char nombre[], int *estado);

/* Suma recursiva de los scores (caso base n == 0). */
int total_rec(const Registro v[], int n);

/* Ordena (insercion). criterio 0: score descendente y id ascendente.
   criterio 1: id ascendente. */
void ordenar(Registro v[], int n, int criterio);

/* Busqueda binaria por id en un vector ordenado por id.
   Devuelve la posicion o -1 si no existe. */
int buscar(const Registro v[], int n, int id);

/* Media de los scores (se documenta en el README, no se imprime). */
double media_scores(int total, int n);

#endif /* RETO_H */
