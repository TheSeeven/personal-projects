#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 100
#define KEY 3

#define INPUT_SIZE 100
typedef enum { False, True } boolean;


struct StringOccurence {
	char* string;
	unsigned int distance[10];
	unsigned int occurences;
	unsigned int nextDist;
};

struct StringOccurence* ConstructorStringOccurence(char* string, unsigned int distance) {
	struct StringOccurence* result = malloc(sizeof(struct StringOccurence));
	if ( result ) {
		result->string = malloc(10);
		strcpy(result->string, string);
		for ( int i = 0; i < 10; i++ ) {
			result->distance[i] = 0;
		}
		result->distance[0] = distance;
		result->occurences = 1;
		result->nextDist = 1;
		return result;
	}
	return 0;
}

unsigned int ocurences(char* input, struct StringOccurence *frequency[100]) {
	unsigned int result = 0;
	for ( int i = 0; i < 100; i++ ) {
		if ( !frequency[i] )break;
		if ( strcmp(input, frequency[i]->string) == 0)
			result++;
	}
	return result;
}

boolean exists(char* input, struct StringOccurence* frequency) {
	for ( int i = 0; i < 100; i++ ) {
		if ( (struct StringOccurence*)frequency[i].nextDist == 0 )break;
		if ( strcmp(input, (struct StringOccurence*)frequency[i].string) == 0 ) {
			return True;
			break;
		}
	}
	return False;
}

void increment(char* input, struct StringOccurence* frequency[100],unsigned int distance) {
	for ( int i = 0; i < 100; i++ ) {
		if ( !frequency[i] )break;
		if ( strcmp(input, frequency[i]->string) == 0 ) {
			frequency[i]->occurences++;
			frequency[i]->distance[frequency[i]->nextDist] = distance;
			frequency[i]->nextDist++;
			break;
		}
	}
}

struct StringOccurence* Kasisky(char* input) {
	struct StringOccurence* frequency = (struct StringOccurence*)malloc(sizeof(struct StringOccurence) * 100);
	memset(frequency, 0, sizeof(struct StringOccurence*) * 100);
	char tempString[10] = { 0 };
	long _counterFrequency = 0;
	long _counterTempString = 0;

	long minlen = 3;
	long textlen = strlen(input);
	long i, j, i0 = -1, k0 = 0;

	for ( i = 0; i < textlen; i++ ) {
		for ( j = i + 1; j < textlen; j++ ) {
			if ( input[i] == input[j] ) {
				long k, l;
				for ( k = 0; input[i + k] == input[j + k]; k++ ) {}
				if ( k >= minlen && (i > i0 + k0 || k - k0 > i - i0) ) {
					i0 = i; k0 = k;
					for ( l = 0; l < k; l++ ) { 
						tempString[_counterTempString] = input[i + l];
						_counterTempString++;
					}
					if ( exists(tempString, frequency) == True ) {
						increment(tempString, frequency,j-i);
					}
					else {
						frequency[_counterFrequency] = *ConstructorStringOccurence(tempString, j - i);
						_counterFrequency++;
					}
					memset(tempString,0, 10);
					_counterTempString = 0;
				}
			}
		}
	}

	return frequency;
}