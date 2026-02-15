# Prednáška 4: Práca so súbormi

> **Predmet:** Algoritmizácia a programovanie
> **Prednášajúci:** Ján Grman

---

## Obsah

1. [Opakovanie – riadiace štruktúry v príkladoch](#opakovanie--riadiace-štruktúry-v-príkladoch)
2. [Vstup a výstup z textového súboru](#vstup-a-výstup-z-textového-súboru)
   - [Čo je súbor](#čo-je-súbor)
   - [Typ FILE a deklarácia](#typ-file-a-deklarácia)
   - [Otvorenie súboru – fopen()](#otvorenie-súboru--fopen)
   - [Základné funkcie pre prácu so súbormi](#základné-funkcie-pre-prácu-so-súbormi)
   - [Zatvorenie súboru – fclose()](#zatvorenie-súboru--fclose)
3. [Príklady práce so súbormi](#príklady-práce-so-súbormi)
   - [Zápis do súboru](#zápis-do-súboru)
   - [Čítanie zo súboru](#čítanie-zo-súboru)
   - [Kopírovanie znakov medzi súbormi](#kopírovanie-znakov-medzi-súbormi)
4. [Testovanie konca riadku a konca súboru](#testovanie-konca-riadku-a-konca-súboru)
   - [Koniec riadku (EOLN)](#koniec-riadku-eoln)
   - [Koniec súboru – EOF](#koniec-súboru--eof)
   - [Koniec súboru – feof()](#koniec-súboru--feof)
5. [Testovanie správnosti otvorenia a zatvorenia](#testovanie-správnosti-otvorenia-a-zatvorenia)
6. [Komplexné príklady](#komplexné-príklady)
   - [Konverzia na veľké písmená + najdlhší riadok](#konverzia-na-veľké-písmená--najdlhší-riadok)
   - [Štandardný vstup a výstup (stdin, stdout)](#štandardný-vstup-a-výstup-stdin-stdout)
   - [Výstup na obrazovku alebo do súboru](#výstup-na-obrazovku-alebo-do-súboru)
7. [Funkcia ungetc() – vrátenie znaku do bufferu](#funkcia-ungetc--vrátenie-znaku-do-bufferu)
8. [Režimy otvárania súborov](#režimy-otvárania-súborov)
9. [Navigácia v súbore – fseek, ftell, rewind](#navigácia-v-súbore--fseek-ftell-rewind)

---

## Opakovanie – riadiace štruktúry v príkladoch


### Príklad: Suma čísel

Program spočítava reálne čísla zadávané z klávesnice, pokým nie je zadaná nula, na konci súčet vypíše.

```c
#include <stdio.h>

int main() {
    float x, suma = 0;
    printf("Zadajte cisla (ukoncite 0)\n");
    do {
        scanf("%f", &x);
        suma += x;
    } while (x != 0.0);
    printf("Sucet je: %.3f", suma);
    return 0;
}
```

### Príklad: Minimum a maximum

Program načíta `n` čísel a vypíše minimum a maximum.

```c
#include <stdio.h>

int main() {
    int i, n;
    float x, min, max;
    scanf("%d", &n);
    if (n > 0) {
        scanf("%f", &x);
        min = max = x;

        for (i = 2; i <= n; i++) {
            scanf("%f", &x);
            if (x > max)
                max = x;
            else if (x < min)
                min = x;
        }
        printf("Minimum: %.2f\n", min);
        printf("Maximum: %.2f\n", max);
    }
    return 0;
}
```

### Príklad: Hviezdičkovanie do trojuholníka

Pre daný počet riadkov vykreslite obrázok (pravouhlý trojuholník):

```
1********
22*******
333******
4444*****
55555****
666666***
7777777**
88888888*
999999999
```

```c
#include <stdio.h>

int main() {
    int i, j, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (i < j)
                putchar('*');
            else
                printf("%d", i % 10);
        putchar('\n');
    }
    return 0;
}
```

Varianta – rovnoramenný trojuholník:

```
*******1*******
******222******
*****33333*****
****4444444****
***555555555***
**66666666666**
*7777777777777*
888888888888888
```

```c
#include <stdio.h>

int main() {
    int i, j, n;
    scanf("%d", &n);
    if (n < 1 || n > 15) return 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 2 * n - 1; j++) {
            if (j <= n - i || j >= n + i)
                putchar('*');
            else
                printf("%d", i % 10);
        }
        putchar('\n');
    }
    return 0;
}
```

---

## Vstup a výstup z textového súboru


### Čo je súbor

- **Súbor** – postupnosť bajtov uložených na médiu (disku) v niekoľkých blokoch (nie nutne za sebou)
- Prístup k blokom zabezpečuje operačný systém
- **Vstup zo súboru** – naraz sa prečíta celý blok z disku do pamäte (buffer), položky sa potom čítajú z pamäte (rýchlejšie)
- **Výstup do súboru** – dáta sa zapisujú do bufferu a keď je plný, zapíše sa na disk
  - Napr. v UNIXe sa dá používať aj nebufrované I/O operácie (`io.h`)
- **Koniec súboru** – často špeciálny znak (napr. `Ctrl+Z`)

### Typ FILE a deklarácia

- Základný dátový typ: `FILE *` – ukazovateľ (pointer) na objekt typu `FILE`
  - Ukazovateľ obsahuje adresu objektu typu `FILE` (ako adresár – zapísaná adresa, kde začína súbor na disku)
  - Dodržať veľké písmená (`FILE *`, nie `file *`)
- Definícia premennej pre prácu so súborom:

```c
FILE *f;
```

- Rovnaké pre čítanie aj pre zápis
- Pre viac premenných:

```c
FILE *fr, *fw;   /* fr pre čítanie, fw pre zápis */
```

> **Tip:** Pre čitateľnosť je vhodné používať `fr` pre čítanie (read) a `fw` pre zápis (write).

### Otvorenie súboru – fopen()

Čítanie (`r` ako *read*):

```c
fr = fopen("POKUS.TXT", "r");
```

Zápis (`w` ako *write*):

```c
fw = fopen("POKUS.TXT", "w");
```

- Aj ďalšie režimy otvorenia súboru (nielen `"r"` a `"w"`)
- Režimy `"r"` a `"w"` – otvorenie **textového** súboru
- Režimy `"rb"` a `"wb"` – otvorenie **binárneho** súboru (podrobnejšie neskôr)

### Základné funkcie pre prácu so súbormi

Všetky funkcie sú zo štandardnej knižnice `stdio.h`. Premenná `f` je typu `FILE *`.

| Funkcia súboru | Ekvivalent konzoly | Popis |
|---|---|---|
| `fgetc(f)` / `getc(f)` | `getchar()` | Čítanie znaku |
| `fputc(c, f)` / `putc(c, f)` | `putchar(c)` | Zápis znaku |
| `fscanf(f, "fmt", ...)` | `scanf("fmt", ...)` | Formátované čítanie |
| `fprintf(f, "fmt", ...)` | `printf("fmt", ...)` | Formátovaný zápis |


### Zatvorenie súboru – fclose()

Keď už nebudeme zo súboru čítať ani doňho zapisovať – uzatvoriť súbor:

```c
fclose(f);
```

> **Dôležité:**
> - Nespoliehať sa na automatické zatvorenie súboru po skončení programu.
> - Počet súčasne otvorených súborov je obmedzený.
> - Zápis bufferu do súboru prebehne pri `fclose()` – pri spadnutí programu by zostali dáta v bufferi a stratili by sa.

---

## Príklady práce so súbormi

### Zápis do súboru

Program vytvorí súbor `pokus.txt`, zapíše doňho čísla od 1 po 10, každé na zvlášť riadok:

```c
#include <stdio.h>

int main() {
    FILE *fw;
    int i;

    fw = fopen("pokus.txt", "w");
    for (i = 1; i <= 10; i++)
        fprintf(fw, "%d\n", i);
    fclose(fw);
    return 0;
}
```

### Čítanie zo súboru

Program načíta tri `double` čísla zo súboru `data.txt` a ich súčet vypíše na obrazovku:

```c
#include <stdio.h>

int main() {
    FILE *fr;
    double x, y, z;

    fr = fopen("data.txt", "r");
    fscanf(fr, "%lf %lf %lf", &x, &y, &z);
    printf("%lf\n", x + y + z);
    fclose(fr);
    return 0;
}
```

> **Poznámka:** Funkcia `fscanf()` vracia počet úspešne prečítaných položiek. V prípade konca súboru vracia hodnotu `EOF`. Súbor `data.txt` je potrebné najprv vytvoriť (napr. v editore).

Vylepšená verzia s kontrolou, či sú v súbore 3 čísla:

```c
#include <stdio.h>

int main() {
    FILE *fr;
    double x, y, z;

    fr = fopen("data.txt", "r");
    if (fscanf(fr, "%lf %lf %lf", &x, &y, &z) == 3)
        printf("%lf\n", x + y + z);
    else
        printf("Subor neobsahuje 3 realne cisla.\n");
    fclose(fr);
    return 0;
}
```

### Kopírovanie znakov medzi súbormi

Program prečíta 2 znaky zo súboru `znaky.txt` a zapíše ich do súboru `kopia.txt`:

```c
#include <stdio.h>

int main() {
    FILE *fr, *fw;
    int c;

    fr = fopen("znaky.txt", "r");
    fw = fopen("kopia.txt", "w");
    c = getc(fr);
    putc(c, fw);
    putc(getc(fr), fw);
    fclose(fr);
    fclose(fw);
    return 0;
}
```

---

## Testovanie konca riadku a konca súboru

### Koniec riadku (EOLN)

- Testovanie štandardného znaku pre koniec riadku v C: `'\n'`
- `'\n'` sa používa aj pre čítanie, aj pre zápis
- Konkrétny význam určuje prekladač podľa systému (`<CR>`, `<LF>`, alebo `<CR><LF>`)

**Príklad:** Program prečíta zo súboru `list.txt` riadok a aj s koncom riadku ho vypíše na obrazovku:

```c
#include <stdio.h>

int main() {
    FILE *fr;
    int c;

    fr = fopen("list.txt", "r");
    while ((c = getc(fr)) != '\n')
        putchar(c);
    putchar(c);    /* vypis \n */
    fclose(fr);
    return 0;
}
```

### Koniec súboru – EOF

- Symbolická konštanta `EOF` – väčšinou definovaná v `stdio.h`, väčšinou má hodnotu `-1`

```c
if ((c = getc(fr)) != EOF)
    ...
```

> **Dôležité:** Premenná `c` nesmie byť definovaná ako `char`, pretože `EOF` je reprezentovaná ako `int` s hodnotou `-1` (na `char` by bola konvertovaná ako iný znak).

**Príklad:** Program skopíruje obsah súboru `list.txt` do súboru `kopia.txt` (pomocou `EOF`):

```c
#include <stdio.h>

int main() {
    FILE *fr, *fw;
    int c;

    fr = fopen("list.txt", "r");
    fw = fopen("kopia.txt", "w");
    while ((c = getc(fr)) != EOF)
        putc(c, fw);
    fclose(fr);
    fclose(fw);
    return 0;
}
```

### Koniec súboru – feof()

Makro `feof()` vracia:
- **TRUE** (nenulovú hodnotu), keď posledné čítanie bolo za koncom súboru
- **FALSE** (nulu), keď sa pri čítaní nedošlo na koniec

> **Poznámka:** `feof()` je vhodné, keď čítame z **binárneho** súboru – ten môže obsahovať znak s hodnotou `0xFF`, ktorý by sa implicitnou konverziou premenil na hodnotu `EOF` a čítanie by sa skončilo predčasne.

**Príklad:** Kopírovanie súboru pomocou `feof()`:

```c
#include <stdio.h>

int main() {
    FILE *fr, *fw;
    int c;

    fr = fopen("list.txt", "r");
    fw = fopen("kopia.txt", "w");
    while (c = getc(fr), feof(fr) == 0)
        putc(c, fw);
    fclose(fr);
    fclose(fw);
    return 0;
}
```

---

## Testovanie správnosti otvorenia a zatvorenia

### fopen() – kontrola otvorenia

- Ak sa podarí otvoriť súbor – vracia ukazovateľ na súbor
- Ak sa nepodarí – vracia konštantu `NULL` (definovaná v `stdio.h`, má hodnotu `0`)

```c
if ((fr = fopen("test.txt", "r")) == NULL)
    printf("Subor sa nepodarilo otvorit.\n");
```

### fclose() – kontrola zatvorenia

- Ak sa podarí zatvoriť súbor – vracia hodnotu `0`
- Ak sa nepodarí – vracia konštantu `EOF`

```c
if (fclose(fr) == EOF)
    printf("Subor sa nepodarilo zatvorit.\n");
```

### Kompletný príklad s ošetreniami

Program skopíruje obsah súboru `list.txt` do `kopia.txt` s plnou kontrolou chýb:

```c
#include <stdio.h>

int main() {
    FILE *fr, *fw;
    int c;

    if ((fr = fopen("list.txt", "r")) == NULL) {
        printf("Subor sa nepodarilo otvorit.\n");
        return 0;
    }
    if ((fw = fopen("kopia.txt", "w")) == NULL) {
        printf("Subor sa nepodarilo otvorit.\n");
        fclose(fr);  /* nezabudnut zatvorit uz otvoreny subor */
        return 0;
    }

    while ((c = getc(fr)) != EOF)
        putc(c, fw);

    if (fclose(fr) == EOF)
        printf("Subor sa nepodarilo zatvorit.\n");
    if (fclose(fw) == EOF)
        printf("Subor sa nepodarilo zatvorit.\n");
    return 0;
}
```

> **Tip:** Pri neúspešnom otvorení druhého súboru nezabudnite zatvoriť prvý, už úspešne otvorený súbor.

---

## Komplexné príklady

### Konverzia na veľké písmená + najdlhší riadok

Program vypíše súbor `list.txt` na obrazovku, skonvertuje všetky malé písmená na veľké a na konci vypíše dĺžku najdlhšieho riadku.

```c
#include <stdio.h>

int main() {
    FILE *fr;
    int c, dlzka, max_dlzka;

    /* Kontrola otvorenia suboru */
    if ((fr = fopen("list.txt", "r")) == NULL) {
        printf("Subor sa nepodarilo otvorit.\n");
        return 0;
    }

    dlzka = max_dlzka = 0;

    /* Cita znaky az do konca suboru */
    while ((c = getc(fr)) != EOF) {
        dlzka++;                      /* Napocitava dlzku riadku */

        if (c >= 'a' && c <= 'z')     /* Konverzia malych pismen na velke */
            c += 'A' - 'a';

        putchar(c);                   /* Vypis znaku */

        if (c == '\n') {
            if (max_dlzka < dlzka)    /* Ak je riadok doteraz najdlhsi */
                max_dlzka = dlzka;
            dlzka = 0;               /* Vynulovat dlzku pre dalsi riadok */
        }
    }

    /* Kontrola aj dlzky posledneho riadku, ktory nemusi koncit \n */
    if (max_dlzka < dlzka)
        max_dlzka = dlzka;

    printf("Max. dlzka: %d\n", max_dlzka);

    if (fclose(fr) == EOF)
        printf("Subor sa nepodarilo zatvorit.\n");

    return 0;
}
```


### Štandardný vstup a výstup (stdin, stdout)

`stdin` a `stdout` môžu byť použité v programe ako argumenty operácií so súbormi:

| Súborová funkcia | Ekvivalent | Vysvetlenie |
|---|---|---|
| `getc(stdin)` | `getchar()` | Čítanie z klávesnice |
| `putc(c, stdout)` | `putchar(c)` | Zápis na obrazovku |

- V `stdio.h` je definovaný ešte tretí prúd `stderr`, ktorý sa používa pri vypisovaní chybových správ

### Výstup na obrazovku alebo do súboru

Program vypíše otázku, či má byť výstup vypísaný na obrazovku, alebo do súboru `vystup.txt`. Ak súbor existuje, opýta sa, či má byť prepísaný.

```c
#include <stdio.h>

int main() {
    FILE *fw;
    int c;

    printf("Stlacte O pre vypis na Obrazovku\n");
    printf("alebo iny znak pre zapis do suboru VYSTUP.TXT: ");

    c = getchar();
    while (getchar() != '\n')   /* Vyprazdnenie buffera */
        ;

    if (c == 'o' || c == 'O')
        fw = stdout;                 /* Vypis na standardny vystup */
    else {
        if ((fw = fopen("vystup.txt", "r")) != NULL) {
            printf("Subor vystup.txt existuje, prepisat? [A/N]: ");
            c = getchar();
            while (getchar() != '\n')
                ;
            if (fclose(fw) == EOF) {
                printf("Chyba pri zatvarani suboru\n");
                return 0;
            }
            if (!(c == 'a' || c == 'A'))
                return 0;           /* Nechce prepisat – koniec */
        }
        if ((fw = fopen("vystup.txt", "w")) == NULL) {
            printf("Subor vystup.txt sa nepodarilo otvorit\n");
            return 0;
        }
    }

    printf("Piste text a ukoncite ho znakom *\n");
    while ((c = getchar()) != '*')
        putc(c, fw);              /* Zapis do fw (subor alebo stdout) */

    if (fw != stdout) {
        if (fclose(fw) == EOF) {
            printf("Subor vystup.txt sa nepodarilo zatvorit\n");
            return 0;
        }
    }
    return 0;
}
```


---

## Funkcia ungetc() – vrátenie znaku do bufferu

Často zistíme, že máme prestať čítať znaky až potom, čo prečítame o znak naviac → vrátiť do bufferu:

```c
ungetc(c, fr);
```

- Ak je vrátenie úspešné, `ungetc()` vracia vrátený znak
- Ak je vrátenie neúspešné, vracia `EOF`
- Späť do bufferu môžeme zapísať aj iný ako práve prečítaný znak

### Príklad: Konverzia reťazca na číslo

Časť programu konvertuje znakový reťazec na zodpovedajúcu číselnú hodnotu:

```c
int c, hodnota = 0;

while ((c = getchar()) >= '0' && c <= '9') {
    hodnota = hodnota * 10 + (c - '0');
}
ungetc(c, stdin);
```

### Príklad: Preskočenie znakov pred čítaním čísla

Časť programu prečíta číslo pomocou `fscanf()`, ale predtým musí preskočiť neznámy počet znakov `'$'` (predpokladáme otvorený súbor):

```c
int c, hodnota = 0;

while ((c = getc(fr)) == '$')
    ;
ungetc(c, fr);
fscanf(fr, "%d", &hodnota);
```

---

## Režimy otvárania súborov

Súbory sa otvárajú stále rovnakou funkciou `fopen()` – či ide o textový alebo binárny súbor, či ide o zápis alebo čítanie.

Prototyp funkcie:

```c
FILE *fopen(const char *meno, const char *rezim);
```

- `const char *` – len vstupný argument, nebude sa meniť vo funkcii
- Vracia ukazovateľ (adresu) na otvorený súbor alebo `NULL`

### Prehľad režimov (textové súbory)

| Režim | Popis |
|---|---|
| `"r"` | Textový súbor pre čítanie |
| `"w"` | Textový súbor pre zápis (existujúci sa vymaže) |
| `"a"` | Textový súbor pre pripojenie na koniec |
| `"r+"` | Textový súbor pre čítanie a zápis |
| `"w+"` | Textový súbor pre čítanie, zápis (existujúci sa vymaže) |
| `"a+"` | Textový súbor pre čítanie a zápis na koniec |

### Podrobná tabuľka vlastností režimov

| Vlastnosť | `"r"` | `"w"` | `"a"` | `"r+"` | `"w+"` | `"a+"` |
|---|:---:|:---:|:---:|:---:|:---:|:---:|
| Súbor musí existovať | ✔ | | | ✔ | | |
| Existujúci súbor bude vymazaný | | ✔ | | | ✔ | |
| Existujúci súbor bude rozšírený | | | ✔ | | | ✔ |
| Neexistujúci súbor bude vytvorený | | ✔ | ✔ | | ✔ | ✔ |
| Čítanie z ľubovoľného miesta | ✔ | | | ✔ | ✔ | ✔ |
| Zápis na ľubovoľné miesto | | ✔ | | ✔ | ✔ | |
| Zápis iba na koniec | | | ✔ | | | ✔ |


> **Poznámky:**
> - Niektoré implementácie umožňujú explicitne určiť textový režim: `"rt"`, `"wt"`, `"at"`.
> - Ak otvoríme existujúci súbor v režime `"w"`, najprv sa vymaže a potom sa vytvorí nový.
> - Ak otvoríme existujúci súbor v režime `"a"`, ukazovateľ sa presunie na koniec súboru (rozširovanie).
> - Ak použijeme režim rozšírený o znak `+`, je možné do súboru aj zapisovať/čítať.

---

## Navigácia v súbore – fseek, ftell, rewind

### fseek() – nastavenie pozície

```c
int fseek(FILE *stream, long offset, int whence);
```

Nastavenie ukazovateľa na pozíciu čítania alebo zápisu v otvorenom súbore.

**Argumenty:**
- `stream` – ukazovateľ na súbor
- `offset` – relatívna pozícia oproti `whence`, na ktorú sa má ukazovateľ posunúť (v bajtoch)
- `whence` – k čomu je offset relatívny:

| Konštanta | Význam |
|---|---|
| `SEEK_SET` | Relatívne k začiatku súboru |
| `SEEK_CUR` | Relatívne k aktuálnej pozícii |
| `SEEK_END` | Relatívne ku koncu súboru (používať záporné hodnoty) |

**Návratová hodnota:** `0` pri úspechu, `-1` pri neúspechu.

### Príklady použitia fseek()

```c
fseek(fp, 100, SEEK_SET);    /* Nastavenie na 100. byte suboru         */
fseek(fp, -30, SEEK_CUR);    /* 30 bytov dozadu od aktualnej pozicie   */
fseek(fp, -10, SEEK_END);    /* 10 bytov pred koniec suboru            */
fseek(fp, 0, SEEK_SET);      /* Nastavenie na zaciatok suboru          */
```

### rewind() – návrat na začiatok

```c
void rewind(FILE *stream);
```

Nastavenie ukazovateľa na začiatok súboru. Ekvivalent `fseek(fp, 0, SEEK_SET)`.

### ftell() – zistenie aktuálnej pozície

```c
long ftell(FILE *stream);
```

Zistenie pozície ukazovateľa čítania/zápisu v otvorenom súbore, relatívne k začiatku súboru (kde nastane nasledujúca operácia).

**Použitie:** Zapamätať si pozíciu, na ktorú sa neskôr plánujete vrátiť – zapamätať si návratovú hodnotu a potom ju použiť vo `fseek()` relatívne k začiatku súboru.

**Návratová hodnota:** Aktuálna pozícia alebo `-1` v prípade neúspechu.


---

[← Prednáška 3](../03-cykly/) | [Hlavná stránka](../../README.md) | [Prednáška 5 →](../05-funkcie-polia/)
