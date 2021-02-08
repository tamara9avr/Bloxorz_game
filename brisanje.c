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


void izbrisi_graf(cvor *prvi) {
	cvor * stari = prvi;
	while (stari->next) {
		prvi = prvi->next;
		free(stari);
		stari = prvi;
	}
}


cvor * izbrisi_cvor(int id, cvor * prvi) {
	cvor *temp = prvi, *pom;
	for (temp = prvi; temp->next; temp = temp->next) {
		if (temp->next->id == id) {
			pom = temp->next;
			temp->next = temp->next->next;
			free(pom);
		}
	}
	return prvi;
}