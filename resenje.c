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
	int crt;
} Niz;


