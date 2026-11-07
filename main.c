/* main.c - PG220 | Matricula 2026-0819 | Correo 20260819@itla.edu.do
   Desorden de una agenda de viajes */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "reto.h"

/* ---------- Funciones del reto ---------- */

int calcular(const int x[], int m, int tipo, int p, char nombre[], int *estado)
{
    int score = 0;          /* se reinicia en cada llamada: no arrastra memoria */
    int i, j;
    size_t k, largo;

    for (i = 0; i < m - 1; i++) {
        for (j = i + 1; j < m; j++) {
            if (tipo == 0 && x[i] > x[j] + p) {
                score++;
            } else if (tipo == 1 && x[j] > x[i] + p) {
                score++;
            }
        }
    }

    largo = strlen(nombre);
    for (k = 0; k < largo; k++) {
        nombre[k] = (char)toupper((unsigned char)nombre[k]);
    }

    *estado = (score == 0) ? 1 : 0;
    return score;
}

int total_rec(const Registro v[], int n)
{
    if (n == 0) {
        return 0;
    }
    return v[n - 1].score + total_rec(v, n - 1);
}

/* true si a debe ir antes que b segun el criterio */
static int va_antes(const Registro *a, const Registro *b, int criterio)
{
    if (criterio == 1) {
        return a->id < b->id;
    }
    if (a->score != b->score) {
        return a->score > b->score;
    }
    return a->id < b->id;
}

void ordenar(Registro v[], int n, int criterio)
{
    int i, j;
    Registro clave;

    for (i = 1; i < n; i++) {
        clave = v[i];
        j = i - 1;
        while (j >= 0 && va_antes(&clave, &v[j], criterio)) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = clave;
    }
}

int buscar(const Registro v[], int n, int id)
{
    int bajo = 0;
    int alto = n - 1;
    int medio;

    while (bajo <= alto) {
        medio = bajo + (alto - bajo) / 2;
        if (v[medio].id == id) {
            return medio;
        } else if (v[medio].id < id) {
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }
    return -1;
}

double media_scores(int total, int n)
{
    return total / (double)n;
}

/* ---------- Validacion auxiliar ---------- */

static int nombre_valido(const char *s)
{
    size_t i, largo = strlen(s);

    if (largo < 1 || largo > MAX_LONG_NOMBRE) {
        return 0;
    }
    for (i = 0; i < largo; i++) {
        if (!(isalnum((unsigned char)s[i]) || s[i] == '_')) {
            return 0;
        }
    }
    return 1;
}

/* Lee y valida TODA la entrada. Devuelve 1 si es valida, 0 si hay error. */
static int leer_entrada(int *n, int *m, int *q, Registro reg[],
                        int muestras[MAX_UNIDADES][MAX_MUESTRAS])
{
    int i, j, k;
    char buffer[64];

    if (scanf("%d %d %d", n, m, q) != 3) return 0;
    if (*n < 1 || *n > MAX_UNIDADES) return 0;
    if (*m < 1 || *m > MAX_MUESTRAS) return 0;
    if (*q < ID_MIN || *q > ID_MAX) return 0;

    for (i = 0; i < *n; i++) {
        if (scanf("%d %63s %d %d", &reg[i].id, buffer,
                  &reg[i].config.tipo, &reg[i].config.p) != 4) return 0;
        if (reg[i].id < ID_MIN || reg[i].id > ID_MAX) return 0;
        if (!nombre_valido(buffer)) return 0;
        strcpy(reg[i].nombre, buffer);
        if (reg[i].config.tipo != 0 && reg[i].config.tipo != 1) return 0;
        if (reg[i].config.p < 0 || reg[i].config.p > 100) return 0;

        for (j = 0; j < *m; j++) {
            if (scanf("%d", &muestras[i][j]) != 1) return 0;
            if (muestras[i][j] < VALOR_MIN || muestras[i][j] > VALOR_MAX) return 0;
        }
        for (k = 0; k < i; k++) {              /* id repetido */
            if (reg[k].id == reg[i].id) return 0;
        }
    }
    return 1;
}

/* ---------- Programa principal ---------- */

int main(void)
{
    int muestras[MAX_UNIDADES][MAX_MUESTRAS];
    Registro registros[MAX_UNIDADES];
    Registro copia[MAX_UNIDADES];
    int n, m, q, i, total, pos;
    double media;

    if (!leer_entrada(&n, &m, &q, registros, muestras)) {
        printf("ERROR\n");
        return 0;
    }

    /* Cada unidad se calcula por separado */
    for (i = 0; i < n; i++) {
        registros[i].score = calcular(muestras[i], m, registros[i].config.tipo,
                                      registros[i].config.p, registros[i].nombre,
                                      &registros[i].estado);
    }

    /* Resultados en el orden original */
    for (i = 0; i < n; i++) {
        printf("%d %s %d %d\n", registros[i].id, registros[i].nombre,
               registros[i].score, registros[i].estado);
    }

    total = total_rec(registros, n);
    printf("TOTAL %d\n", total);

    /* ORDER: copia ordenada por score desc / id asc */
    for (i = 0; i < n; i++) copia[i] = registros[i];
    ordenar(copia, n, 0);
    printf("ORDER");
    for (i = 0; i < n; i++) printf(" %d", copia[i].id);
    printf("\n");

    /* FIND: copia ordenada por id y busqueda binaria */
    for (i = 0; i < n; i++) copia[i] = registros[i];
    ordenar(copia, n, 1);
    pos = buscar(copia, n, q);
    printf("FIND %d %d\n", q, (pos >= 0) ? copia[pos].score : -1);

    media = media_scores(total, n);   /* solo para el README, no se imprime */
    (void)media;

    return 0;
}
