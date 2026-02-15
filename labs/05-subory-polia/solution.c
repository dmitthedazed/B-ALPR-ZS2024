//**********************************************************************
//*  cv_05      - ZS 2022-23
//**********************************************************************
#include <stdio.h>
//**********************************************************************
int cv5_1()         /* citanie znakov z obrazovky zapis do suboru */
{
    printf("\nPriklad 1\n");
    int c;
    FILE* fw;
    if((fw = fopen("vystup.txt", "w")) == NULL) {
        printf("Subor sa nepodarilo otvorit");
        return 0;
    }
    printf("Zadaj znaky: ");
    while((c=getchar()) != '.') {
      if(c >= 'A' && c<='Z') c = c - 'A' + 'a';
      else if(c >= 'a' && c <= 'z') c = '.';
      else if(c >= '0' && c <= '9') c = '-';
      else if(c == '\n') c = '\n';
      else c = '*';
      // vytlacim
      putc(c, fw);
    }

    if(fclose(fw) == EOF)
        printf("Subor sa nepodarilo zatvorit.\n");
    return 0;
}
//**********************************************************************
int cv5_2()     /*citanie zo suboru do pola parnych cisel*/
{
    printf("\nPriklad 2\n");
    FILE* fr;
    int p[100];
    int i=0,cis,parne=0;
    if((fr = fopen("cisla.txt", "r")) == NULL) {
        printf("Subor sa nepodarilo otvorit");
        return 0;
    }
    while(fscanf(fr, "%d", &cis) != EOF) {
        if(cis % 2 == 0) {
            p[parne] = cis;
            parne ++;
        }
    }

    for(i=parne-1; i>=0; i--) {
        printf("%d ", p[i]);
    }
    printf("\n");
    if(fclose(fr) == EOF)
        printf("Subor sa nepodarilo zatvorit.\n");
    return 0;
}
//**********************************************************************
int cv5_3()    /* Nasobilka do suboru  */
{
    printf("\nPriklad 3\n");
    FILE *fw;
    float i, x = 0;
    if((fw = fopen("nasobky.txt", "w")) == NULL){
       printf("Subor sa nepodarilo otvorit.\n");
       return 0;
    }
    printf("Zadajte realne cislo: ");
    scanf("%f",&x);
    for(i = 1; i <= 10; i++) {
        fprintf(fw,"%2.0f: %8.2f, %8.2f, %8.2f\n", i, i*x, i*2*x, i*x*x);
    }
    fclose(fw);
    return 0;
}
//**********************************************************************
int cv5_4()    /* Prepis suboru na obrazovku alebo do suboru  */
{
    printf("\nPriklad 4\n");
	FILE *fr, *fw;
    int c;
    if ((fr = fopen("znak.txt", "r")) == NULL ){
        printf("Subor fr sa nepodarilo otvorit\n");
        return -1;
    }
    printf("Stlacte s pre zapis do suboru \n");
    printf("alebo iny znak pre vypis na obrazovku: ");
    c = getchar();
    if ((c == 's' || c == 'S')){
        if((fw = fopen("novy.txt", "w")) == NULL) {
            printf("Subor fw sa nepodarilo otvorit\n");
            return -2;
        }
    }
    else
        fw = stdout;

    while (( c = fgetc(fr))!= EOF)
            fputc(c, fw);
    if (fw != stdout)
        fclose(fw);
    fclose(fr);
    return 0;
}
//**********************************************************************
int cv5_5()            /* Porovna 2 subory */
{
    printf("\nPriklad 5\n");
	FILE *fr1, *fr2;
    int c1, c2, pocet, dlhsi;
    pocet = dlhsi = 0;

    if ((fr1 = fopen("prvy.txt", "r")) == NULL ){
        printf("Subor fr1 sa nepodarilo otvorit\n");
        return -1;
    }
    if ((fr2 = fopen("druhy.txt", "r")) == NULL ){
        printf("Subor fr2 sa nepodarilo otvorit\n");
        return -1;
    }

    while ((c1 = getc(fr1)) != EOF && (c2 = getc(fr2)) != EOF) {
       if ( c1 != c2 ) pocet++;
    }
    while ((c1 = getc(fr1)) != EOF || (c2 = getc(fr2)) != EOF){
                dlhsi++;
    }
    if ( pocet == 0 && dlhsi == 0)
        printf ("subory su identicke\n");
    else
        printf("Pocet roznych znakov: %d  \nJeden subor je dlhsi o %d znakov\n", pocet, dlhsi);

    fclose(fr1);
    fclose(fr2);
    return 0;
}
//**********************************************************************
int cv5_6()             /* Pocet malych pismen v riadkoch v subore */
{
    printf("\nPriklad 6\n");
	FILE *fr, *fa;
    int c, pocet = 0;

    fr = fopen("vstup.txt", "r");
    fa = fopen("cisla.txt", "a");

    while ( (c = getc(fr))!= EOF ) {
         if (c >= 'a' && c <= 'z')
            pocet++;
         if (c == '\n') {
            fprintf(fa, "\n%d", pocet);
            pocet = 0;
         }
        putc(c, fa );
    }
    fclose(fr);
    fclose(fa);
    return 0;
}
//**********************************************************************
int cv5_7()                  /* Znaky v subore */
{
    printf("\nPriklad 7\n");
	FILE *fr;
    int c;
    int medzery = 0;
    fr = fopen("text.txt", "r");

    while((c = fgetc(fr)) != EOF) {
    	if(c == '*') break;
        else if(c == 'x' || c == 'X') printf("Precital som X\n");
        else if(c == 'y' || c == 'Y') printf("Precital som Y\n");
        else if(c == '#' || c == '$' || c == '&') printf("Precital som riadiaci znak\n");
        else if (c == ' ') medzery++;
    }
    printf("Koniec\n");
    printf("Pocet nacitanych medzier: %d\n", medzery);

    fclose(fr);
    return 0;
}
//**********************************************************************
int cv5_8()           /* sucet cisel medzi 2 cislami  */
{
    printf("\nPriklad 8\n");
    int i, c1, c2, suma = 0;
    printf("Zadaj 2 cele cisla \n");
    scanf("%d %d", &c1, &c2);
    if (c1 < c2) {
        for( i = c1 + 1; i < c2; i++ ) suma = suma + i;
    }
    else if ( c2 < c1) {
        for( i = c2 + 1; i < c1; i++ ) suma = suma + i;
    }
    if( c1 == c2)
        printf("neda sa vypocitat\n");
    else
        printf("sucet cisel %d\n", suma);
    return 0;
}
//**********************************************************************
int cv5_9()           /* faktorial  */
{
    printf("\nPriklad 9\n");
    int i, cislo;
    long fakt = 1;
    printf("Zadaj cele cislo <= 33 \n");
    scanf("%d", &cislo);
    for( i = 1; i <= cislo; i++ ) fakt = fakt*i;

    printf("faktorial cisla %d je %lu \n", cislo, fakt);
    return 0;
}
//**********************************************************************
int cv5_10()           /* vypis cisel a --  */
{
    printf("\nPriklad 10\n");
    int i = 0, p, k;
    printf("Zadaj 2 cisla p a k (0 < p, k < 100\n");
    scanf("%d %d", &p, &k);

    for( i = 1; i <= p; i++ ) {
        if((i%k) == 0)
            printf("%2d ", i);
        else
            printf("-- ");
    }
    printf("\n");
    return 0;
}
//**********************************************************************
int cv5_11()           /* for a while  */
{
    printf("\nPriklad 11\n");
    int i;
//------------------------------
    for( i = 0; i < 10; i++ )
        printf("%2d. \n", i + 1);
    printf("\n");
//------------------------------
    i = 0;
    while(i < 10) {
         printf("%2d. \n", i + 1);
         i++;
    }
    return 0;
}
//**********************************************************************
int cv5_12()           /* ci je postupnost cisel spravna  */
{
    printf("\nPriklad 12\n");
    int i, n, p[50];
    printf("Zadaj cele cislo n < 50\n");
        scanf("%d", &n);
    printf("Zadaj %d celych cisel \n", n);
        for( i = 0; i < n; i++ )
            scanf("%d", &p[i]);
//------------------------------
    if((p[0] > 10) || (p[0] < 0 ))
        printf("p[0] - Postupnost nie je spravna\n");
    else {
        for (i = 1; i < n; i++) {
            if ((p[i] >= 2*p[i-1]) || (p[i] <= (p[i-1]/2))) {
                printf("Postupnost nie je spravna \n");
                return -1;
            }
        }
        printf("Postupnost je spravna \n");
    }
    return 0;
}
//**********************************************************************
int cv5_13()           /* kreslenie trojuholnikov z cisel  */
{
    printf("\nPriklad 13\n");
    int i, j, k, l, n, s, v;

    printf("Zadaj 3 cele cisla \n");
    scanf("%d %d %d", &n, &s, &v);

    if(n < 1 || n > 15 || n % 2 == 0)
            printf("Zly vstup\n");
//------------------------------
    else {
        for(k = 0; k < v; k++) {
            for (i = 0; i < n; i++) {
                for (l = 0; l < s; l++) {
                    for (j = 0; j < n; j++) {
                        if(j <= i)
                            printf("%d", i + 1);
                        else
                            putchar('-');
                    }
                }
                putchar('\n');
              }
                for(i = n - 1; i > 0; i--) {
                    for (l = 0; l < s; l++) {
                        for(j = 0; j < n; j++) {
                            if(j < i)
                                printf("%d", i );
                            else
                                putchar('-');
                        }
                    }
                    putchar('\n');
                }
       }
    }
    return 0;
}
//**********************************************************************
int main()
 {
     cv5_1(); getchar();
     cv5_2(); getchar();
     cv5_3(); //getchar();
     cv5_4(); getchar();
     cv5_5(); getchar();
     cv5_6(); getchar();
     cv5_7(); getchar();
     cv5_8(); getchar();
     cv5_9(); getchar();
     cv5_10(); getchar();
     cv5_11(); getchar();
     cv5_12(); getchar();
     cv5_13();
    return 0;
 }
//**********************************************************************
