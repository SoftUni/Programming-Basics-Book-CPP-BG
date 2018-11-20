#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cout << "*";
    }
    for(int i = 0; i < n - 2; i++) {
        std::cout << std::endl << "*";
        for(int j = 0; j < n - 2; j++) {
            std::cout << " ";
        }
        std::cout << "*";
    }
    std::cout << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << "*";
    }
    return 0;
}
