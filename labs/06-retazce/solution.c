//**********************************************************************
//*  cv_06      - ZS 2022-23
//**********************************************************************
#include <stdio.h>
#include <string.h>

void read_line(char *buf, int size)
{
    if (fgets(buf, size, stdin) != NULL) {
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
        }
    } else {
        buf[0] = '\0';
    }
}
//**********************************************************************
char *otoc(char *vstup)         /* otocenie retazca priamo na mieste */
{
    int l = 0, p = strlen(vstup) - 1;
    char ch;

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
//**********************************************************************
int hrame_sa_s_retazcom()
{
    char retazec[500];
    int i, j, dlzka;
    printf("Zadajte riadok znakov:\n");
    read_line(retazec, sizeof(retazec));

    dlzka = strlen(retazec);

    i = 0;
    while (i < dlzka) {
      if (retazec[i] == ' ') {
        // zacnem od znaku medzera.. na ktoreho miesto dam znak vpravo.. a na jeho miesto zase dalsie.. az do konca retazca..
        for (j = i; j < dlzka; j++) retazec[j] = retazec[j+1];
        dlzka--; // retazec je kratsi o 1
        //premennu i neposuvam
      }
      else if ((retazec[i] >= '0') && (retazec[i] <= '9')) {
        // j=dlzka lebo musim odstahovat aj nulovy znak
        for (j = dlzka; j > i; j--) retazec[j+1] = retazec[j];
        // ten ciselny znak na pozicii i prepisem *
        retazec[i] = '*';
        // odstahovanim vznikla jedna medzera na pozicii i+1
        retazec[i+1] = '*';
        dlzka++; // retazec je dlhsi o 1
        //premennu i posuvam az o 2, lebo preskocim aj druhu *
        i+=2;
      }
      else i++; // retazec sa nezmenil a ja sa posuvam dalej
    };
    // mam zmazane medzery, mam zmenene 0 az 9 na * a tak otocim...
    otoc(retazec);

    // vypisem
    puts(retazec);
    return 0;
}

int retazce_a_subory() {
   FILE *fr, *fw;
   char riadok[500];
   int dlzka, poradie = 1;
   if ((fr = fopen("vstup.txt", "r")) == NULL) {
        printf("subor sa nepodarilo otvorit na citanie!");
        return -1;
   }
   if ((fw = fopen("vystup.txt", "w")) == NULL) {
        printf("subor sa nepodarilo otvorit na zapis!");
        fclose(fr);
        return -2;
   }

   while (fgets(riadok, 500, fr) != NULL) {
     dlzka = strlen(riadok);
     if (riadok[dlzka-1] == '\n') dlzka--; // ak enter tam je, ten do dlzky nepocitajme
     if (poradie % 2) {  // neparny
       for (int i=0; i<dlzka/2; i++) riadok[i] = '*';
     }
     else { // parny
       for (int i=dlzka/2; i<dlzka; i++) riadok[i] = '-';
     }
     poradie++;
     fputs(riadok, fw);
   }

   fclose(fw);
   fclose(fr);
   return 0;
}

int ine_p1()
{
    char retazec[50];
    int i, j, dlzka;
    printf("Zadajte riadok znakov:\n");
    read_line(retazec, sizeof(retazec));

    dlzka = strlen(retazec);

    i = 0;
    while (i < dlzka) {
      if (retazec[i] == '*') {
        // j=dlzka lebo musim odstahovat aj nulovy znak
        if (dlzka+2>50) {
            printf("Pole je naplnene!\n");
            break;
        };
        dlzka = dlzka + 3; // retazec je dlhsi o 2 znaky
        for (j = dlzka; j > i; j--) retazec[j+2] = retazec[j];
        // ten ciselny znak na pozicii i prepisem *
        retazec[i] = '>';
        // odstahovanim vznikla jedna medzera na pozicii i+1
        retazec[i+1] = '*';
        retazec[i+2] = '<';

        //premennu i posuvam az o 3, lebo preskocim ">*<"
        i=i+2;
      }
      else i++; // retazec sa nezmenil a ja sa posuvam dalej
    };
    // vypisem
    puts(retazec);
    return 0;
}

int ine_p2()
{
    char retazec[50], podretazec[6];
    int i, j, zhoda, dlzka1, dlzka2;
    printf("Zadajte riadok znakov:\n");
    read_line(retazec, sizeof(retazec));
    dlzka1 = strlen(retazec);
    printf("Zadajte riadok znakov podretazec:\n");
    read_line(podretazec, sizeof(podretazec));
    dlzka2 = strlen(podretazec);

    i=0;
    while (i<(dlzka1+1-dlzka2)) {
      for (zhoda=0,j=0; j<dlzka2; j++) {
        if (retazec[i+j] == podretazec[j]) zhoda++;
        else break; // nezhoda rovno ukoncuje test zhody
      }
      if (zhoda == dlzka2) {  // ak je zhoda uplna potom odmazavam v pozicii i pocet znakov dlzka2
        //retazec sme vlastne skratili o dlzku podretazca
        dlzka1 -= dlzka2;
        // no a my pekne stahujeme pismenka dolava o dlzku poderatazca .. od pozicie i
        for (j=i; j<dlzka1+1; j++) {
          retazec[j] = retazec[j+dlzka2];
        }
        // ked mazem, tak sa neposuvam
      }
      else i++; // ked nemazem, tak sa posuvam dalej v retazci
    }
    puts(retazec);
    return 0;
}

int najdlhsie_opakovanie(char  x[],  int  pocet,  char *znak)
{
    char najznak, z=0;
    int i, maxopakovani=0,opakovani = 0;

    for (i=0; i<pocet; i++) {
      if (z == x[i]) opakovani++;
      else {
        if (opakovani > maxopakovani) {
            maxopakovani = opakovani;
            najznak = z;
        }
        z = x[i]; opakovani = 1;
      }
    }
    if (opakovani > maxopakovani) {
      maxopakovani = opakovani;
      najznak = z;
    }
    *znak = najznak;
    return maxopakovani;
}

//**********************************************************************
int main()
 {
   //hrame_sa_s_retazcom();
   retazce_a_subory();
   //ine_p1();
   //ine_p2();
   //char x[] = "aabbbcCcCcddeeeeff";
   //char znak;
   //int opakovanie = najdlhsie_opakovanie(x,  18,  &znak);
   //printf("najdlhsie opakovanie je [%d] pre znak [%c]", opakovanie, znak);
   return 0;
 }
//**********************************************************************
