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

int stanje(int st, char c, char or) {
	if (st) return 0;
	else {
		if (((c == 'A' || c == 'D' ) && (or=='U' || or=='D'))||((c=='W' || c=='S')&&(or=='L' || or=='R'))) return 0;
		else return 1;
	}
}

cvor * pomeraj(char c, cvor *pom, int j) {
	char p;
	if (c == 'A') p = 'L';
	else if (c == 'D') p = 'R';
	else if (c == 'S') p = 'D';
	else if (c == 'W') p = 'U';

	int t;
	for (t = 0; t < j; t++) {
		if (pom->poz == p) return pom;
		if (pom == NULL) return NULL;
		pom = pom->next;
	}
	if (t == j ) {
	  return NULL;
	}
}

void ispis(Niz * niz, int m, int n) {
	int z = (m-2)*(n-2), s=0;
	for (int t = 0; t < z; t++) {
		if (niz[t].pos[0] == '\0')
			break;
		if (s < n - 2) {
			for (int y = 0; y < niz[t].crt; y++) {
					printf("-");
					s++;
					if(s==n-2) {
						s = 0;
						putchar('\n');
					}
			}
				if (niz[t].sf != 'T') {
					printf("%c", niz[t].pos[0]);
				}
				else printf("%c", niz[t].sf);
				if (niz[t].pos[0] == 'x') niz[t].pos[0] = 'o';
			s++;
		}
		else {
			if (t == z) break;
			s = 0;
			t--;
			putchar('\n');
		}
	}
	putchar('\n');
}

void igrica(Niz * niz, cvor *prvi, int m, int n) {
	char c;
	cvor *curr = prvi;
	cvor *pom;
	int state;
	int i = 0,j;

	while (niz[i].sf != 'S') {
		i++;
	}
	niz[i].pos[0] = 'x';

	j = niz[i + 1].br - niz[i].br;

	for (int L = 0; L < niz[i].br; L++) {
		curr = curr->next;
	}
	pom = curr;
	state = 1;

	//system("cls");
	ispis(niz, m, n);
	c = getchar();

	do{
		scanf("%c",&c);
		
		if (state) {
			pom = pomeraj(c, pom, j);
			if (pom == NULL) { printf("GAME OVER!\nExit 6\nRetry 3\nClear map 5"); break; }
			i = pom->id;
			if (c == 'A') niz[i].pos[1] = 'L';
			else if (c == 'D') niz[i].pos[1] = 'R';
			else if (c == 'S') niz[i].pos[1] = 'D';
			else if (c == 'W') niz[i].pos[1] = 'U';

			
			niz[i].pos[0] = 'x';
			j = niz[i + 1].br - niz[i].br;
			curr = prvi;
			for (int t = 0; t < niz[i].br; t++) {
				curr = curr->next;
			}
			pom = curr;

			pom = pomeraj(c, pom, j);
			if (pom == NULL) { printf("GAME OVER!\nExit 6\nRetry 3\nClear map 5"); break; }
			i = pom->id;
			j = niz[i + 1].br - niz[i].br;
			curr = prvi;
			for (int t = 0; t < niz[i].br; t++) {
				curr = curr->next;
			}
			pom = curr;

			niz[i].pos[0] = 'x';
			if (c == 'A') niz[i].pos[1] = 'R';
			else if (c == 'D') niz[i].pos[1] = 'L';
			else if (c == 'S') niz[i].pos[1] = 'U';
			else if (c == 'W') niz[i].pos[1] = 'D';
		}

		else {
			if (((c=='W' || c == 'S') && (niz[i].pos[1]=='L' || niz[i].pos[1]=='R')) || ((c=='A' || c=='D') && (niz[i].pos[1] == 'U' || niz[i].pos[1] == 'D'))) {
				cvor* temp = curr;
				char k = niz[i].pos[1];

				pom = pomeraj(c, temp, j);
				if (pom == NULL) { printf("GAME OVER!\nExit 6\nRetry 3\nClear map 5"); break; }
				i = pom->id;
				j = niz[i + 1].br - niz[i].br;
				curr = prvi;
				for (int t = 0; t < niz[i].br; t++) {
					curr = curr->next;
				}
				pom = curr;

				niz[i].pos[0] = 'x';
				niz[i].pos[1] = k;

				char p;

				if (k == 'L') p = 'A';
				else if (k == 'R') p = 'D';
				else if (k == 'U') p = 'W';
				else if (k == 'D') p = 'S';

				pom = pomeraj(p, pom, j);
				if (pom == NULL) { printf("GAME OVER!\nExit 6\nRetry 3\nClear map 5"); break; }

				if (pom->st == 'T') {
					state = stanje(state, c, niz[i].pos[1]);
					if (state) {
						printf("YOU WON!\nExit 6\nRetry 3\nClear map 5");
						break;
					}
				}

				i = pom->id;
				j = niz[i + 1].br - niz[i].br;
				curr = prvi;
				for (int t = 0; t < niz[i].br; t++) {
					curr = curr->next;
				}
				pom = curr;

				niz[i].pos[0] = 'x';
				
				if (k == 'L') niz[i].pos[1] = 'R';
				else if (k == 'R') niz[i].pos[1] = 'L';
				else if (k == 'U') niz[i].pos[1] = 'D';
				else if (k == 'D') niz[i].pos[1] = 'U';
			}

	
			if ((c == 'A' && niz[i].pos[1] == 'R') || (c=='D' && niz[i].pos[1]=='L' ) || (c=='W' && niz[i].pos[1] =='D' )||(c=='S' && niz[i].pos[1] =='U' )){
					pom = pomeraj(c, pom, j);
					if (pom == NULL) { printf("GAME OVER!\nExit 6\nRetry 3\nClear map 5"); break; }

					if (pom->st == 'T') {
						state = stanje(state, c, niz[i].pos[1]);
						if (state) {
							printf("YOU WON!\nExit 6\nRetry 3\nClear map 5");
							break;
						}
					}

					i = pom->id;
					j = niz[i + 1].br - niz[i].br;
					curr = prvi;
					for (int t = 0; t < niz[i].br; t++) {
						curr = curr->next;
					}
					pom = curr;
					niz[i].pos[0] = 'x';
					niz[i].pos[1] = 'o';
			}
			if ((c == 'A' && niz[i].pos[1] == 'L') || (c=='D' && niz[i].pos[1]=='R') || (c == 'W' && niz[i].pos[1] == 'U') || (c == 'S' && niz[i].pos[1] == 'D')) {
					pom = pomeraj(c, pom, j);
					i = pom->id;
					j = niz[i + 1].br - niz[i].br;
					curr = prvi;
					for (int t = 0; t < niz[i].br; t++) {
						curr = curr->next;
					}
					pom = curr;

					pom = pomeraj(c, pom, j);
					if (pom == NULL) { printf("GAME OVER!\nExit 6\nRetry 3\nClear map 5"); break; }

					if (pom->st == 'T') {
						state = stanje(state, c, niz[i].pos[1]);
						if (state) {
							printf("YOU WON!\nExit 6\nRetry 3\nClear map 5");
							break;
						}
					}

					i = pom->id;
					j = niz[i + 1].br - niz[i].br;
					curr = prvi;
					for (int t = 0; t < niz[i].br; t++) {
						curr = curr->next;
					}
					pom = curr;
					niz[i].pos[0] = 'x';
					niz[i].pos[1] = 'o';
			}
		}

		state = stanje(state, c, niz[i].pos[1]);

		//system("cls");
		ispis(niz, m, n);
		
		
		c = getchar();

	} while (1);
}