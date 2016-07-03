#include <stdio.h>
#include <stdlib.h>
#include "iofile.h"

/* Miscellaneous */
static long getFileSize(FILE *f) {
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);

	return size;
}
void printBase(const void *buffer, long size, int base) {
	#define bin 0
	#define oct 1
	#define hex 2

	if (base == bin) { /* Print Binary */
		for (long i = 0; i < size; i++) {
			unsigned char n = ((unsigned char*)buffer)[i];

			for (int i = 7; i >= 0; i--) {
				if ((n >> i) & 1) {
					printf("1");
				}
				else {
					printf("0");
				}
			}

			printf(" ");
		}
	}
	else if (base == oct) { /* Print Octa */
		for (long i = 0; i < size; i++) {
			printf("%04o ", ((unsigned char*)buffer)[i]);
		}
	}
	else if (base == hex) { /* Print Hexa */
		for (long i = 0; i < size; i++) {
			printf("%02X ", ((unsigned char*)buffer)[i]);
		}
	}
}



/* READ FILE */
void *readFile(const char *fileName, long *bufferSize) {
	#define NULL 0
	#define BUFFER_SIZE *bufferSize
	
	void *BUFFER = NULL;
	FILE *f = fopen(fileName, "rb");

	if (f) {
		BUFFER_SIZE = getFileSize(f);
		BUFFER = malloc(BUFFER_SIZE);

		fread(BUFFER, sizeof(char), BUFFER_SIZE, f);
	}
	else { /* Handle exceptions while opening file */
		BUFFER = NULL;
		BUFFER_SIZE = 0;
	}

	fclose(f);

	return BUFFER;
}

/* WRITE FILE */
int writeFile(const char *fileName, void *buffer, long bufferSize) {
	#define NULL 0
	#define BUFFER_SIZE bufferSize

	FILE *f = fopen(fileName, "wb");

	if (f) {
		fwrite(buffer, sizeof(char), BUFFER_SIZE, f);
		fclose(f); 
		return 1;
	}
	else { /* Handle exceptions while writing file */
		fclose(f);
		return 0;
	}
}