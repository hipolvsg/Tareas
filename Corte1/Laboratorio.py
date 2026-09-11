#Laboratorio   
#Central de reciclaje comunitaria
#Un barrio puso en marcha una central de reciclaje. Cada punto de acopio recibe material durante la semana 
#y la junta comunal necesita un programa que registre los pesos y produzca un informe.
#El laboratorio se resuelve completo en C++ y completo en Python.

# --- PARTE A — Arreglos y matrices ---
# Definir una matriz de 4 puntos de acopio × 6 días con los pesos recogidos en kilogramos.
# Calcular e imprimir: total por punto, total por día, el punto más productivo de la semana 
# y el día de menor recolección de toda la central. Informar cuántos registros tienen valor 0.
matriz = [
    [120.5, 0.0, 150.0, 90.5, 200.0, 110.0],
    [85.0, 95.0, 0.0, 105.0, 115.0, 130.0],
    [200.0, 210.0, 190.0, 0.0, 220.0, 215.0],
    [50.0, 60.0, 70.0, 80.0, 90.0, 100.0]
]

total_punto = [sum(fila) for fila in matriz]
total_dia = [sum(matriz[i][j] for i in range(4)) for j in range(6)]
ceros = sum(fila.count(0.0) for fila in matriz)

punto_max = total_punto.index(max(total_punto))
dia_min = total_dia.index(min(total_dia))

print("=== PARTE A ===")
for i, tp in enumerate(total_punto, 1):
    print(f"Total punto {i}: {tp} kg")
for j, td in enumerate(total_dia, 1):
    print(f"Total dia {j}: {td} kg")
print(f"Punto mas productivo: Punto {punto_max + 1}")
print(f"Dia de menor recoleccion: Dia {dia_min + 1}")
print(f"Registros con valor 0: {ceros}\n")


# --- PARTE B — Memoria dinámica y punteros (Equivalente en Python) ---
# Preguntar cuántos puntos registrar, llenarlo con pesos y calcular el promedio.
print("=== PARTE B ===")
n = int(input("Ingrese cantidad de puntos nuevos: "))
pesos = [float(input(f"Peso {i+1}: ")) for i in range(n)]
promedio = sum(pesos) / n if n > 0 else 0
print(f"Promedio: {promedio} kg\n")


# --- PARTE C — Objetos ---
# Clase PuntoAcopio con atributos encapsulados y métodos.
# Clase MaterialEspecial que hereda y redefina la descripción.
# Lista con al menos cuatro objetos mezclando ambas clases y mostrando su descripción.
class PuntoAcopio:
    def __init__(self, codigo, barrio, total_recogido):
        self._codigo = codigo
        self._barrio = barrio
        self._total_recogido = total_recogido

    def registrar_recoleccion(self, kilos):
        if kilos > 0:
            self._total_recogido += kilos

    def supera_meta(self, meta):
        return self._total_recogido >= meta

    def obtener_descripcion(self):
        return f"Punto [Codigo: {self._codigo}, Barrio: {self._barrio}, Total: {self._total_recogido} kg]"


class MaterialEspecial(PuntoAcopio):
    def __init__(self, codigo, barrio, total_recogido, tipo_material):
        super().__init__(codigo, barrio, total_recogido)
        self._tipo_material = tipo_material

    def obtener_descripcion(self):
        return f"Material Especial [Codigo: {self._codigo}, Barrio: {self._barrio}, Total: {self._total_recogido} kg, Tipo: {self._tipo_material}]"


print("=== PARTE C ===")
elementos = [
    PuntoAcopio("P01", "Centro", 450.5),
    MaterialEspecial("M01", "Norte", 120.0, "Electronicos"),
    PuntoAcopio("P02", "Sur", 300.0),
    MaterialEspecial("M02", "Occidente", 215.5, "Pilas")
]

for obj in elementos:
    print(obj.obtener_descripcion())