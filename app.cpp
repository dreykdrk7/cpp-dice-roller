#include <iostream>
#include <limits>
#include <random>
#include <map>
#include <vector>

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
    
    return 0;
}