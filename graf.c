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

cvor* ubaci_na_kraj(cvor *novi, cvor* prvi) {
	cvor *temp = prvi;
	if (!(temp)) {
		prvi = novi;
	}
	else {
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = novi;
	}
	return prvi;
}

cvor * linearna_lista(cvor *prvi, char **matrica, int m, int n) {
	cvor *novi;
	int z = 0;
	for(int i=1; i<m-1; i++) 
		for (int j = 1; j < n-1; j++) {
			if (matrica[i][j] == '-') continue;
			else {
				if (matrica[i + 1][j] != '-') {
					novi = malloc(sizeof(cvor));
					novi->id = z;
					for (int y = j+1; y < n; y++) {
						if (matrica[i][y] != '-') novi->id++;
					}
					for (int y = 0; y <= j; y++) {
						if (matrica[i+1][y] != '-') novi->id++;
					}
					novi->st = matrica[i+1][j];
					novi->poz = 'D';
					novi->next = NULL;
					prvi = ubaci_na_kraj(novi, prvi);
				}
				if (matrica[i-1][j] != '-') {
					novi = malloc(sizeof(cvor));
					novi->id = z;
					for (int y = j; y < n; y++) {
						if (matrica[i-1][y] != '-') novi->id--;
					}
					for (int y = 0; y < j; y++) {
						if (matrica[i][y] != '-') novi->id--;
					}
					novi->st = matrica[i-1][j];
					novi->poz = 'U';
					novi->next = NULL;
					prvi = ubaci_na_kraj(novi, prvi);
				}
				if (matrica[i][j + 1] != '-') {
					novi = malloc(sizeof(cvor));
					novi->id = z + 1;
					novi->st = matrica[i][j + 1];
					novi->poz = 'R';
					novi->next = NULL;
					prvi = ubaci_na_kraj(novi, prvi);
				}
				if (matrica[i][j - 1] != '-') {
					novi = malloc(sizeof(cvor));
					novi->id = z - 1;
					novi->st = matrica[i][j - 1];
					novi->poz = 'L';
					novi->next = NULL;
					prvi = ubaci_na_kraj(novi, prvi);
				}
				z++;
			}
		}
	return prvi;
}


Niz * niz_suseda(char ** matrica, int m, int n) {
	Niz *niz=malloc(m*sizeof(Niz));
	int z = 0, pom = 0, l=0;
	for (int i = 1; i < m - 1; i++) 
		for (int j = 1; j < n - 1; j++) {
			if (matrica[i][j] == '-') {
				l++;
				continue;
			}
			else {
				niz[z].crt = l;
				l = 0;
				niz[z].sf = matrica[i][j];
				niz[z].pos[0] = 'o';
				niz[z++].br = pom;
				if (matrica[i + 1][j] != '-') {
					pom++;
				}
				if (matrica[i - 1][j] != '-') {
					pom++;
				}
				if (matrica[i][j + 1] != '-') {
					pom++;
				}
				if (matrica[i][j - 1] != '-') {
					pom++;
				}
			}
		}
	niz[z].br = pom;
	niz[z].crt = 0;
	l = 0;
	return niz;
}