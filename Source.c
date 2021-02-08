#include "Header.h"

void main() {
	int k;
	char arr[1000];
	int i = 0, j = 0, t = 0;;
	int ret,n=0;
	cvor * prvi = NULL;
	Niz *niz=malloc(1000*sizeof(Niz));
	FILE *input = fopen("mapa.txt", "r");

	char c;
	do{
		ret=fscanf(input, "%c", &c);
		if (ret == EOF) { break; }
		if (c != '\n') {
			arr[t++] = c;
			j++;
		}
		else {
			i++;
			j = 0;
		}
	} while (1);

	arr[t] = '\0';

	int m = i+1;
	n = j;

	char **matrica = malloc(m * sizeof(char*));
	for (int i = 0; i < m; i++) {
		matrica[i] = malloc(n * sizeof(char));
	}

	int x = 0, p = 0;
	for (int y = 0; y < t; y++) {
		if (p < n) {
			matrica[x][p] = arr[y];
			p++;
		}
		else {
			p = 0; x++; y--;
		}
	}

	printf("1.Napravi graf\n2.Izbrisi cvor po zelji\n3.Pocni igru\n4.Pomoc\n5.Obrisi graf\n6.Napusti program\n");

	do {
		scanf("%d", &k);
		switch (k) {
		case 1: {
			prvi = NULL;
			prvi = linearna_lista(prvi, matrica, m, n);
			if (prvi == NULL) { printf("Greska u ucitavanju"); break; }
			niz = niz_suseda(matrica, m, n);
			break;
		}
		case 2: {
			prvi = NULL;
			int iid, jid;
			char r;
			scanf("%d %d %c", &iid, &jid, &r);

			arr[(iid)*n + jid] = r;
			int x = 0, p = 0;
			for (int y = 0; y < t; y++) {
				if (p < n) {
					matrica[x][p] = arr[y];
					p++;
				}
				else {
					p = 0; x++; y--;
				}
			}
			
			prvi = linearna_lista(prvi, matrica, m, n);
			if (prvi == NULL) { printf("Greska u ucitavanju"); break; }
			niz = niz_suseda(matrica, m, n);
			break;
		}

		case 3: {
			igrica(niz, prvi, m, n);
			break;
		}
		case 4: {
			//resenje()
			break;
		}
		case 5: {
			izbrisi_graf(prvi);
			break;
		}
		case 6: {
			exit(1);
			break;
		}
		}
	} while (1);
}