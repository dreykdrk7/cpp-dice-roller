#include <iostream>
#include <limits>
#include <random>
#include <map>
#include <vector>
#include <fstream>
#include <string>

// Función para obtener un número entero válido del usuario
int getValidInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        // Verificar si la entrada es un número entero válido
        if (std::cin.fail() || value <= 0) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar la entrada inválida
            std::cout << "Por favor, ingrese un número entero válido." << std::endl;
        } else {
            break;
        }
    }
    return value;
}

// Función para obtener una cadena válida del usuario
std::string getValidString(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);

        // Verificar si la entrada es una cadena válida
        if (value.empty()) {
            std::cout << "Por favor, ingrese una cadena válida." << std::endl;
        } else {
            break;
        }
    }
    return value;
}

// Función para simular las tiradas del dado
std::vector<int> simulateDiceRolls(int numTiradas, int numLados) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, numLados);

    std::vector<int> results;
    for (int i = 0; i < numTiradas; i++) {
        int dado = dis(gen);
        std::cout << "Tirada " << i + 1 << ": " << dado << std::endl;
        results.push_back(dado);
    }

    return results;
}

// Función para mostrar estadísticas de las tiradas
void showStatistics(const std::vector<int>& results, int numLados) {
    std::map<int, int> frequency;
    for (int result : results) {
        frequency[result]++;
    }

    std::cout << "\nEstadísticas de las tiradas:" << std::endl;
    for (int i = 1; i <= numLados; i++) {
        if (frequency[i] > 0) {
            std::cout << "Número " << i << ": " << frequency[i] << " veces" << std::endl;
            continue;
        }
    }
}

// Función para guardar los resultados y estadísticas en un archivo
void saveResultsToFile(const std::vector<int>& results, int numLados, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        return;
    }

    file << "Resultados de las tiradas:" << std::endl;
    for (size_t i = 0; i < results.size(); i++) {
        file << "Tirada " << i + 1 << ": " << results[i] << std::endl;
    }

    std::map<int, int> frequency;
    for (int result : results) {
        frequency[result]++;
    }

    file << "\nEstadísticas de las tiradas:" << std::endl;
    for (int i = 1; i <= numLados; i++) {
        if (frequency[i] > 0) {
            file << "Número " << i << ": " << frequency[i] << " veces" << std::endl;
        }
    }

    file.close();
    std::cout << "Los resultados y estadísticas se han guardado en " << filename << std::endl;
}

int main() {

    std::map<int, int> tiposDeDados = {
        {4, 4},
        {6, 6},
        {8, 8},
        {10, 10},
        {12, 12},
        {20, 20}
    };

    std::cout << "Seleccione el tipo de dado:" << std::endl;
    for (const auto& dado : tiposDeDados) {
        std::cout << "D" << dado.first << std::endl;
    }

    int tipoDado = getValidInput("Ingrese el número de lados del dado (4, 6, 8, 10, 12, 20): ");
    while (tiposDeDados.find(tipoDado) == tiposDeDados.end()) {
        std::cout << "Por favor, ingrese un tipo de dado válido." << std::endl;
        tipoDado = getValidInput("Ingrese el número de lados del dado (4, 6, 8, 10, 12, 20): ");
    }

    int numTiradas = getValidInput("Ingrese el número de tiradas del dado: ");
    while (numTiradas <= 0) {
        std::cout << "Por favor, ingrese un número válido de tiradas (mayor que 0)." << std::endl;
        numTiradas = getValidInput("Ingrese el número de tiradas del dado: ");
    }

    std::vector<int> results = simulateDiceRolls(numTiradas, tipoDado);
    showStatistics(results, tipoDado);
    
    std::string saveOption;
    std::cout << "¿Desea guardar los resultados y estadísticas en un archivo? (s/n): ";
    std::cin >> saveOption;
    if (saveOption == "s" || saveOption == "S") {
        std::cin.ignore(); // Ignorar el salto de línea pendiente
        std::string filename = getValidString("Ingrese el nombre del archivo (sin extensión): ") + ".txt";
        saveResultsToFile(results, tipoDado, filename);
    }
    return 0;
}