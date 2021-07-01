// Tema2_SC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Kasisky.h"



unsigned char cryptAnalysisVector[26] = { 0 };
const double constStatisticVector[26] = { 8.2,1.5,2.8,4.3,13.0,2.2,2.0,6.1,7.0,0.15,0.77,4.0,2.4,6.7,7.5,1.9,0.09,6.0,6.3,9.1,2.8,0.98,2.4,0.15,2.0,0.07 };

const char charMatrixLowercase[26][26] = {
	{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
	{'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
	{'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
	{'d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
	{'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
	{'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
	{'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
	{'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
	{'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
	{'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
	{'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
	{'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
	{'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
	{'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
	{'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
	{'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
	{'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
	{'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
	{'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
	{'t', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
	{'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
	{'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
	{'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
	{'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
	{'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
	{'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}
};


void crypt(char* inputString, char* keyword,boolean silencePrint) {
	
	char temp[INPUT_SIZE] = { 0 };

	unsigned int COUNTER = 0;
	unsigned int LENGTH = strlen(inputString) - 1;
	unsigned int KEYWORD_LENGTH = strlen(keyword) - 1;
	for ( unsigned int i = 0; i < LENGTH; i++ ) {
		temp[i] = keyword[COUNTER];
		COUNTER++;
		if ( COUNTER > KEYWORD_LENGTH || keyword[COUNTER] == '\n' ) {
			COUNTER = 0;
		}
	}
	for ( int i = 0; i < LENGTH; i++ ) {
		inputString[i] = charMatrixLowercase[temp[i] - 97][inputString[i] - 97];
	}
	if(silencePrint == False)
	printf("Crypt Vigenere: %s\n", inputString);

}

void decrypt(char* inputString, char* keyword,boolean Assgin,boolean Print) {
	char AlternateResult[100] = { 0 };
	char temp[INPUT_SIZE] = {0};
	unsigned int COUNTER = 0;
	unsigned int LENGTH = strlen(inputString) - 1;
	unsigned int KEYWORD_LENGTH = strlen(keyword) - 1;
	for ( unsigned int i = 0; i < LENGTH; i++ ) {
		temp[i] = keyword[COUNTER];
		COUNTER++;
		if ( COUNTER > KEYWORD_LENGTH || keyword[COUNTER] == '\n' ) {
			COUNTER = 0;
		}
	}
	int x;
	int y = 0;
	for ( int i = 0; i < LENGTH; i++ ) {
		x = temp[i] - 97;
		for ( int j = 0; j < 26; j++ ) {
			if ( charMatrixLowercase[x][j] != inputString[i] ) y++;
			else break;
		}
		if ( Assgin == True )
			inputString[i] = charMatrixLowercase[0][y];
		else 	{
			AlternateResult[i] = charMatrixLowercase[0][y];
		}
		y = 0;
	}
	if ( Print == True && Assgin == False ) {
		printf("Decrypt Vigenere: %s\n", AlternateResult);
	}
	else if ( Print == True ) {
		printf("Decrypt Vigenere: %s\n", inputString);
	}
	
	
}

void statisticCryptAnalysis(char* inputString) {
	unsigned int INPUT_LENGTH = strlen(inputString) - 1;

	for ( unsigned int i = 0; i < INPUT_LENGTH; i++ ) {
		cryptAnalysisVector[inputString[i] - 97]++;
	}
}



int gcd(int a, int b) {
	if ( a == 0 )
		return b;
	return gcd(b % a, a);
}

int findGCD(int arr[10]) {
	int result = arr[0];
	for ( int i = 1; i < 10; i++ ) {
		if ( arr[i] == 0 ) break;
		result = gcd(arr[i], result);
		if ( result == 1 ) {
			return 1;
		}
	}
	return result;
}


int* breakPassword(int key_length) {
	char  result[50] = { 0 };
	boolean notSearch[26] = {0};
	for ( int i = 0; i < 26; i++ ) {
		notSearch[i] = False;
	}
	int _lastMaxIndex = 0;
	int _counterResult = 0;
	for ( int i = 0; i < key_length; i++ ) {
		int max = 0;
		for ( int j = 0; j < 26; j++ ) {
			if ( cryptAnalysisVector[j] > max && notSearch[j] != True ) {
					max = cryptAnalysisVector[j];
					_lastMaxIndex = j;
			}
		}
		notSearch[_lastMaxIndex] = True;
		result[_counterResult] = _lastMaxIndex+97;
		_counterResult++;
	}
	return result;

}

void cryptAnalysis(char* input, char* keyword) {
	char copyInput[INPUT_SIZE] = { 0 };
	strcpy(copyInput, input);
	crypt(copyInput, keyword,True);

	//struct StringOccurence* frequency[100] = { 0 };
	struct StringOccurence* frequency = Kasisky(input);

	

	statisticCryptAnalysis(copyInput);

	int tempDistances[10] = { 0 };
	int curentGCD;

	char result[100] = { 0 };
	int _counterResult = 0;
	for ( int i = 0; i < 100; i++ ) {
		if ( (struct StringOccurence*)frequency[i].nextDist == 0) break;
		for ( int j = 0; j < 10; j++ ) {
			if ( (struct StringOccurence*)frequency[i].distance[j] == 0 ) break;
			else {
				tempDistances[j] = (struct StringOccurence*)frequency[i].distance[j];
			}
		}
		curentGCD = findGCD(tempDistances);
		char* frequencyCommonVector = breakPassword(curentGCD);
		
		for ( int k = 0; k < 50; k++ ) {
			if ( frequencyCommonVector[k] == 0 ) break; 
			else {
				char x = frequencyCommonVector[k] - 4;
				if ( x < 97 ) {
					x += 26;
				}
				result[_counterResult] = x;
				_counterResult++;
			}
		}
		_counterResult = 0;
		decrypt(copyInput, result, False, True);
		memset(result, 0, 100);
	}
	
}

void inputManager(char* inputString, char* keyword) {
	printf("Input String: ");
	fgets(inputString, INPUT_SIZE, stdin);

	printf("Input Keyword: ");
	fgets(keyword, INPUT_SIZE, stdin);
	printf("\n");
}

int main(void) {
	char userInput[100] = {0};
	char keyword[100] = {0};

	inputManager(userInput, keyword);
	printf("Crypting Vigenere: \n");
	crypt(userInput, keyword,False);
	printf("After Decrypt: \n");

	decrypt(userInput, keyword,True,True);
	printf("After Crypt Analisis: \n");
	cryptAnalysis(userInput, keyword);


	
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
