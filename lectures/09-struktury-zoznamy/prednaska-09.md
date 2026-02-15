# Prednáška 9: Štruktúry, spájané zoznamy a bitové operácie

> **Predmet:** Algoritmizácia a programovanie
> **Prednášajúci:** Ján Grman
> **Semester:** Zimný semester 2024

---

## Obsah

1. [Štruktúry](#štruktúry)
   - [Čo je to štruktúra?](#čo-je-to-štruktúra)
   - [Definícia štruktúry (5 spôsobov)](#definícia-štruktúry)
   - [Prístup k položkám štruktúry](#prístup-k-položkám-štruktúry)
   - [Pole v štruktúre](#pole-v-štruktúre)
   - [Štruktúry a ukazovatele](#štruktúry-a-ukazovatele)
   - [Prístup do štruktúry pomocou ukazovateľa](#prístup-do-štruktúry-pomocou-ukazovateľa)
   - [Štruktúra v inej štruktúre (vnorené štruktúry)](#štruktúra-v-inej-štruktúre)
   - [Alokácia pamäte pre položky štruktúry](#alokácia-pamäte-pre-položky-štruktúry)
   - [Štruktúry a funkcie](#štruktúry-a-funkcie)
   - [Dynamické vytváranie štruktúr vo funkciách](#dynamické-vytváranie-štruktúr-vo-funkciách)
2. [Uniony](#uniony)
   - [Union vložený do štruktúry](#union-vložený-do-štruktúry)
3. [Spájané zoznamy](#spájané-zoznamy)
   - [Štruktúry ukazujúce samy na seba](#štruktúry-ukazujúce-samy-na-seba)
   - [Spájaný zoznam – princíp](#spájaný-zoznam--princíp)
   - [Spájaný zoznam – príklad (mazanie deliteľných 3)](#spájaný-zoznam--príklad)
   - [Kruhový zoznam](#kruhový-zoznam)
4. [Bitové operácie](#bitové-operácie)
   - [Práca s bitmi – úvod](#práca-s-bitmi)
   - [Prehľad bitových operátorov](#prehľad-bitových-operátorov)
   - [Bitový súčin (AND)](#bitový-súčin-and)
   - [Bitový súčet (OR)](#bitový-súčet-or)
   - [Bitový exkluzívny súčet (XOR)](#bitový-exkluzívny-súčet-xor)
   - [Bitový posun doľava](#bitový-posun-doľava)
   - [Bitový posun doprava](#bitový-posun-doprava)
   - [Negácia po bitoch](#negácia-po-bitoch)
   - [Práca so skupinou bitov (príznaky)](#práca-so-skupinou-bitov)
   - [Bitové pole](#bitové-pole)

---

## Štruktúry

<details>



### Čo je to štruktúra?

**Štruktúra (`struct`)** je **heterogénny dátový typ** – je zložený z prvkov rozličných dátových typov (na rozdiel od poľa, ktoré je homogénny dátový typ).

```c
struct {
    položka_1;
    ...
    položka_n;
};
```

> **Poznámka:** Štruktúru je možné definovať **piatimi rôznymi spôsobmi**.

---

### Definícia štruktúry

#### Spôsob 1 – Základný (nepomenovaná štruktúra)

Štruktúra **nie je pomenovaná** – nedá sa inde v programe použiť. Použiť sa dajú len definované premenné.

```c
struct {
    int vyska;
    float vaha;
} pavol, jan, karol;
```

#### Spôsob 2 – Pomenovaná štruktúra s premennými

Štruktúra **je pomenovaná** – dá sa využiť aj inde v programe.

```c
struct miery {
    int vyska;
    float vaha;
} pavol, jan, karol;
```

#### Spôsob 3 – Oddelená definícia a deklarácia premenných

Definícia štruktúry a premenných je **oddelená** (premenné sa môžu vytvárať viackrát).

```c
struct miery {
    int vyska;
    float vaha;
};

struct miery pavol;
struct miery jan, karol;
```

#### Spôsob 4 – Typedef (nepomenovaná štruktúra, pomenovaný typ)

Štruktúra **nie je pomenovaná**, pomenovaný je **typ**. Typ sa dá použiť na definíciu premenných, pretypovanie...

```c
typedef struct {
    int vyska;
    float vaha;
} MIERY;

MIERY pavol, jan, karol;   /* nebolo použité "struct" */
```

#### Spôsob 5 – Typedef s pomenovanou štruktúrou (odporúčaný)

Štruktúra **aj typ** sú pomenované. Neskôr to budeme potrebovať (napr. pri spájaných zoznamoch).

```c
typedef struct miery {
    int vyska;
    float vaha;
} MIERY;

MIERY pavol, jan, karol;
```

> **Odporúčanie:** Pomenovať typ aj štruktúru rovnako, odlíšiť ich len veľkosťou písma (napr. `miery` / `MIERY`).

<details>



---

### Prístup k položkám štruktúry

Prístup k položkám sa realizuje pomocou **bodkovej notácie**:

```c
typedef struct {
    int vyska;
    float vaha;
} MIERY;

MIERY pavol, jan, karol;

pavol.vyska = 182;
karol.vaha = 62.5;
jan.vyska = pavol.vyska;
```

Často sa používa **pole štruktúr**:

```c
MIERY ludia[100];

ludia[50].vyska = 156;
ludia[0] = ludia[50];       /* v ANSI C sa dá priradiť celá štruktúra */
```

---

### Pole v štruktúre

Štruktúru možno využiť na to, aby sa dalo **naraz skopírovať celé pole** (priame priradenie polí v C nie je možné):

```c
typedef struct {
    int pole[10];
} STR_POLE;

void main()
{
    STR_POLE a, b;
    a.pole[0] = 5;
    b = a;              /* skopíruje sa celé pole */
}
```

---

### Štruktúry a ukazovatele

<details>



Ukazovatele na štruktúry sa používajú pri:
- **štruktúrach v dynamickej pamäti**
- **štruktúrach vo funkciách**

```c
typedef struct {
    char meno[30];
    int rocnik;
} STUDENT;

STUDENT s, *p_s;

/* Alokácia pamäte pre štruktúru */
p_s = (STUDENT *) malloc(sizeof(STUDENT));

/* Alebo nastaviť ukazovateľ na existujúcu štruktúru */
p_s = &s;
```

Možno tiež definovať **typ ukazovateľa** na štruktúru:

```c
typedef struct {
    char meno[30];
    int rocnik;
} STUDENT, *P_STUDENT;

STUDENT s;
P_STUDENT p_s;
p_s = (P_STUDENT) malloc(sizeof(STUDENT));

s.rocnik = 2;            /* prístup cez premennú */
(*p_s).rocnik = 3;       /* prístup cez dereferenciu ukazovateľa */
p_s->rocnik = 4;         /* prístup cez šípkovú notáciu (preferované) */
```

---

### Prístup do štruktúry pomocou ukazovateľa

| Zápis | Vysvetlenie |
|-------|-------------|
| `s.rocnik = 2;` | Priamy prístup cez premennú |
| `(*p_s).rocnik = 3;` | Dereferencovanie ukazovateľa + bodková notácia |
| `p_s->rocnik = 4;` | Šípková notácia (preferované) |
| `*p_s.rocnik = 5;` | **CHYBA!** Operátor `.` má väčšiu prioritu ako `*` |

> **Pozor:** Zápis `*p_s.rocnik` je chybný, pretože `.` má väčšiu prioritu ako `*`. Správne je `(*p_s).rocnik` alebo `p_s->rocnik`.

---

### Štruktúra v inej štruktúre

Vnorená (vhniezdená) štruktúra musí byť **definovaná skôr**, ako je použitá v inej štruktúre (nie je to len odkaz/ukazovateľ):

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

#### Príklad: Najvyšší plat (cez index)

```c
int i, kto = 0;
float max = 0.0, pom;
OSOBA ludia[100];

/* ... inicializácia ... */

for (i = 0; i < 100; i++) {
    if ((pom = ludia[i].plat) > max) {
        max = pom;
        kto = i;
    }
}

printf("Zamestnanec s najvyssim platom byva: %s %d",
       ludia[kto].adresa.ulica, ludia[kto].adresa.cislo);
```

#### Príklad: Najvyšší plat (cez ukazovatele)

```c
float max = ludia[0].plat, pom;
OSOBA ludia[100], *p_kto, *p_pom;

/* ... inicializácia ... */

for (p_pom = p_kto = ludia;
     p_pom < ludia + 100;
     p_pom++) {
    if ((p_pom->plat) > max) {
        p_kto = p_pom;
        max = p_pom->plat;
    }
}

printf("Zamestnanec s najvyssim platom byva: %s %d",
       p_kto->adresa.ulica, p_kto->adresa.cislo);
```

---

### Alokácia pamäte pre položky štruktúry

```c
typedef struct {
    char c;
    int i, j, k;
    char d;
} POKUS;

POKUS p;
```

Pravidlá ukladania do pamäte:

- Položky obsadzujú pamäť **zhora dole** a **zľava doprava** (v poradí: `c`, `i`, `j`, `k`, `d`)
- Položky sú väčšinou **zarovnávané na párne adresy** – za `char c` je väčšinou 1 prázdny byte (padding)
- Štruktúra väčšinou **končí na párnej adrese** – za `char d` je tiež 1 voľný byte

> Na zistenie skutočnej veľkosti štruktúry použite: `sizeof(p);`

<details>



---

### Štruktúry a funkcie

| Verzia jazyka | Parameter | Návratový typ |
|---------------|-----------|---------------|
| **K&R C** | ukazovateľ na štruktúru | ukazovateľ na štruktúru |
| **ANSI C** | ukazovateľ na štruktúru **aj** samotná štruktúra | ukazovateľ na štruktúru **aj** samotná štruktúra |

#### Príklad: Sčítanie komplexných čísel (návrat hodnotou)

```c
typedef struct {
    double re, im;
} KOMP;

KOMP sucet(KOMP a, KOMP b)
{
    KOMP c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

void main()
{
    KOMP x, y, z;
    x.re = 1.4; x.im = 3.2;
    y = x;
    z = sucet(x, y);
}
```

> **Poznámka:** Ak sú štruktúry veľké, vytváranie lokálnych kópií je **časovo aj pamäťovo náročné** ⇒ vhodné používať ukazovatele.

#### Príklad: Sčítanie komplexných čísel (cez ukazovatele)

```c
typedef struct {
    double re, im;
} KOMP;

void sucet(KOMP *a, KOMP *b, KOMP *c)
{
    c->re = a->re + b->re;
    c->im = a->im + b->im;
}

void main()
{
    KOMP x, y, z;
    x.re = 1.4; x.im = 3.2;
    y = x;
    sucet(&x, &y, &z);
}
```

---

### Dynamické vytváranie štruktúr vo funkciách

#### Variant 1: Návrat ukazovateľom

```c
typedef struct {
    char meno[30];
    int rocnik;
} STUDENT;

STUDENT *vytvor1(void)
{
    STUDENT *p;
    p = (STUDENT *) malloc(sizeof(STUDENT));
    if (p == NULL)
        printf("Malo pamate.\n");
    return p;
}
```

#### Variant 2: Návrat cez parameter (ukazovateľ na ukazovateľ)

```c
void vytvor2(STUDENT **p)
{
    *p = (STUDENT *) malloc(sizeof(STUDENT));
    if (*p == NULL)
        printf("Malo pamate.\n");
}
```

#### Použitie:

```c
void nastav(STUDENT *p, char *meno, int rok)
{
    p->rocnik = rok;
    strcpy(p->meno, meno);
}

void main()
{
    STUDENT s, *p_s1, *p_s2;
    p_s1 = vytvor1();
    vytvor2(&p_s2);
    s.rocnik = p_s1->rocnik = 1;
    nastav(&s, "Martin", 1);
    nastav(p_s1, "Peter", 2);
    nastav(p_s2, "Michal", 3);
}
```

---

## Uniony

**Union** je dátový typ, kde sa vyhradí pamäť pre **najväčšiu položku** a všetky položky sa **prekrývajú**:

```c
typedef union {
    char c;
    int i;
    float f;
} ZIF;

ZIF a, *p_a = &a;

a.c = '#';       /* premazávajú sa hodnoty */
p_a->i = 1;
a.f = 2.3;
```

> **Dôležité:** Vyhradí sa pamäť o veľkosti najväčšieho prvku. Union **neposkytuje informáciu** o type prvku, ktorý bol naposledy do neho uložený!

---

### Union vložený do štruktúry

Riešenie problému identifikácie typu v unione – kombinácia `enum`, `union` a `struct`:

```c
typedef enum {
    ZNAK, CELE, REALNE
} TYP;                       /* vymenovaný typ: rozlíšenie typov */

typedef union {
    char c;
    int i;
    float f;
} ZIF;                       /* union: uchovávanie znak/celé/reálne číslo */

typedef struct {
    TYP typ;                 /* informácia o type položky */
    ZIF polozka;             /* samotná položka */
} ZN_INT_FL;
```

---

## Spájané zoznamy

### Štruktúry ukazujúce samy na seba

Štruktúra môže obsahovať **ukazovateľ na ten istý typ štruktúry**. Príklady z praxe:

**Príklad 1 – Hypertext:**
Web stránka má odkaz na inú web stránku (ukazovateľ na rovnaký typ).

**Príklad 2 – Pacienti v čakárni:**
Každý človek si pamätá, kto je pred ním (ukazovateľ na ten istý typ).

<details>



#### Správna definícia:

```c
typedef struct polozka {
    int hodnota;
    struct polozka *p_dalsi;     /* odkaz na samého seba – rovnaký typ */
} POLOZKA;
```

> **Pozor:** Aj štruktúra, aj typ **musia byť pomenované**. Nasledujúci kód je **chybný**:
>
> ```c
> typedef struct {
>     int hodnota;
>     struct POLOZKA *p_dalsi;    /* CHYBA: POLOZKA ešte nie je známa */
> } POLOZKA;
> ```

---

### Spájaný zoznam – princíp

Spájaný zoznam je **dynamický zoznam prvkov**:
- V pamäti je práve toľko prvkov, koľko je potreba
- Dá sa pridávať na ktorékoľvek miesto v zozname

Každý prvok obsahuje **dáta** a **ukazovateľ na ďalší prvok**:

```c
typedef struct clovek {
    char meno[30];
    int rocnik;
    struct clovek *dalsi;
} CLOVEK;
```

<details>



#### Vytváranie zoznamu:

```c
CLOVEK *p, *q;

p = (CLOVEK *) malloc(sizeof(CLOVEK));
q = (CLOVEK *) malloc(sizeof(CLOVEK));

strcpy(p->meno, "Janko");
p->rocnik = 1;

strcpy(q->meno, "Misko");
q->rocnik = 2;

p->dalsi = q;        /* Janko ukazuje na Miška */
q->dalsi = NULL;     /* Miško je posledný */
```

Výsledná štruktúra v pamäti:

```
p → [Janko, 1] → [Miško, 2] → NULL
```

---

### Spájaný zoznam – príklad

Vytvorí sa spájaný zoznam s hodnotami `1...n`, potom sa **vymažú všetky prvky deliteľné 3**.

```
Pred: 1 → 2 → 3 → 4 → 5 → 6 → 7 → NULL
Po:   1 → 2 → 4 → 5 → 7 → NULL
```

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct prvok {
    int hodnota;
    struct prvok *dalsi;
} PRVOK;

void main()
{
    int i, n;
    PRVOK *p_prv, *p_akt, *p_pred;

    printf("Zadaj pocet prvkov zoznamu: ");
    scanf("%d", &n);

    /* Vytvorenie prvého prvku */
    if ((p_prv = (PRVOK *) malloc(sizeof(PRVOK))) == NULL) {
        printf("Malo pamate.\n");
        return;
    }
    p_prv->hodnota = 1;

    /* Vytvorenie zvyšných prvkov */
    p_akt = p_prv;
    for (i = 2; i <= n; i++) {
        if ((p_akt->dalsi = (PRVOK *) malloc(sizeof(PRVOK))) == NULL) {
            printf("Malo pamate.\n");
            break;
        }
        p_akt = p_akt->dalsi;
        p_akt->hodnota = i;
    }
    p_akt->dalsi = NULL;

    /* Mazanie prvkov deliteľných 3 */
    for (p_pred = p_akt = p_prv;
         p_akt != NULL;
         p_pred = p_akt, p_akt = p_akt->dalsi) {
        if (p_akt->hodnota % 3 == 0) {
            p_pred->dalsi = p_akt->dalsi;
            free((void *) p_akt);
            p_akt = p_pred;
        }
    }
}
```

<details>



---

### Kruhový zoznam

#### Princíp

Kruhový zoznam je spájaný zoznam, kde **posledný prvok ukazuje späť na prvý**. Príklad: simulácia hry „Kolo, kolo mlynské" – záznamy o deťoch, ktoré ešte nevypadli.

<details>



**Fázy budovania:**

1. **Prázdny zoznam:** `akt = NULL`
2. **Jeden prvok:** Prvok ukazuje sám na seba (`akt->dalsi = akt`)
3. **Dva prvky:** Nový prvok sa vloží za aktuálny; obaja ukazujú na seba navzájom
4. **Tri a viac prvkov:** Nový prvok sa vloží za aktuálny; ukazovatele sa upravia

#### Funkcie kruhového zoznamu

| Funkcia | Popis |
|---------|-------|
| `DIETA *pridaj(DIETA *akt)` | Pridanie do zoznamu za aktuálny prvok |
| `DIETA *zmaz(DIETA *akt)` | Zmazanie zo zoznamu za aktuálnym prvkom |
| `DIETA *posun(DIETA *akt)` | Posun ukazovateľa na `akt->dalsi` |
| `void vypis(DIETA *akt)` | Výpis celého zoznamu |

#### Kompletná implementácia

```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 50

typedef struct dieta {
    char meno[N];
    struct dieta *dalsi;
} DIETA;

/* Prototypy funkcií */
DIETA *pridaj(DIETA *akt);
DIETA *zmaz(DIETA *akt);
DIETA *posun(DIETA *akt);
void vypis(DIETA *akt);

int main()
{
    DIETA *akt = NULL;
    char c;

    do {
        printf("Kruhovy zoznam.\n");
        printf("p: pridaj\n");
        printf("z: zmaz\n");
        printf("s: posun\n");
        printf("k: koniec\n\n");

        c = getch();

        switch (c) {
            case 'p': akt = pridaj(akt); break;
            case 'z': akt = zmaz(akt);   break;
            case 's': akt = posun(akt);  break;
        }

        vypis(akt);
    } while (c != 'k');

    return 0;
}

/* Pridáva za aktuálny prvok */
DIETA *pridaj(DIETA *akt)
{
    DIETA *p = (DIETA *) malloc(sizeof(DIETA));
    printf("Zadajte meno: ");
    scanf("%s", p->meno);

    if (akt == NULL) {              /* vkladá sa prvý záznam */
        akt = p;
        akt->dalsi = p;             /* ukazuje sám na seba */
        return akt;
    }
    else {                          /* akt už ukazuje na nejaký prvok */
        p->dalsi = akt->dalsi;      /* vloženie za aktuálny */
        akt->dalsi = p;
        return akt->dalsi;
    }
}

/* Maže za aktuálnym prvkom */
DIETA *zmaz(DIETA *akt)
{
    DIETA *p;

    if (akt == NULL)                     /* zoznam je prázdny */
        return NULL;
    else if (akt->dalsi == akt) {        /* jednoprvkový zoznam */
        free(akt);
        return NULL;
    }
    else {                               /* aspoň 2 prvky v zozname */
        p = akt->dalsi->dalsi;
        free(akt->dalsi);
        akt->dalsi = p;
    }
    return akt;
}

/* Vráti ukazovateľ na ďalší prvok */
DIETA *posun(DIETA *akt)
{
    return (akt == NULL ? NULL : akt->dalsi);
}

/* Vypíše zoznam */
void vypis(DIETA *akt)
{
    DIETA *p = akt;

    if (p == NULL)
        printf("Zoznam je prazdny.\n\n");
    else {
        do {
            printf("%s -> ", p->meno);
            p = p->dalsi;
        } while (p != akt);
        printf("\n\n");
    }
}
```

---

## Bitové operácie

### Práca s bitmi

Bitové operácie pracujú s **reprezentáciou čísla v dvojkovej sústave**.

**Prevod do dvojkovej sústavy** (delenie dvomi):

```
Príklad – prevod čísla 4:
4 / 2 = 2   zvyšok 0
2 / 2 = 1   zvyšok 0        → Zvyšky prečítané zospodu hore:
1 / 2 = 0   zvyšok 1        → 100₂ = 4₁₀
```

Príklady hodnôt:

| Desiatkovo | Dvojkovo |
|:----------:|:--------:|
| 1 | `001` |
| 2 | `010` |
| 3 | `011` |
| 4 | `100` |

---

### Prehľad bitových operátorov

| Operátor | Názov | Popis |
|:--------:|-------|-------|
| `&` | Bitový súčin (AND) | 1 ak oba bity sú 1 |
| `\|` | Bitový súčet (OR) | 1 ak aspoň jeden bit je 1 |
| `^` | Bitový XOR | 1 ak sa bity líšia |
| `<<` | Posun doľava | Násobenie mocninou 2 |
| `>>` | Posun doprava | Celočíselné delenie mocninou 2 |
| `~` | Negácia (NOT) | Prevráti všetky bity |

> **Poznámka:** Argumenty bitových operátorov **nemôžu byť** `float`, `double` ani `long double`.

---

### Bitový súčin (AND)

`i`-ty bit výsledku `x & y` bude 1 vtedy, ak `i`-ty bit `x` **aj** `i`-ty bit `y` sú 1, inak 0.

**Pravdivostná tabuľka:**

| x | y | x & y |
|:-:|:-:|:-----:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

**Príklady použitia:**

```c
/* Zistenie, či je číslo nepárne */
#define je_neparne(x) (1 & (unsigned)(x))

/* Extrahovanie najnižších 7 bitov (ASCII znak) */
c = c & 0x7F;     /* ekvivalent: c &= 0x7F; */
/* 0x7F = 0000 0000 0111 1111 */
```

#### Rozdiel medzi bitovým a logickým súčinom

```c
unsigned int i = 1, j = 2, k, l;
k = i && j;     /* k = 1 (logický AND: obe nenulové → true) */
l = i & j;      /* l = 0 (bitový AND: 0001 & 0010 = 0000)  */
```

---

### Bitový súčet (OR)

`i`-ty bit výsledku `x | y` bude 1 vtedy, ak `i`-ty bit `x` **alebo** `i`-ty bit `y` je 1, inak 0. Používa sa na **nastavenie niektorých bitov na 1**, pričom nechá ostatné bity nezmenené.

**Pravdivostná tabuľka:**

| x | y | x \| y |
|:-:|:-:|:------:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

```c
/* Makro vráti nepárne číslo nezmenené, párne zväčší o 1 */
#define na_neparne(x) (1 | (unsigned)(x))
```

---

### Bitový exkluzívny súčet (XOR)

`i`-ty bit výsledku `x ^ y` bude 1 vtedy, ak sa `i`-ty bit `x` **nerovná** `i`-temu bitu `y`, inak 0.

**Pravdivostná tabuľka:**

| x | y | x ^ y |
|:-:|:-:|:-----:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

```c
/* Zistenie, či sa dve čísla líšia */
if (x ^ y)    /* čísla sú rozdielne */
```

---

### Bitový posun doľava

`x << n` posunie bity v `x` o `n` pozícií **doľava**. Bity zľava sa strácajú, bity sprava sú dopĺňané nulami. Efekt: **násobenie hodnotou 2ⁿ**.

```
x       = 0001 1011 0010 0101 =  6949
x << 1  = 0011 0110 0100 1010 = 13898  = 2 × 6949
x << 3  = násobenie 2³ = 8
```

```c
x = x << 1;     /* rýchle násobenie dvomi */
x = x << 3;     /* násobenie osmičkou */
```

---

### Bitový posun doprava

`x >> n` posunie bity v `x` o `n` pozícií **doprava**. Bity sprava sa strácajú, bity zľava sú dopĺňané nulami. Efekt: **celočíselné delenie hodnotou 2ⁿ**.

```
x       = 0011 0110 0100 1010 = 13898
x >> 1  = 0001 1011 0010 0101 =  6949  = 13898 / 2
x >> 3  = celočíselné delenie 2³ = 8
```

#### Príklad: Násobenie a delenie bitovými posunmi

```c
/* Bitové posuny sú rýchlejšie ako násobenie a delenie */
i = j * 80;                        /* 80 = 64 + 16 */
i = (j << 6) + (j << 4);          /* rýchlejšie */
```

#### Príklad: Zistenie hodnoty konkrétneho bitu

```c
#define ERROR -1
#define CLEAR 1
#define BIT_V_CHAR 8

int bit(unsigned x, unsigned i)
{
    if (i >= sizeof(x) * BIT_V_CHAR)
        return (ERROR);
    else
        return ((x >> i) & CLEAR);    /* posun i-ty bit na pozíciu 0 a maskuj */
}
```

---

### Negácia po bitoch

Jednotkový doplnok `~x` **prevráti** nulové bity na jednotkové a naopak.

```c
/* Nastavenie posledných 4 bitov na nulu */
x &= 0xFFF0;      /* funguje LEN ak sizeof(int) == 2 */
x &= ~0xF;         /* funguje VŽDY – platformovo nezávislé */
```

#### Príklad: Zistenie dĺžky typu `int` v bitoch

```c
#include <stdio.h>

int dlzka_int()
{
    unsigned int x, i = 0;
    x = ~0;              /* negácia 0 → samé 1 */
    while ((x >> 1) != 0)
        i++;
    return (++i);
}

int main()
{
    printf("Dlzka typu int je %d bitov\n", dlzka_int());
    return 0;
}
```

---

### Práca so skupinou bitov

Stavová premenná `stav` na definovanie **prístupových práv** k súboru pomocou bitových príznakov:

```c
#define READ   0x8      /* 2³ = 0000 1000 */
#define WRITE  0x10     /* 2⁴ = 0001 0000 */
#define DELETE 0x20     /* 2⁵ = 0010 0000 */

unsigned int stav;

stav |= READ | WRITE | DELETE;       /* nastaví bity 3, 4 a 5 na 1 */
stav |= READ | WRITE;                /* nastaví bity 3 a 4 na 1 */
stav &= ~(READ | WRITE | DELETE);    /* nastaví bity 3, 4 a 5 na 0 */
stav &= ~READ;                       /* nastaví bit 3 na 0 */

if (!(stav & (WRITE | DELETE)))      /* ak bity 4 a 5 sú nulové */
    ...
```

---

### Bitové pole

Bitové pole je **štruktúra s obmedzenou veľkosťou** (veľkosť typu `int`), kde najmenšia dĺžka položky je **1 bit**.

Každá položka je určená **menom a dĺžkou v bitoch**. Oblasti použitia:
- Uloženie viac celých čísel v jednom (šetrenie pamäte)
- Prístup k jednotlivým bitom

#### Príklad: Uloženie dátumu do jedného `int`-u

```c
typedef struct {
    unsigned den    : 5;    /* bity 0–4  (max. 31) */
    unsigned mesiac : 4;    /* bity 5–8  (max. 15) */
    unsigned rok    : 7;    /* bity 9–15 (max. 127, preto rok − 1980) */
} DATUM;

DATUM dnes, zajtra;
dnes.den = 29;
dnes.mesiac = 11;
dnes.rok = 2012 - 1980;
zajtra.den = dnes.den + 1;
```

#### Príklad: Dátum ako bitové pole aj hexadecimálne číslo (union)

```c
#include <stdio.h>

typedef struct {
    unsigned den    : 5;    /* bity 0–4 */
    unsigned mesiac : 4;    /* bity 5–8 */
    unsigned rok    : 7;    /* bity 9–15 */
} DATUM;

typedef union {
    DATUM        datum;
    unsigned int cislo;
} BITY;

int main(void)
{
    BITY dnes;
    int d, m, r;

    printf("Zadaj dnesny datum [dd mm rrrr]: ");
    scanf("%d %d %d", &d, &m, &r);

    dnes.datum.den = d;
    dnes.datum.mesiac = m;
    dnes.datum.rok = r - 1980;

    printf("datum: %2d.%2d.%4d - cislo: %X hexa\n",
           dnes.datum.den, dnes.datum.mesiac,
           dnes.datum.rok + 1980, dnes.cislo);

    return 0;
}
```

---

## Zhrnutie

| Téma | Kľúčové koncepty |
|------|-------------------|
| **Štruktúry** | `struct`, `typedef`, bodková notácia, šípková notácia `->` |
| **Uniony** | `union`, prekrývanie pamäte, kombinácia s `enum` a `struct` |
| **Spájané zoznamy** | Dynamická alokácia, jednosmerný zoznam, kruhový zoznam |
| **Bitové operácie** | `&`, `|`, `^`, `<<`, `>>`, `~`, bitové polia |

---

[← Prednáška 8](../08-dynamicka-pamat/) | [Hlavná stránka](../../README.md) | [Prednáška 10 →](../10-smernikovy-deep-dive/)
