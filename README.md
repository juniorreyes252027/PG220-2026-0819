# PG220-2026-0819 - Desorden de una agenda de viajes

- **Estudiante:** Junior Nicolás Reyes Ferreras
- **Matrícula:** 2026-0819
- **Correo:** 20260819@itla.edu.do

## Modelo y decisiones
Cada unidad es un registro independiente (`Registro` con `Config` anidada). El score cuenta las
parejas i<j que cumplen la desigualdad estricta según `tipo` y `p`. Se calcula con dos bucles
anidados, sin ordenar las muestras. `score` se reinicia en cada llamada a `calcular`.
Se valida toda la entrada antes de imprimir; si hay error se imprime solo `ERROR`.
`ORDER` y `FIND` usan copias de los registros (inserción por score/id y por id), y `FIND` usa búsqueda binaria.
Ver `plan.md` para el pseudocódigo.

## Compilación y ejecución
```
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o reto
./reto < pruebas/publica1.in            (Linux/macOS)
reto.exe < pruebas\publica1.in          (Windows cmd)
python3 evaluar.py publicas.json ./reto (py evaluar.py publicas.json reto.exe en Windows)
python3 correr_pruebas.py ./reto        (todas las pruebas de pruebas/)
```

## Resultados
Los 6 casos públicos y las 6 pruebas propias dieron OK (12/12). Las salidas obtenidas están en `pruebas/*.obtenido`.

| Prueba | Tipo | Esperado = Obtenido |
|---|---|---|
| publica1 a publica5 | públicas válidas | Sí |
| publica6 | pública inválida (x=101) | Sí (`ERROR`) |
| propia1_normal | normal, ambos tipos | Sí |
| propia2_borde | n=2, m=8, id=9999, p=0 y p=100, valores 0 y 100 | Sí |
| propia3_qausente | q=55 ausente | Sí (`FIND 55 -1`) |
| propia4_invalida_idrepetido | id repetido | Sí (`ERROR`) |
| propia5_invalida_incompleta | entrada incompleta | Sí (`ERROR`) |
| propia6_invalida_tipo | tipo=2 fuera de dominio | Sí (`ERROR`) |

Las salidas esperadas de las pruebas propias se calcularon con un programa independiente en Python (`pruebas/esperado_referencia.py`) y se contrastaron con el programa en C.

## Media de los scores (no se imprime)
Expresión en C: `media = total / (double)n;`

| Caso | total | n | media (2 decimales) |
|---|---|---|---|
| publica1 | 3 | 2 | 1.50 |
| publica4 | 17 | 2 | 8.50 |
| propia1_normal | 21 | 3 | 7.00 |
| propia2_borde | 10 | 2 | 5.00 |

## Fuentes consultadas
- Corona Nakamura y Ancona Valdez (2011). *Diseño de algoritmos y su codificación en lenguaje C*. McGraw-Hill.
- Documentación de la biblioteca estándar de C: `strlen`, `toupper`, `isalnum`, `scanf`.

## Historial de commits
| # | Hash | Avance |
|---|---|---|
| 1 | 53be2c9 | Estructura, interpretación y plan |
| 2 | 2e10479 | Desarrollo parcial verificable |
| 3 | 40b60c4 | Pruebas, validación y revisión |
| 4 |  | Correcciones finales y documentación |

El hash final se entrega aparte, junto al enlace del repositorio.
