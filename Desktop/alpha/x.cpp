#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>


int main() {
    const int size = 79;
    int numbers[size];
    for (int i = 0; i < size; ++i) {
        numbers[i] = i + 1;
    }

    int prev_permutation[size] = {0};
    std::ifstream file("previous_permutation.txt");
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file >> prev_permutation[i];
        }
        file.close();
    }

    int permutation[size] = {0};
    std::default_random_engine rng(std::chrono::system_clock::now().time_since_epoch().count());
    do {
        std::shuffle(numbers, numbers + size, rng);
        std::copy(numbers, numbers + size, permutation);
    } while (std::equal(permutation, permutation + size, prev_permutation));

    for (int i = 0; i < size; ++i) {
        std::cout << permutation[i] << " ";
    }
    std::cout << std::endl;

    std::ofstream outfile("previous_permutation.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outfile << permutation[i] ;
        }
        outfile.close();
        std::cout<< std::endl;
    }

    return 0;
}
