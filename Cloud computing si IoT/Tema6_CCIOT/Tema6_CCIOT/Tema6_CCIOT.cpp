// Tema6_CCIOT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


template<typename T>
int squareSum(T number){
    return number * number;
}

template<typename T, typename... Args>
int squareSum(T number, Args... args) {
    return squareSum(number) + squareSum(args...);
}

template<typename T>
T maximum(T n1, T n2){
    if ( n1 > n2 ) return n1;
        return n2;
}

template<typename T, typename... Args>
T maximum(T n1, Args... args) {
    T max = maximum(args...);
    if ( n1 > max )
        return n1;
    else
        return max;
}


int main() {
    std::cout << "All squares: " << squareSum(3) << std::endl;
    std::cout << "The max is: " << maximum(13,2) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
