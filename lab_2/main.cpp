#include <iostream>
#include "Thirteen.h"

int main() {
    try {

        Thirteen num1("1A");
        Thirteen num2("2B");


        std::cout << "num1: " << num1.toString() << std::endl;
        std::cout << "num2: " << num2.toString() << std::endl;

        Thirteen sum = num1 + num2;
        std::cout << "num1 + num2: " << sum.toString() << std::endl;

        num1 += num2;
        std::cout << "num1 += num2: " << num1.toString() << std::endl;


    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
