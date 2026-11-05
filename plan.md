# Plan - PG220 | Matrícula 2026-0819

## 1. Análisis
- **Entrada:** `n m q`, luego n registros `id nombre tipo p x1..xm`.
- **Salida:** una línea por unidad (`id NOMBRE score estado`), luego `TOTAL`, `ORDER`, `FIND`.
- **Regla:** para toda pareja i<j: tipo 0 cuenta si `x[i] > x[j] + p`; tipo 1 cuenta si `x[j] > x[i] + p`.
  `estado = 1` si score = 0. No se ordenan las muestras.
- **Errores:** valor fuera de dominio, id repetido o entrada incompleta → imprimir solo `ERROR`.

## 2. Pseudocódigo
```
leer_entrada():
    leer n, m, q y validar dominio
    para cada unidad i:
        leer id, nombre, tipo, p y validar
        leer m muestras y validar 0..100
        si id repetido -> error
    si algo falla -> devolver error

principal:
    si leer_entrada falla: imprimir ERROR; terminar
    para cada unidad: score = calcular(...)        # score empieza en 0 cada vez
    imprimir unidades en orden original
    total = total_rec(registros, n)
    copia1 = registros; ordenar(copia1, score desc, id asc); imprimir ORDER
    copia2 = registros; ordenar(copia2, id asc); pos = buscar(copia2, q)
    imprimir FIND q (score o -1)

calcular(x, m, tipo, p, nombre, *estado):
    score = 0
    para i de 0 a m-2:
        para j de i+1 a m-1:
            si tipo==0 y x[i] > x[j]+p: score++
            si tipo==1 y x[j] > x[i]+p: score++
    nombre -> mayúsculas
    *estado = (score==0)
    devolver score

total_rec(v, n): si n==0 -> 0; si no -> v[n-1].score + total_rec(v, n-1)

ordenar: inserción con comparación según criterio
buscar: búsqueda binaria (bajo, alto, medio) sobre copia ordenada por id
```

## 3. Decisiones
- `muestras[20][8]` y `Registro` con `Config` anidada (tipo, p).
- Se valida todo antes de imprimir, para no dar resultados parciales.
- Se ordenan copias de los registros; el vector original conserva el orden de entrada.
- Sin `qsort`, `bsearch`, `gets`, memoria dinámica ni `conio.h`.
