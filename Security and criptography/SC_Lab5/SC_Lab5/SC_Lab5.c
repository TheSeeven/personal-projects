// SC_Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>

#include "aes.h"
#define STRING_SIZE 1024
#define M_HEX 'H'
#define M_CHAR 'C'


void inputManager(char* input) {
	fgets(input, STRING_SIZE, stdin);
}

void cryptAES(char* input) {

}

void decryptAES(char* input) {

}

BYTE** aloc4x4_BYTE_matrix(BYTE* input) {
	BYTE** result = (BYTE**)malloc(4 * sizeof(BYTE*));
	for ( int i = 0; i < 4; i++ ) {
		result[i] = (BYTE*)malloc(4 * sizeof(BYTE*));
		memset(result[i], 0, sizeof(BYTE) * 4);
	}
	unsigned int _stringCounter = 0;
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			if ( _stringCounter >= strlen(input) - 1 ) break;
			result[j][i] = input[_stringCounter];
			_stringCounter++;
		}
	}
	return result;
}

char** aloc4x4_CHAR_matrix(char* input) {
	char** result = (char**)malloc(4 * sizeof(char*));
	for ( int i = 0; i < 4; i++ ) {
		result[i] = (char*)malloc(4 * sizeof(char*));
		memset(result[i], 0, sizeof(char) * 4);
	}
	unsigned int _stringCounter = 0;
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			if ( _stringCounter >= strlen(input) - 1 ) break;
			result[j][i] = input[_stringCounter];
			_stringCounter++;
		}
	}
	return result;
}

void print_4x4(char** input, bool skip_0,char mode) {
	if ( mode == M_HEX ) printf("HEX: \n");
	else printf("CHAR: \n");
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			if ( input[i][j] != 0 )
				if ( mode == M_HEX )
					printf("%X ", input[i][j]);
				else printf("%c ", input[i][j]);
			else
				if ( skip_0 == true )
					printf(" ");
				else printf("X");
		}
		printf("\n");
	}
}

void apply_XOR(BYTE** input, char** key) {
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			input[j][i] = input[j][i] ^ key[j][i];
		}
	}
}

char** stackBuilder(char* input, char *key) {
	BYTE** result = aloc4x4_BYTE_matrix(input);
	char** _key = aloc4x4_CHAR_matrix(key);
	free(_key);
	return result;
}

int main(int argc, char* argv)
{
	char* key = "juolkmnghljoupit";
	char inputMSG[STRING_SIZE];
	inputManager(inputMSG);

	stackBuilder(inputMSG, key);
	printf("helo world! %s",inputMSG);
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
