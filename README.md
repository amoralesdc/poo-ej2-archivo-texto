# Ejercicio 2 - Archivo de texto

Gestor de tareas en C++ con dos modos:

1. **Guardar:** pide al menos 5 tareas y las escribe en `tareas.txt`, una por línea (`std::ofstream`).
2. **Leer:** abre `tareas.txt`, lo lee línea por línea (`std::ifstream`) y muestra las tareas en pantalla.

La lógica está en la clase `GestorTareas`, que tiene la ruta del archivo y un `std::vector<std::string>` con las tareas.

## Compilar y ejecutar
```bash
make
./tareas   # elige 1 para guardar y luego 2 para leer
```
Solo usa la librería estándar (C++17).
