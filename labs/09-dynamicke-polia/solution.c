#include <stdio.h>
#include <stdlib.h>

int **create(int riadky, int stlpce) {
    int **p, i;
    p = (int **) malloc(riadky * sizeof(int *));
    for(i = 0; i < riadky; i++)
        p[i] = (int *) malloc(stlpce * sizeof(int));
    return p;
}

void Uvolni(int **pole, int riadky) {
    int r;
    if (pole == NULL) return;
    for (r=0; r<riadky; r++) free(pole[r]);
    free(pole);
}

void Vypis(int **pole, int riadky, int stlpce) {
    int r,s;
    for (r=0; r<riadky; r++) {
        for (s=0; s<stlpce; s++) {
            printf("%5d", pole[r][s]);
        }
        printf("\n");
    }
}

int **AlokujNapln(int *riadky, int *stlpce) {
  FILE *f;
  // nepodarilo sa otvorit SUBOR
  if ((f = fopen("vstup.txt", "r")) == NULL) return NULL;

  // citaj rozmery
  fscanf(f, "%d", riadky); // preco tam nie je & ??? lebo riadky je uz adresa
  fscanf(f, "%d", stlpce); // detto

  int **p = create(*riadky, *stlpce); // preco pouzivam *riadky a nie riadky ?
  // nepodarilo sa ALOKOVAT maticu / pole
  if (p == NULL) {
    fclose(f);
    return NULL;
  }

  int r, s;
  for (r=0; r < *riadky; r++) {
    for (s=0; s < *stlpce; s++) {
        if (fscanf(f, "%d", &p[r][s]) != 1) { // dari sa nam citat cislo ?
            Uvolni(p, *riadky); // uvolnime pole
            fclose(f); // zatvorime subor
            return NULL; // skoncime
        }
    }
  }
  fclose(f);
  return p;
}

int NajdiMax(int**pole, int riadky, int stlpce,int *riadok, int *stlpec) {
  int r,s, max;
  // inicializujem vystupy
  *riadok = 0; *stlpec = 0; max = pole[0][0];

  for (r=0; r<riadky; r++) {
    for (s=0; s<stlpce; s++) {
        if (pole[r][s] > max) {
          max = pole[r][s];
          *riadok = r;
          *stlpec = s;
        }
    }
  }
  return max;
}

int main() {
    int **pole;
    int riadky, stlpce, max, max_riadok, max_stlpec;

    pole = AlokujNapln(&riadky, &stlpce);
    if (pole == NULL) {
      printf("Pole sa nepodarilo naplnit!");
      return 1;
    }
    Vypis(pole, riadky, stlpce);
    max = NajdiMax(pole, riadky, stlpce, &max_riadok, &max_stlpec);
    printf("Maximum pola [%d] sa naslo na suradnici [%d, %d]", max, max_riadok, max_stlpec);
    Uvolni(pole, riadky);
    return 0;
}
