# Prednáška 10: Smerníky — hlboký ponor

> **Predmet:** Algoritmizácia a programovanie
> **Prednášajúci:** Ján Grman
> **Semester:** Zimný semester 2024

---

## Obsah

1. [Premenné a smerníky](#premenné-a-smerníky)
   - [Premenná v pamäti](#premenná-v-pamäti)
   - [Premenná a pointer na ňu](#premenná-a-pointer-na-ňu)
2. [Parametre funkcií a smerníky](#parametre-funkcií-a-smerníky)
   - [Parameter hodnotou](#parameter-hodnotou)
   - [Parameter odkazom](#parameter-odkazom)
   - [Výstupný parameter](#výstupný-parameter)
   - [Kombinácia: hodnota + odkaz](#kombinácia-hodnota--odkaz)
   - [Príklad: výpočet obvodu a obsahu kruhu](#príklad-výpočet-obvodu-a-obsahu-kruhu)
3. [Jednorozmerné polia a smerníky](#jednorozmerné-polia-a-smerníky)
   - [Základy práce s poliami](#základy-práce-s-poliami)
   - [Prístup k prvkom poľa](#prístup-k-prvkom-poľa)
   - [Dynamické pole](#dynamické-pole)
   - [Pole ako parameter funkcie](#pole-ako-parameter-funkcie)
4. [Spájané zoznamy](#spájané-zoznamy)
   - [Záznamy v pamäti](#záznamy-v-pamäti)
   - [Vyhľadávanie – prvý záznam spĺňajúci podmienku](#vyhľadávanie--prvý-záznam-spĺňajúci-podmienku)
   - [Vyhľadávanie – posledný záznam spĺňajúci podmienku](#vyhľadávanie--posledný-záznam-spĺňajúci-podmienku)
   - [Pridanie prvku na pozíciu](#pridanie-prvku-na-pozíciu)

---

## Premenné a smerníky

<details>
<summary>🖼️ Titulný obrázok – Smerníky</summary>

![Smerníky – úvod](images/img-000.png)

</details>

### Premenná v pamäti

Každá premenná má v pamäti svoju **adresu** a **hodnotu**.

```c
#include <stdio.h>

int main() {
    int i;      // premenná i sa v pamäti vytvorila na adrese 15 s nejakou hodnotou
    i = 4;      // premenná i dostala hodnotu 4
}
```

| Dátová oblasť | Adresa | Hodnota |
|---|---|---|
| premenná `i` | 15 | 4 (predtým `?`) |

<details>
<summary>🖼️ Premenná v pamäti</summary>

![Premenná v pamäti](images/img-001.png)

</details>

---

### Premenná a pointer na ňu

Smerník (pointer) je premenná, ktorá obsahuje **adresu** inej premennej.

```c
#include <stdio.h>

int main() {
    int i;          // premenná i na adrese 15
    int *p;         // premenná p na adrese 78

    p = &i;         // p bola naplnená ADRESOU premennej i
    i = 4;

    printf("%d,%d,%d", i, p, *p);
    // Výstup: 4,15,4
    // premenná, jej adresa a hodnota na tej adrese
}
```

| Dátová oblasť | Adresa | Hodnota |
|---|---|---|
| premenná `i` | 15 | 4 |
| smerník `p` | 78 | 15 (adresa `i`) |

> **Poznámka:** `p` ukazuje na rovnakú pamäť ako prezentuje `i`. Operátor `*p` dereferencuje pointer – získa hodnotu na adrese, kam `p` ukazuje.

<details>
<summary>🖼️ Premenná a pointer</summary>

![Premenná a pointer](images/img-002.png)

</details>

---

## Parametre funkcií a smerníky

### Parameter hodnotou

Pri volaní funkcie sa vytvoria **kópie** hodnôt.

```c
int max(int a, int b) {
    return (a > b ? a : b);
}

int main() {
    int x = 3, y = 4, z;
    z = max(x, y);   // a,b sú kópie hodnôt x a y
}
```

| Kontext | Adresa | Hodnota |
|---|---|---|
| `x` v main | 15 | 3 |
| `y` v main | 34 | 4 |
| `z` v main | 38 | 4 (po návrate) |
| `a` vo funkcii | 45 | 3 (kópia) |
| `b` vo funkcii | 57 | 4 (kópia) |

> Funkcia dostane kópie – zmena `a` alebo `b` **neovplyvní** `x` a `y`.

<details>
<summary>🖼️ Volanie hodnotou</summary>

![Volanie hodnotou](images/img-003.png)

</details>

---

### Parameter odkazom

Pri volaní odkazom sa odovzdávajú **adresy** premenných.

```c
int max(int *a, int *b) {
    return (*a > *b ? *a : *b);
}

int main() {
    int x = 3, y = 4, z;
    z = max(&x, &y);   // a,b sú ADRESY premenných x a y
}
```

| Kontext | Adresa | Hodnota |
|---|---|---|
| `x` v main | 15 | 3 |
| `y` v main | 34 | 4 |
| `a` vo funkcii | 45 | 15 (adresa `x`) |
| `b` vo funkcii | 57 | 34 (adresa `y`) |

<details>
<summary>🖼️ Volanie odkazom</summary>

![Volanie odkazom](images/img-004.png)

</details>

---

### Výstupný parameter

Funkcia môže zapísať výsledok priamo do premennej volajúceho cez smerník.

```c
void max(int *a, int *b, int *c) {
    *c = (*a > *b ? *a : *b);
}

int main() {
    int x = 3, y = 4, z;
    max(&x, &y, &z);   // a,b,c sú ADRESY x, y a z
}
```

- Výraz vo funkcii použije adresy – ukazujú na hodnoty 3 a 4
- Číslo 4 sa priradí tam, kam ukazuje `c` (t.j. do premennej `z`)

<details>
<summary>🖼️ Výstupný parameter (všetky odkazom)</summary>

![Výstupný parameter](images/img-005.png)

</details>

---

### Kombinácia: hodnota + odkaz

Vstupné parametre hodnotou, výstupný parameter odkazom.

```c
void max(int a, int b, int *c) {
    *c = (a > b ? a : b);
}

int main() {
    int x = 3, y = 4, z;
    max(x, y, &z);   // a,b sú kópie; c je ADRESA premennej z
}
```

- `a` a `b` sú kópie hodnôt `x` a `y`
- `c` je adresa premennej `z` – výsledok sa priradí kam ukazuje `c`

<details>
<summary>🖼️ Kombinácia hodnota + odkaz</summary>

![Kombinácia](images/img-006.png)

</details>

---

### Príklad: výpočet obvodu a obsahu kruhu

Funkcia `kruh()` vypočíta obvod a obsah kruhu – výsledky vráti cez výstupné parametre (volanie odkazom).

```c
#include <stdio.h>

#define PI 3.14
#define na_druhu(i) ((i) * (i))

void kruh(int r, float *o, float *s) {
    *o = 2 * PI * r;
    *s = PI * na_druhu(r);
}

int main() {
    int polomer;
    float obvod, obsah;

    printf("Zadaj polomer kruhu: ");
    scanf("%d", &polomer);

    kruh(polomer, &obvod, &obsah);
    printf("obvod: %.2f, obsah: %.2f\n", obvod, obsah);
    return 0;
}
```

<details>
<summary>🖼️ Príklad – kruh</summary>

![Príklad – kruh](images/img-007.png)

</details>

---

## Jednorozmerné polia a smerníky

<details>
<summary>🖼️ Titulný obrázok – Polia a smerníky</summary>

![Polia a smerníky](images/img-008.png)

</details>

### Základy práce s poliami

Pole je štruktúra zložená z niekoľkých prvkov **rovnakého typu** (blok prvkov).

```c
TYP x[N];   // statická definícia poľa
```

- Pole obsahuje **N** prvkov
- Dolná hranica indexu je vždy **0**, horná je **N-1**
- Číslo `N` musí byť známe v čase prekladu
- Hodnoty **nie sú inicializované** na 0

| Index | 0 | 1 | 2 |
|---|---|---|---|
| Hodnota | 5 | 6 | 7 |

> Príklad: `int x[3];` — pole 3 prvkov typu `int`.

<details>
<summary>🖼️ Základy polí</summary>

![Základy polí](images/img-009.png)

</details>

---

### Prístup k prvkom poľa

```c
#define N 10

int x[N], i;

x[0] = 1;                        // priradenie hodnoty do prvého prvku poľa

for (i = 0; i < N; i++)
    x[i] = i + 1;                 // v cykle priradenie hodnoty všetkým prvkom

for (i = 0; i < N; i++)
    printf("x[%d]: %d\n", i, x[i]); // výpis prvkov poľa
```

<details>
<summary>🖼️ Prístup k prvkom poľa</summary>

![Prístup k prvkom poľa](images/img-010.png)

</details>

---

### Dynamické pole

```c
int x[3] = { 1, 2, 3 };      // statické pole na adresách 40, 42, 44
int *y;                        // smerník na int
int *z;                        // smerník na int — zatiaľ neukazuje nikam!

y = x;
// Teraz y ukazuje presne na x (x je pole = smerník, x[i] je int)
// y[1] sa rovná x[1]
// *(y+2) sa rovná x[2]

z = (int*)malloc(3 * sizeof(int));   // dynamická alokácia
z[0] = 4; z[1] = 5; z[2] = 6;
```

> **Poznámka:** Identifikátor poľa `x` je v podstate konštantný smerník na prvý prvok. Smerník `y` po priradení `y = x` ukazuje na rovnaké miesto v pamäti.

---

### Pole ako parameter funkcie

Pole sa dá odovzdať dvoma ekvivalentnými spôsobmi:

#### Spôsob 1: zátvorkovou notáciou `int pole[]`

```c
int maximum(int pole[], int n) {
    int i, max = pole[0];
    for (i = 1; i < n; i++) {
        if (pole[i] > max)
            max = pole[i];
    }
    return max;
}
```

#### Spôsob 2: smerníkovou notáciou `int *pole`

```c
int maximum(int *pole, int n) {
    int i, max = *pole;
    for (i = 1; i < n; i++) {
        if (*(pole + i) > max)
            max = *(pole + i);
    }
    return max;
}
```

> **Poznámka:** Oba zápisy sú ekvivalentné. `pole[i]` je to isté ako `*(pole + i)`.

---

## Spájané zoznamy

<details>
<summary>🖼️ Titulný obrázok – Spájané zoznamy</summary>

![Spájané zoznamy](images/img-016.png)

</details>

### Záznamy v pamäti

Záznamy spájaného zoznamu v pamäti **nemusia nasledovať za sebou**. Každý prvok obsahuje dáta a smerník na ďalší prvok.

Príklad rozmiestnenia v pamäti:

| Adresa | 43392 | 43420 | 43286 | 43348 | 43102 | 43606 | 43622 |
|---|---|---|---|---|---|---|---|
| Meno | Janko | Miško | Anka | Zuzka | David | Lucka | Jožko |
| Číslo | 1 | 2 | 3 | 5 | 6 | 4 | 8 |

- `zac` ukazuje na adresu 43392 (Janko) – začiatok zoznamu
- Každý prvok ukazuje na ďalší cez smerník `dalsi`

<details>
<summary>🖼️ Záznamy v pamäti</summary>

![Záznamy v pamäti](images/img-017.png)

</details>

---

### Vyhľadávanie – prvý záznam spĺňajúci podmienku

Funkcia `vratPrveMeno()` vráti ukazovateľ na **prvý** záznam s daným menom.

```c
CLOVEK *vratPrveMeno(CLOVEK *zac, char meno[]) {
    while (zac != NULL) {
        if (!strcmp(zac->meno, meno))
            return zac;
        zac = zac->dalsi;
    }
    return NULL;
}
```

- Ak nájdeme hľadaný prvok – vrátime aktuálny ukazovateľ
- Ak sa nenájde – vrátime `NULL`

> **Poznámka:** Vo funkcii pracujeme s **lokálnou kópiou** ukazovateľa `zac`, takže pôvodný ukazovateľ v hlavnom programe sa nezmení.

<details>
<summary>🖼️ Hľadanie prvého záznamu</summary>

![Hľadanie prvého záznamu](images/img-018.png)
![Hľadanie – priebeh](images/img-019.png)

</details>

---

### Vyhľadávanie – posledný záznam spĺňajúci podmienku

Funkcia `vratPosledneMeno()` vráti ukazovateľ na **posledný** záznam s daným menom.

```c
CLOVEK *vratPosledneMeno(CLOVEK *zac, char meno[]) {
    CLOVEK *najdeny = NULL;

    while (zac != NULL) {
        if (!strcmp(zac->meno, meno))
            najdeny = zac;       // zapamätá si posledný nájdený
        zac = zac->dalsi;
    }
    return najdeny;
}
```

- Pomocný ukazovateľ `najdeny` ukazuje na **posledný doteraz nájdený** záznam spĺňajúci podmienku
- Na rozdiel od `vratPrveMeno()` sa pri nájdení nevraciame hneď, ale pokračujeme ďalej

<details>
<summary>🖼️ Hľadanie posledného záznamu</summary>

![Hľadanie posledného záznamu](images/img-020.png)
![Priebeh hľadania](images/img-021.png)

</details>

---

### Pridanie prvku na pozíciu

Funkcia `vlozNaPoziciu()` vloží prvok do zoznamu na danú pozíciu.

```c
CLOVEK *vlozNaPoziciu(CLOVEK *zac, CLOVEK *vloz, int p) {
    CLOVEK *akt = zac;
    int i = 1;

    if (zac == NULL) return vloz;       // prázdny zoznam
    if (vloz == NULL) return zac;       // nie je čo vkladať

    if (p == 1) {                       // vloženie na začiatok
        vloz->dalsi = zac;
        return vloz;
    }

    while (akt->dalsi != NULL && i < p - 1) {
        akt = akt->dalsi;
        i++;
    }

    vloz->dalsi = akt->dalsi;           // vloženie do stredu/na koniec
    akt->dalsi = vloz;
    return zac;
}
```

#### Špeciálne prípady

**Prázdny zoznam:**
```c
if (zac == NULL) return vloz;
// vloz sa stane jediným prvkom zoznamu
```

**Prázdny prvok:**
```c
if (vloz == NULL) return zac;
// nie je čo vkladať, vráti sa pôvodný zoznam
```

**Vloženie na začiatok** (`p == 1`):
```c
vloz->dalsi = zac;
return vloz;
// vloz sa stane novým začiatkom zoznamu
```

**Vloženie do stredu alebo na koniec:**
- Prechádzame zoznam pomocou `akt` kým nenájdeme pozíciu `p - 1`
- `vloz->dalsi` nastavíme na nasledovníka `akt`
- `akt->dalsi` nastavíme na `vloz`

<details>
<summary>🖼️ Vkladanie na pozíciu – vizualizácia</summary>

![Vkladanie do prázdneho / na začiatok](images/img-025.png)
![Vkladanie na začiatok](images/img-027.png)
![Vkladanie do stredu](images/img-029.png)

</details>

---

[← Prednáška 9](../09-struktury-zoznamy/) | [Hlavná stránka](../../README.md) | [Prednáška 11 →](../11-typova-konverzia-preprocesor/)
