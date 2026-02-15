# Prednáška 12: Záverečné opakovanie

> **Predmet:** Algoritmizácia a programovanie
> **Prednášajúci:** Ján Grman
> **Semester:** Zimný semester 2024

---

## Obsah

1. [Preprocesor a konštanty](#preprocesor-a-konštanty)
2. [Vstup a výstup](#vstup-a-výstup)
   - [`getchar` a `scanf`](#getchar-a-scanf)
   - [`scanf` a operátor `&`](#scanf-a-operátor-)
3. [Dôležité zátvorky](#dôležité-zátvorky)
4. [Skrátené vyhodnocovanie logických výrazov](#skrátené-vyhodnocovanie-logických-výrazov)
   - [Priority operátorov](#priority-operátorov)
5. [Riadiace príkazy cyklov](#riadiace-príkazy-cyklov)
   - [Príkaz `while`](#príkaz-while)
   - [Príkaz `do-while`](#príkaz-do-while)
   - [Príkaz `for`](#príkaz-for)
   - [Cvičenie: prepísanie `break` a `continue`](#cvičenie-prepísanie-break-a-continue)
6. [ASCII tabuľka](#ascii-tabuľka)
7. [Polia a algoritmy](#polia-a-algoritmy)
   - [Nájdenie maxima / najčastejšieho prvku](#nájdenie-maxima--najčastejšieho-prvku)
   - [Vrátenie hodnoty cez parameter funkcie](#vrátenie-hodnoty-cez-parameter-funkcie)
8. [Typová konverzia](#typová-konverzia)
9. [Práca so súbormi](#práca-so-súbormi)
   - [Testovanie otvorenia súboru](#testovanie-otvorenia-súboru)
   - [Testovanie zatvorenia súboru](#testovanie-zatvorenia-súboru)
   - [Testovanie konca súboru: `EOF`](#testovanie-konca-súboru-eof)
   - [Kontrola `EOF` vo vnorených cykloch](#kontrola-eof-vo-vnorených-cykloch)
   - [Základné funkcie pre prácu so súborom](#základné-funkcie-pre-prácu-so-súborom)
   - [Cvičenie: kontrola správneho zátvorkovania](#cvičenie-kontrola-správneho-zátvorkovania)
10. [Polia a reťazce](#polia-a-reťazce)
    - [Základy práce s poliami](#základy-práce-s-poliami)
    - [Definícia a inicializácia reťazca](#definícia-a-inicializácia-reťazca)
    - [Štandardné funkcie pre reťazce](#štandardné-funkcie-pre-reťazce)
11. [Štruktúry](#štruktúry)
    - [Definícia štruktúry (`typedef`)](#definícia-štruktúry-typedef)
    - [Prístup k položkám](#prístup-k-položkám)
    - [Pole v štruktúre](#pole-v-štruktúre)
    - [Štruktúra v inej štruktúre](#štruktúra-v-inej-štruktúre)
    - [Globálne a lokálne premenné](#globálne-a-lokálne-premenné)
12. [Jednoduché dátové typy a `sizeof`](#jednoduché-dátové-typy-a-sizeof)
13. [Parametre funkcií](#parametre-funkcií)
    - [Volanie hodnotou](#volanie-hodnotou)
    - [Volanie odkazom](#volanie-odkazom)
    - [Operátor `&` vs `&&`](#operátor--vs-)
14. [Ukazovatele](#ukazovatele)
    - [Základy ukazovateľov](#základy-ukazovateľov)
    - [Ukazovateľ na ukazovateľ](#ukazovateľ-na-ukazovateľ)
    - [Ukazovatele a polia](#ukazovatele-a-polia)
    - [Zápis s jednorozmerným a dvojrozmerným poľom](#zápis-s-jednorozmerným-a-dvojrozmerným-poľom)
15. [Spájané zoznamy](#spájané-zoznamy)
    - [Základná štruktúra](#základná-štruktúra)
    - [Posun vs. zmena zoznamu](#posun-vs-zmena-zoznamu)
    - [Vloženie prvku na inú pozíciu](#vloženie-prvku-na-inú-pozíciu)
    - [Prístup k položkám prvku](#prístup-k-položkám-prvku)
    - [Kontrola hodnoty ďalšieho prvku](#kontrola-hodnoty-ďalšieho-prvku)
    - [Pamätanie začiatku zoznamu](#pamätanie-začiatku-zoznamu)
    - [Zmena zoznamu vo funkcii](#zmena-zoznamu-vo-funkcii)
16. [Binárne operácie](#binárne-operácie)

---

## Preprocesor a konštanty

Opakovanie pravidiel definovania konštánt:

```c
#define MAX 1000
#define PI 3.14
#define DVE_PI (2 * PI)
#define MOD %
#define AND &&
#define MENO_SUBORU "list.txt"
#define DLHA_KONSTANTA Toto je dlha konstanta, \
            ktora sa nezmesti do jednoho riadku.
```

> **Dôležité:**
> - Za hodnotou **nie je** `;`
> - Medzi menom konštanty a jej hodnotou **nie je** `=`

---

## Vstup a výstup

### `getchar` a `scanf`

```c
int i;
char c;

c = getchar();           // getchar() – na načítavanie ZNAKOV, nie čísel!

c = getchar();           // načítanie znaku pomocou getchar
scanf("%c", &c);         // načítanie znaku pomocou scanf
scanf("%d", &i);         // načítanie celého čísla
```

> **Upozornenie:** `getchar()` slúži na načítavanie **znakov**, nie čísel!

---

### `scanf` a operátor `&`

```c
int i;
char c, str[10];

scanf("%d", &i);         // &i – adresa premennej i
scanf("%c", &c);         // &c – adresa premennej c
scanf("%s", str);        // str – statická adresa poľa (bez &!)
```

Prečo `scanf` očakáva adresy:
- Vo funkcii `scanf` sa vytvorí **lokálna kópia** parametra — adresa
- Na túto adresu sa zapíše načítaná hodnota
- Po skončení funkcie sa zabudne lokálna kópia adresy, no na tej adrese **zostane načítaná hodnota**

| Výraz | Význam |
|---|---|
| `i` | premenná (hodnota) |
| `&i` | adresa premennej |
| `c` | premenná (hodnota) |
| `&c` | adresa premennej |
| `str` | statická adresa poľa (reťazca znakov) |

---

## Dôležité zátvorky

Zátvorky sú dôležité **všade**, ale najmä:

**Pri definovaní makra:**

```c
#define obvod_obdlznika(a, b) (2 * (a) + 2 * (b))
```

**Ak potrebujeme iné poradie vyhodnocovania:**

```c
if ((i < 0 || i >= N) && (j < 0 || j >= N))
    // ...

while ((c = getchar()) != '*')
    // ...

if ((f = fopen("a.txt", "r")) != NULL)
    // ...
```

> **Poznámka:** Priradenie (`=`) má nízku prioritu, preto je potrebné ho uzavrieť do zátvoriek v podmienkach.

---

## Skrátené vyhodnocovanie logických výrazov

V jazyku C sa logický súčet a súčin vyhodnocujú v **skrátenom vyhodnocovaní** (short-circuit evaluation). Argumenty sú vyhodnocované zľava, a hneď ako je zrejmý konečný výsledok, vyhodnocovanie sa **skončí**.

**Logický súčin (`&&`):** ak je hodnota i-teho podvýrazu `0`, celý výraz je `0`:

```c
(y != 0) && (x / y < z)
// ak y == 0, hodnota výrazu je FALSE a delenie nulou nenastane
```

**Logický súčet (`||`):** ak je hodnota i-teho podvýrazu `1`, celý výraz je `1`:

```c
(x > 10) || (x % 5)
// ak x > 10, hodnota výrazu je TRUE a x % 5 sa nevyhodnocuje
```

#### Praktické využitie

```c
// Kontrola pred výpočtom:
if (x > 0 && logaritmus(x) > 0.5)
    // ...

// Kontrola ukazovateľa pred prístupom:
if (y != NULL && y->data == 100)
    // ...

// Lacný výpočet pred drahým:
if (lacny_vypocet(z) || drahy_vypocet(z))
    // ...
```

#### Príklad

```c
#include <stdio.h>

int main(void) {
    int i = 22, j = 10;

    if ((i %= j) || ++j == 11)
        printf("Logicky sucet\n");

    printf("i = %d  j = %d\n", i, j);
    return 0;
}
```

> **Vysvetlenie:** `i %= j` → `i = 22 % 10 = 2` (nenulové = TRUE). Vďaka skrátenému vyhodnocovaniu sa `++j` **nevykoná**. Výstup: `i = 2  j = 10`.

---

### Priority operátorov

| Operátor | Smer vyhodnocovania |
|---|---|
| `!  ++  --  -  +  (typ)` (unárne, pretypovanie) | sprava doľava |
| `*  /  %` | zľava doprava |
| `+  -` | zľava doprava |
| `<  <=  >=  >` | zľava doprava |
| `==  !=` | zľava doprava |
| `&&` | zľava doprava |
| `\|\|` | zľava doprava |
| `? :` | sprava doľava |
| `=  +=  -=  *=  ...` | sprava doľava |
| `,` | zľava doprava |

---

## Riadiace príkazy cyklov

### Príkaz `while`

Cyklus iteruje, pokým platí podmienka. Testuje podmienku **pred** prechodom cyklu — cyklus **nemusí prebehnúť ani raz**.

```c
while (podmienka)
    prikaz;
```

#### Príklad

```c
#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != '*') {
        if (c != ' ')
            putchar(c);
    }
    return 0;
}
```

> Program číta znaky z klávesnice, opisuje ich na obrazovku, medzery ignoruje a skončí po prečítaní znaku `*`.

---

### Príkaz `do-while`

Testuje podmienku **po** prechode cyklu — cyklus sa vykoná **aspoň raz**. Program opúšťa cyklus pri **nesplnenej** podmienke.

```c
do {
    prikazy;
} while (podmienka);
```

---

### Príkaz `for`

Používa sa, keď dopredu vieme **počet prechodov** cyklom.

```c
for (vyraz_start; vyraz_stop; vyraz_iter)
    prikaz;
```

#### Príklad

```c
for (i = 1; i <= 100; i++)
    printf("%d: I will not cut corners.\n", i);
```

> Napíše 100× "I will not cut corners" – vždy do nového riadku, každý riadok začne číslom riadku. Keď je nesplnený `vyraz_stop`, cyklus končí.

---

### Cvičenie: prepísanie `break` a `continue`

Prepíšte nasledujúci cyklus tak, aby ste **nepoužili** príkazy `break` a `continue`:

```c
while (i <= k) {
    c = fgetc(f);
    if (c == EOF) break;
    if (c == '*') continue;
    if (c == '\n') i++;
    else poc++;
}
```

---

## ASCII tabuľka

| Rozsah | Hodnoty | Popis |
|---|---|---|
| 0 – 31 | | Riadiace znaky |
| 32 | `' '` | Medzera |
| 33 – 47 | `'!'` – `'/'` | Pomocné znaky |
| 48 – 57 | `'0'` – `'9'` | Číslice |
| 58 – 64 | `':'` – `'@'` | Pomocné znaky |
| 65 – 90 | `'A'` – `'Z'` | Veľké písmená |
| 97 – 122 | `'a'` – `'z'` | Malé písmená |
| 123 – 126 | `'{'` – `'~'` | Pomocné znaky |

Neviditeľné znaky: `7` Bell, `8` BackSpace, `9` Tab, `10` LineFeed, `13` Carriage Return, …

---

## Polia a algoritmy

### Nájdenie maxima / najčastejšieho prvku

Na nájdenie najčastejšie sa vyskytujúceho čísla v poli — **nerobte** histogram výskytu všetkých celých čísel! Použite vnorený cyklus a pamätajte si doteraz najčastejšie číslo a jeho počet výskytov.

```c
for (i = 0; i < N; i++) {
    vyskyt = 1;
    for (j = i + 1; j < N; j++)
        if (pole[i] == pole[j])
            vyskyt++;
    if (vyskyt > max) {
        cislo = pole[i];   /* index = i */
        max = vyskyt;
    }
}
```

> Stačia 1–2 celočíselné premenné na uloženie doteraz najčastejšieho čísla (alebo jeho indexu) a jeho počtu výskytov.

---

### Vrátenie hodnoty cez parameter funkcie

```c
int najvyssia_hodnota(int *pole, int n, int *pocet) {
    int i, hodnota = pole[0];

    for (i = 1; i < n; i++)
        if (pole[i] > hodnota)
            hodnota = pole[i];

    *pocet = 0;
    for (i = 0; i < n; i++)
        if (pole[i] == hodnota)
            (*pocet)++;

    return hodnota;
}

// Použitie:
int a[100], najvyssi, pocet_opakovani;
// ... (inicializácia)
najvyssi = najvyssia_hodnota(a, 100, &pocet_opakovani);
```

---

## Typová konverzia

Reálne delenie dvoch celých čísel — rôzne spôsoby:

```c
#include <stdio.h>

int main(void) {
    int i = 5, j = 2;
    float f;

    f = (float) i / j;             // Správne: 2.5
    printf("Typova konverzia: 1. moznost: %f\n", f);

    f = i / (float) j;             // Správne: 2.5
    printf("Typova konverzia: 2. moznost: %f\n", f);

    f = (float) i / (float) j;     // Správne: 2.5
    printf("Typova konverzia: 3. moznost: %f\n", f);

    f = (float) (i / j);           // CHYBNE: najprv celočíselné delenie → 2.0
    printf("Explicitna typ. konverzia - chybne: %f\n", f);

    f = i / j;                     // CHYBNE: celočíselné delenie → 2.0
    printf("Implicitna typ. konverzia - chybne: %f\n", f);

    return 0;
}
```

---

## Práca so súbormi

### Testovanie otvorenia súboru

Akcie otvorenia a zatvorenia súboru **nemusia byť úspešné** — preto treba testovať úspešnosť.

`fopen()` – ak sa podarí otvoriť súbor, vracia **ukazovateľ na súbor**, inak vracia konštantu `NULL` (definovaná v `stdio.h`, má hodnotu `0`).

```c
if ((fr = fopen("test.txt", "r")) == NULL) {
    printf("Subor sa nepodarilo otvorit.\n");
    return 0;
}
```

---

### Testovanie zatvorenia súboru

`fclose()` – ak sa podarí zatvoriť súbor, vracia hodnotu `0`. Ak sa nepodarí, vracia konštantu `EOF`.

```c
if (fclose(fr) == EOF)
    printf("Subor sa nepodarilo zatvorit.\n");
```

---

### Testovanie konca súboru: `EOF`

- Symbolická konštanta `EOF` je väčšinou definovaná v `stdio.h`
- Väčšinou má hodnotu `-1`
- Premenná `c` **nesmie byť** definovaná ako `char`, pretože `EOF` je reprezentovaná ako `int` s hodnotou `-1` (na `char` by bola konvertovaná ako iný znak)

```c
int c;   // NIE char c!

if ((c = getc(fr)) != EOF)
    // ...
```

---

### Kontrola `EOF` vo vnorených cykloch

```c
while ((c = getc(f)) != EOF) {
    if (isalpha(c)) {
        // CHYBNE:
        // while ((c = getc(f)) != ' ') ;
        
        // SPRÁVNE – aj tu treba kontrolovať EOF:
        while ((c = getc(f)) != EOF && c != ' ')
            ;
    }
}
```

> **Upozornenie:** Ak vo vnorenom cykle nekontrolujete `EOF`, a súbor skončí, budete sa cykliť donekonečna!

---

### Základné funkcie pre prácu so súborom

Funkcie štandardnej knižnice `stdio.h` (premenná `f` je typu `FILE *`):

| Funkcia | Popis |
|---|---|
| `int getc(FILE *f)` | Čítanie znaku zo súboru |
| `int putc(int c, FILE *f)` | Zápis znaku do súboru |
| `int fgetc(FILE *f)` | Čítanie znaku zo súboru (funkcia) |
| `int fputc(int c, FILE *f)` | Zápis znaku do súboru (funkcia) |
| `fscanf(FILE *f, "format", args)` | Formátované čítanie zo súboru |
| `fprintf(FILE *f, "format", args)` | Formátovaný zápis do súboru |

---

### Cvičenie: kontrola správneho zátvorkovania

Napíšte program na kontrolu správneho uzátvorkovania výrazu, pričom výraz môže obsahovať tri typy zátvoriek: `()`, `{}`, `[]`.

- V prípade správneho uzátvorkovania vypíše: *Spravne uzatvorkovany vyraz*
- V opačnom prípade: *Nespravne uzatvorkovany vyraz*

**Ukážkový vstup:** `(3*{a+b}-{4*(5+[6*7])}+8)`
**Ukážkový výstup:** `Spravne uzatvorkovany vyraz`

> **Pomôcka:** Pole znakov použite ako zásobník.

---

## Polia a reťazce

### Základy práce s poliami

Pole je štruktúra zložená z niekoľkých prvkov **rovnakého typu** (blok prvkov).

```c
TYP x[N];   // statická definícia poľa
```

- Pole obsahuje **N** prvkov
- Dolná hranica je vždy **0**, horná je **N-1**
- Číslo `N` musí byť známe v čase prekladu
- Hodnoty **nie sú inicializované** na 0

| Index | 0 | 1 | 2 |
|---|---|---|---|
| Hodnota | 5 | 6 | 7 |

---

### Definícia a inicializácia reťazca

```c
char s[6];                      // statický reťazec s najviac 6 znakmi (vrátane '\0')

char s[] = "ahoj";              // inicializuje sa miesta práve pre daný text + '\0'
// s: | 'a' | 'h' | 'o' | 'j' | '\0' |

char s[15] = "abrakadabra";     // zvyšok sa vyplní nulami

char s[10];
s = "ahoj";                     // CHYBA! V C nie je možné takto priradiť
                                // statickému reťazcu konštantu
```

> Reťazec je vždy ukončený znakom `'\0'`.

---

### Štandardné funkcie pre reťazce

| Funkcia | Popis |
|---|---|
| `int strlen(char *s)` | Vráti dĺžku reťazca (bez `\0`) |
| `char *strcpy(char *s1, char *s2)` | Kopírovanie reťazca `s2` do `s1`, vracia ukazovateľ na `s1` |
| `char *strcat(char *s1, char *s2)` | Pripojí reťazec `s2` k `s1`, vracia ukazovateľ na `s1` |

---

## Štruktúry

### Definícia štruktúry (`typedef`)

Definícia nového typu – štruktúra nie je pomenovaná, pomenovaný je typ. Typ sa dá použiť na definíciu premenných, pretypovanie, atď.

```c
typedef struct {
    int vyska;
    float vaha;
} MIERY;

MIERY pavol, jan, karol;   // nebolo použité "struct"
```

---

### Prístup k položkám

Bodková notácia:

```c
typedef struct {
    int vyska;
    float vaha;
} MIERY;

MIERY pavol, jan, karol;

pavol.vyska = 182;
karol.vaha = 62.5;
jan.vyska = pavol.vyska;

// Pole štruktúr:
MIERY ludia[100];
ludia[50].vyska = 156;
ludia[0] = ludia[50];       // v ANSI C sa dá urobiť kopírovanie štruktúr
```

---

### Pole v štruktúre

```c
typedef struct {
    int pole[10];
} STR_POLE;

void main() {
    STR_POLE a, b;
    a.pole[0] = 5;
    b = a;          // takto sa dá skopírovať celé pole naraz!
}
```

> Štruktúra umožňuje **naraz skopírovať celé pole** – priame priradenie `b = a` prekopíruje všetky prvky.

---

### Štruktúra v inej štruktúre

Vnorená štruktúra musí byť definovaná **skôr**, ako je použitá v inej štruktúre.

```c
typedef struct {
    char ulica[30];
    int cislo;
} ADRESA;

typedef struct {
    char meno[30];
    ADRESA adresa;
    float plat;
} OSOBA;
```

#### Príklad: zamestnanec s najvyšším platom

```c
int i, kto = 0;
float max = 0.0, pom;
OSOBA ludia[100];
// ... (inicializácia)

for (i = 0; i < 100; i++) {
    if ((pom = ludia[i].plat) > max) {
        max = pom;
        kto = i;
    }
}
printf("Zamestnanec s najvyssim platom byva: %s %d",
       ludia[kto].adresa.ulica, ludia[kto].adresa.cislo);
```

---

### Globálne a lokálne premenné

```c
float x;                           // globálna premenná

int main() {
    int n;
    OSOBA ludia[100];
    // ...
    najdi(ludia, n);
    return 0;
}

void najdi(OSOBA l[], int n) {
    // ...
    for (i = 0; i < n; i++)
        l[i].plat = x;             // prístup ku globálnej premennej
}
```

> Ak má byť premenná **lokálna** – prenášajte ju cez argumenty funkcie.

---

## Jednoduché dátové typy a `sizeof`

Jazyk C zaručuje tieto vzťahy:

| Pravidlo |
|---|
| `sizeof(char) = 1` Byte |
| `sizeof(short int) <= sizeof(int) <= sizeof(long int)` |
| `sizeof(unsigned int) = sizeof(signed int)` |
| `sizeof(float) <= sizeof(double) <= sizeof(long double)` |

**Operátor `sizeof`** vráti počet bajtov typu alebo premennej:

```c
int pole[100];
dlzka = sizeof(pole) / sizeof(int);   // počet prvkov poľa
```

> **Obmedzenia:**
> - **Nepomôže** zistiť dĺžku poľa **vo funkcii** (a už vôbec nie počet využitých položiek poľa)
> - **Nepomôže** zistiť dĺžku reťazca (na to použite `strlen`)

---

## Parametre funkcií

### Volanie hodnotou

```c
int A(int i) {
    // i je KÓPIA hodnoty z main
    // zmena i neovplyvní pôvodnú premennú
}
```

- Pri volaní `A(3)` sa na zásobníku vytvorí kópia hodnoty `3`
- Po návrate z funkcie sa kópia zahodí

---

### Volanie odkazom

```c
int A(int *i) {
    // i je ADRESA premennej z main
    // *i pristupuje k pôvodnej premennej
}
```

- Pri volaní `A(&premenna)` sa odovzdá adresa premennej (napr. `15`)
- Funkcia cez `*i` mení priamo pôvodnú premennú

---

### Operátor `&` vs `&&`

```c
int x = 11, y = 4;

if (x && y)      // Logický súčin: 11 a 4 sú nenulové → PRAVDA
    printf("*");

if (x & y)       // Bitový súčin: 1011 & 0100 = 0000 → NEPRAVDA
    printf("+");

// Výstup: *
```

| Operátor | Typ | 11 (1011₂) op 4 (0100₂) | Výsledok |
|---|---|---|---|
| `&&` | Logický súčin | nenulové && nenulové | PRAVDA |
| `&` | Bitový súčin | 1011 & 0100 | 0 (NEPRAVDA) |

---

## Ukazovatele

### Základy ukazovateľov

Premenné obsahujúce **adresy**.

```c
int *p;    // definícia ukazovateľa na int
```

> **Nikdy nepracujte** s ukazovateľom, ktorý ste predtým nenasmerovali na zmysluplnú adresu! Ak potrebujete zaistiť, aby neukazoval na konkrétne miesto, priradíte mu hodnotu `NULL`.

---

### Ukazovateľ na ukazovateľ

```c
int **p, *q, r;

// p: ukazovateľ na ukazovateľ na int (adresa 17)
// q: ukazovateľ na int (adresa 51)
// r: int (adresa 67)

p = &q;       // p ukazuje na q
q = &r;       // q ukazuje na r
r = 5;

printf("%p %p %p %p %p %d %p %d %d",
       &p, &q, &r, p, q, r, *p, *q, **p);
// Výstup: 17 51 67 51 67 5 67 5 5
```

| Výraz | Hodnota | Vysvetlenie |
|---|---|---|
| `&p` | 17 | adresa premennej `p` |
| `&q` | 51 | adresa premennej `q` |
| `&r` | 67 | adresa premennej `r` |
| `p` | 51 | hodnota `p` = adresa `q` |
| `q` | 67 | hodnota `q` = adresa `r` |
| `r` | 5 | hodnota `r` |
| `*p` | 67 | dereferencuj `p` → hodnota na adrese 51 = `q` = 67 |
| `*q` | 5 | dereferencuj `q` → hodnota na adrese 67 = `r` = 5 |
| `**p` | 5 | dvojitá dereferencácia → `*(*p)` = `*(q)` = 5 |

Operátory:
- `&` – vráti adresu premennej
- bez operátora – hodnota premennej (ak je hodnotou adresa, tak je to adresa)
- `*` – hodnotu premennej vezme ako adresu a z tej adresy vráti hodnotu

---

### Ukazovatele a polia

```c
int *p, q[5], i = 0;

for (i = 0; i < 5; i++)
    q[i] = i;           // q: {0, 1, 2, 3, 4}

p = q;                  // p ukazuje na začiatok poľa q
p = q + 2;              // to isté ako p = &q[2]
i = *(q + 2);           // to isté ako i = q[2]
```

- `p` je ukazovateľ na `int` – dá sa meniť
- `q` je **statický** ukazovateľ na `int` (meno poľa) – nedá sa meniť

---

### Zápis s jednorozmerným a dvojrozmerným poľom

**Jednorozmerné pole:**

| Zápis | Ekvivalent | Význam |
|---|---|---|
| `&pole[0]` | `pole + 0` alebo `pole` | Adresa začiatku poľa |
| `&pole[i]` | `pole + i` | Adresa i-teho prvku |
| `pole[i]` | `*(pole + i)` | Hodnota i-teho prvku |
| `pole[0] = 10` | `*pole = 10` | Priradenie do 0. prvku |
| `pole[10] = 70` | `*(pole + 10) = 70` | Priradenie do 10. prvku |

**Dvojrozmerné pole:**

| Zápis | Ekvivalent 1 | Ekvivalent 2 |
|---|---|---|
| `pole2[i][j]` (hodnota) | `*(pole2[i] + j)` | `*(*(pole2 + i) + j)` |
| `&pole2[i][j]` (adresa) | `pole2[i] + j` | `*(pole2 + i) + j` |

---

## Spájané zoznamy

### Základná štruktúra

```c
typedef struct prvok {
    char meno[51];
    int cislo;
    struct prvok *dalsi;
} PRVOK;
```

Pojmy:
- **Spájaný zoznam** – dátová štruktúra s prvkami prepojenými smerníkmi
- **Prvok** spájaného zoznamu – jedna štruktúra
- **Položka** prvku – jedno dátové pole v štruktúre (`meno`, `cislo`)
- **Ukazovateľ na zoznam** (`zac`, `akt`) – smerník na prvok

> **Nie je to to isté:** zoznam ≠ prvok ≠ položka ≠ ukazovateľ!

---

### Posun vs. zmena zoznamu

Priradením hodnoty ukazovateľu je možné:

**Posunúť ukazovateľ** na iný prvok (prechádzanie zoznamom):

```c
akt = akt->dalsi;          // posun na ďalší prvok
```

**Zmeniť zoznam** (presmerovať smerník v rámci zoznamu):

```c
akt->dalsi = akt;          // zmena štruktúry zoznamu!
```

---

### Vloženie prvku na inú pozíciu

Vloženie prvku, na ktorý ukazuje `vloz`, za pozíciu aktuálneho prvku (na ktorý ukazuje `akt`):

1. Predchádzajúci pred `vloz` bude ukazovať na nasledovníka `vloz`
2. `vloz` bude ukazovať na prvok za `akt`
3. `akt` bude ukazovať na `vloz`

```c
void vloz(ZOZNAM *zac, ZOZNAM *akt, ZOZNAM *vloz) {
    ZOZNAM *pred_vloz;

    if (zac != NULL && akt != NULL && vloz != NULL
        && akt->dalsi != vloz) {

        if (vloz == zac)
            zac = zac->dalsi;
        else {
            pred_vloz = najdi_predchodcu(vloz);
            pred_vloz->dalsi = vloz->dalsi;
        }

        vloz->dalsi = akt->dalsi;
        akt->dalsi = vloz;
    }
}
```

> **NdÚ:** Naprogramujte funkciu `najdi_predchodcu`.

**Hraničné situácie na ošetrenie:**
- Čo ak `akt` je na začiatku / konci zoznamu?
- Čo ak `vloz` je na začiatku / konci zoznamu?

---

### Prístup k položkám prvku

K položkám prvku spájaného zoznamu môžeme pristupovať, **len ak** daný prvok existuje (nie je `NULL`).

```c
// CHYBNE:
if (akt->hodnota == 7)
    // ...

// SPRÁVNE (s kontrolou NULL):
if (akt != NULL && akt->hodnota == 7)
    // ...
```

> Využite **skrátené vyhodnocovanie** logických operátorov!

---

### Kontrola hodnoty ďalšieho prvku

Ak treba vložiť prvok do usporiadaného zoznamu, môžete sa potrebovať opýtať na hodnotu ďalšieho prvku:

```c
// CHYBNE (bez kontrol):
if (akt->hodnota < vloz->data && akt->dalsi->hodnota > vloz->data)
    // ...

// SPRÁVNE (s kontrolami NULL):
if (vloz != NULL)
    if (akt != NULL && akt->hodnota < vloz->data
        && akt->dalsi != NULL && akt->dalsi->hodnota > vloz->data)
        // ...
```

> Predtým je treba zistiť, či `vloz`, `akt` a `akt->dalsi` neukazujú na `NULL`.

---

### Pamätanie začiatku zoznamu

Vždy je potrebné pamätať si počas celej práce so zoznamom jeho **začiatok** (`zac`). Pri rozdelení zoznamu je treba uložiť aj **začiatok časti** zoznamu (`pom`) — pokým sa zoznam nespojí.

```c
PRVOK *zac;     // začiatok zoznamu
PRVOK *akt;     // aktuálny prvok
PRVOK *pom;     // začiatok časti zoznamu, ktorú ideme „odpojiť"
```

---

### Zmena zoznamu vo funkcii

Ak vo funkcii meníme zoznam (vkladáme, mažeme, preusporadúvame), **môže sa zmeniť začiatok** zoznamu. Preto je potrebné vrátiť ukazovateľ na nový začiatok.

**Spôsob 1: návratová hodnota**

```c
ZOZNAM *zmena(ZOZNAM *zac, ...) {
    // ...
    return zac;
}
```

**Spôsob 2: ukazovateľ na ukazovateľ**

```c
void zmena(ZOZNAM **zac, ...) {
    // ...
}
```

---

## Binárne operácie

```c
#include <stdio.h>

int main() {
    printf("1 << 1 = %d\t%x\n", 1 << 1, 1 << 1);        // 2     0x2
    printf("1 << 7 = %d\t%x\n", 1 << 7, 1 << 7);        // 128   0x80
    printf("1024 >> 9 = %d\t%x\n", 1024 >> 9, 1024 >> 9);// 2     0x2
    printf("13 & 6 = %d\t%x\n", 13 & 6, 13 & 6);        // 4     0x4
    printf("13 | 6 = %d\t%x\n", 13 | 6, 13 | 6);        // 15    0xf
    printf("13 ^ 6 = %d\t%x\n", 13 ^ 6, 13 ^ 6);        // 11    0xb
    printf("2 & 1 = %d\t%x\n", 2 & 1, 2 & 1);           // 0     0
    printf("2 | 1 = %d\t%x\n", 2 | 1, 2 | 1);           // 3     0x3
    printf("2 ^ 1 = %d\t%x\n", 2 ^ 1, 2 ^ 1);           // 3     0x3
    return 0;
}
```

Výsledky:

| Výraz | Desiatkovo | Šestnástkovo | Poznámka |
|---|---|---|---|
| `1 << 1` | 2 | 0x2 | posun doľava |
| `1 << 7` | 128 | 0x80 | 128 = 2⁷ |
| `1024 >> 9` | 2 | 0x2 | 1024 = 2¹⁰ |
| `13 & 6` | 4 | 0x4 | 1101 & 0110 = 0100 |
| `13 \| 6` | 15 | 0xf | 1101 \| 0110 = 1111 |
| `13 ^ 6` | 11 | 0xb | 1101 ^ 0110 = 1011 |
| `2 & 1` | 0 | 0 | 10 & 01 = 00 |
| `2 \| 1` | 3 | 0x3 | 10 \| 01 = 11 |
| `2 ^ 1` | 3 | 0x3 | 10 ^ 01 = 11 |

---

[← Prednáška 11](../11-typova-konverzia-preprocesor/) | [Hlavná stránka](../../README.md)
