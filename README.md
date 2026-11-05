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

## Estado
Etapa 1: estructura y plan. El cálculo se implementa en las siguientes etapas.

### Avance etapa 2
Implementados: lectura con validación, `calcular`, `total_rec` y líneas de resultado + `TOTAL`.
Pendiente: `ordenar`, `buscar`, `ORDER`, `FIND` y las pruebas completas.
Verificado a mano con `pruebas/publica1.in` (esperado parcial: `30 ABA11 0 1`, `10 LIBRO9 3 0`, `TOTAL 3`)
y con `pruebas/publica6.in` (esperado `ERROR`).
