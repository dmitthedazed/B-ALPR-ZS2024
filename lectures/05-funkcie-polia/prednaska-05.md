# Prednáška 5: Funkcie, pamäť a statické jednorozmerné polia

> **Predmet:** Algoritmizácia a programovanie
> **Prednášajúci:** Ján Grman

---

## Obsah

1. [Funkcie a práca s pamäťou](#funkcie-a-práca-s-pamäťou)
   - [Globálne a lokálne premenné](#globálne-a-lokálne-premenné)
   - [Inicializácia premenných](#inicializácia-lokálnych-a-globálnych-premenných)
   - [Alokácia pamäte](#alokácia-pamäte)
     - [Statická alokácia](#statická-alokácia-pamäte)
     - [Dynamická alokácia](#dynamická-alokácia)
     - [Vymedzenie pamäte v zásobníku](#vymedzenie-pamäte-v-zásobníku)
2. [Funkcie](#funkcie)
   - [Definícia funkcie](#definícia-funkcie)
   - [Funkcia bez parametrov](#funkcia-bez-parametrov)
   - [Procedúry a dátový typ void](#procedúry-a-dátový-typ-void)
   - [Parametre funkcií – volanie hodnotou](#parametre-funkcií--volanie-hodnotou)
   - [Parametre funkcií – volanie odkazom](#parametre-funkcií--volanie-odkazom)
   - [Vzájomné volanie funkcií](#vzájomné-volanie-funkcií)
3. [Príklady s funkciami](#príklady-s-funkciami)
   - [Maximum z dvoch čísel](#príklad-maximum-z-dvoch-čísel)
   - [Násobenie a delenie](#príklad-násobenie-a-delenie)
   - [Navzájom sa odkazujúce funkcie](#príklad-navzájom-sa-odkazujúce-funkcie)
   - [Faktoriál – iteratívne](#príklad-faktoriál--iteratívne)
   - [Výpis súboru po stránkach](#príklad-výpis-súboru-po-stránkach)
4. [Jednorozmerné polia](#jednorozmerné-polia)
   - [Základy práce s poliami](#základy-práce-s-poliami)
   - [Príklady definícií statického poľa](#príklady-definícií-statického-poľa)
   - [Prístup k prvkom poľa](#prístup-k-prvkom-poľa)
   - [Inicializácia poľa v definícii](#inicializácia-poľa-v-definícii)
   - [Zistenie veľkosti poľa](#zistenie-veľkosti-poľa)
   - [Pole ako parameter funkcie](#pole-ako-parameter-funkcie)
5. [Príklady s poliami](#príklady-s-poliami)
   - [Výpočet študijného priemeru](#výpočet-študijného-priemeru)
   - [Nájdenie výskytu hodnoty v poli](#nájdenie-výskytu-hodnoty-v-poli)
   - [Nájdenie všetkých výskytov hodnoty](#nájdenie-všetkých-výskytov-hodnoty)
   - [Porovnanie polí znakov](#porovnanie-polí-znakov)
   - [Histogram písmen v reťazci](#histogram-písmen-v-reťazci)
   - [Otočenie veľkého čísla](#otočenie-veľkého-čísla)
   - [Histogram výskytov písmen v súbore](#histogram-výskytov-písmen-v-súbore)
   - [Vloženie prvku do poľa](#vloženie-prvku-do-poľa)
   - [Zmazanie prvku poľa](#zmazanie-prvku-poľa)
   - [Zmazanie duplicít v poli](#zmazanie-duplicít-v-poli)
   - [Súčet veľkých čísel](#súčet-veľkých-čísel)
   - [Počet výskytov podpostupnosti](#počet-výskytov-podpostupnosti)
   - [Určenie monotónnosti postupnosti](#určenie-monotónnosti-postupnosti)
   - [Otočenie obsahu poľa](#otočenie-obsahu-poľa)
   - [Eratostenovo sito](#eratostenovo-sito)
   - [Kontrola sumy s ladením](#kontrola-sumy-s-ladením)

---

## Funkcie a práca s pamäťou


### Globálne a lokálne premenné

Stanovenie, kde bude premenná dostupná:

- **Globálne premenné**
  - Platnosť: od miesta definície po koniec súboru (nie programu — program sa môže skladať z viac súborov)
- **Lokálne premenné**
  - Definované vo funkciách
  - Platnosť: od definície po koniec funkcie

#### Príklad: globálne definície

```c
#include <stdio.h>

int i;              // premenná i je platná pre všetky 3 funkcie

void prva()
{ ... }

int j;              // premenná j je platná len pre funkcie: druha() a main()

int druha()
{ ... }

void main()
{ ... }
```

#### Príklad: lokálne premenné

```c
#include <stdio.h>

int i1, i2;

void prva()
{
    int i1, j1;
    // globálna premenná i1 je prekrytá lokálnou premennou i1
    // používať sa môžu premenné: i1, j1 (lokálne) a i2 (globálna)
    ...
}

int j1, j2;

int druha()
{
    int i1, j1, k1;
    // dve globálne premenné: i2, j2
    // tri lokálne premenné: i1, j1, k1
    ...
}
```

### Inicializácia lokálnych a globálnych premenných

| Typ premennej | Automatická inicializácia | Poznámka |
|---|---|---|
| **Lokálne** | Nie sú automaticky inicializované | Obsahujú náhodné hodnoty |
| **Globálne** | Automaticky inicializované na `0` (`0.0`, `\0`) | Lepšie sa na to nespoliehať |

> **Upozornenie:** Vyhnúť sa globálnym premenným — môžu vniesť zmätok do väčších programov!

---

### Alokácia pamäte


Každá premenná musí mať v čase svojej existencie pridelený pamäťový priestor. Akcia na vyhradenie pamäťového priestoru sa nazýva **alokácia**, ktorá môže byť:

- **Statická**
- **Dynamická**

#### Statická alokácia pamäte

- Keď vieme prekladaču vopred povedať, aké máme na premenné pamäťové nároky (napr. vieme, že budeme potrebovať dve premenné typu `double` a jednu premennú typu `char`)
- Prekladač sám určí požiadavky pre všetky definované premenné a pri spustení programu sa pre ne alokuje miesto
- Behom programu sa nemanipuluje s touto pamäťou
- Premenné majú alokované miesto od začiatku programu do jeho konca
- Ruší ich operačný systém
- Vymedzuje miesto v **dátovej oblasti**
- Globálne premenné sú statické

> **Poznámka:** Nie vždy statická alokácia stačí — napr. pri rekurzii alebo keď potrebujeme načítať obsah súboru do pamäte. Vtedy treba použiť dynamickú alokáciu alebo vymedzenie pamäte v zásobníku.

#### Dynamická alokácia

- Vymedzenie pamäte v **hromade** (heap)
- Za behu programu dynamicky prideliť (alokovať) oblasť pamäte určitej veľkosti
- Pristupuje sa do nej prostredníctvom **ukazovateľov**

#### Vymedzenie pamäte v zásobníku

- Zaisťuje kompilátor pri volaní funkcie
- Väčšina lokálnych premenných definovaných vo funkciách
- Existencia týchto premenných začína pri vstupe do funkcie a končí pri výstupe z funkcie
- Ak chceme prenášať hodnotu premennej medzi jednotlivými volaniami funkcie — nemôže byť premenná alokovaná v zásobníku

---

## Funkcie


- Jazyk C je založený na funkciách
  - Kratšie programy majú jednu funkciu `main()`
  - Väčšina má viac funkcií
- Spracovanie programu
  - Začína volaním funkcie `main()`
  - Končí opustením funkcie `main()`
- Funkcie **nemôžu byť vhniezdené**
- Nie procedúry — všetky funkcie vracajú hodnotu
  - Dajú sa použiť aj ako procedúry (vrátia `void`)

### Definícia funkcie

- **Definícia:** určuje hlavičku aj telo funkcie
- **Deklarácia:** len špecifikuje hlavičku funkcie (meno, typ návratovej hodnoty, parametre)

```c
// Hlavička funkcie:
int max(int a, int b);

// Definícia:
int max(int a, int b)
{
    return (a > b ? a : b);
}

// Volanie funkcie:
x = max(10 * i, j - 15);
```

> **Poznámka:** `return h;` — funkcia vráti hodnotu `h`.

### Funkcia bez parametrov

```c
// Definícia funkcie:
int scitaj()
{
    int a, b;
    scanf("%d %d", &a, &b);
    return (a + b);
}

// Volanie funkcie:
j = scitaj();
```

### Procedúry a dátový typ void

Formálne procedúry v C neexistujú, dá sa to obísť dvoma spôsobmi:

**1. Funkcia návratovú hodnotu vracia, ale nepotrebujeme ju:**

```c
getchar();           // čakanie na stlačenie klávesy

(void) getchar();    // čitateľnejšie, niektoré prekladače to vyžadujú
```

**2. Funkcia sa definuje ako funkcia vracajúca typ `void`:**

```c
void vypis_int(int i)
{
    printf("%d", i);
}

// Volanie:
vypis_int(a + b);
```

### Parametre funkcií – volanie hodnotou


- **Predávanie parametrov hodnotou** — parametre sú vo funkcii len čítané
- Každá zmena parametra je dočasná, je len v rámci funkcie a po jej ukončení sa stratí

**Ako funguje:**

1. Vytvorí sa lokálna kópia premennej v zásobníku a vo funkcii sa pracuje len s ňou
2. Na konci funkcie sa lokálna kópia stráca

**Príklad:** Volanie funkcie `int A(...)` s parametrom `3`, ktorý sa vo funkcii zmení na `4`:

| Krok | Dátová oblasť | Zásobník |
|---|---|---|
| Spustenie `main()` | — | `3` |
| Volanie `A(3)` | vytvorí sa kópia | `3` (pôvodná) + kópia |
| V tele `A()` | zmena kópie na `4` | `4` (kópia), `3` (pôvodná) |
| Návrat do `main()` | kópia zrušená | `3` (nezmenená) |

### Parametre funkcií – volanie odkazom


- Predávanie parametrov odkazom **neexistuje** v C
- Volanie odkazom by umožnilo meniť parametre v rámci funkcie
- Rieši sa pomocou **ukazovateľov**
- Ukazovateľ určuje, na ktorom mieste v dátovej pamäti sa má premenná zmeniť (nemení sa ukazovateľ — adresa)

**Príklad:** Funkcia vypočíta obvod a obsah kruhu — volanie odkazom:

```c
#include <stdio.h>

#define PI 3.14
#define na_druhu(i) ((i) * (i))

void kruh(int r, float *o, float *s)
{
    *o = 2 * PI * r;
    *s = PI * na_druhu(r);
}

int main()
{
    int polomer;
    float obvod, obsah;

    printf("Zadaj polomer kruhu: ");
    scanf("%d", &polomer);

    kruh(polomer, &obvod, &obsah);
    printf("obvod: %.2f, obsah: %.2f\n", obvod, obsah);
    return 0;
}
```

#### Príklad funkcie: výmena premenných

```c
void vymen(int *p_x, int *p_y)
{
    int pom;

    pom = *p_x;
    *p_x = *p_y;
    *p_y = pom;
}

// Správne volanie:
vymen(&i, &j);
```

> **Pozor na chyby:**
> - `vymen(i, j);` — **chyba:** vymieňa obsah adries daných obsahom `i`, `j` (vymieňa hodnoty na adresách 5 a 7)
> - `vymen(*i, *j);` — **chyba:** z adries 5 a 7 sa zoberú hodnoty a tie sa použijú ako adresy

### Vzájomné volanie funkcií


Funkcie sa môžu navzájom volať — v takom prípade je potrebná **dopredná deklarácia** (prototyp) funkcie, ktorá je definovaná neskôr.

---

## Príklady s funkciami

### Príklad: maximum z dvoch čísel

```c
#include <stdio.h>

int max(int a, int b) {
    return (a > b ? a : b);
}

int main() {
    int x, y;
    printf("Zadajte 2 cisla: ");
    scanf("%d %d", &x, &y);
    printf("Maximum: %d\n", max(x, y));
    return 0;
}
```

#### Volanie funkcie viackrát

```c
#include <stdio.h>
#define N 5

int max(int a, int b) {
    return (a > b ? a : b);
}

int main() {
    int i, x, y;
    for (i = 1; i <= N; i++) {
        printf("[%d] zadajte 2 cisla: ", i);
        scanf("%d %d", &x, &y);
        printf("Maximum: %d\n", max(x, y));
    }
    return 0;
}
```

### Príklad: násobenie a delenie

Program načíta celé číslo, potom umožní používateľovi v cykle číslo násobiť dvoma, deliť troma, vypísať číslo — pokým používateľ program neukončí.

```c
#include <stdio.h>

int nasob_2(int x);
int del_3(int x);

int main() {
    int i, c;
    printf("Zadajte cele cislo: ");
    scanf("%d", &i);

    do {
        printf("\ncislo ma hodnotu: %d\n\n", i);
        printf("stlacte N na vynasobie cisla dvoma.\n");
        printf("stlacte D na vydelenie cisla troma.\n");
        printf("stlacte K na ukoncenie programu.\n");
        c = getch();

        if (c == 'n' || c == 'N')
            i = nasob_2(i);
        else if (c == 'd' || c == 'D')
            i = del_3(i);
    } while (c != 'k' && c != 'K');

    return 0;
}

int nasob_2(int x) {
    return x * 2;
}

int del_3(int x) {
    return x / 3;
}
```

### Príklad: navzájom sa odkazujúce funkcie

Program vypočíta hodnotu funkcií `p(x)` a `q(x)` pre dané `x`:

$$
p(x) = \begin{cases} 2 & \text{ak } x \leq 1 \\ p(x-1) + q(x/2) & \text{ak } x > 1 \end{cases}
$$

$$
q(x) = \begin{cases} x/3 & \text{ak } x \leq 3 \\ q(x-3) \cdot p(x-5) & \text{ak } x > 3 \end{cases}
$$

```c
#include <stdio.h>

float q(float x);  // dopredná deklarácia

float p(float x) {
    if (x <= 1)
        return 2.0;
    return (p(x - 1) + q(x / 2));
}

float q(float x) {
    if (x <= 3)
        return x / (float) 3.0;
    return (q(x - 3) * p(x - 5));
}

int main() {
    float x;
    do {
        printf("Zadajte realne cislo (konec pri zadani -1.0)\n");
        scanf("%f", &x);
        if (x == -1.0) break;
        printf("\np(%.3f) = %.3f\n", x, p(x));
        printf("q(%.3f) = %.3f\n\n", x, q(x));
    } while (1);
}
```

### Príklad: faktoriál – iteratívne

```c
#include <stdio.h>

long faktorial(long n)
{
    if (n <= 0)
        return 1;
    else {
        int i;
        long f = 1;
        for (i = 1; i <= n; i++)
            f *= i;
        return f;
    }
}

void main()
{
    int n;
    printf("Zadajte cele cislo: ");
    scanf("%d", &n);
    printf("%d! = %ld\n", n, faktorial(n));
}
```

### Príklad: výpis súboru po stránkach

Program opisuje text zo súboru `subor.txt` na obrazovku s tým, že po vypísaní jednej stránky čaká na stlačenie klávesy `<Enter>`.

```c
#include <stdio.h>

#define RIADKY_OBR 20
#define MENO "subor.txt"

void vypis(FILE *fr);  // úplný funkčný prototyp

int main(void) {
    FILE *fr;

    if ((fr = fopen(MENO, "r")) == NULL) {
        printf("Subor %s nebol otevoreny.\n", MENO);
        return 1;
    }

    vypis(fr);

    if (fclose(fr) == EOF)
        printf("Subor %s nebol zatvoreny.\n", MENO);
    return 0;
}

void vypis(FILE *fr) {
    int c, pocet = 0;

    while ((c = getc(fr)) != EOF) {
        putchar(c);
        if (c == '\n') {
            if (++pocet >= RIADKY_OBR) {
                pocet = 0;
                while (getchar() != '\n')  // čaká na odriadkovanie
                    ;
            }
        }
    }
}
```

---

## Jednorozmerné polia


### Základy práce s poliami


Pole je štruktúra zložená z niekoľkých prvkov rovnakého typu (blok prvkov).

```c
TYP x[N];    // statická definícia poľa
```

- Pole obsahuje `N` prvkov
- Dolná hranica indexu je vždy **0** ⇒ horná hranica je **N-1**
- Číslo `N` musí byť známe v **čase prekladu**
- Hodnoty **nie sú inicializované** na 0

**Príklad** s `N = 3`, typ `int`:

| Index | Hodnota |
|-------|---------|
| 0     | 5       |
| 1     | 6       |
| 2     | 7       |

### Príklady definícií statického poľa

```c
#define N 10

int x[N], y[N + 1], z[N * 2];
```

| Pole | Počet prvkov | Indexy |
|------|-------------|--------|
| `x`  | 10          | 0 – 9  |
| `y`  | 11          | 0 – 10 |
| `z`  | 20          | 0 – 19 |

### Prístup k prvkom poľa

```c
#define N 10

int x[N], i;

// priradenie hodnoty do prvého prvku poľa
x[0] = 1;

// v cykle priradenie hodnoty postupne všetkým prvkom poľa
for (i = 0; i < N; i++)
    x[i] = i + 1;

// výpis prvkov poľa
for (i = 0; i < N; i++)
    printf("x[%d]: %d\n", i, x[i]);
```

### Inicializácia poľa v definícii

```c
int x[3] = { 1, 2, 3 };     // počet prvkov poľa je daný počtom hodnôt
int y[] = { 1, 2, 3 };      // rovnaké — veľkosť sa odvodí automaticky
int z[5] = { 1, 2, 3 };     // hodnoty z[3] a z[4] sú inicializované na 0
```

> **Pozor:** Nasledujúce **nie je povolené**, keďže `n` je premenná a nie konštanta (hodnota nemusí byť známa v čase prekladu):
> ```c
> int n = 5;
> int z[n];   // chyba!
> ```

### Zistenie veľkosti poľa

`x` je statický ukazovateľ — `sizeof(x)` vráti veľkosť celého poľa v bajtoch:

```c
int x[10];
// sizeof(x) == 10 * sizeof(int)    (napr. 40)

int i;
int pole[] = { 3, 6, 9, 12, 15 };

for (i = 0; i < (sizeof(pole) / sizeof(int)); i++) {
    printf("%d ", pole[i]);
}
// sizeof(pole) / sizeof(int) = počet prvkov poľa
```

### Pole ako parameter funkcie


Identifikátor nasledovaný zátvorkami: `int pole[]`

```c
int maximum(int pole[], int n)
{
    int i, max = pole[0];
    for (i = 1; i < n; i++) {
        if (pole[i] > max)
            max = pole[i];
    }
    return max;
}
```

> **Dôležité:** Vo funkcii sa **nedá zistiť veľkosť poľa** — preto ju treba uviesť ako parameter. Aj keď napíšete `int pole[10]`, parameter bude stále považovaný za `pole[]`.

Volanie funkcie s poľom ako parametrom:

```c
max = maximum(pole, 10);
```

> **Poznámka:** Parameter poľa sa dá vo funkcii meniť, pretože sa predáva adresa (nie kópia) — nezáleží na tom, či ide o statické alebo dynamické pole.

---

## Príklady s poliami

### Výpočet študijného priemeru

```c
#include <stdio.h>
#define MAX 10

int main() {
    int i;
    float znamky[MAX];
    float priemer = 0;

    for (i = 0; i < MAX; i++) {
        printf("Aka je znamka z %d-teho predmetu? ", i + 1);
        scanf("%f", &znamky[i]);
        priemer += znamky[i];
    }
    priemer /= MAX;
    printf("Priemer znamok je %.2f.", priemer);

    return 0;
}
```

### Nájdenie výskytu hodnoty v poli

```c
#include <stdio.h>

int main() {
    int x[] = {12, 67, 56, 60, 88, 34, 123};
    int hodnota, velkost, i, najdene = -1;

    scanf("%d", &hodnota);
    velkost = sizeof(x) / sizeof(int);

    i = 0;
    while (najdene < 0 && i < velkost) {
        if (x[i] == hodnota)
            najdene = i;
        else
            i++;
    }

    if (najdene != -1)
        printf("%d je na pozicii %d.\n", hodnota, i);
    else
        printf("%d sa v poli nenachadza.\n", hodnota);
    return 0;
}
```

### Nájdenie všetkých výskytov hodnoty

```c
#include <stdio.h>

int main() {
    int x[] = {12, 67, 56, 60, 88, 34, 123};
    int hodnota, velkost, i, najdene = -1;

    scanf("%d", &hodnota);
    velkost = sizeof(x) / sizeof(int);

    for (i = 0; i < velkost; i++)
        if (x[i] == hodnota)
            if (najdene == -1) {
                printf("%d je na pozicii %d", hodnota, i);
                najdene = 1;
            } else
                printf(", %d", i);

    if (najdene == -1)
        printf("%d sa v poli nenachadza.\n", hodnota);
    else
        printf("\n");
    return 0;
}
```

### Porovnanie polí znakov

Funkcia zistí, či dva reťazce (polia znakov) sú rovnaké. Pri porovnaní sa ignoruje veľkosť písmen.

```c
int rovnake_retazce(char s1[], int n1, char s2[], int n2) {
    int i = 0;

    if (n1 != n2)
        return 0;

    while (i < n1) {
        if (toupper(s1[i]) != toupper(s2[i]))
            break;
        i++;
    }

    if (i == n1) return 1;
    else return 0;
}
```

### Histogram písmen v reťazci

```c
#include <stdio.h>
#include <stdlib.h>
#define N ('Z' - 'A' + 1)

int main() {
    int i;
    char hist[N], slovo[100];

    scanf("%s", slovo);              // načítanie slova

    for (i = 0; i < N; i++)          // inicializácia histogramu
        hist[i] = 0;

    i = 0;
    while (i < 100 && slovo[i] != '\0') {   // naplnenie histogramu
        hist[toupper(slovo[i]) - 'A']++;
        i++;
    }

    for (i = 0; i < N; i++)          // výpis histogramu
        if (hist[i] != 0)
            printf("%c: %d\n", i + 'A', hist[i]);

    return 0;
}
```

### Otočenie veľkého čísla

Napíšte program, ktorý otočí číslo (napr. číslo 123 po otočení je 321), pričom uvažujte veľmi dlhé čísla, ktoré sa nezmestia ani do `long int` (max. 1000 číslic).

```c
#include <stdio.h>
#define MAX 1000

int main() {
    char num[MAX];
    int i = 0, j, flag = 0;

    printf("Nacitajte kladne cislo: ");
    scanf("%s", num);

    while (num[i] != '\0') {
        if (num[i] < '0' || num[i] > '9') {
            printf("Nespravne cislo.");
            return 0;
        }
        i++;
    }

    printf("Obratene cislo: ");
    for (j = i - 1; j >= 0; j--)
        if (flag == 0 && num[j] == '0')
            ;   // preskočenie úvodných núl
        else {
            printf("%c", num[j]);
            flag = 1;
        }
    return 0;
}
```

### Histogram výskytov písmen v súbore

Program vytvorí histogram výskytov písmen v súbore (pre každé písmeno — počet jeho výskytov).

```c
#include <stdio.h>
#include <stdlib.h>

#define SUBOR "pismena.txt"
#define N ('Z' - 'A' + 1)    // počet písmen abecedy

int main()
{
    int c, i, hist[N];
    FILE *fr;

    if ((fr = fopen(SUBOR, "r")) == NULL) {
        printf("Subor sa nepodarilo otvorit.\n");
        return 1;
    }

    for (i = 0; i < N; i++)
        hist[i] = 0;

    while ((c = toupper(getc(fr))) != EOF) {
        if (c >= 'A' && c <= 'Z')
            hist[c - 'A']++;
    }

    for (i = 0; i < N; i++)
        if (hist[i] != 0)
            printf("%c: %2d\n", 'A' + i, hist[i]);

    if (fclose(fr) == EOF) {
        printf("Subor sa nepodarilo zatvorit.\n");
        return 1;
    }

    return 0;
}
```

### Vloženie prvku do poľa

Program načíta do poľa celé čísla a vloží zadané číslo na zadanú pozíciu.

```c
#include <stdio.h>

int main() {
    int a[50], velkost, cislo, i, poz;

    printf("Zadajte velkost pola: ");
    scanf("%d", &velkost);

    printf("Zadajte %d prvkov pola:\n", velkost);
    for (i = 0; i < velkost; i++)
        scanf("%d", &a[i]);

    printf("Zadajte poziciu a cislo na vlozenie: ");
    scanf("%d %d", &poz, &cislo);

    // posun prvkov doprava od konca
    i = velkost++;
    while (i > poz) {
        a[i] = a[i - 1];
        i--;
    }
    a[i] = cislo;

    printf("Pole po vlozeni prvku:\n");
    for (i = 0; i < velkost; i++)
        printf(" %d", a[i]);
    return 0;
}
```

### Zmazanie prvku poľa

Program načíta do poľa celé čísla a vymaže číslo zo zadanej pozície.

```c
#include <stdio.h>

int main() {
    int a[50], i, poz, velkost;

    printf("Zadajte pocet prvkov pola (<=50): ");
    scanf("%d", &velkost);

    printf("Zadajte %d prvkov pola:\n", velkost);
    for (i = 0; i < velkost; i++)
        scanf("%d", &a[i]);

    printf("Zadajte poziciu na vymazanie prvku: ");
    scanf("%d", &poz);

    // posun prvkov doľava
    i = poz;
    while (i < velkost - 1) {
        a[i] = a[i + 1];
        i++;
    }
    velkost--;

    printf("Pole po vymazani prvku:\n");
    for (i = 0; i < velkost; i++)
        printf("%d ", a[i]);
    return 0;
}
```

### Zmazanie duplicít v poli

Program načíta do poľa celé čísla a vymaže čísla tak, aby sa žiadne v poli neopakovalo.

```c
#include <stdio.h>

int main() {
    int a[50], i, j, k, velkost;

    printf("Zadajte pocet prvkov pola: ");
    scanf("%d", &velkost);

    printf("Zadajte %d prvkov pola:\n", velkost);
    for (i = 0; i < velkost; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < velkost; i++) {
        j = i + 1;
        while (j < velkost) {
            if (a[i] == a[j]) {
                k = j;
                velkost--;
                while (k < velkost) {
                    a[k] = a[k + 1];
                    k++;
                }
            } else
                j++;
        }
    }

    printf("Pole po zmazani duplicit:\n");
    for (i = 0; i < velkost; i++)
        printf("%d ", a[i]);
    return 0;
}
```

### Súčet veľkých čísel

Program vypočíta súčet veľkých čísel zapísaných v poli — uvažujte veľmi dlhé čísla, ktoré sa nezmestia ani do `long int` (max. 1000 číslic).

```c
#include <stdio.h>
#define MAX 50

int sucet(int cislo1[], int cislo2[], int vysledok[], int m, int n);

int main() {
    int i, n, m, p, cislo1[MAX], cislo2[MAX], vysledok[MAX];
    char c;

    printf("Zadajte prve cislo: ");
    m = 0;
    while ((c = getchar()) != '\n')
        cislo1[m++] = c - '0';

    printf("Zadajte druhe cislo: ");
    n = 0;
    while ((c = getchar()) != '\n')
        cislo2[n++] = c - '0';

    p = sucet(cislo1, cislo2, vysledok, m, n);

    printf("Sucet je: ");
    for (i = 0; i < p; i++)
        printf("%d", vysledok[i]);
    printf("\n");
    return 0;
}

int sucet(int cislo1[], int cislo2[], int vysledok[], int m, int n) {
    int i, j, k, prenos, c1, c2, pom[MAX];

    i = m - 1;
    j = n - 1;
    k = 0;
    prenos = 0;

    while (i >= 0 || j >= 0) {
        if (i >= 0) c1 = cislo1[i];
        else c1 = 0;
        if (j >= 0) c2 = cislo2[j];
        else c2 = 0;

        pom[k++] = (c1 + c2 + prenos) % 10;
        prenos = (c1 + c2 + prenos) / 10;
        i--;
        j--;
    }

    if (prenos != 0)
        pom[k++] = prenos;

    for (i = 0; i < k; i++)
        vysledok[k - i - 1] = pom[i];

    return k;
}
```

### Počet výskytov podpostupnosti

Zistiť počet výskytov podpostupnosti v postupnosti.

```c
#include <stdio.h>
#define MAX 50

int pocet_vyskytov(int post[], int n, int podpost[], int m);

int main() {
    int i, n, m, post[MAX], podpost[MAX];

    printf("Zadajte pocet cisel postupnosti: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &post[i]);

    printf("Zadajte pocet cisel hladanej podpostupnosti: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &podpost[i]);

    printf("Pocet vyskytov podpostupnosti v postupnosti: %d\n",
        pocet_vyskytov(post, n, podpost, m));
    return 0;
}

int pocet_vyskytov(int post[], int n, int podpost[], int m) {
    int i = 0, j, vyskyt = 0;

    while (i + m <= n) {
        for (j = i; j < i + m; j++)
            if (post[j] != podpost[j - i]) break;
        if (j == i + m)
            vyskyt++;
        i++;
    }
    return vyskyt;
}
```

### Určenie monotónnosti postupnosti

Program zistí, či načítaná postupnosť je rastúca, klesajúca, konštantná alebo aj rastúca aj klesajúca.

**Verzia s poľom:**

```c
#include <stdio.h>
#define N 5

int main() {
    int i, pole[N];
    int rast = 1, kles = 1, konst = 1;

    printf("Zadajte %d prvkov pola:\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &pole[i]);

    for (i = 1; i < N; i++) {
        if (pole[i] != pole[i - 1]) konst = 0;
        if (pole[i] <= pole[i - 1]) rast = 0;
        if (pole[i] >= pole[i - 1]) kles = 0;
    }

    printf("Funkcia je ");
    if (konst) printf("konstantna.\n");
    if (rast)  printf("rastuca.\n");
    if (kles)  printf("klesajuca.\n");
    if (!konst && !rast && !kles)
        printf("aj rastuca aj klesajuca.\n");
    return 0;
}
```

**Verzia bez poľa:**

```c
#include <stdio.h>
#define N 5

int main() {
    int i, akt, pred;
    int rast = 1, kles = 1, konst = 1;

    printf("Zadajte %d prvkov pola:\n", N);
    scanf("%d", &pred);

    for (i = 1; i < N; i++) {
        scanf("%d", &akt);
        if (akt != pred) konst = 0;
        if (akt <= pred) rast = 0;
        if (akt >= pred) kles = 0;
        pred = akt;
    }

    printf("Funkcia je ");
    if (konst) printf("konstantna.\n");
    if (rast)  printf("rastuca.\n");
    if (kles)  printf("klesajuca.\n");
    if (!konst && !rast && !kles)
        printf("aj rastuca aj klesajuca.\n");
    return 0;
}
```

### Otočenie obsahu poľa

Funkcia otočí reťazec (pole znakov).

```c
void reverse(char data[], int size) {
    int i, pom;

    for (i = 0; i < size / 2; i++) {
        pom = data[i];
        data[i] = data[size - i - 1];
        data[size - i - 1] = pom;
    }
    printf("%s\n", data);
}
```

### Eratostenovo sito


Algoritmus na nájdenie prvočísel v poli — vyškrtáva všetky násobky prvočísel, počnúc 2 (vyškrtnutie = prepísanie čísla na 0).

**Princíp:**

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
|---|---|---|---|---|---|---|---|---|---|----|----|----|----|-----|
| 2 | 3 | ~~4~~ | 5 | ~~6~~ | 7 | ~~8~~ | ~~9~~ | ~~10~~ | 11 | ~~12~~ | 13 | ~~14~~ | ~~15~~ | ~~16~~ |

V cykle pre každý prvok poľa: vyškrtneme všetky jeho násobky.

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

void main()
{
    int n, i, k, odm;
    int prv[MAX];

    printf("Do ktoreho cisla hladat prvocisla? (< %d) ", MAX);
    scanf("%d", &n);

    n--;    // znížime n o 1, nevyškrtávame násobky jednotky

    for (i = 0; i < n; i++)      // inicializácia
        prv[i] = i + 2;

    odm = (int) sqrt(n) - 1;

    for (i = 0; i < odm; i++) {
        if (prv[i] != 0) {                  // ak sme predtým číslo nevyškrtli
            for (k = i + 1; k < n; k++) {    // vyškrtni všetky násobky
                if (prv[k] != 0) {           // ak ešte nie je vyškrtnuté
                    if (prv[k] % prv[i] == 0)    // ak je deliteľné
                        prv[k] = 0;
                }
            }
        }
    }

    printf("Prvocisla: ");
    for (i = 0; i < n; i++)
        if (prv[i] != 0)
            printf("%d, ", prv[i]);

    putchar('\n');
}
```

### Kontrola sumy s ladením

Program zistí, či prvé číslo v súbore `suma.txt` je súčtom čísel, ktoré sú za ním. Použitie základného a podrobného ladenia (príklad z cvičení).

```c
#include <stdio.h>
#include <stdlib.h>

#define LADENIE_ZAKLADNE
#define LADENIE_PODROBNE

int main() {
    FILE *fr;
    float cena, suma, sucet = 0.0;

    #if defined(LADENIE_ZAKLADNE) || defined(LADENIE_PODROBNE)
        printf("Otvorenie suboru\n");
    #endif

    if ((fr = fopen("suma.txt", "r")) == NULL) {
        printf("Nepodarilo sa otvorit subor.\n");
        exit(1);
    }

    #ifdef LADENIE_PODROBNE
        printf("Subor otvoreny\n");
    #endif

    #if defined(LADENIE_ZAKLADNE) || defined(LADENIE_PODROBNE)
        printf("Kontrola sumy\n");
    #endif

    fscanf(fr, "%f", &sucet);

    while (fscanf(fr, "%f", &cena) != EOF) {
        suma += cena;
        #ifdef LADENIE_PODROBNE
            printf("Suma: %.2f\n", suma);
        #endif
    }

    if (suma == sucet)
        printf("Suma je spravna\n");
    else
        printf("Suma je nespravna\n");

    #ifdef LADENIE_PODROBNE
        printf("Suma skontrolovana\n");
    #endif

    #if defined(LADENIE_ZAKLADNE) || defined(LADENIE_PODROBNE)
        printf("Zatvaranie suboru\n");
    #endif

    if (fclose(fr) == EOF) {
        printf("Nepodarilo sa zatvorit subor.\n");
        exit(1);
    }

    #ifdef LADENIE_PODROBNE
        printf("Subor zatvoreny\n");
    #endif

    return 0;
}
```

> **Tip:** Po odladení programu stačí zakomentovať alebo odstrániť riadky `#define LADENIE_ZAKLADNE` a `#define LADENIE_PODROBNE` a všetky ladiace výpisy sa automaticky vypnú.

---

[← Prednáška 4](../04-subory/) | [Hlavná stránka](../../README.md) | [Prednáška 6 →](../06-retazce-ukazovatele/)
