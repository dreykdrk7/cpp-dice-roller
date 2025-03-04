#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>

// Función para obtener un número entero válido del usuario
int getValidInput() {
    int numTiradas;
    while (true) {
        std::cout << "Ingrese el número de tiradas del dado: ";
        std::cin >> numTiradas;

        // Verificar si la entrada es un número entero válido
        if (std::cin.fail() || numTiradas <= 0) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar la entrada inválida
            std::cout << "Por favor, ingrese un número entero válido (mayor que 0)." << std::endl;
        } else {
            break;
        }
    }
    return numTiradas;
}

// Función para simular las tiradas del dado
void simulateDiceRolls(int numTiradas) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    for (int i = 0; i < numTiradas; i++) {
        int dado = dis(gen);
        std::cout << "Tirada " << i + 1 << ": " << dado << std::endl;
    }
}

int main() {
    
    int numTiradas = getValidInput();
    simulateDiceRolls(numTiradas);
    return 0;
}