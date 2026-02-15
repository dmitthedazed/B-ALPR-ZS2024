# Prednáška 3: Cykly a mnohonásobné vetvenie

> **Predmet:** Algoritmizácia a programovanie  
> **Prednášajúci:** Ján Grman

---

## Obsah

1. [Opakovanie](#1-opakovanie)
   - [Operátory](#príklad-operátory)
   - [Ternárny operátor](#príklad-ternárny-operátor)
   - [Príkaz if](#príklad-if)
   - [Priestupný rok](#príklad-priestupný-rok)
2. [Iteračné príkazy – cykly](#2-iteračné-príkazy--cykly)
3. [Cyklus while](#3-cyklus-while)
   - [Príklady s while](#príklady-s-while)
   - [Prázdne telo cyklu](#prázdne-telo-cyklu)
4. [Cyklus do-while](#4-cyklus-do-while)
5. [Cyklus for](#5-cyklus-for)
   - [Priebeh for-cyklu](#priebeh-for-cyklu)
   - [Prepísanie for na while](#prepísanie-for-na-while)
   - [Príklady s for](#príklady-s-for)
6. [Odporúčania pre cykly](#6-odporúčania-pre-cykly)
7. [Praktické príklady s cyklami](#7-praktické-príklady-s-cyklami)
   - [Výpis čísel](#výpis-čísel-od-1-po-n)
   - [Počet deliteľov](#počet-deliteľov)
   - [Výpis písmen](#výpis-písmen-opakovane)
   - [Súčty čísel](#súčty-čísel-od-1-do-i)
   - [Hviezdičkovanie](#hviezdičkovanie)
   - [Príklad: break a continue](#príklad-break-a-continue)
8. [Mnohonásobné vetvenie – switch](#8-mnohonásobné-vetvenie--switch)
   - [Syntax switch](#syntax-príkazu-switch)
   - [Viaceré hodnoty v jednej vetve](#viaceré-hodnoty-v-jednej-vetve)
   - [Príklady so switch](#príklady-so-switch)
   - [Poznámky k switch](#poznámky-k-príkazu-switch)
9. [Príkazy goto a return](#9-príkazy-goto-a-return)
10. [Časté chyby](#10-časté-chyby)
11. [Záverečné príklady](#11-záverečné-príklady)
12. [Ďalšie námety na precvičenie](#12-ďalšie-námety-na-precvičenie)

---

## 1. Opakovanie

### Príklad: operátory

Čo vypíše nasledujúci program? Aké budú hodnoty premenných?

```c
#include <stdio.h>

int main() {
    int a = 2, b = 3, c = 4, d = 5, e = 6;

    printf("%d\n", e / --a * b++ / c++);
    printf("a: %d, b: %d, c: %d, d: %d, e: %d\n", a, b, c, d, e);
    a %= b = d = 1 + e / 2;
    printf("a: %d, b: %d, c: %d, d: %d, e: %d\n", a, b, c, d, e);

    return 0;
}
```

**Výstup:**

```
4
a: 1, b: 4, c: 5, d: 5, e: 6
a: 1, b: 4, c: 5, d: 4, e: 6
```

---

### Príklad: ternárny operátor

Program načíta 2 reálne čísla a pomocou ternárneho operátora vypíše ich maximum.

```c
#include <stdio.h>

int main() {
    float x, y;

    printf("Zadajte 2 realne cisla: ");
    scanf("%f %f", &x, &y);              /* načítavanie na adresu premennej: & */
    printf("%.2f\n", (x > y) ? x : y);
    return 0;
}
```

> **Pozor:** Pri `scanf` nezabudnite na operátor `&` (adresa premennej).

---

### Príklad: if

Program načíta znak z klávesnice a ak je to číslica, vypíše správu.

```c
#include <stdio.h>

int main() {
    char c;
    if ((c = getchar()) >= '0' && c <= '9')
        printf("cislica");
    return 0;
}
```

> **Poznámka:** Priradenie `c = getchar()` musí byť uzátvorkované, lebo `!=` (resp. `>=`) má väčšiu prioritu ako `=`.

---

### Príklad: priestupný rok

Program zistí, či zadaný rok je priestupný.

**Pravidlá:**

| Podmienka | Výsledok |
|-----------|----------|
| Rok je deliteľný 400 | Priestupný (napr. 1600, 2000) |
| Rok je deliteľný 100 (ale nie 400) | Nie je priestupný |
| Rok je deliteľný 4 (ale nie 100) | Priestupný (napr. 2004, 2008) |
| Inak | Nie je priestupný |

**Pseudokód:**

```
IF rok modulo 400 je 0
    THEN priestupny
ELSE IF rok modulo 100 je 0
    THEN nie_je_priestupny
ELSE IF rok modulo 4 je 0
    THEN priestupny
ELSE nie_je_priestupny
```

**Riešenie jednou podmienkou:**

```c
#include <stdio.h>

int main() {
    int rok;

    printf("Zadajte rok: ");
    scanf("%d", &rok);

    if (((rok % 4 == 0) && (rok % 100 != 0)) || (rok % 400 == 0))
        printf("%d je priestupny rok", rok);
    else
        printf("%d nie je priestupny rok", rok);

    return 0;
}
```

---

## 2. Iteračné príkazy – cykly

Cykly umožňujú opakovať vykonávanie príkazu alebo bloku príkazov. Jazyk C poskytuje tri typy cyklov:

| Cyklus | Charakteristika |
|--------|----------------|
| `while` | Testuje podmienku **pred** vykonaním tela |
| `do-while` | Testuje podmienku **po** vykonaní tela (vykoná sa aspoň raz) |
| `for` | Používa sa, keď dopredu poznáme počet iterácií |

Vo všetkých typoch cyklov je možné použiť príkazy na zmenu behu cyklu:

- **`break`** – ukončuje najvnútornejšiu slučku a opúšťa cyklus
- **`continue`** – skáče na koniec najvnútornejšej slučky a vynúti ďalšiu iteráciu


---

## 3. Cyklus while

Cyklus `while` iteruje, pokým platí podmienka. Testuje podmienku **pred** prechodom cyklu – cyklus teda nemusí prebehnúť ani raz.

```c
while (podmienka)
    prikaz;
```

> **Dôležité:** Používame ho, keď ukončovacia podmienka závisí na nejakom príkaze v tele cyklu. Ak by nezávisela, podmienka by bola splnená stále a cyklus by bol nekonečný.


### Príklady s while

**Príklad 1:** Program číta znaky z klávesnice, opisuje ich na obrazovku, medzery ignoruje a skončí po prečítaní znaku `*`.

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

> **Poznámka:** Načítanie znaku `c = getchar()` musí byť uzátvorkované, lebo `!=` má väčšiu prioritu ako `=`.

**Príklad 2:** Rovnaký program s použitím `break` a `continue`:

```c
#include <stdio.h>

int main() {
    int c;
    while (1) {
        if ((c = getchar()) == ' ')
            continue;
        if (c == '*')
            break;
        putchar(c);
    }
    return 0;
}
```

### Prázdne telo cyklu

Telo cyklu môže byť aj prázdne – napríklad na vynechanie medzier na vstupe:

```c
while (getchar() == ' ')
    ;
```

Alebo preskočí všetky biele znaky na vstupe:

```c
while ((c = getchar()) == ' ' || c == '\t' || c == '\n')
    ;
```

---

## 4. Cyklus do-while

Cyklus `do-while` testuje podmienku **po** prechode cyklu – cyklus sa vykoná **aspoň raz**. Program opúšťa cyklus pri nesplnenej podmienke.

```c
do {
    prikazy;
} while (podmienka);
```


**Príklad:** Program číta znaky z klávesnice, opisuje ich na obrazovku, medzier si nevšíma a skončí po prečítaní `*`, na konci vypíše `*`.

```c
#include <stdio.h>

int main() {
    int c;
    do {
        if ((c = getchar()) != ' ')
            putchar(c);
    } while (c != '*');
    return 0;
}
```

---

## 5. Cyklus for

Cyklus `for` sa používa, keď dopredu vieme počet prechodov cyklom.

```c
for (vyraz_start; vyraz_stop; vyraz_iter)
    prikaz;
```

- **`vyraz_start`** – inicializácia (vykoná sa raz na začiatku)
- **`vyraz_stop`** – podmienka ukončenia (keď nie je splnená, cyklus končí)
- **`vyraz_iter`** – iteračný výraz (vykoná sa po každom prechode)


**Príklad:** Napíš 100× „I will not cut corners":

```c
for (i = 1; i <= 100; i++)
    printf("%d: I will not cut corners.\n", i);
```

### Priebeh for-cyklu

Výrazy `vyraz_start`, `vyraz_stop`, `vyraz_iter` nemusia spolu súvisieť a nemusia byť vôbec uvedené – v každom prípade treba uviesť bodkočiarku.

| Krok | Popis |
|------|-------|
| 1. | Na začiatku sa vyhodnotí `vyraz_start` |
| 2. | Otestuje sa, či je `vyraz_stop` pravdivý – ak nie, cyklus skončí |
| 3. | Ak áno, vykoná sa `prikaz` a vykoná sa `vyraz_iter` |
| 4. | Pokračuje sa krokom 2. |

> **Poznámka:** V cykle `for` sa dajú použiť `break` a `continue`.

### Prepísanie for na while

Cyklus `for` sa dá vždy prepísať ako cyklus `while`:

```c
/* for verzia */
for (vyraz_start; vyraz_stop; vyraz_iter)
    prikaz;

/* ekvivalentný while */
vyraz_start;
while (vyraz_stop) {
    prikaz;
    vyraz_iter;
}
```

### Príklady s for

**Klasické a odporúčané použitie:**

```c
int i;
for (i = 1; i <= 10; i++)
    printf("%d ", i);
```

**Využitie inicializácie v definícii** (nevhodné – nie je všetko spolu):

```c
int i = 1;
for ( ; i <= 10; i++)
    printf("%d ", i);
```

**Riadiaca premenná menená v tele cyklu** (nevhodné):

```c
int i = 1;
for ( ; i <= 10; )
    printf("%d ", i++);
```

**Operátor čiarka v inicializácii** (vhodné pri inicializácii, nevhodné pri výpočte):

```c
int i, sum;
for (i = 1, sum = 0; i <= 10; sum += i, i++)
    printf("%d ", i);
```

**Ľubovoľný krok iterácie:**

```c
int i, sucin;
for (i = 3, sucin = 1; i <= 9; i += 2)
    sucin *= i;
```

> Cyklus môže meniť riadiacu premennú ľubovoľným spôsobom (nielen `i++`).

---

## 6. Odporúčania pre cykly

- Mať len **jednu riadiacu premennú**
- Riadiaca premenná má byť ovplyvňovaná len v **riadiacej časti cyklu**, nie v jeho tele
- Inicializácia v **inicializačnej časti**
- Ak má cyklus prázdne telo, bodkočiarku dať **na nový riadok**
- Príkaz `continue` je vhodné nahradiť konštrukciou `if-else`
- Príkaz `break` – len v najnutnejších prípadoch, najlepšie maximálne na jednom mieste
- Cykly `while` a `for` sú prehľadnejšie ako `do-while`, preto ich **uprednostňujte**


---

## 7. Praktické príklady s cyklami

### Výpis čísel od 1 po n

Tri ekvivalentné riešenia pomocou rôznych cyklov:

```c
#include <stdio.h>

int main() {
    int i, n;
    scanf("%d", &n);

    /* --- for --- */
    for (i = 1; i <= n; i++)
        printf("%d\n", i);

    /* --- while --- */
    i = 1;
    while (i <= n) {
        printf("%d\n", i);
        i++;
    }

    /* --- do-while (s kontrolou) --- */
    if (n >= 1) {
        i = 1;
        do {
            printf("%d\n", i++);
        } while (i <= n);
    }

    return 0;
}
```

> **Pozor:** `do-while` vždy vykoná prvý beh cyklom. Podmienka `if (n >= 1)` zabezpečí, že keď `n < 1`, cyklus sa nevykoná ani raz.

---

### Počet deliteľov

Výpis počtu deliteľov zadaného čísla zo zadaného intervalu.

```c
#include <stdio.h>

int main() {
    int i, int1, int2, del, pocet = 0;

    printf("Zadajte interval a delitel: ");
    scanf("%d %d %d", &int1, &int2, &del);
    for (i = int1; i <= int2; i++)
        if (!(i % del))
            pocet++;
    printf("V <%d, %d> je %d delitelov cisla %d.\n",
        int1, int2, pocet, del);
    return 0;
}
```

---

### Výpis písmen opakovane

Výpis písmen od A po zadané písmeno – zvolený počet krát.

```c
#include <stdio.h>

int main() {
    char c1, c2;
    int i, n;

    printf("Zadajte velke pismeno: ");
    c2 = getchar();
    if (c2 >= 'A' && c2 <= 'Z') {
        printf("Kolkokrat vypisat A - %c? ", c2);
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            for (c1 = 'A'; c1 <= c2; c1++)
                putchar(c1);
            putchar('\n');
        }
    }
    return 0;
}
```

---

### Výpis prvých 1, 2, 3, …, n písmen

```c
#include <stdio.h>

int main() {
    int i, j, n;
    printf("Zadajte pocet: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++)
            putchar('A' + j);
        putchar('\n');
    }
    return 0;
}
```

**Výstup pre n = 5:**

```
A
AB
ABC
ABCD
ABCDE
```

---

### Súčty čísel od 1 do i

Program vypíše súčty 1 + … + i pre všetky i od 1 do n.

```c
#include <stdio.h>

int main() {
    int i, j, n, sucet;
    printf("Zadajte n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sucet = 0;
        for (j = 1; j <= i; j++)
            sucet += j;
        printf("1 - %2d: %2d\n", i, sucet);
    }
    return 0;
}
```

**Výstup pre n = 7:**

```
1 -  1:  1
1 -  2:  3
1 -  3:  6
1 -  4: 10
1 -  5: 15
1 -  6: 21
1 -  7: 28
```

> **Poznámka:** Počet prechodov vnútorným cyklom sa s každou iteráciou vonkajšieho cyklu zvyšuje.

---

### Hviezdičkovanie

#### Hviezdičkovanie 1 – striedavé pozície

Do riadku nakreslí striedavo na každú druhú pozíciu hviezdičku.

```c
#include <stdio.h>

int main() {
    int i, dlzka;
    printf("Zadajte dlzku: ");
    scanf("%d", &dlzka);

    for (i = 1; i <= dlzka; i++)
        if (i % 2)
            putchar(' ');
        else
            putchar('*');
    return 0;
}
```

Výstup pre `dlzka = 8`: `  * * * *`

---

#### Hviezdičkovanie 2 – kríž

Pomocou hviezdičiek nakreslí kríž.

```c
#include <stdio.h>

int main() {
    int dlzka, i, j;
    printf("Zadajte dlzku ramena: ");
    scanf("%d", &dlzka);

    for (i = 1; i <= dlzka * 2 + 1; i++) {
        for (j = 1; j <= dlzka * 2 + 1; j++)
            if (j == dlzka + 1 || i == dlzka + 1)
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }
    return 0;
}
```


---

#### Hviezdičkovanie 3 – šachovnica

```c
#include <stdio.h>

int main() {
    int r, i, j;
    printf("Zadajte rozmer: ");
    scanf("%d", &r);

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= r; j++)
            if ((i % 2 == 0 && j % 2 == 1) ||
                (i % 2 == 1 && j % 2 == 0))
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }
    return 0;
}
```

---

#### Hviezdičkovanie 4 – vzor „tehly"

```c
for (i = 1; i <= r; i++) {
    for (j = 1; j <= r; j++)
        if (i % 2 == 1 && (j % 6 == 1 || j % 6 == 2) ||
            i % 2 == 0 && j % 6 != 1 && j % 6 != 2)
            putchar('*');
        else
            putchar(' ');
    putchar('\n');
}
```

> **Poznámka:** V podmienke sú len zátvorky, ktoré musia byť – operátor `&&` má vyššiu prioritu ako `||`.

---

#### Hviezdičkovanie 5 – štvorec (obrys)

Pomocou hviezdičiek nakreslí štvorec – body (`*`) vnútri, bodky (`.`) na okraji.

```c
#include <stdio.h>

int main() {
    int i, j, r;
    printf("Zadajte rozmer: ");
    scanf("%d", &r);

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= r; j++)
            if ((i > 1) && (i < r) && (j > 1) && (j < r))
                putchar('*');
            else
                putchar('.');
        putchar('\n');
    }
    return 0;
}
```

**Výstup pre r = 4:**

```
....
.**.
.**.
....
```

---

### Príklad: break a continue

```c
#include <stdio.h>

int main() {
    int i;

    for (i = 5; i <= 10; i++) {
        if (i == 8)
            break;
        printf("prvy for – i: %d\n", i);
    }

    for (i = 5; i <= 10; i++) {
        if (i == 8)
            continue;
        printf("druhy for – i: %d\n", i);
    }

    return 0;
}
```

**Výstup:**

```
prvy for – i: 5
prvy for – i: 6
prvy for – i: 7
druhy for – i: 5
druhy for – i: 6
druhy for – i: 7
druhy for – i: 9
druhy for – i: 10
```

> **`break`** ukončí celý cyklus (pri `i == 8` sa prvý cyklus úplne zastaví).  
> **`continue`** preskočí zvyšok tela a pokračuje ďalšou iteráciou (pri `i == 8` sa len nevypíše riadok).

---

## 8. Mnohonásobné vetvenie – switch

Keď máme viac vetiev porovnávajúcich rovnakú premennú s rôznymi hodnotami, namiesto dlhého reťazca `if-else if` použijeme príkaz `switch`:

```c
/* namiesto: */
if (c == 'a')
    ...
else if (c == 'b')
    ...
else if (c == 'c')
    ...
else
    ...
```

### Syntax príkazu switch

```c
switch (vyraz) {
    case hodnota_1: prikaz_1; break;
    ...
    case hodnota_n: prikaz_n; break;
    default: prikaz_def; break;
}
```

**Vlastnosti:**

- Výraz, podľa ktorého sa rozhoduje, musí byť typu `int`
- Každá vetva musí byť ukončená príkazom `break`
- V každej vetve môže byť viac príkazov – nie je nutné ich uzatvárať do zátvoriek `{}`
- Vetva `default` sa vykonáva, keď žiadna iná vetva nie je splnená


### Viaceré hodnoty v jednej vetve

Ak je viac hodnôt, pre ktoré chceme vykonať rovnaký príkaz, zreťazíme `case` návesti:

```c
switch (vyraz) {
    case h_1:
    case h_2:
    case h_3: prikaz_123; break;
    case h_4: prikaz_4; break;
    default:  prikaz_def; break;
}
```

> **Dôležité:** Ak vetva nie je ukončená príkazom `break`, program neopustí `switch`, ale spracováva nasledujúcu vetvu v poradí – až po najbližšie `break` alebo koniec `switch` (tzv. **fall-through**).

### Príklady so switch

**Príklad – bez `break` (fall-through):**

Časť programu vypíše znaky `123` po stlačení `'a'`, `'b'` alebo `'c'`; po stlačení `'d'` vypíše `23`; po stlačení inej klávesy vypíše len `3`.

```c
switch (getchar()) {
    case 'a':
    case 'b':
    case 'c': putchar('1');    /* fall-through */
    case 'd': putchar('2');    /* fall-through */
    default:  putchar('3');
}
```

**Príklad – s `break` (správne):**

Každá vetva vypíše len svoju hodnotu.

```c
switch (getchar()) {
    case 'a':
    case 'b':
    case 'c': putchar('1'); break;
    case 'd': putchar('2'); break;
    default:  putchar('3'); break;
}
```

---

### Poznámky k príkazu switch

- Príkaz `break` v kontexte `switch`:
  - Ruší najvnútornejšiu slučku cyklu, **alebo** ukončuje príkaz `switch`
  - Treba dávať pozor na cyklus vo vnútri `switch` a naopak
- Vetva `default` nemusí byť posledná (ale z konvencie sa tam dáva)
- Ak je vetva `default` na konci, `break` nie je nutný (dáva sa z konvencie)

**Príklad – `default` na začiatku:**

Aj keď nie je `default` na konci, vykoná sa vtedy, keď nie je splnená žiadna iná vetva:

```c
switch (getchar()) {
    default:
        printf("Nestlacil si ani '1' ani '2'.\n");
        break;
    case '1':
        printf("Stlacil si '1'.\n");
        break;
    case '2':
        printf("Stlacil si '2'.\n");
        break;
}
```

---

**Príklad – switch v kombinácii s while (nevhodné):**

Nasledujúci kód mieša `break` a `continue` zo `switch` a `while` – je neprehľadný:

```c
int c = 0;
while (c != '*') {
    switch (c = getchar()) {
        case ' ':
        case '\t':
            putchar('#');
            continue;       /* continue patrí WHILE cyklu! */
        case '*':
            break;          /* break patrí SWITCH! */
        default:
            putchar(c);
            break;
    }
}
```

> **Pozor:** Tento kód mieša veci, ktoré nemajú nič spoločné – `break` vo `switch` neukončí `while` cyklus, `continue` vo `switch` sa vzťahuje na vonkajší `while`.

**Lepšie riešenie:**

```c
while ((c = getchar()) != '*') {
    switch (c) {
        case ' ':
        case '\t':
            putchar('#');
            break;
        default:
            putchar(c);
            break;
    }
}
```

**Ešte kratšie (ale menej prehľadné):**

```c
while ((c = getchar()) != '*') {
    switch (c) {
        case ' ':
        case '\t':
            c = '#';
        default:
            putchar(c);
    }
}
```

---

## 9. Príkazy goto a return

### Príkaz goto

> **Príkazu `goto` sa dá v štrukturovanom jazyku (ako je C) vždy vyhnúť → nepoužívať!**

Ak ho niekto chce používať, musí si ho naštudovať (Herout, 3. vydanie str. 59; 4. vydanie str. 65).

### Príkaz return

- Ukončí práve sa vykonávajúcu funkciu, ktorá ho obsahuje
- Vo funkcii `main()` – ukončí sa program
- Často sa pomocou `return` vracia hodnota → neskôr

```c
void vypis(int k) {
    if (k == 0)
        return;

    /* výpočet, kde je treba nenulové číslo */
    printf("k: %d, ...", k);
}
```

---

## 10. Časté chyby

| Chybný kód | Problém |
|-------------|---------|
| `if (i == 1) then` | `then` nie je kľúčové slovo jazyka C |
| `if i == 1` | Chýbajú zátvorky okolo podmienky |
| `if (i == 1)  y = x  else  x++;` | Chýba bodkočiarka za `y = x` |
| `if (i = 1)` | Priradenie `=` namiesto porovnania `==` |
| `if (c = getchar() == '*')` | Chýbajú zátvorky: má byť `(c = getchar()) == '*'` |
| `while (x == 1) do` | Za `while` nie je `do` |
| `for (i = 0; i < 10; i++);  x += i;` | Bodkočiarka za `for` – telo cyklu je prázdne, `x += i` sa vykoná len raz |


---

## 11. Záverečné príklady

### Príklad: switch v cykle for

```c
#include <stdio.h>

int main() {
    int i;
    for (i = 3; i < 13; i++)
        switch (i) {
            case 3:  printf("Hodnota je 3\n"); break;
            case 4:  printf("Hodnota je 4\n"); break;
            case 5:
            case 6:
            case 7:
            case 8:  printf("Hodnota je medzi 5 a 8\n"); break;
            case 11: printf("Hodnota je 11\n"); break;
            default: printf("Nedefinovana hodnota\n");
        }
    return 0;
}
```

**Výstup:**

```
Hodnota je 3
Hodnota je 4
Hodnota je medzi 5 a 8
Hodnota je medzi 5 a 8
Hodnota je medzi 5 a 8
Hodnota je medzi 5 a 8
Nedefinovana hodnota
Nedefinovana hodnota
Hodnota je 11
Nedefinovana hodnota
```

---

### Príklad: hádanie magického čísla

Program náhodne vyberie magické číslo. Používateľ ho háda, pokým ho nezistí alebo neukončí program zadaním čísla `-1`.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int magicke;
    int tip;
    magicke = rand();

    printf("Vas tip na magicke cislo: ");
    scanf("%d", &tip);

    while (tip != magicke && tip != -1) {
        if (tip > magicke)
            printf("\ntip je prilis vysoky, zadajte dalsi: ");
        else
            printf("\ntip je prilis nizky, zadajte dalsi:\n");
        scanf("%d", &tip);
    }

    if (tip == magicke) {
        printf("*** BINGO! ***");
        printf(" %d je magicke cislo.\n", magicke);
    } else {
        printf("Skus nabuduce.\n");
    }

    return 0;
}
```

---

### Príklad: trojuholník z hviezdičiek

```c
#include <stdio.h>

int main() {
    int i, j, n;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (i >= j)
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }
    return 0;
}
```

**Výstup pre n = 5:**

```
*
**
***
****
*****
```


---

### Variácie trojuholníka – vplyv umiestnenia for-cyklu

#### Pridaný vonkajší for (2× pod seba)

```c
for (k = 1; k <= 2; k++)
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (i >= j) putchar('*');
            else putchar(' ');
        putchar('\n');
    }
```

Výsledok: trojuholník sa vykreslí 2× pod seba.

#### Pridaný stredný for (2× vedľa seba)

```c
for (i = 1; i <= n; i++) {
    for (k = 1; k <= 2; k++)
        for (j = 1; j <= n; j++)
            if (i >= j) putchar('*');
            else putchar(' ');
    putchar('\n');
}
```

Výsledok: každý riadok sa vykreslí 2× vedľa seba.

#### Pridaný vnútorný for (zdvojenie znakov)

```c
for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
        for (k = 1; k <= 2; k++)
            if (i >= j) putchar('*');
            else putchar(' ');
    putchar('\n');
}
```

Výsledok: každý znak sa zdvojí.

> **Úloha:** Nakreslite trojuholníky vedľa seba (4×) aj pod seba (2×).


---

## 12. Ďalšie námety na precvičenie

- Od zadaného písmena vypísať písmená do konca abecedy
- Od zadaného písmena vypísať k písmen
- Načíta sa celé číslo n, zadá sa n čísel a vypíše sa ich súčet
- Vypísať čísla od 1 po zvolené n vždy oddelené znakom `+` (a medzerami) a na konci riadku pridať `=` a ich súčet
- n riadkov: súčet od 1 po 1, v ďalšom riadku od 1 po 2, …, až od 1 po n
- Vypísať čísla od 1 po n tak, že sa vypisujú len čísla deliteľné daným celým číslom k
- Nakresliť pomocou hviezdičiek obrázok X
- Obrázok X opakovať n-krát pod seba
- Obrázok X opakovať m-krát vedľa seba

---


---

[← Prednáška 2](../02-konstanty-operatory/) | [Hlavná stránka](../../README.md) | [Prednáška 4 →](../04-subory/)
