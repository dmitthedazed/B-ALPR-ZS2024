#include <stdio.h>
#include <string.h>

char *sifruj(char *sprava, char *heslo) {
    int sd = strlen(sprava);
    int sh = strlen(heslo);
    int i, j, offset;
    for (i=0, j=0; i<sd; i++) {
      offset = sprava[i] - 'A';
      offset = offset + (heslo[j] - 'A' + 1);
      offset = offset % 26;
      sprava[i] = 'A' + offset;

      //alebo tieto 4 riadky sa daju napisat aj takto ... code hell
      //sprava[i] = 'A' + ((sprava[i] - 'A') + (heslo[j] - 'A' + 1)) % 26

      j++;
      if (j>=sh) j=0;
    }
    return sprava;
}

char *odsifruj(char *sprava, char *heslo) {
    int sd = strlen(sprava);
    int sh = strlen(heslo);
    int i, j, offset;
    for (i=0, j=0; i<sd; i++) {
      offset = sprava[i] - 'A';
      offset = offset - (heslo[j] - 'A') - 1;
      if (offset < 0) offset = 26 + offset;
      sprava[i] = 'A' + offset;

      j++;
      if (j>=sh) j=0;
    }
    return sprava;
}

int analyzuj(char *subor, int *riadky, int *medzery, int *cisla) {
    FILE *fr;
    int znak, velkost = 0;

    *riadky = *medzery = *cisla = 0;

    if ((fr = fopen(subor, "r")) == NULL) {
       return -1;
    }
    while ( (znak=fgetc(fr)) != EOF ) {
        velkost++;
        if (znak == ' ') (*medzery)++;
        else if ((znak >= '0') && (znak <= '9')) (*cisla)++;
        else if (znak == '\n') (*riadky)++;
    }
    // subor zatvorime
    fclose(fr);
    return velkost;
}

// toto je upravena verzia OTOC, lebo ak retazec obsahuje na konci ENTER,, ten sa otocit NESMIE
char *otoc_spec(char *vstup)         /* otocenie retazca priamo na mieste */
{
    int l = 0, p = strlen(vstup) - 1;
    char ch;

    if (vstup[p] == '\n') p--;

    // princip je ze sa nastavim indexom na prvy a posledny znak
    // vymienam znaky
    // a pozicie posuvam protisebe smerom k stredu
    while (l<p) {
        ch = vstup[l];
        vstup[l] = vstup[p];
        vstup[p] = ch;
        l++; p--;
    }
    return vstup;
}

int otoc_riadky(char *subor, char *vystup) {
    FILE *fr, *fw;
    char riadok[500];

    if ((fr = fopen(subor, "r")) == NULL) {
       return -1;
    }
    if ((fw = fopen(vystup, "w")) == NULL) {
       fclose(fr);
       return -2;
    }
    while ( fgets(riadok, 500, fr) != NULL ) {
        fputs(otoc_spec(riadok), fw);
    }
    // subory zatvorime
    fclose(fw);
    fclose(fr);
    return 0;
}

// nebolo to v zadani.. aj dlzku najkratsieho hodim ako vystup a vypisem zvonku..
int najkratsi_riadok(char *subor) {

    FILE *fr;
    int r, minr = -1;
    char riadok[500];

    if ((fr = fopen(subor, "r")) == NULL) {
       return -1;
    }
    while ( fgets(riadok, 500, fr) != NULL ) {
       r = strlen(riadok);
       if (minr == -1) minr = r;
       else if (r < minr) minr = r;
    }
    // subor zatvorime
    fclose(fr);
    return minr;
}

int main() {

    char sprava[500], heslo[50];
    printf("Zadajte text na sifrovanie:");
    scanf("%s", sprava);
    printf("Zadajte heslo:");
    scanf("%s", heslo);
    printf("vystup sifrovania: %s\n", sifruj(sprava, heslo));
    printf("povodny vystup : %s\n", sprava);
    printf("desifrovanie: %s\n", odsifruj(sprava, heslo));

    int riadky, medzery, cisla, velkost;
    velkost = analyzuj("vstup.txt", &riadky, &medzery, &cisla);
    if (velkost == -1) printf("subor sa nepodarilo otvorit!");
    else printf("subor ma velkost: %d, pocet riadkov: %d, medzery: %d a cisla: %d",  velkost, riadky, medzery, cisla);

    otoc_riadky("vstup.txt", "vystup.txt");
    int riadok = najkratsi_riadok("vstup.txt");
    if (riadok == -1) printf("subor sa nepodarilo otvorit");
    else printf("najkratsi riadok: %d\n", riadok);
    return 0;
}
