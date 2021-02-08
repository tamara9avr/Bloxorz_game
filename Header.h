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

void igrica(Niz * niz, cvor *prvi, int m, int n);
Niz * niz_suseda(char ** matrica, int m, int n);
cvor * linearna_lista(cvor *prvi, char ** matrica, int m, int n);
void izbrisi_graf(cvor *prvi);
void ispis(Niz * niz, int m, int n); 
cvor * izbrisi_cvor(int id, cvor * prvi);