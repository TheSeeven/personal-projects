// SC_Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>


struct Coordinates {
    char i;
    char j;
};

void display(struct Coordinates coord) {
    printf("%d%d", coord.i,coord.j);
}

char charMatrixUppercase[5][5] = {
    {'A', 'B', 'C', 'D','E'},
    {'F', 'G', 'H', 'I', 'K'},
    {'L', 'M', 'N', 'O','P'},
    {'Q', 'R', 'S', 'T','U'},
    {'V', 'W', 'X', 'Y','Z'},
};


struct Coordinates getCoordinates(char character) {
    struct Coordinates res;
    if (character == 'i' || character == 'j') {
        res.i = 2;
        res.j = 4;
        return res;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((charMatrixUppercase[i][j] == ((character)-32)) || charMatrixUppercase[i][j] == character) {
                res.i = i+1;
                res.j = j+1;
                return res;
            }
        }
    }
}

void criptarePolybus(char* inputString, struct Coordinates* dest) {
    unsigned int resultCounter = 0;
    memset(dest, 0, 50 * sizeof(struct Coordinates));
    for (int i = 0; i < 50; i++) {
        if (inputString[i] == '\n') {
            break;
        }
        if (inputString[i] == ' ') { continue; }
        dest[resultCounter] = getCoordinates(inputString[i]);
        resultCounter++;
    }
}

void decriptarePolybus(struct Coordinates* inputCoordinates) {
    for (int i = 0; i < 50; i++) {
        if (inputCoordinates[i].i == 0) {
            break;
        }
        printf("%c", charMatrixUppercase[inputCoordinates[i].i-1][inputCoordinates[i].j-1]+32);
    }
}

int main()
{   
    struct Coordinates criptedPolybus[50];
    char userInput[50];
    printf("Introduceti textul de criptat: ");
    fgets(userInput, 50, stdin);

    printf("Dupa Polybus: ");
    criptarePolybus(userInput, criptedPolybus);
    for (int i = 0; i < 50; i++) {
        if (criptedPolybus[i].i == 0) break;
        display(criptedPolybus[i]);
    }

    printf("\nDecriptare Polybus: ");
    decriptarePolybus(criptedPolybus);
    return 0;
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
