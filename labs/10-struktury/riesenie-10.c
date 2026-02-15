#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char priezvisko_meno[100];
    int rocnik;
    float priemer;
} STUDENT;

STUDENT *nacitajPole(char *subor, int *nacitane) {

  STUDENT *pole;
  FILE *f = fopen(subor, "r");
  if (f == NULL) return NULL;

  fscanf(f, "%d\n", nacitane); // vieme preco nie je & vsak ?
  if (*nacitane < 1) return NULL; // ochrana musi byt :-)

  pole = (STUDENT *) malloc(*nacitane * sizeof(STUDENT));
  if (pole == NULL) { // mozno zbutocna ochrana .. ale vzorova...
    fclose(f);
    return NULL;
  }

  int i;
  for (i=0; i < *nacitane; i++) { // zase vieme preco *nacitane, vsak ?
    fgets(pole[i].priezvisko_meno, 100, f);
    pole[i].priezvisko_meno[strlen(pole[i].priezvisko_meno)-1] = '\0';
    fscanf(f, "%d\n", &pole[i].rocnik);
    fscanf(f, "%f\n", &pole[i].priemer);
  }

  fclose(f);
  return pole;
}

void vypisPole(STUDENT *studenti, int pocet) {
  int i;
  for (i=0; i < pocet; i++) {
    printf("%s;%d;%.1f\n", studenti[i].priezvisko_meno, studenti[i].rocnik, studenti[i].priemer);
  }
}

STUDENT *najlepsiPole (STUDENT *studenti, int pocet, int rocnik) {
  STUDENT *naj = NULL;
  int i;
  for (i=0; i < pocet; i++) {
    if (studenti[i].rocnik == rocnik) { // som v rocniku ?
        if (naj == NULL) naj = &studenti[i]; // nemal som najlepsieho, ale uz mam
        else if (studenti[i].priemer < naj->priemer) naj = &studenti[i]; // mam lepsieho,
        //poriadne si vsimnite ako citam polozku priemer zo studenti[i] a z NAJ ...
        // dobre sa zamyslite PRECO ?!
    }
  }
  return naj;
}

int main() {
  STUDENT *pole, *naj;
  int pocet;
  pole = nacitajPole("vstup.txt", &pocet);
  if (pole == NULL) {
        printf("nepodarilo sa nacitat a naplnit pole");
        return -1;
  }
  vypisPole(pole, pocet);
  naj = najlepsiPole(pole, pocet, 4);
  if (naj == NULL) {
        printf("v rocniku nieje student");
        free(pole);
        return -2;
  }
  printf("najlepsi student je %s", naj->priezvisko_meno);
  free(pole);
  return 0;
}
