#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char priezvisko_meno[100];
    int rocnik;
    float priemer;
    struct student *dalsi;
} STUDENT;

void uvolniSpajany(STUDENT *studenti);

STUDENT *nacitajSpajany(char *subor) {

  int nacitane;
  STUDENT *prvy = NULL, *posledny = NULL, *akt;
  FILE *f = fopen(subor, "r");
  if (f == NULL) return NULL;

  fscanf(f, "%d\n", &nacitane); // tetaz je to lokalna premenna a nie smernik ako v 10tom
  if (nacitane < 1) {
    fclose(f);
    return NULL;
  } // ochrana musi byt :-)

  int i;
  for (i=0; i < nacitane; i++) {
    // vytvorim studenta
    akt = (STUDENT *) malloc(sizeof(STUDENT));
    if (akt == NULL) {
      uvolniSpajany(prvy);
      fclose(f);
      return NULL;
    }
    // naplnim ho udajmi
    fgets(akt->priezvisko_meno, 100, f);
    akt->priezvisko_meno[strlen(akt->priezvisko_meno)-1] = '\0';
    fscanf(f, "%d\n", &akt->rocnik);
    fscanf(f, "%f\n", &akt->priemer);
    akt->dalsi = NULL; // vyrobime vycistene.. nikdy nevieme ci nie je posledny..

    // toto je finta ako si naplnim zaciatok zoznamu.. robim to len raz .. k
    if (prvy == NULL) prvy = akt;
    // POSLEDNY je ten ktory bol vytvoreny OTOCKU pred touto OTOCKOU
    if (posledny != NULL) posledny->dalsi = akt;
    posledny = akt;
  }

  fclose(f);
  return prvy;
}

void vypisSpajany(STUDENT *studenti) {
  while (studenti != NULL) {
    printf("%s;%d;%.1f\n", studenti->priezvisko_meno, studenti->rocnik, studenti->priemer);
    studenti = studenti->dalsi;
  }
}

STUDENT *najlepsiSpajany (STUDENT *studenti, int rocnik) {
  STUDENT *naj = NULL;
  while (studenti != NULL) {
    if (studenti->rocnik == rocnik) { // som v rocniku ?
        if (naj == NULL) naj = studenti; // nemal som najlepsieho, ale uz mam .. porovnaj s minulym cvicenim !!!
        else if (studenti->priemer < naj->priemer) naj = studenti; // mam lepsieho,
        // dobre sa zamyslite PRECO  minule bolo naj = &studenti[i]?!
    }
    studenti = studenti->dalsi;
  }
  return naj;
}

void uvolniSpajany(STUDENT *studenti) {
  STUDENT *f;
  while (studenti != NULL) {
    f = studenti;
    studenti = studenti->dalsi;
    free(f);
  }
}

int main() {
  STUDENT *s, *naj;

  s = nacitajSpajany("vstup.txt");
  if (s == NULL) {
        printf("nepodarilo sa nacitat a naplnit pole");
        return -1;
  }
  vypisSpajany(s);
  naj = najlepsiSpajany(s, 3);
  if (naj == NULL) {
        printf("v rocniku nieje student");
        return -2;
  }
  printf("najlepsi student je %s", naj->priezvisko_meno);
  uvolniSpajany(s);
  return 0;
}
