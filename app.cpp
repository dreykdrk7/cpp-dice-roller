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

int main() {
    std::srand(std::time(0));
    
    int numTiradas = getValidInput();

    for (int i = 0; i < numTiradas; i++) {
        int dado = std::rand() % 6 + 1;
        std::cout << "Tirada " << i + 1 << ": " << dado << std::endl;
    }

    return 0;
}