# General

- Si tengo todos los elementos de `[1, n]` entonces puedo sumar todos los valores del rango `[0, n*(n+1)/2]`.
- Si puedo obtener todo lo de `[a, b]` mediante sumas y agrego el elemento `c` tq `c <= b+1`, entonces ahora puedo obtener todo lo de `[a, b + c]`.
- Si dado un `i`, me piden ver los valores a la izquierda/derecha de `i` tal que `<= A[i]` o `>= A[i]` es útil crear el array `B` tq `B[i] = {A[i], i}` y ordenarlo lexicograficamente. Luego, es fácil ver cuáles son las <= `A[i]` o >= `A[i]` y cuáles son sus indices. 

	Puedo iterar en orden los elementos y con un set mantener los indices ordenados por si quiero algunos específicos.

- Si quiero reconstruir una solución óptima de DP o grafos, puedo hacer lo siguiente: supongamos que tengo la función `f(i, j)` que me dice el valor óptimo buscado. Puedo, crear la matriz `buildSolution` y en `buildSolution[i][j]` guardar la branch por la que se metió `f(i, j)`.

## TIPS DP 
- Si sé que la cantidad de estados quizás no es tan grande pero el espacio de ellos si lo es, usar `map`

## ERRORES COMUNES
- Si `memo[i][j] = UNDEFINED`, fijarse que `memo[i][j]` nunca pueda valer `-1`
- Si uso un `map` o `unordered_map`, chequear de no estar definiendo keys de más cuando hago una consulta estilo `M[key]`
- Usar un `set` en lugar de un `unordered_set` cuando no me importa el orden

## SUGERENCIAS
- Si estoy haciendo uso de una variable `j` como indice de un vector pero solo la uso para agregar elementos en un orden especifico, entonces conviene hacer `.pb()`. Esto es para ahorrar posibles bugs con el tema de ir incrementando `j`. Además, deja un código más legible.
- Si tengo `n` elementos y los elementos pueden ser muy grandes, cuando no me interesen los valores y quiero llevar frecuencia de ellos, puedo comprimirlos con otro valor y luego con otro vector poder acceder `O(1)` a su frecuencia. Esto sirve para evitar la constance de usar un `unordered_map`

## MATEMATICA
- Sea x un número. Puedo calcular sus divisores $\iff$ puedo factorizarlo en primos
- Las funciones trigonométricas en C++ trabajan en radianes, así que para cualquier ángulo que tenga en grados tengo que previamente convertirlo usando la relación entre 180 y $\pi$

## INTERACTIVOS
- Cada vez que hago `cout` tengo que hacer un `cout.flush()`

## ESTRUCTURAS DE DATOS
- Si tengo un segment tree, y busco el primer elemento que cumple `P(x)`, chequear que si en `query` llego a un intervalo de tamaño 1, asegurarme que el elemento cumpla la propiedad.