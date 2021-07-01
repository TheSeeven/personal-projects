// CriptareMesaje.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

char KEY = 1;

void caesar(char* input) {
	for (int i = 0; i < 20; i++) {
		if (input[i] == '\n') {
			break;
		}
		if (input[i] < 97) {
			input[i] = ((input[i] + KEY - 65) % 26) + 65;
		}
		else {
			input[i] = (((input[i] + KEY) - 97) % 26) + 97;
		}

	}
}

void decript(char* input) {
	for (int i = 0; i < 20; i++) {
		if (input[i] == '\n') {
			break;
		}
		if (input[i] > 90) {
			if (((input[i] - KEY) < 97)) {
				input[i] = ((input[i] - KEY) % 26) + ((char)(96 / 26) * 26) + 26;
			}
			else {
				input[i] = input[i] - KEY;
			}
		}
		else {
			if (((input[i] - KEY) < 65)) {
				input[i] = ((input[i] - KEY) % 26) + ((char)(64 / 26) * 26) + 26;
			}
			else {
				input[i] = input[i] - KEY;
			}
		}
	}
}


int main()
{
	char inputString[20];
	memset(inputString, 0, 20 * sizeof(char));
	printf("Input String: ");
	fgets(inputString, 20, stdin);
	printf("Before Caesar:  %s", inputString);
	caesar(inputString);
	printf("After Caesar: %s", inputString);
	decript(inputString);
	printf("After decript: %s", inputString);
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
