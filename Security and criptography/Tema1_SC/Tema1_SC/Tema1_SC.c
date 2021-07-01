// Tema1_SC.c : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 100
#define CAESAR_KEY 7

struct Coordinates {
	unsigned char x;
	unsigned char y;
};

struct Coordinates* CoordinatesConstructor(unsigned char a, unsigned char b) {
	struct Coordinates* result = malloc(sizeof(struct Coordinates));
	if (result) {
		result->x = a;
		result->y = b;
		return result;
	}
	return 0;
}

const char charMatrixUppercase[5][5] = {
   // 0    1    2    3   4
	{'M', 'Q', 'G', 'V','Y'},  // 0
	{'B', 'O', 'L', 'Z', 'E'}, // 1
	{'D', 'A', 'S', 'X','N'},  // 2
	{'W', 'U', 'C', 'F','I'},  // 3
	{'R', 'K', 'H', 'T','P'},  // 4
};


void cryptCaesar(char* input) {
	for (int i = 0; i < STRING_SIZE; i++) {
		if (input[i] == '\n') {
			break;
		}
		if (input[i] < 97) {
			input[i] = ((input[i] + CAESAR_KEY - 65) % 26) + 65;
		}
		else {
			input[i] = (((input[i] + CAESAR_KEY) - 97) % 26) + 97;
		}
	}
	printf("After Caesar: %s", input);
}


void decryptCaesar(char* input) {
	for (int i = 0; i < STRING_SIZE; i++) {
		if (input[i] == '\n') {
			break;
		}
		if (input[i] > 90) {
			if (((input[i] - CAESAR_KEY) < 97)) {
				input[i] = ((input[i] - CAESAR_KEY) % 26) + ((char)(96 / 26) * 26) + 26;
			}
			else {
				input[i] = input[i] - CAESAR_KEY;
			}
		}
		else {
			if (((input[i] - CAESAR_KEY) < 65)) {
				input[i] = ((input[i] - CAESAR_KEY) % 26) + ((char)(64 / 26) * 26) + 26;
			}
			else {
				input[i] = input[i] - CAESAR_KEY;
			}
		}
	}
	printf("After decript: %s", input);
}

struct Coordinates* getCoordinates(char *ch) {
	if (*ch < 91) {
		*ch = *ch + 32;
	}
	if(*ch == 'j' || *ch == 'i') { return CoordinatesConstructor(3, 4); }
	for (unsigned int x = 0; x < 5; x++) {
		for (unsigned int y = 0; y < 5; y++) {
			if (*ch == (charMatrixUppercase[x][y]+32)) {
				return CoordinatesConstructor(x, y);
			}
		}
	}
	return 0;
}

void cryptBifid(char* input) {
	unsigned char COUNTER = 0;
	struct Coordinates* charCoords[STRING_SIZE];
	char halfresult[STRING_SIZE];
	memset(charCoords, 0, STRING_SIZE * sizeof(struct Coordinates));
	memset(halfresult, 0, STRING_SIZE * sizeof(char));

	for (int i = 0; i < STRING_SIZE; i++) {
		if (input[i] == '\n') break;
		charCoords[i] = getCoordinates(&input[i]);
		COUNTER++;
	}
	for (int i = 0; i < COUNTER; i++) {
		halfresult[i] = charCoords[i]->x + 48;
		halfresult[COUNTER+i] = charCoords[i]->y + 48;
	}
	for (int i = 0; i < COUNTER; i++) {
		input[i] = charMatrixUppercase[halfresult[i*2]-48][halfresult[(i*2)+1] - 48] + 32;
	}
	for (int i = 0; i < COUNTER; i++) {
		free(charCoords[i]);
	}
	printf("Crypt Bifid: %s", input);
}

void decryptBifid(char* input) {

	struct Coordinates* charCoords[STRING_SIZE];
	char halfresult[STRING_SIZE];
	memset(charCoords, 0, STRING_SIZE * sizeof(struct Coordinates));
	memset(halfresult, 0, STRING_SIZE * sizeof(char));
	unsigned int INPUT_LENGTH = (unsigned int)strlen(input)-1;
	unsigned int COUNTER = INPUT_LENGTH;
	for (unsigned int i = 0; i < INPUT_LENGTH; i++) {
		if (input[i] == '\n') break;
		charCoords[i] = getCoordinates(&input[i]);
	}

	for (unsigned int i = 0; i < INPUT_LENGTH*2; i+=2) {
		halfresult[i] = charCoords[i/2]->x;
		halfresult[i+1] = charCoords[i/2]->y;
	}
	for (unsigned int i = 0; i < INPUT_LENGTH; i++) {
		input[i] = charMatrixUppercase[halfresult[i]][halfresult[i + INPUT_LENGTH]] + 32;
	}
	printf("After decrypt Bifid: %s\n", input);
}

void statisticAnalysis(char* inputString) {
	unsigned char frequensisVector[26] ;
	memset(frequensisVector, 0, 26 * sizeof(unsigned char));
	unsigned int INPUT_LENGTH = strlen(inputString) - 1;
	
	for (unsigned int i = 0; i < INPUT_LENGTH; i++) {
		frequensisVector[inputString[i]-97]++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%c : %d\n", i+97, frequensisVector[i]);
	}
}

void cryptAnalysisCaesar(char* inputString) {
	char tempString[STRING_SIZE];
	memset(tempString, 0, STRING_SIZE * sizeof(char));

	unsigned int INPUT_LENGTH = strlen(inputString)-1;

	for (int key = 1; key < 25; key++) {
		for (unsigned int ch = 0; ch < INPUT_LENGTH; ch++) {
			if ((inputString[ch] - key) < 97) {
				tempString[ch] = inputString[ch] - 97 + 123 - key;
			}
			else {
				tempString[ch] = inputString[ch] - key;
			}
		}
		printf("With key %d is %s\n", key, tempString);
		memset(tempString, 0, STRING_SIZE * sizeof(char));
	}
	printf("\nStatistic analysis: \n");
	printf("Caesar Code: %s", inputString);
	statisticAnalysis(inputString);
}

void inputManager(char *inputString) {
	memset(inputString, 0, STRING_SIZE * sizeof(char));
	printf("Input String: ");
	fgets(inputString, STRING_SIZE, stdin);
}


int main()
{
	char inputString[STRING_SIZE];
	inputManager(inputString);
	printf("\nCAESAR\n");


	cryptCaesar(inputString);
	decryptCaesar(inputString);

	printf("\nBIFID\n");

	cryptBifid(inputString);
	decryptBifid(inputString);

	printf("\nTry to crack\n");
	cryptCaesar(inputString);
	cryptAnalysisCaesar(inputString);

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
