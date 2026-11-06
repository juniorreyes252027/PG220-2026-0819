# PG220-2026-0819 - Desorden de una agenda de viajes

- **Estudiante:** Junior Nicolás Reyes Ferreras
- **Matrícula:** 2026-0819
- **Correo:** 20260819@itla.edu.do

## Interpretación del problema
Cada unidad es un caso independiente con `id`, `nombre`, `tipo`, `p` y `m` muestras.
El score cuenta las parejas de posiciones i<j que cumplen la desigualdad estricta:
tipo 0 -> `x[i] > x[j] + p`; tipo 1 -> `x[j] > x[i] + p`. `estado = 1` si score = 0.
Las muestras no se ordenan antes de contar.

## Estructura
- `reto.h`: constantes, `Config`, `Registro` y prototipos.
- `main.c`: programa principal y funciones.
- `plan.md`: análisis, pseudocódigo y decisiones.

## Compilación y ejecución
```
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o reto
./reto < pruebas/publica1.in            (Linux/macOS)
reto.exe < pruebas\publica1.in          (Windows cmd)
py evaluar.py publicas.json reto.exe    (casos públicos)
py correr_pruebas.py reto.exe           (todas las pruebas de la carpeta pruebas)
```

## Estado
Etapa 3: programa completo (`ORDER` y `FIND` incluidos) y pruebas públicas y propias.
Falta la media de scores y la documentación final.
