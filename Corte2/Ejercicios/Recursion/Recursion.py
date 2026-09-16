#recursion
import time
#definición de la función factorial y fibonacci con impresión de nivel de recursión
def factorial(n):
    #flag para controlar el nivel de recursión
    print(f'factorial({n}) \n')
    global nivel
    nivel += 1
    print(f'evalua {n} en nivel: {nivel}')
        #caso base
    if n == 0:
        nivel -= 1
        return 1
    else:
        #caso recursivo
        result = n * factorial(n - 1)
        nivel -= 1
        if n == 1:
            print(f'finaliza {n} en nivel: {nivel}')
            print(f'resultado: {result}')
        return result
def fibonacci(n):
    print(f'fibonacci({n}) \n')
    global nivel
    nivel += 1
    print(f'evalua {n} en nivel: {nivel}')
        #caso base
    if n <= 1:
        nivel -= 1
        return n
    else:
        #caso recursivo
        result = fibonacci(n - 1) + fibonacci(n - 2)
        nivel -= 1
        if n == 1:
            print(f'finaliza {n} en nivel: {nivel}')
            print(f'resultado: {result}')
        return result


#ejecución de factorial y fibonacci + definición de nivel
nivel = 4
factorial(nivel)
print('\n')
nivel = 5
factorial(nivel)

print('\n')
nivel = 5
inicio = time.perf_counter()
resultado = factorial(nivel)
fin = time.perf_counter()
print(f"Tiempo de ejecución: {fin - inicio} segundos")

print ('\n')
nivel = 10
inicio = time.perf_counter()
resultado = factorial(nivel)
fin = time.perf_counter()
print(f"Tiempo de ejecución: {fin - inicio} segundos")


print ('\n')
nivel = 15
inicio = time.perf_counter()
resultado = factorial(nivel)
fin = time.perf_counter()
print(f"Tiempo de ejecución: {fin - inicio} segundos")

#verificación de tiempo de ejecución de fibonacci

print('\n')
nivel = 5
inicio = time.perf_counter()
resultado = factorial(nivel)
fin = time.perf_counter()
print(f"Tiempo de ejecución: {fin - inicio} segundos")

#TAREA: Consultar recursión matemática y backtracking, y explicar la diferencia entre ambas.