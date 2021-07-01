// SC_Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 100
#define KEY 3


struct StringOccurence {
    char* string;
    unsigned int occurences;
};

struct StringOccurence* ConstructorStringOccurence(char* string) {
    struct StringOccurence* result  = malloc(sizeof(struct StringOccurence));
    if (result) {
        result->string=*string;
        result->occurences = 1;
        return result;
    }
    return 0;
}

void incrementOccurence(struct StringOccurence* entity) {
    if (entity) {
        entity->occurences++;
    }
}

void getIterator(char* out, char* in,int index) {
    int count = 0;
    for (int i = index; i < strlen(in); i++) {
        if (count < KEY) {
            out[count] = in[i];
            count++;
        }
        else {
            break;
        }
    }
}

char* Kasiski(char* input) {
    struct StringOccurence* frequency[10] = { 0 };
    int _counter_frequency = 0;
    char iterator[KEY + 1] = {0};
    int _length_input = strlen(input);




    for (int i = 0; i+KEY < _length_input; i++) {
        getIterator(iterator, input, i);
        frequency[_counter_frequency] = ConstructorStringOccurence(iterator);
        _counter_frequency++;
    }

    return 0;
}


void inputManager(char* input) {
    fgets(input, STRING_SIZE, stdin);
}


int main()
{
    char input[STRING_SIZE] = {0};
    inputManager(input);
    Kasiski(input);
  
    //Kasiski(input);
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
