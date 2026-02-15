# Prednáška 7: Ukazovatele, vyhľadávanie a usporiadanie

> **Predmet:** Algoritmizácia a programovanie
> **Prednášajúci:** Ján Grman
> **Semester:** ZS 2024

---

## Obsah

1. [Ukazovatele – pokračovanie](#1-ukazovatele--pokračovanie)
   - [Referenčný operátor `&`](#11-referenčný-operátor-)
   - [Dereferenčný operátor `*`](#12-dereferenčný-operátor-)
   - [Nulový ukazovateľ `NULL`](#13-nulový-ukazovateľ-null)
   - [Prečo je potrebné určovať typ smerníka](#14-prečo-je-potrebné-určovať-typ-smerníka)
   - [Ukazovateľ na `void`](#15-ukazovateľ-na-void)
   - [Konverzia ukazovateľov](#16-konverzia-ukazovateľov)
   - [Príklad: ukazovateľ na `void`](#17-príklad-ukazovateľ-na-void)
2. [Ukazovateľová aritmetika](#2-ukazovateľová-aritmetika)
   - [Operátor `sizeof`](#21-operátor-sizeof)
   - [Súčet ukazovateľa a celého čísla](#22-súčet-ukazovateľa-a-celého-čísla)
   - [Rozdiel ukazovateľa a celého čísla](#23-rozdiel-ukazovateľa-a-celého-čísla)
   - [Porovnávanie ukazovateľov](#24-porovnávanie-ukazovateľov)
   - [Rozdiel dvoch ukazovateľov rovnakého typu](#25-rozdiel-dvoch-ukazovateľov-rovnakého-typu)
   - [Zhrnutie aritmetických operácií](#26-zhrnutie-aritmetických-operácií)
3. [Algoritmy vyhľadávania](#3-algoritmy-vyhľadávania)
   - [Sekvenčné vyhľadávanie](#31-sekvenčné-vyhľadávanie)
   - [Binárne vyhľadávanie](#32-binárne-vyhľadávanie)
   - [Kompletný program: vyhľadávanie](#33-kompletný-program-vyhľadávanie)
4. [Spojenie usporiadaných polí (Merge)](#4-spojenie-usporiadaných-polí-merge)
5. [Algoritmy usporiadania](#5-algoritmy-usporiadania)
   - [BubbleSort](#51-bubblesort)
   - [MaxSort](#52-maxsort)
   - [InsertSort](#53-insertsort)
   - [QuickSort](#54-quicksort)
6. [Operácie s poľom](#6-operácie-s-poľom)
   - [Vloženie prvku do poľa](#61-vloženie-prvku-do-poľa)
   - [Zmazanie prvku z poľa](#62-zmazanie-prvku-z-poľa)
7. [Hornerova schéma – hodnota polynómu](#7-hornerova-schéma--hodnota-polynómu)
8. [Príklady na doma](#8-príklady-na-doma)
   - [MergeSort](#81-mergesort)
   - [Partial Selection Sort](#82-partial-selection-sort)
   - [Binárne vyhľadávanie – rekurzívne](#83-binárne-vyhľadávanie--rekurzívne)
9. [Kontrola sumy + ladenie (debugging)](#9-kontrola-sumy--ladenie-debugging)

---

## 1. Ukazovatele – pokračovanie

<details>


### 1.1 Referenčný operátor `&`

- Jedinou úlohou ukazovateľa je **ukazovať na premenné** určitého typu.
- Každá premenná je uložená v pamäti na nejakej **adrese**.
- Ak má ukazovateľ ukazovať na premennú, musíme poznať jej adresu.
- Adresu ľubovoľnej premennej získame pomocou **referenčného operátora `&`**.

```c
p = &i;
```

> Príkazom `p = &i;` sme adresu premennej `i` uložili do premennej `p` – teda ukazovateľ `p` ukazuje na premennú `i`.

<details>


### 1.2 Dereferenčný operátor `*`

- Hodnotu premennej, na ktorú ukazovateľ ukazuje, sprístupníme pomocou **unárneho operátora `*`**:

```c
*p
```

<details>


### 1.3 Nulový ukazovateľ `NULL`

Keď ukazovateľ **neukazuje nikam**, používame `NULL`:

- `NULL` je symbolická konštanta definovaná v `stdio.h`:

```c
#define NULL 0
#define NULL ((void *) 0)
```

- Je možné priradiť ho ukazovateľom na **ľubovoľný typ**:

```c
if (p_i == NULL)
    ...
```


### 1.4 Prečo je potrebné určovať typ smerníka

- Všetky ukazovatele majú **rovnakú veľkosť** (sú to pamäťové miesta na uchovanie adresy).
- Prečo musí byť určený typ smerníka, keď všetky sú rovnako veľké?

> Ak nasmerujeme smerník na určitú adresu, vieme, že na tejto adrese **začína** a ďalej spojito pokračuje cez toľko bajtov, koľko je potrebných na uloženie príslušného typu premennej.


### 1.5 Ukazovateľ na `void`

Niekedy vznikne situácia, kedy potrebujeme použiť ukazovateľ, ale **nemusíme vedieť** na aký typ ukazuje. Použijeme **generický ukazovateľ**:

```c
void *p;
```

- Môže ukazovať na **ľubovoľný typ**.


### 1.6 Konverzia ukazovateľov

> ⚠️ **Vyhnúť sa jej!** Ak sa nedá vyhnúť – explicitne pretypovávať.

```c
int *p_i;
char *p_c;

p_c = p_i;            /* nevhodné */
p_c = (char *)p_i;    /* vhodnejšie */
```


### 1.7 Príklad: ukazovateľ na `void`

**Priradenie cez `void *`** – pri priraďovaní je potrebné uviesť typ:

```c
int i;
float f;
void *p_void = &i;       /* p_void ukazuje na i */

*(int *) p_void = 2;     /* nastavenie i na 2 */

p_void = &f;             /* p_void ukazuje na f */
*(float *) p_void = 3.5; /* nastavenie f na 3.5 */
```

**Kompletný príklad** – program vypíše načítané číslo pomocou ukazovateľa na `int` a na `void`:

```c
#include <stdio.h>

int main() {
    int i, *p_int = &i;
    void *p_void = &i;

    printf("Zadajte cele cislo: ");
    scanf("%d", &i);
    printf("i: %d, p_int: %d, p_void: %d\n",
           i, *p_int, (*(int *)p_void));

    return 0;
}
```


---

## 2. Ukazovateľová aritmetika

S ukazovateľmi sa dajú robiť nasledujúce **aritmetické operácie**:

| Operácia | Popis |
|----------|-------|
| `p + n` | Súčet ukazovateľa a celého čísla |
| `p - n` | Rozdiel ukazovateľa a celého čísla |
| `p1 < p2`, `p1 == p2`, ... | Porovnávanie ukazovateľov rovnakého typu |
| `p1 - p2` | Rozdiel dvoch ukazovateľov rovnakého typu |

> Majú zmysel len v rámci bloku dynamicky vytvorenej pamäte (polia). Ostatné operácie nedávajú zmysel.

### 2.1 Operátor `sizeof`

Na vysvetlenie aritmetických operácií s ukazovateľmi potrebujeme operátor `sizeof()`:
- Zistí veľkosť dátového typu v **bajtoch**.
- Vyhodnotí sa v **čase prekladu** (nezdržuje beh).

```c
int i, *p_i;

i = sizeof(p_i);   /* počet bajtov na uloženie ukazovateľa na int – nevyužíva sa */
i = sizeof(*p_i);  /* počet bajtov na uloženie typu int – využíva sa často */
```


### 2.2 Súčet ukazovateľa a celého čísla

```c
int n, *p1, *p2;
/* ... (n = 3), sizeof(*p1) == 2 */

p2 = p1 + n;
/* Interne: p2 = (int *)p1 + sizeof(*p1) * n */
/* p2 = 30 + 2 * 3 = 36 */
```

<details>


**Príklady** (predpokladajme `sizeof(char) == 1`, `sizeof(int) == 2`, `sizeof(float) == 4`):

```c
char  *p_c = 10;   /* p_c + 1 == 11 */
int   *p_i = 20;   /* p_i + 1 == 22 */
float *p_f = 30;   /* p_f + 1 == 34 */
```

> ⚠️ **POZOR!** Na tomto príklade ide o **adresy**, nie o hodnoty.

### 2.3 Rozdiel ukazovateľa a celého čísla

```c
int n, *p1, *p2;
/* ... (n = 3), sizeof(*p2) == 2 */

p1 = p2 - n;
/* Interné: p1 = (int *)p2 - sizeof(*p2) * n */
/* p1 = 36 - 2 * 3 = 30 */
```


### 2.4 Porovnávanie ukazovateľov

**Operátory:** `<`, `<=`, `>`, `>=`, `==`, `!=`

Porovnávanie má zmysel len keď ukazovatele:
- sú **rovnakého typu**
- ukazujú na **ten istý úsek pamäte**

**Výsledok porovnania:**
- Ak je podmienka splnená: `1`
- Inak: `0`

#### Príklad: výpis reťazca pomocou ukazovateľov

```c
char *p1, *p2, str[N];

strcpy(str, "ahoj");
p1 = str;
p2 = p1;

while (p2 < p1 + N && *p2 != '\0')
    printf("%c", *p2++);
```

> Vypisuje znaky, pokiaľ nepresiahne dĺžku pridelenej pamäte premennej `str` **a** pokým nedosiahne koniec zapísaného slova.

<details>


#### Porovnávanie ukazovateľov s konštantou `NULL`

Bez explicitného pretypovávania. `p = NULL` znamená, že **neukazuje na žiadne zmysluplné miesto** v pamäti:

```c
int n, *p;
/* ... */

if (n >= 0)
    p = alokuj(n);
else
    p = NULL;

/* ... */

if (p != NULL)
    /* ... */
```

### 2.5 Rozdiel dvoch ukazovateľov rovnakého typu

```c
int n, *p1, *p2;
/* ... */
n = p1 - p2;
/* Interné: n = ((int *)p1 - (int *)p2) / sizeof(*p1) */
```

**Príklad** – ak je v bloku pamäte `'?'`, vypíše pozíciu, inak `-1`:

```c
char *p1, *p2, str[N];

p1 = str;
for (p2 = p1; p2 < p1 + N && *p2 != '?'; p2++)
    ;
printf("%d", (p2 < p1 + N) ? (p2 - p1 + 1) : -1);
```


### 2.6 Zhrnutie aritmetických operácií

Aritmetické operácie s ukazovateľmi majú zmysel len vtedy, keď:
- sú ukazovatele na **rovnaký typ**
- ukazujú na **ten istý úsek pamäte**

> OS nezaručí, že neskôr alokovaný blok bude na vyššej adrese.


---

## 3. Algoritmy vyhľadávania

<details>


Program načíta do poľa **usporiadanú postupnosť čísel** a hodnotu, ktorú chce v postupnosti (v poli) vyhľadať (nájsť jej index). Použije **sekvenčné** a **binárne** vyhľadávanie.

### 3.1 Sekvenčné vyhľadávanie

- Najjednoduchšie vyhľadávanie.
- Od začiatku poľa postupne zväčšuje index, pokým nepríde na hodnotu väčšiu alebo rovnú, alebo pokým nepríde na koniec poľa.
- **Neefektívne** pre veľké polia.

```c
int sekvencne(int pole[], int n, int x)
{
    int i = 0;

    while (i < n && pole[i] < x)
        i++;

    if (i < n && pole[i] == x)
        return i;

    return -1;
}
```

### 3.2 Binárne vyhľadávanie

Nájdenie stredu intervalu – ak je hľadaná hodnota menšia ako hodnota stredného prvku → hľadanie v **ľavej polovici**, inak v **pravej polovici**.

<details>


```c
int binarne(int pole[], int n, int x)
{
    int m, l = 0, r = n - 1;

    while (l <= r) {
        m = (l + r) / 2;

        if (x == pole[m])
            return m;
        if (x < pole[m])
            r = m - 1;
        else
            l = m + 1;
    }

    if (pole[m] == x)
        return m;
    else
        return -1;
}
```

### 3.3 Kompletný program: vyhľadávanie

```c
#include <stdio.h>
#include <stdlib.h>

int sekvencne(int pole[], int n, int x);
int binarne(int pole[], int n, int x);

int main()
{
    int p[100], i, n, x, vysl;
    char c;

    printf("Zadaj pocet prvkov pola (<100): ");
    scanf("%d", &n);

    if (n >= 100) {
        printf("Prilis velky pocet prvkov...\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    printf("Zadajte hodnotu, ktora sa ma vyhladat: ");
    scanf("%d", &x);
    while (getchar() != '\n');

    printf("Vyhladavat Binarne alebo Sekvencne? [b/s]: ");
    c = getchar();
    printf("%c\n", c);

    if ((c = tolower(c)) == 's')
        vysl = sekvencne(p, n, x);
    else if (c == 'b')
        vysl = binarne(p, n, x);
    else {
        printf("Zadali ste nespravnu hodnotu.\n");
        return 1;
    }

    if (vysl > -1)
        printf("Index hladanej hodnoty je %d.\n", vysl);
    else
        printf("Hladana hodnota sa v poli nenachadza.\n");

    return 0;
}
```

---

## 4. Spojenie usporiadaných polí (Merge)

Program spojí usporiadané polia celých čísel `A` a `B` do `A` tak, aby výsledok bol opäť **usporiadaný** (predpokladáme, že sa do `A` všetky hodnoty zmestia):

```c
void merge(int A[], int m, int B[], int n)
{
    while (m > 0 && n > 0) {
        if (A[m - 1] > B[n - 1]) {
            A[m + n - 1] = A[m - 1];
            m--;
        } else {
            A[m + n - 1] = B[n - 1];
            n--;
        }
    }

    while (n > 0) {
        A[m + n - 1] = B[n - 1];
        n--;
    }
}
```

---

## 5. Algoritmy usporiadania

Usporiadanie poľa čísel (od najmenšieho po najväčšie) – rôzne algoritmy s **rôznou efektivitou**:

| Algoritmus | Zložitosť | Poznámka |
|------------|-----------|----------|
| **BubbleSort** | O(n²) | Najmenej efektívne |
| **MaxSort** | O(n²) | Menej výmen ako BubbleSort |
| **InsertSort** | O(n²) | Efektívne pre malé / takmer usporiadané polia |
| **QuickSort** | O(n log n) priem. | Rýchle, oplatí sa pre veľké polia, rekurzia |

<details>


### 5.1 BubbleSort

- Porovnávanie hodnôt dvoch **susedných buniek** poľa:
  - Do bunky s nižším indexom → menšie z nich
  - Do bunky s vyšším indexom → väčšie z nich
- Po jednom prechode poľom sa **maximálny prvok** dostane na koniec poľa, potom ostáva usporiadať N−1 prvkov.
- **Najmenej efektívne.**

#### Implementácia

```c
void vymen(int *x, int *y)
{
    int pom = *x;
    *x = *y;
    *y = pom;
}

void bubblesort(int a[], int n)
{
    int i, j;

    for (i = n; i > 1; i--)
        for (j = 1; j < i; j++)
            if (a[j - 1] > a[j])
                vymen(&a[j - 1], &a[j]);
}
```

> V úseku `0...i` „vybubláme" najväčší prvok nakoniec.

<details>


### 5.2 MaxSort

- Nájdi v úseku **maximálny prvok**, vymeň ho s posledným prvkom, skráť usporiadavané pole o 1 – pokým nie je jednoprvkové.
- Porovnanie s BubbleSort-om: **rovnako porovnávaní**, ale **menej výmen**.

#### Implementácia

```c
void maxsort(int a[], int n)
{
    int i, j, max;

    for (i = n - 1; i > 0; i--) {
        max = 0;
        for (j = 1; j <= i; j++)
            if (a[j] > a[max])
                max = j;

        if (i != max)
            vymen(&a[max], &a[i]);
    }
}
```

> V úseku `0...i` nájdeme maximum. Ak maximum z úseku `0...i` nie je `i`-ty prvok, vymeníme ich.

### 5.3 InsertSort

- Časť poľa je **usporiadaná** a vsunie sa do nej prvok tak, aby pole zostalo usporiadané.

<details>


#### Implementácia

```c
void insertsort(int a[], int n)
{
    int i, j, pom;

    for (i = 1; i < n; i++) {
        pom = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > pom) {
            a[j + 1] = a[j--];
        }

        a[j + 1] = pom;
    }
}
```

> Úsek `0..i-1` je usporiadaný, vsunieme `a[i]` tak, aby zostal usporiadaný. Cyklus `while` hľadá vhodné miesto pre prvok `a[i]`.

### 5.4 QuickSort

- Princíp **rozdeľuj a panuj** (divide and conquer):
  1. Z poľa sa vyberie **pivot** (napr. prvý prvok poľa).
  2. Podľa pivota rozdelíme vstupné pole na tri časti:
     - Čísla **menšie** ako pivot
     - **Pivot** samotný
     - Čísla **väčšie** ako pivot
  3. Rovnakým spôsobom usporadúvame časti (1) a (3).
- Využíva **rekurziu**.
- **Rýchle** – oplatí sa pre veľké polia.

<details>


#### Implementácia

```c
int rozdel(int a[], int l, int r)
{
    int i, j;
    int pivot = a[l];

    i = l;
    j = r + 1;

    do {
        do ++i; while (a[i] <= pivot && i <= r);
        do --j; while (a[j] > pivot);

        if (i < j)
            vymen(&a[i], &a[j]);
    } while (i < j);

    vymen(&a[l], &a[j]);
    return j;
}

void quickSort(int a[], int l, int r)
{
    int j;

    if (l < r) {
        j = rozdel(a, l, r);
        quickSort(a, l, j - 1);
        quickSort(a, j + 1, r);
    }
}
```

---

## 6. Operácie s poľom

### 6.1 Vloženie prvku do poľa

Program načíta do poľa celé čísla a **vloží** zadané číslo na zadanú pozíciu:

```c
#include <stdio.h>

int main()
{
    int a[50], velkost, cislo, i, poz;

    printf("Zadajte velkost pola: ");
    scanf("%d", &velkost);

    printf("Zadajte %d prvkov pola:\n", velkost);
    for (i = 0; i < velkost; i++)
        scanf("%d", &a[i]);

    printf("Zadajte poziciu a cislo na vlozenie: ");
    scanf("%d %d", &poz, &cislo);

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

### 6.2 Zmazanie prvku z poľa

Program načíta do poľa celé čísla a **vymaže** číslo zo zadanej pozície:

```c
#include <stdio.h>

int main()
{
    int a[50], i, poz, velkost;

    printf("Zadajte pocet prvkov pola (<=50): ");
    scanf("%d", &velkost);

    printf("Zadajte %d prvkov pola:\n", velkost);
    for (i = 0; i < velkost; i++)
        scanf("%d", &a[i]);

    printf("Zadajte poziciu na vymazanie prvku: ");
    scanf("%d", &poz);

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

---

## 7. Hornerova schéma – hodnota polynómu

Program načíta koeficienty polynómu a hodnotu premennej `x` a vypočíta hodnotu polynómu v bode `x`.

**Efektívny algoritmus** znižujúci na minimum počet násobení:

$$a_0 + a_1 x + a_2 x^2 + \ldots + a_{n-1} x^{n-1} + a_n x^n = a_0 + x(a_1 + x(a_2 + x(\ldots + x(a_{n-1} + a_n x)\ldots)))$$

Polynóm stupňa $N$ tak môže byť vyhodnotený len s použitím:
- $N - 1$ operácií **násobenia**
- $N$ operácií **sčítania**

#### Implementácia

```c
#include <stdio.h>
#include <stdlib.h>

float horner(float p[], int n, float x);
void nacitaj(float p[], int n);

int main()
{
    int n;
    float x, p[100];

    printf("Zadajte stupen polynomu: ");
    scanf("%d", &n);
    n++;

    if (n > 100)
        return 0;

    nacitaj(p, n);

    printf("Zadajte hodnotu premennej x: ");
    scanf("%f", &x);

    printf("Hodnota polynomu je: %f\n", horner(p, n, x));

    return 0;
}

float horner(float p[], int n, float x)
{
    int i;
    float v = p[n - 1];

    for (i = n - 2; i >= 0; i--)
        v = x * v + p[i];

    return v;
}

void nacitaj(float p[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("p[%d]: ", i);
        scanf("%f", &p[i]);
    }
}
```

---

## 8. Príklady na doma


### 8.1 MergeSort

- Rozdelenie n-prvkového zoznamu na polovice (**rekurzívne**) – až na n 1-prvkových zoznamov (1-prvkové zoznamy sú usporiadané).
- Opakovanie spájania podzoznamov a vytváranie tak dlhších usporiadaných podzoznamov, až pokým nezostane 1 zoznam, ktorý je **usporiadaný**.

<details>


#### `CopyArray` – prekopírovanie obsahu poľa B do A (od `iMin` po `iMax-1`)

```c
void CopyArray(int B[], int iMin, int iMax, int A[])
{
    int k;
    for (k = iMin; k < iMax; k++)
        A[k] = B[k];
}

void MergeSort(int A[], int B[], int n)
{
    SplitMerge(A, 0, n, B);
}
```

> Aby sa dal algoritmus volať rekurzívne pre rôzne podčasti poľa, potrebujeme aj dolný index (pre celé pole voláme s `0`).

#### `SplitMerge` – rekurzívne rozdeľuj a spájaj

```c
void SplitMerge(int A[], int iMin, int iMax, int B[])
{
    int iStred;

    if (iMax - iMin < 2)
        return;    /* 1-prvkové pole je usporiadané */

    iStred = (iMax + iMin) / 2;

    SplitMerge(A, iMin, iStred, B);
    SplitMerge(A, iStred, iMax, B);
    Merge(A, iMin, iStred, iMax, B);
    CopyArray(B, iMin, iMax, A);
}
```

> **Rekurzívna vetva:**
> 1. Rozdeľ na polovice
> 2. Usporiadaj ľavú polovicu
> 3. Usporiadaj pravú polovicu
> 4. Spoj usporiadané polovice (do B)
> 5. Prekopíruj usporiadané do A

#### `Merge` – spájanie dvoch usporiadaných podpolí

Spájame ľavú časť A (index `i0`: `iMin` – `iStred-1`) a pravú časť A (index `i1`: `iStred` – `iMax-1`) a zapisujeme do poľa B:

```c
void Merge(int A[], int iMin, int iStred, int iMax, int B[])
{
    int i0, i1, j;
    i0 = iMin;
    i1 = iStred;

    for (j = iMin; j < iMax; j++) {
        if (i0 < iStred && (i1 >= iMax || A[i0] <= A[i1])) {
            B[j] = A[i0];
            i0++;
        } else {
            B[j] = A[i1];
            i1++;
        }
    }
}
```

> Ak v ľavej časti ešte sú prvky **a** (buď v pravej časti už nie sú prvky, alebo v ľavej časti je menší alebo rovný prvok) → berieme z ľavej časti.

### 8.2 Partial Selection Sort

Nájdenie **k-teho najmenšieho prvku** poľa:

```c
int select(int pole[], int n, int k)
{
    int i, j, minIndex, minHod;

    for (i = 0; i < k; i++) {
        minIndex = i;
        minHod = pole[i];

        for (j = i + 1; j <= n; j++) {
            if (pole[j] < minHod) {
                minIndex = j;
                minHod = pole[j];
            }
        }

        vymen(&pole[i], &pole[minIndex]);
    }

    return pole[k - 1];
}
```

### 8.3 Binárne vyhľadávanie – rekurzívne

```c
int binarneRek(int A[], int k, int iMin, int iMax)
{
    if (iMax < iMin)
        return -1;
    else {
        int iStred = (iMin + iMax) / 2;

        if (A[iStred] > k)
            return binarneRek(A, k, iMin, iStred - 1);
        else if (A[iStred] < k)
            return binarneRek(A, k, iStred + 1, iMax);
        else
            return iStred;
    }
}
```

---

## 9. Kontrola sumy + ladenie (debugging)

Program zistí, či prvé číslo v súbore `suma.txt` je súčtom čísel, ktoré sú za ním. Použitie **základného** a **podrobného ladenia** (príklad z cvičení).

```c
#include <stdio.h>
#include <stdlib.h>

#define LADENIE_ZAKLADNE
#define LADENIE_PODROBNE

int main()
{
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

> **Tip:** Makrá `LADENIE_ZAKLADNE` a `LADENIE_PODROBNE` umožňujú rýchlo zapnúť/vypnúť ladiace výpisy bez zmeny logiky programu. Stačí zakomentovať príslušný `#define`.

---

[← Prednáška 6](../06-retazce-ukazovatele/) | [Hlavná stránka](../../README.md) | [Prednáška 8 →](../08-dynamicka-pamat/)
