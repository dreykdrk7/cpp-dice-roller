#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    
    int numTiradas;
    std::cout << "Ingrese el número de tiradas del dado: ";
    std::cin >> numTiradas;

    for (int i = 0; i < numTiradas; i++) {
        int dado = std::rand() % 6 + 1;
        std::cout << "Tirada " << i + 1 << ": " << dado << std::endl;
    }

    return 0;
}