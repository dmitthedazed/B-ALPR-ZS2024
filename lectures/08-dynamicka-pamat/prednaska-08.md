# Prednáška 8: Dynamické prideľovanie pamäte a viacrozmerné polia

> **Predmet:** Algoritmizácia a programovanie  
> **Prednášajúci:** Ján Grman  
> **Semester:** Zimný semester 2024

---

## 📑 Obsah

1. [Dynamické prideľovanie a uvoľňovanie pamäte](#1-dynamické-prideľovanie-a-uvoľňovanie-pamäte)
   - [Funkcia `malloc()`](#11-funkcia-malloc)
   - [Testovanie pridelenia pamäte](#12-testovanie-pridelenia-pamäte)
   - [Kedy potrebujeme prideliť pamäť](#13-kedy-potrebujeme-prideliť-pamäť)
   - [Uvoľňovanie pamäte – `free()`](#14-uvoľňovanie-pamäte--free)
   - [Príklad: alokácia pre jeden `char`](#15-príklad-alokácia-pre-jeden-char)
   - [Príklad: alokácia pre jeden `int`](#16-príklad-alokácia-pre-jeden-int)
   - [Funkcia `calloc()`](#17-funkcia-calloc)
2. [Príklad: súčin n čísel](#2-príklad-súčin-n-čísel)
3. [Dynamické polia](#3-dynamické-polia)
4. [Ukazovatele na funkcie](#4-ukazovatele-na-funkcie)
   - [Pole ukazovateľov na funkcie](#41-pole-ukazovateľov-na-funkcie)
   - [Čítanie zložitejších definícií](#42-čítanie-zložitejších-definícií)
   - [Definícia s využitím `typedef`](#43-definícia-s-využitím-typedef)
5. [Príklad: výpočet priemeru (kompletný program)](#5-príklad-výpočet-priemeru-kompletný-program)
6. [Polia a ukazovatele](#6-polia-a-ukazovatele)
   - [Statické polia – základy](#61-statické-polia--základy)
   - [Vzťah polí a ukazovateľov](#62-vzťah-polí-a-ukazovateľov)
   - [Prístup k prvkom cez ukazovateľ](#63-prístup-k-prvkom-cez-ukazovateľ)
   - [Zistenie veľkosti poľa – `sizeof()`](#64-zistenie-veľkosti-poľa--sizeof)
7. [Pole meniace svoju veľkosť](#7-pole-meniace-svoju-veľkosť)
   - [Manuálne zväčšenie poľa](#71-manuálne-zväčšenie-poľa)
   - [Funkcia `realloc()`](#72-funkcia-realloc)
8. [Pole ako parameter funkcie](#8-pole-ako-parameter-funkcie)
9. [Viacrozmerné polia](#9-viacrozmerné-polia)
   - [Základné definície](#91-základné-definície)
   - [Prístup k prvkom](#92-prístup-k-prvkom)
   - [Uloženie v pamäti](#93-uloženie-v-pamäti)
   - [Spôsoby definície dvojrozmerných polí](#94-spôsoby-definície-dvojrozmerných-polí)
   - [Porovnanie spôsobov vytvárania polí](#95-porovnanie-spôsobov-vytvárania-polí)
   - [Zubaté pole](#96-zubaté-pole)
   - [Alokovanie dynamického pravoúhleho poľa](#97-alokovanie-dynamického-pravoúhleho-poľa)
   - [Prístup k prvkom statického 2D poľa cez ukazovateľ](#98-prístup-k-prvkom-statického-2d-poľa-cez-ukazovateľ)
   - [Dvojrozmerné pole ako parameter funkcie](#99-dvojrozmerné-pole-ako-parameter-funkcie)
   - [Inicializácia polí](#910-inicializácia-polí)
10. [Pole reťazcov](#10-pole-reťazcov)
11. [Parametre funkcie `main()`](#11-parametre-funkcie-main)
12. [Príklad: práca s maticami (kompletný program)](#12-príklad-práca-s-maticami-kompletný-program)

---

## 1. Dynamické prideľovanie a uvoľňovanie pamäte

Prideľovanie pamäte za chodu programu:

| Oblasť | Riadenie | Poznámka |
|---|---|---|
| **Zásobník** (stack) | Operačný systém | Automatické premenné |
| **Hromada** (heap) | Programátor | Dynamické prideľovanie |

> **Životnosť dynamických dát:** od alokovania po uvoľnenie pamäte.

<details>



### 1.1 Funkcia `malloc()`

Definovaná v `stdlib.h` (niekedy v `alloc.h`):

```c
void *malloc(unsigned int pocet_bytov);
```

- **Parameter:** počet bajtov na alokovanie
- **Návratová hodnota:** adresa prvého prideleného bajtu (vhodné pretypovať)
- Ak nie je v pamäti dostatok miesta, vráti `NULL`

<details>



### 1.2 Testovanie pridelenia pamäte

Vždy kontrolujte, či `malloc()` pridelil pamäť:

```c
int *p_i;

if ((p_i = (int *) malloc(1000)) == NULL) {
    printf("Nepodarilo sa pridelit pamat\n");
    exit(1);
}
```

### 1.3 Kedy potrebujeme prideliť pamäť

Inicializácia ukazovateľa vytvorí len miesto pre samotný ukazovateľ:

```c
int *p_i;
```

Pri použití ukazovateľa **len na prístup** k už vyhradeným premenným **nie je potrebné** alokovať pamäť:

```c
int pole[20];
for (p_i = pole; p_i < pole + 20; p_i++)
    printf("%d ", *p_i);
```

Alokujeme **len vtedy**, keď skutočne potrebujeme **ďalšiu pamäť**:

```c
int i;
p_i = (int *) malloc(1000 * sizeof(int));
for (i = 0; i < 20; i++)
    *(p_i + i) = pole[i];
```

<details>



### 1.4 Uvoľňovanie pamäte – `free()`

Nepotrebnú pamäť je vhodné ihneď vrátiť operačnému systému:

```c
void free(void *ptr);
```

Príklad:

```c
char *p_c;

p_c = (char *) malloc(1000 * sizeof(char));
/* ... práca s pamäťou ... */
free(p_c);
p_c = NULL;
```

> **Poznámka:** Po uvoľnení pamäte je dobrou praxou nastaviť ukazovateľ na `NULL`.

### 1.5 Príklad: alokácia pre jeden `char`

```c
char *p_c;

if ((p_c = (char *) malloc(1)) == NULL)
    /* chybová správa a ukončenie */

*p_c = 'a';
/* ... */
free(p_c);
```

> ⚠️ **Pozor:** Bez alokácie pamäte ukazovateľ `p_c` nemá pridelenú pamäť a môže ukazovať kamkoľvek — program spadne!

### 1.6 Príklad: alokácia pre jeden `int`

**Nesprávne** — alokuje len 1 bajt (nedostatočné pre `int`):

```c
int *p_i;
if ((p_i = (int *) malloc(1)) == NULL) {
    printf("Nie je dostatok pamate\n");
    exit(1);
}
```

**Správne** — používame `sizeof(int)`:

```c
int *p_i;
if ((p_i = (int *) malloc(1 * sizeof(int))) == NULL) {
    printf("Nie je dostatok pamate\n");
    exit(1);
}
free(p_i);
```

> **Poznámka:** `sizeof(int)` vracia veľkosť typu `int` v bajtoch (typicky 2 alebo 4).

### 1.7 Funkcia `calloc()`

Rovnako ako `malloc()`, ale automaticky inicializuje všetky bajty na `0`:

```c
void *calloc(unsigned int pocet, unsigned int velkost);
```

<details>



---

## 2. Príklad: súčin n čísel

Program načíta 5 čísel a vypočíta ich súčin. Obsahuje 3 pomocné funkcie + `main()`:

- Alokovanie pamäte pre n čísel
- Načítanie n čísel z klávesnice
- Vypočítanie súčinu n čísel

### Funkcia na alokovanie pamäte

```c
int *alokuj(int n)
{
    return ((int *) malloc(n * sizeof(int)));
}
```

### Funkcia na načítanie n čísel

```c
void nacitaj(int *p_i, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("Zadajte %d-te cislo: ", i + 1);
        scanf("%d", p_i + i);
    }
}
```

### Funkcia na vypočítanie súčinu

```c
void sucin(int *p, int n, int *sucin)
{
    int i;

    *sucin = 1;
    for (i = 0; i < n; i++)
        *sucin *= *(p + i);
}
```

> **Úloha:** Pozrite si kratšie napísanú verziu funkcie v literatúre (Herout).

### Funkcia `main()`

```c
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int *cisla, suc;
    cisla = alokuj(N);
    nacitaj(cisla, N);
    sucin(cisla, N, &suc);
    printf("Sucin je: %d\n", suc);
    free(cisla);
    return 0;
}
```

---

## 3. Dynamické polia

Dynamické pole vytvoríme pomocou `malloc()` a pristupujeme k nemu rovnako ako k statickému:

```c
int i = 5, *p_i;
p_i = (int *) malloc(n * sizeof(int));
for (i = 0; i < n; i++)
    p_i[i] = i;
```

> **Úloha:** Prepíšte prístup pomocou ukazovateľovej aritmetiky:
> ```c
> for (i = 0; i < n; i++)
>     *(p_i + i) = i;
> ```

<details>



---

## 4. Ukazovatele na funkcie

Funkcia môže vrátiť ukazovateľ na typ:

```c
FILE *fopen(...);  /* vracia smerník na typ FILE */
```

Definovanie premennej ako ukazovateľ na funkciu:

```c
double (*p_fd)();           /* ukazovateľ na funkciu vracajúcu double */
```

| Zápis | Význam |
|---|---|
| `double *p_fd;` | ukazovateľ na `double` |
| `double *p_fd();` | funkcia vracajúca ukazovateľ na `double` |
| `double (*p_fd)();` | ukazovateľ na funkciu vracajúcu `double` |

Priradenie adresy funkcie:

```c
double scitaj(double x, double y);
p_fd = scitaj;    /* p_fd má adresu funkcie scitaj() */
```

### Príklad: tabuľka hodnôt polynómov

Pomocné funkcie pre polynómy:

```c
double pol1(double x)
{
    return (x * x + 3);
}

double pol2(double x)
{
    return (x + 8);
}
```

Funkcia `vypis()` na vypísanie tabuľky s ukazovateľom na funkciu:

```c
void vypis(double d, double h, double k, double (*p_f)())
{
    double x;
    for (x = d; x <= h; x += k)
        printf("%lf, %lf\n", x, (*p_f)(x));
}
```

Volanie vo funkcii `main()`:

```c
vypis(-1.0, 1.0, 0.1, pol1);
vypis(-2.0, 2.0, 0.05, pol2);
```

### Príklad: Ahoj / Čau / Koniec

Program načítava písmená — po stlačení `'A'` vypíše "Ahoj", po `'C'` vypíše "Cau", po `'K'` skončí:

```c
#include <stdio.h>
#include <stdlib.h>

void ahoj() {
    printf("Ahoj\n");
}

void cau() {
    printf("Cau\n");
}

int main() {
    int c;
    void (*p_fnc)();       /* definícia ukazovateľa na funkciu */

    printf("Ahoj / Cau / Koniec\n");
    while ((c = toupper(getchar())) != 'K') {
        if (c == 'A') p_fnc = ahoj;
        else if (c == 'C') p_fnc = cau;
        else continue;

        (*p_fnc)();
    }
    return 0;
}
```

### 4.1 Pole ukazovateľov na funkcie

Prvkami poľa môžu byť aj ukazovatele na funkcie (všetky funkcie musia byť toho istého typu):

```c
typedef void (*P_FNC)();     /* definícia ukazovateľa na funkciu vracajúcu void */

P_FNC funkcie[10];           /* pole 10 ukazovateľov */
```

Použitie pri riadení programu pomocou menu:

```c
typedef void (*P_FNC)();

P_FNC funkcie[5] = {file, edit, search, compile, run};

/* volanie funkcie: */
funkcie[1]();    /* zavolá edit() */
```

### Príklady definícií

| Definícia | Význam |
|---|---|
| `int i;` | `i` je typu `int` |
| `float *y;` | `y` je ukazovateľ na typ `float` |
| `double *z();` | `z` je funkcia vracajúca ukazovateľ na `double` |
| `int (*v)();` | `v` je ukazovateľ na funkciu vracajúcu `int` |
| `int *(*v)();` | `v` je ukazovateľ na funkciu vracajúcu ukazovateľ na `int` |

### 4.2 Čítanie zložitejších definícií

Postup čítania:

1. Nájdeme **identifikátor**, od neho čítame doprava
2. Pokým nenarazíme na samotnú pravú zátvorku `)` — vraciame sa k zodpovedajúcej ľavej zátvorke, potom pokračujeme doprava (preskakujeme prečítané)
3. Ak narazíme na `;`, vraciame sa na najľavejšie spracované miesto a čítame doľava

**Príklad:** čítanie definície `int *(*v)();`

1. Nájdeme identifikátor `v`, čítame doprava
2. Nájdeme `)`, k nej zodpovedajúcu `(`, od nej čítame doprava: `*`
3. Doprava, preskakujeme prečítané, po `)`, k nej `(`
4. Doprava, preskakujeme prečítané, po `;`, doľava

> **Výsledok:** `v` je pointer na funkciu vracajúcu pointer na `int`

<details>



### 4.3 Definícia s využitím `typedef`

Operátor `typedef` vytvára nový typ — využíva sa najmä na definovanie zložitejších typov:

```c
typedef float *P_FLOAT;
/* P_FLOAT je ukazovateľ na typ float */
```

Príklady použitia:

```c
/* Bez typedef: */
int *p_i, **p_p_i;

/* S typedef: */
typedef int *P_INT;
typedef P_INT *P_P_INT;

P_INT p_i;       /* ukazovateľ na int */
P_P_INT p_p_i;   /* ukazovateľ na ukazovateľ na int */
```

```c
typedef double (*P_FD)();   /* ukazovateľ na funkciu vracajúcu double */
```

---

## 5. Príklad: výpočet priemeru (kompletný program)

Program načíta celé číslo `n`, alokuje blok pamäte pre `n` celých čísel, od používateľa čísla načíta a nakoniec vypočíta ich priemer.

### Hlavičky a prototypy

```c
#include <stdio.h>
#include <stdlib.h>

int *alokuj(int pocet);
void nacitaj(int *pole, int pocet);
float priemer(int *pole, int pocet);
void vypis(int *pole, int pocet);
```

### Funkcia `main()`

```c
int main()
{
    int *pole, n;

    printf("Zadajte pocet cisel: ");
    scanf("%d", &n);
    if ((pole = alokuj(n)) == NULL) {
        printf("Nepodarilo sa alokovat pole.\n");
        return 1;
    }
    nacitaj(pole, n);
    printf("Priemer cisel: \n");
    vypis(pole, n);
    printf("je %.3f.\n", priemer(pole, n));
    free(pole);
    return 0;
}
```

### Pomocné funkcie

```c
int *alokuj(int pocet)
{
    return (int *) malloc(pocet * sizeof(int));
}

void nacitaj(int *pole, int pocet)
{
    int i;
    for (i = 0; i < pocet; i++) {
        printf("%d-te cislo: ", i);
        scanf("%d", pole + i);
    }
}

float priemer(int *pole, int pocet)
{
    int i, suma = 0;
    for (i = 0; i < pocet; i++)
        suma += *(pole + i);
    return (float) suma / (float) pocet;
}

void vypis(int *pole, int pocet)
{
    int i;
    for (i = 0; i < pocet; i++)
        printf("%d, ", *(pole + i));
}
```

---

## 6. Polia a ukazovatele

### 6.1 Statické polia – základy

Pole je štruktúra zložená z niekoľkých prvkov rovnakého typu (súvislý blok prvkov):

```c
TYP x[N];    /* statická definícia poľa */
```

- Pole obsahuje `N` prvkov
- Dolná hranica je vždy **0**, horná hranica je **N-1**
- Číslo `N` musí byť známe **v čase prekladu**
- Hodnoty **nie sú inicializované** na 0

### 6.2 Vzťah polí a ukazovateľov

Adresa i-teho prvku poľa `x`:

$$\texttt{\&x[i]} = \text{bázová adresa } x + i \times \texttt{sizeof(typ)}$$

Platí:

```c
x + i   == &x[i]
*(x + i) == x[i]
```

Pre dynamické pole:

```c
int *p;
p = (int *) malloc(4 * sizeof(int));
```

| Index | Cez index | Cez ukazovateľ |
|---|---|---|
| 0 | `p[0]` | `*p` |
| 1 | `p[1]` | `*(p + 1)` |
| 2 | `p[2]` | `*(p + 2)` |
| 3 | `p[3]` | `*(p + 3)` |

> **Rozdiel** medzi statickými a dynamickými poliami je najmä v spôsobe prideľovania pamäte.

Pre statické pole:

```c
int x[4];
```

Platí:

```c
&x[0] == &*(x + 0) == x
&x[i] == &*(x + i) == (x + i)
```

> ⚠️ `x` je **statický ukazovateľ** — nemôžeme spraviť `x = p_i;`, ale môžeme `*x = 2;` (to isté ako `x[0] = 2;`).

### 6.3 Prístup k prvkom cez ukazovateľ

Prepísanie prístupu k poľu `slovo` pomocou ukazovateľov:

**Pôvodný kód (indexy):**

```c
i = 0;
while (i < N && slovo[i] != '\0') {
    hist[toupper(slovo[i]) - 'A']++;
    i++;
}
```

**Prepísaný kód (ukazovatele):**

```c
i = 0;
while (i < N && *(slovo + i) != '\0') {
    hist[toupper(*(slovo + i)) - 'A']++;
    i++;
}
```

### 6.4 Zistenie veľkosti poľa – `sizeof()`

```c
int x[10], *p_x;
p_x = (int *) malloc(10 * sizeof(int));
```

Po alokovaní pamäte sú `x` aj `p_x` ukazovatele na pole 10 prvkov typu `int`, ale:

| Výraz | Hodnota | Poznámka |
|---|---|---|
| `sizeof(x)` | `10 * sizeof(int)` (napr. 20) | Statický ukazovateľ — veľkosť celého poľa |
| `sizeof(p_x)` | `sizeof(int *)` (napr. 4) | Dynamický ukazovateľ — veľkosť samotného ukazovateľa |

---

## 7. Pole meniace svoju veľkosť

### 7.1 Manuálne zväčšenie poľa

```c
int *x, n = 5, *p1, *p2, *p;

/* Alokovanie poľa x */
x = (int *) malloc(n * sizeof(int));
x[0] = 10; x[4] = 3;

/* Potreba zväčšiť pole */
p = (int *) malloc(10 * n * sizeof(int));    /* alokovanie väčšieho poľa */

/* Kopírovanie obsahu */
p1 = x;
p2 = p;
while (p1 < x + n)
    *p2++ = *p1++;

n *= 10;
free(x);     /* uvoľnenie menšieho poľa */
x = p;       /* nastavenie x na nové pole */
```

### 7.2 Funkcia `realloc()`

Definovaná v `stdlib.h`:

```c
void *realloc(void *pole, unsigned int size);
```

- `pole` — ukazovateľ na existujúcu pamäť
- `size` — nová veľkosť
- Zväčší pole, alebo vytvorí nové a prekopíruje tam hodnoty z pôvodného poľa

```c
x = realloc(x, 10 * n * sizeof(int));
```

---

## 8. Pole ako parameter funkcie

Zápisy `int pole[]` a `int *pole` sú **ekvivalentné** ako parametre funkcie:

```c
int maximum(int pole[], int n) { /* ... */ }
int maximum(int *pole, int n)  { /* ... */ }
```

> Pri použití `int pole[]` je jasnejšie, že ide o pole a nie o ukazovateľ na `int`.

Volanie:

```c
max = maximum(pole, 10);
```

Dá sa použiť aj na podmnožinu poľa (napr. 3. až 7. prvok):

```c
int x[10];
max = maximum(&x[2], 5);
/* alebo ekvivalentne: */
max = maximum(x + 2, 5);
```

### Funkcia `maximum()` ako procedúra

```c
void maximum(int pole[], int n, int *p_max)
{
    int *p;
    *p_max = pole[0];
    for (p = pole + 1; p < pole + n; p++) {
        if (*p > *p_max)
            *p_max = *p;
    }
}
```

> ⚠️ Ak by sme dali `p_max = p;`, stratili by sme ukazovateľ na premennú, kam treba vrátiť maximum.

### Vytváranie poľa vo funkcii

```c
void init(double **p_f)
{
    double *a;
    int i;

    a = (double *) malloc(5 * sizeof(double));
    for (i = 0; i < 5; i++) {
        printf("Zadaj %d. cislo: ", i);
        scanf("%lf", &a[i]);
    }
    *p_f = a;
}

int main()
{
    double *p_d;
    init(&p_d);
    /* p_d teraz ukazuje na pole 5 double prvkov */
    return 0;
}
```

> **Poznámka:** Ukazovateľ `a` je vyrobený na hromade (heap) cez `malloc()`, takže prežije koniec funkcie. Keby sme použili lokálne statické pole `double a[5];`, pamäť by sa uvoľnila pri ukončení funkcie.

---

## 9. Viacrozmerné polia

<details>



### 9.1 Základné definície

Definícia dvojrozmerného poľa:

```c
int x[5][4];
```

S použitím `typedef`:

```c
typedef int DVA[5][4];
DVA d;
```

Alebo postupne:

```c
typedef int JEDEN[4];
typedef JEDEN DVA[5];
DVA d;
```

Príklad poľa 5×4:

| | Stĺpec 0 | Stĺpec 1 | Stĺpec 2 | Stĺpec 3 |
|---|---|---|---|---|
| **Riadok 0** | 1 | 2 | 3 | 4 |
| **Riadok 1** | 5 | 6 | 7 | 8 |
| **Riadok 2** | 9 | 10 | 11 | 12 |
| **Riadok 3** | 13 | 14 | 15 | 16 |
| **Riadok 4** | 17 | 18 | 19 | 20 |

### 9.2 Prístup k prvkom

Pomocou indexov — rovnaký ako pre jednorozmerné polia:

```c
/* Dvojrozmerné pole */
int tabulka[5][10];
tabulka[1][6] = 4;
tabulka[4][9] = 0;

/* Trojrozmerné pole */
int trojtabulka[5][6][7];
trojtabulka[0][5][0] = 4;
```

### 9.3 Uloženie v pamäti

Viacrozmerné pole je uložené **po riadkoch**:

```c
int x[2][3];
```

```
Adresa:   10        12        14        16        18        20
Hodnota:  x[0][0]   x[0][1]   x[0][2]   x[1][0]   x[1][1]   x[1][2]
          |--- x[0] (riadok 0) ---|     |--- x[1] (riadok 1) ---|
          |--- x (celé pole) ------------------------------------|
```

Kľúčové vzťahy:

| Výraz | Význam |
|---|---|
| `x`, `x[0]` | Tá istá adresa, ale **iného typu** |
| `x + 1` vs `x[0] + 1` | **Odlišné** adresy (riadok vs prvok) |
| `x[i]` | Ukazovateľ na i-ty riadok |
| `*(x + 1)` == `x[1]` | Adresa druhého riadku |
| `x[i][j]` | Hodnota prvku poľa |

Ekvivalentné zápisy:

| Operácia | Indexy | Ukazovateľová aritmetika |
|---|---|---|
| Adresa i-teho riadku | `x[i]` | `*(x + i)` |
| Adresa prvku `[i][j]` | `&x[i][j]` | `*(x + i) + j` |
| Hodnota prvku `[i][j]` | `x[i][j]` | `*(*(x + i) + j)` |

<details>



### 9.4 Spôsoby definície dvojrozmerných polí

Existujú 4 spôsoby:

#### a) Statické dvojrozmerné pole

```c
int xa[2][3];
```

- Alokované pri preklade
- Súvislý blok 6 prvkov
- Uložené po riadkoch
- Konštantný ukazovateľ

```
xa[0][0]  xa[0][1]  xa[0][2]  xa[1][0]  xa[1][1]  xa[1][2]
|-------- xa[0] ----------|  |-------- xa[1] ----------|
|-------- xa ------------------------------------------|
```

#### b) Pole ukazovateľov

```c
int *xb[2];

xb[0] = (int *) malloc(3 * sizeof(int));
xb[1] = (int *) malloc(3 * sizeof(int));

xb[0][2] = 5;   /* prístup k prvkom */
```

- Jednorozmerné pole dvoch ukazovateľov na `int`
- Riadky **nemusia** nasledovať v pamäti bezprostredne za sebou
- Ak u statického poľa `xa[0][3] = 5` priradí hodnotu do `xa[1][0]`, u poľa `xb` to **nemusí platiť**

```
xb[0]  xb[1]  ...  xb[0][0]  xb[0][1]  xb[0][2]  ...  xb[1][0]  xb[1][1]  xb[1][2]
```

#### c) Ukazovateľ na pole

```c
int (*xc)[3];

xc = (int (*)[3]) malloc(2 * 3 * sizeof(int));

xc[0][2] = 5;   /* prístup k prvkom */
```

- `xc` je ukazovateľ na pole troch `int`-ov
- Ak alokujeme dostatok pamäte — obdoba statického poľa
- Riadky nasledujú v pamäti **bezprostredne za sebou**

```
xc  →  xc[0][0]  xc[0][1]  xc[0][2]  xc[1][0]  xc[1][1]  xc[1][2]
```

#### d) Ukazovateľ na ukazovateľ

```c
int **xd;

/* (1) alokujeme ukazovatele na riadky */
xd = (int **) malloc(2 * sizeof(int *));

/* (2) alokujeme jednotlivé riadky */
xd[0] = (int *) malloc(3 * sizeof(int));
xd[1] = (int *) malloc(3 * sizeof(int));

xd[0][2] = 5;   /* prístup k prvkom */
```

| Výraz | Typ | Význam |
|---|---|---|
| `xd` | `int **` | ukazovateľ na ukazovateľ na `int` |
| `*xd` | `int *` | ukazovateľ na `int` |
| `**xd` | `int` | prvok typu `int` |

```
xd  →  xd[0]  xd[1]  →  xd[0][0]  xd[0][1]  xd[0][2]
                          xd[1][0]  xd[1][1]  xd[1][2]
```

<details>



### 9.5 Porovnanie spôsobov vytvárania polí

#### Typ poľa

| Definícia | Typ |
|---|---|
| `int xa[2][3]` | **Statické** pole |
| `int *xb[2]` | **Dynamické** pole (po alokácii) |
| `int (*xc)[3]` | **Dynamické** pole (po alokácii) |
| `int **xd` | **Dynamické** pole (po alokácii) |

#### Pamäťové nároky

| Definícia | Pamäť naviac | Poznámka |
|---|---|---|
| `int xa[2][3]` | žiadna | Pamäťovo **najvýhodnejšia** |
| `int *xb[2]` | 2 ukazovatele | Pre riadky `xb[0]`, `xb[1]` |
| `int (*xc)[3]` | 1 ukazovateľ | Pre `xc` |
| `int **xd` | 3 ukazovatele | Pre `xd` + `xd[0]` + `xd[1]` |

#### Charakter poľa

| Definícia | Charakter |
|---|---|
| `int xa[2][3]` | **Pravoúhle** pole |
| `int *xb[2]` | **Zubaté** pole (rôzne dĺžky riadkov) |
| `int (*xc)[3]` | **Pravoúhle** pole |
| `int **xd` | **Zubaté** pole (rôzne dĺžky riadkov) |

<details>



### 9.6 Zubaté pole

Dvojrozmerné pole s rôznou dĺžkou riadkov — časť matice pod diagonálou (vrátane):

```c
int *m[3], i;
for (i = 0; i < 3; i++)
    m[i] = (int *) malloc((i + 1) * sizeof(int));
```

Výsledná štruktúra:

```
m[0] →  m[0][0]
m[1] →  m[1][0]  m[1][1]
m[2] →  m[2][0]  m[2][1]  m[2][2]
```

### 9.7 Alokovanie dynamického pravoúhleho poľa

```c
int **create(int riadky, int stlpce)
{
    int **p, i;

    p = (int **) malloc(riadky * sizeof(int *));
    for (i = 0; i < riadky; i++)
        p[i] = (int *) malloc(stlpce * sizeof(int));

    return p;
}
```

Príklad volania:

```c
int **a, **b;
a = create(3, 5);
b = create(10, 20);
```

### 9.8 Prístup k prvkom statického 2D poľa cez ukazovateľ

```c
int **x, y[5][6];

x = (int **) y;
```

> ⚠️ Ukazovateľ `x` sa **nedá** používať na prístup do poľa `y`, pretože `x` nie je definovaná na prístup do dvojrozmerného poľa — nemá informáciu o veľkosti riadkov. Je potrebné riadiť sa podľa počtu riadkov a stĺpcov ručne.

### 9.9 Dvojrozmerné pole ako parameter funkcie

Ako jednorozmerné pole, ale s odlišnosťou:
- **Prvá dimenzia** — prázdna `[]`
- **Druhá dimenzia** musí byť uvedená, napr. `[10]`
- Je potrebné preniesť do funkcie aj **počet riadkov**
- Skutočný parameter: len pravoúhle polia (`xa`, `xc`)

Pre pole `double x[5][6]`:

```c
double x[][6]      /* správne */
double (*x)[6]     /* správne — ekvivalentné */
/* double *x[6]    — NESPRÁVNE! — pole 6 ukazovateľov */
```

#### Príklad: maximum z 2D poľa

```c
double maximum(double pole[][4], int riadky)
{
    double pom = pole[0][0];
    int i, j;

    for (i = 0; i < riadky; i++) {
        for (j = 0; j < 4; j++)
            if (pole[i][j] > pom)
                pom = pole[i][j];
    }
    return (pom);
}
```

### 9.10 Inicializácia polí

Najčastejšie u reťazcov (aj pre iné polia):

```c
double f[3] = {1.5, 3.0, 7.6};     /* všetky prvky uvedené */
double f[]  = {1.5, 3.0, 7.6};     /* počet sa určí podľa hodnôt */
double f[3] = {1.5, 3.0};          /* chýbajúce doplnené 0.0 */
/* double f[3] = {1.5, 3.0, 7.6, 3.8};  — CHYBA! príliš veľa hodnôt */
```

Inicializácia dvojrozmerných polí — počet stĺpcov **musí byť uvedený**:

```c
double f[][2] = {
    {1.5, 3.0},
    {7.6, 3.8}
};
```

> **Poznámka:** Počet riadkov sa môže vynechať — určí sa automaticky podľa počtu inicializátorov.

---

## 10. Pole reťazcov

Asi najčastejšie využívané pole s rôznou dĺžkou riadkov:

```c
char *p_text[4];

p_text[0] = "prvy";
p_text[1] = "druhy";
p_text[2] = (char *) malloc(6);
strcpy(p_text[2], "treti");
p_text[3] = "stvrty";
```

> **Poznámka:** Len reťazec `p_text[2]` je alokovaný dynamicky, ostatné sú statické reťazcové literály.

Prístup k jednotlivým znakom:

```c
char *p_text[4], c, *p;

/* Prístup k jednotlivým prvkom */
c = p_text[0][0];    /* 'p' */

/* Vytlačenie reťazca po znakoch */
p = &p_text[0][0];
while (*p != '\0')
    putchar(*p++);

/* Vytlačenie reťazca pomocou printf() */
printf("%s\n", p_text[1]);

/* Vytlačenie reťazca pomocou puts() */
puts(p_text[2]);
```

### Práca s ukazovateľom na pole reťazcov

```c
char *p_text[4], **p;
p = p_text;
puts(++*p);     /* vytlačí "rvy" — posunie p_text[0] o 1 znak */
```

> ⚠️ `*p` ukazuje na `p_text[0]`. Príkaz `++*p` zväčší hodnotu `p_text[0]` o 1, takže potom ukazuje na `"rvy"` — táto zmena je **trvalá**!

```c
char *p_text[4], **p;
p = p_text;
puts(*++p);     /* vytlačí "druhy" — posunie p na druhý riadok */
```

Iterácia cez všetky reťazce:

```c
char *p_text[4], **p;
p = p_text;
for (i = 0; i < 4; i++)
    puts(*p++);     /* ++ má väčšiu prioritu ako * */
```

<details>



---

## 11. Parametre funkcie `main()`

```c
int main(int argc, char *argv[])
```

| Parameter | Typ | Význam |
|---|---|---|
| `argc` | `int` | Počet reťazcov vstupného poľa |
| `argv` | `char *[]` | Vstupné pole argumentov |

**Príklad volania:**

```
$ test parameter1 parameter2
```

| Index | Hodnota |
|---|---|
| `argc` | 3 |
| `argv[0]` | `"test"` (názov programu) |
| `argv[1]` | `"parameter1"` |
| `argv[2]` | `"parameter2"` |

> **Poznámka:** Reťazce v úvodzovkách sa počítajú ako jeden argument:
> `test "ahoj nazdar" cau` → `argc` = 3

### Príklad: spracovanie argumentov

Ak je argument `"-h"`, program vypíše "help", inak "program":

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 2 && !strcmp(argv[1], "-h"))
        printf("help\n");
    else
        printf("program\n");
    return 0;
}
```

---

## 12. Príklad: práca s maticami (kompletný program)

Funkcionality:
- Načítanie matíc zo súboru (názov súboru ako argument programu)
- 3 matice: `m1`, `m2`, `m3`
- Menu: výpis, sčítanie (`m3 = m1 + m2`), násobenie (`m3 = m1 × m2`), výmena (`m1 ↔ m2`)

### Hlavičky a prototypy

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define SUBOR "matice.txt"

void nacitaj(int m1[N][N], int m2[N][N], int m3[N][N], char meno[]);
void vypis(int m1[N][N], int m2[N][N], int m3[N][N]);
void scitaj(int m1[N][N], int m2[N][N], int m3[N][N]);
void nasob(int m1[N][N], int m2[N][N], int m3[N][N]);
void vymen(int m1[N][N], int m2[N][N]);
int nacitaj_pom(int m[N][N], FILE *f);
```

### Funkcia `main()`

```c
int main(int argc, char *argv[])
{
    int c, m1[N][N], m2[N][N], m3[N][N];

    nacitaj(m1, m2, m3, argc == 2 ? argv[1] : SUBOR);
    do {
        printf("\n*** MATICE ***\n");
        printf("v: vypis\ns: scitanie\n");
        printf("n: nasobenie\nm: vymena\nk: koniec\n");
        while ((c = tolower(getchar())) == '\n');
        switch (c) {
            case 'v': vypis(m1, m2, m3); break;
            case 's': scitaj(m1, m2, m3); break;
            case 'n': nasob(m1, m2, m3); break;
            case 'm': vymen(m1, m2); break;
        }
    } while (c != 'k');
    return 0;
}
```

### Načítanie matíc zo súboru

```c
void nacitaj(int m1[N][N], int m2[N][N], int m3[N][N], char meno[])
{
    FILE *f;

    if ((f = fopen(meno, "r")) == NULL) {
        printf("Subor %s sa nepodarilo otvorit.\n", meno);
        exit(1);
    }
    if (nacitaj_pom(m1, f) || nacitaj_pom(m2, f) || nacitaj_pom(m3, f)) {
        printf("Nepodarilo sa nacitat matice.\n");
        exit(1);
    }
    if (fclose(f) == EOF)
        printf("Subor sa nepodarilo zatvorit.\n");
}

int nacitaj_pom(int m[N][N], FILE *f)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (fscanf(f, "%d", &m[i][j]) != 1)
                return 1;
    return 0;
}
```

### Výpis matíc

```c
void vypis(int m1[N][N], int m2[N][N], int m3[N][N])
{
    int i, j, k, (*m)[N];

    for (k = 0; k < 3; k++) {
        switch (k) {
            case 0: m = m1; break;
            case 1: m = m2; break;
            case 2: m = m3; break;
        }
        printf("Matica c.%d:\n", k + 1);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++)
                printf("%d ", m[i][j]);
            putchar('\n');
        }
        printf("\n");
    }
}
```

### Sčítanie matíc

```c
void scitaj(int m1[N][N], int m2[N][N], int m3[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m3[i][j] = m1[i][j] + m2[i][j];
    printf("Sucet matic c.1 a 2 je v matici c.3\n");
}
```

### Násobenie matíc

```c
void nasob(int m1[N][N], int m2[N][N], int m3[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m3[i][j] = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                m3[i][j] += m1[i][k] * m2[k][j];
    printf("Sucin matic c.1 a 2 je v matici c.3\n");
}
```

### Výmena matíc

```c
void vymen(int m1[N][N], int m2[N][N])
{
    int i, j, m[N][N];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = m1[i][j];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m1[i][j] = m2[i][j];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m2[i][j] = m[i][j];
    printf("Matice c.1 a 2 su vymenene.\n");
}
```

<details>



---

[← Prednáška 7](../07-ukazovatele-vyhladavanie/) | [Hlavná stránka](../../README.md) | [Prednáška 9 →](../09-struktury-zoznamy/)
