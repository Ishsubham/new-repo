#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));
    
    for (int i = 1; i <= 79; i++) {
        int random_number = std::rand() % 10 + 1;
        std::cout << "Random number generated on run " << i << " is: " << random_number << std::endl;
    }
    
    return 0;
}
