#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Clase que guarda y lee una lista de tareas en un archivo de texto
class GestorTareas {
public:
    explicit GestorTareas(std::string ruta) : ruta(std::move(ruta)) {}

    void agregar(const std::string& tarea) { tareas.push_back(tarea); }

    // Modo 1: escribe cada tarea en una linea del archivo
    bool guardar() const {
        std::ofstream archivo(ruta);
        if (!archivo) return false;
        for (const auto& t : tareas) archivo << t << "\n";
        return true;
    }

    // Modo 2: lee el archivo linea por linea
    bool cargar() {
        std::ifstream archivo(ruta);
        if (!archivo) return false;
        tareas.clear();
        std::string linea;
        while (std::getline(archivo, linea))
            if (!linea.empty()) tareas.push_back(linea);
        return true;
    }

    void mostrar() const {
        std::cout << "\n--- Tareas pendientes (" << tareas.size() << ") ---\n";
        for (std::size_t i = 0; i < tareas.size(); ++i)
            std::cout << i + 1 << ". " << tareas[i] << "\n";
    }

    std::size_t cantidad() const { return tareas.size(); }

private:
    std::string ruta;
    std::vector<std::string> tareas;
};

int main() {
    GestorTareas gestor("tareas.txt");
    std::string opcion;

    std::cout << "=== Gestor de tareas ===\n"
              << "1) Guardar tareas en archivo\n"
              << "2) Leer tareas del archivo\n"
              << "Elige un modo: ";
    std::getline(std::cin, opcion);

    if (opcion == "1") {
        std::cout << "Escribe tus tareas (minimo 5). Linea vacia para terminar:\n";
        std::string tarea;
        while (true) {
            std::cout << "> ";
            if (!std::getline(std::cin, tarea)) break;
            if (tarea.empty()) {
                if (gestor.cantidad() >= 5) break;
                std::cout << "  Llevas " << gestor.cantidad() << ", necesitas al menos 5\n";
                continue;
            }
            gestor.agregar(tarea);
        }
        if (gestor.guardar())
            std::cout << "Se guardaron " << gestor.cantidad() << " tareas en tareas.txt\n";
        else
            std::cout << "No se pudo escribir el archivo\n";
    } else if (opcion == "2") {
        if (gestor.cargar()) gestor.mostrar();
        else std::cout << "No existe tareas.txt, primero usa el modo 1\n";
    } else {
        std::cout << "Opcion no valida\n";
    }
    return 0;
}
