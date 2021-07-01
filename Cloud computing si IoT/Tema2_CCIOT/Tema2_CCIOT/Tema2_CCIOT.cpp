// Lab2_CCIOT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

static void printVector(std::vector<std::string>& vector) {
    for (auto i : vector) {
        std::cout << i << std::endl;
    }
}

static void eraseOddElements(std::vector<std::string>& vector) {
    bool erase = true;
    std::vector<std::string> result;
    for (std::vector<std::string>::iterator it = vector.begin(); it != vector.end(); ++it)
    {
        if (erase) {
            result.push_back(*it);
            erase = false;
        }
        else {
            erase = true;
        }
    }
    vector = result;
}


static void eraseFifthElemntFromVector(std::vector<std::string>& vector) {
    vector[4].erase();
    unsigned int moveIndex = 4;
    for (int i = moveIndex + 1; i < vector.size(); i++) {
        vector[moveIndex] = vector[i];
        moveIndex++;
    }
    vector.resize(vector.size() - 1);
}

static void replaceFirstAndLast(std::vector<std::string>& vector) {
    *vector.begin() = "FIRST";
    vector[vector.size() - 1] = "LAST";
    std::cout << "\nThe size of vectorr   " << vector.size() << std::endl;
}

int main()
{
    std::vector<std::string> vector;
    for (int i = 0; i < 21; i++) vector.push_back("C++ - " + std::to_string(i));    // Create a vector of whatever type you like (minimum length of 10); 

    printVector(vector);                                                            // Print it�s content;

    std::cout << "\nAfter erasing" << std::endl;                                    // Erase the odd elements;
    eraseOddElements(vector);
    printVector(vector);

    std::cout << "\nAfter replacing the first and last" << std::endl;               // Replace the first element and the last element with another value;
    replaceFirstAndLast(vector);
    printVector(vector);

    std::cout << "\nAfter erasing the fifth element" << std::endl;                  // Create a rule that erases the 5th element from the vector;
    eraseFifthElemntFromVector(vector);
    printVector(vector);
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
