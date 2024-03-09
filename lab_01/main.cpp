#include "lab_func.hpp"
#include <iostream>

int main() {
    std::cout << "Type your string(a,b ,c letters only allowed)" << std::endl;
    std::string s;
    std::cin >> s;
    std::cout << lab_func(s) << std::endl;
}
