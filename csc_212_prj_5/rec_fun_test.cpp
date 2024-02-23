#include "rec_fun.h" //rec_fun header file
#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::cout << "Testing triangular pattern:" << std::endl;
    triangle(std::cout, 3, 5);

    std::cout << "\nTesting binary print:" << std::endl;
    binary_print(std::cout, 27);
    std::cout << std::endl;
    binary_print(std::cout, 4);
    std::cout << std::endl;

    std::cout << "\nTesting power function:" << std::endl;
    double result = pow(2, 3);
    std::cout << "Result: " << result << std::endl;

    std::cout << "\nTesting indented sentences:" << std::endl;
    indented_sentences(1, 4);

    return 0;
}