#include <iostream>
#include <string>

int main() {
    std::cout << "Enter 4 digit number: ";
    std::string digits;
    while(std::getline(std::cin,digits) && digits.size() != 4) {
        std::cout << "Please enter 4 digit number\n";
    }
    std::cout << digits;
}