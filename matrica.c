#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Cvor {
	int id;
	char st;
	char poz;
	struct Cvor *next;
}cvor;

typedef struct array {
	int br;
	char sf;
	char pos[2];
} Niz;

Niz ** arr_ar(FILE *input) {
	Niz *arr = malloc(1000 * sizeof(Niz));
	int i = 0, j = 0, t = 0;
	int ret, n = 0;
	char c;

	do {
		ret = fscanf(input, "%c", &c);
		if (ret == EOF) { break; }
		if (c != '\n') {
			arr[t++].pos[0] = c;
			j++;
		}
		else {
			i++;
			j = 0;
		}
	} while (1);

	arr[t].pos[0] = '\0';
	arr = realloc(arr, t * sizeof(Niz));

	return arr;
}

char ** matrica_mx(FILE *input, Niz *arr){
	int ret, i=0, j=0, t = 0;
	char c;
	do{
		ret=fscanf(input, "%c", &c);
		if (ret == EOF) { break; }
		if (c != '\n') {
			j++;
			t++;
		}
		else {
			i++;
			j = 0;
		}
	} while (1);

	char **matrica = malloc(i * sizeof(char*));
	for (int i = 0; i < i; i++) {
		matrica[i] = malloc(j * sizeof(char));
	}

	int x = 0, p = 0;
	for (int y = 0; y < t; y++) {
		if (p < j) {
			matrica[x][p++] = arr[y].pos[0];
		}
		else {
			matrica[x][p] = '\0';
			p = 0; x++;
		}
	}
	return matrica;
}

int duzina(FILE *input) {
	int ret, i=0;
	char c;
	do {
		ret=fscanf(input, "%c", &c);
		if (ret == EOF) { break; }
		if (c != '\n') {
			continue;
		}
		else {
			i++;
		}
	} while (1);
	return i;
}

int sirina(FILE *input) {
	int ret, j=0;
	char c;
	do {
		ret=fscanf(input, "%c", &c);
		if (ret == EOF) { break; }
		if (c != '\n') {
			j++;
		}
		else {
			return j;
		}
	} while (1);
}