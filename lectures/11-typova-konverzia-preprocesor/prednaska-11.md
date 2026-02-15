# Prednáška 11: Typová konverzia a preprocesor

> **Predmet:** Algoritmizácia a programovanie
> **Prednášajúci:** Ján Grman
> **Semester:** Zimný semester 2024

---

## Obsah

1. [Typová konverzia](#typová-konverzia)
   - [Implicitná typová konverzia](#implicitná-typová-konverzia)
   - [Pravidlá implicitnej konverzie](#pravidlá-implicitnej-konverzie)
   - [Príklady implicitnej konverzie](#príklady-implicitnej-konverzie)
   - [Explicitná typová konverzia (pretypovanie)](#explicitná-typová-konverzia)
   - [Príklad: priemer troch čísel](#príklad-priemer-troch-čísel)
2. [Preprocesor](#preprocesor)
   - [Činnosť preprocesora](#činnosť-preprocesora)
   - [Konštrukcie pre preprocesor](#konštrukcie-pre-preprocesor)
   - [Konštanty – makrá bez parametrov](#konštanty--makrá-bez-parametrov)
   - [Pravidlá pre písanie konštánt](#pravidlá-pre-písanie-konštánt)
   - [Príklady definovania konštánt](#príklady-definovania-konštánt)
   - [Kedy sa makro nerozvinie](#kedy-sa-makro-nerozvinie)
   - [Prekrývanie definícií](#prekrývanie-definícií)
   - [Makro ako skrytá časť programu](#makro-ako-skrytá-časť-programu)
   - [Makrá s parametrami](#makrá-s-parametrami)
   - [Preddefinované makrá](#preddefinované-makrá)
   - [Vkladanie súborov](#vkladanie-súborov)
   - [Podmienený preklad](#podmienený-preklad)
   - [Operátory `defined`, `#elif` a `#error`](#operátory-defined-elif-a-error)
   - [Oddelený preklad](#oddelený-preklad)
3. [Príklady](#príklady)
   - [Príklad 1: súčet prvých N čísel](#príklad-1-súčet-prvých-n-čísel)
   - [Príklad 2: makro na tretiu mocninu](#príklad-2-makro-na-tretiu-mocninu)
   - [Príklad 3: makro citaj_int](#príklad-3-makro-citaj_int)
   - [Príklad 4: ladiace výpisy](#príklad-4-ladiace-výpisy)

---

## Typová konverzia

<details>
<summary>🖼️ Titulný obrázok – Typová konverzia</summary>

![Typová konverzia](images/img-002.png)

</details>

### Implicitná typová konverzia

Typová konverzia je **prevod premennej určitého typu na iný typ** (napr. `int` na `float`).

Dva druhy konverzií:

| Druh | Popis |
|---|---|
| **Implicitná** | Samovoľná, automatická |
| **Explicitná** | Vynútená, požadovaná programátorom |

---

### Pravidlá implicitnej konverzie

**Pravidlo 1** – Pred vykonaním operácie sa samostatné operandy konvertujú:
- Kedykoľvek sa objaví typ `char` alebo `short int` → konvertuje sa na `int`
- Všetky operandy `unsigned char` a `unsigned short` sa konvertujú na `int` (ak `int` nepretečie, inak na `unsigned int`)

**Pravidlo 2** – Ak majú dva operandy jednej operácie rôzny typ, operand s **nižšou prioritou** je konvertovaný na typ s **vyššou prioritou** podľa hierarchie:

| Priorita (od najnižšej) | Konvertuje sa na |
|---|---|
| `int` | `unsigned int` |
| `unsigned int` | `long` |
| `long` | `unsigned long` |
| `unsigned long` | `float` |
| `float` | `double` |
| `double` | `long double` |

> Ak je jeden operand typu `float` a druhý má nižšiu prioritu, druhý sa konvertuje na `float`.

**Pravidlo 3** – V priraďovacích príkazoch je typ na **pravej strane** konvertovaný na typ z **ľavej strany**:

```c
double x;
x = 5;        // x bude mať hodnotu 5.0

int i;
i = 5.0;       // i bude mať hodnotu 5 (desatinná časť sa odreže)
```

<details>
<summary>🖼️ Pravidlá implicitnej konverzie</summary>

![Pravidlá 1](images/img-004.png)
![Pravidlá 2](images/img-005.png)
![Pravidlá 3](images/img-006.png)

</details>

---

### Príklady implicitnej konverzie

#### Príklad s typom `char`

```c
char c;

c = 1;         // 1 je konvertované na char, c obsahuje znak "ctrl A"
c++;           // c obsahuje znak "ctrl B"
c = c + '1';   // ordinálne číslo znaku '1' je 49 → c obsahuje znak
               // s ordinálnym číslom 51, teda znak '3'
```

#### Príklad s typom `int`

```c
int i;

i = 'A';       // i obsahuje ordinálne číslo znaku 'A', teda 65
i = 'A' + 2;   // i obsahuje 67 (ordinálne číslo znaku 'C')
i = 3.8;       // i bude mať hodnotu 3 (0.8 sa odreže)
```

#### Kombinovaný príklad

```c
double g;
int i;
char c;

g = 5;         // g obsahuje číslo 5.0
i = g * c;     // najprv sa c skonvertuje na int, potom na double,
               // výsledok g * c je double, ale podľa pravidla 3
               // sa skonvertuje na int a priradí do i
```

---

### Explicitná typová konverzia

**Pretypovanie** (casting) – jazyk C dovoľuje takmer ľubovoľnú konverziu, čo je aj riziko.

**Syntax:**

```c
(typ) výraz
```

**Časté pretypovanie:**

| Výraz | Účel |
|---|---|
| `(int) char_vyraz` | Prevod znaku na ordinálne číslo |
| `(char) int_vyraz` | Prevod ordinálneho čísla na znak |
| `(int) double_vyraz` | Odrezanie desatinnej časti |
| `(double) int_vyraz` | Prevod celého čísla na reálne |
| `(double) float_vyraz` | Zväčšenie presnosti |

Najčastejšie sa používa na **pretypovanie ukazovateľov**:

```c
#include <math.h>

int i = 10;
double f;
f = sqrt((double) i);    // sqrt() vráti druhú odmocninu
```

> Nie je to nutné (implicitná konverzia by to zvládla), ale zvyšuje to čitateľnosť.

<details>
<summary>🖼️ Explicitná konverzia</summary>

![Explicitná konverzia](images/img-010.png)
![Explicitná konverzia – ukazovatele](images/img-011.png)

</details>

---

### Príklad: priemer troch čísel

Program načíta tri celé čísla a vypíše ich priemer na dve desatinné miesta.

```c
#include <stdio.h>

int main() {
    int x, y, z;

    printf("Zadajte 3 cele cisla: ");
    scanf("%d %d %d", &x, &y, &z);

    printf("Priemer: %.2f\n", (float)(x + y + z) / 3.0);
    return 0;
}
```

> **Poznámka:** Bez pretypovanie by `(x+y+z) / 3` bolo celočíselné delenie. Pretypovaním výrazu na `float` a delením `3.0` dostaneme reálny výsledok.

---

## Preprocesor

<details>
<summary>🖼️ Titulný obrázok – Preprocesor</summary>

![Preprocesor](images/img-013.png)

</details>

### Činnosť preprocesora

Preprocesor spracováva zdrojový text **PRED kompilátorom**:

- Zamieňa text (napr. identifikátory konštánt za číselné hodnoty)
- Vypustí zo zdrojového textu všetky **komentáre**
- Prevádza **podmienený preklad**
- **Nekontroluje** syntaktickú správnosť programu

> Riadok, ktorý má spracovávať preprocesor, sa začína znakom `#`.

---

### Konštrukcie pre preprocesor

#### Definovanie a rušenie makier

```c
#define meno_makra text       // definovanie makra
#undef meno_makra             // zrušenie definície makra
```

#### Podmienený preklad

```c
#if konst
    // ...
#elif podmienka
    // ...
#else
    // ...
#endif
```

#### Vkladanie súborov

```c
#include <filename>           // zo systémového adresára
#include "filename"           // z adresára používateľa
```

#### Výpis chybových správ

```c
#error text                   // výpis chyby vo fáze predspracovania
```

#### Preklad podľa definície makra

```c
#ifdef meno_makra             // ak je makro definované
    // ...
#endif

#ifndef meno_makra            // ak makro NIE JE definované
    // ...
#endif
```

---

### Konštanty – makrá bez parametrov

- Symbolické konštanty sa používajú často – zbavujú program **„magických čísel"**
- Väčšinou definované na začiatku modulu
- Platnosť konštánt je do konca modulu
- Náhrada konštanty hodnotou = **rozvoj (expanzia) makra**

---

### Pravidlá pre písanie konštánt

- Mená konštánt **veľkými písmenami**
- Meno konštanty je od hodnoty oddelené **aspoň jednou medzerou**
- Za hodnotou by mal byť **vysvetľujúci komentár**
- Nové konštanty môžu využívať skôr definované konštanty
- Ak je hodnota konštanty dlhšia ako riadok, musí byť na konci riadku znak `\`

---

### Príklady definovania konštánt

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

### Príklad použitia konštanty: výpočet obsahu kruhu

```c
#include <stdio.h>
#define PI 3.14

int main() {
    double r;

    printf("Zadajte polomer: ");
    scanf("%lf", &r);
    printf("Obvod kruhu s polomerom %f je %f\n", r, 2 * r * PI);
    return 0;
}
```

### Príklad použitia konštanty: malé písmená na veľké

```c
#include <stdio.h>
#define POSUN ('a' - 'A')
#define EOLN '\n'
#define PRED_MALE '*'

int main() {
    int c;

    while ((c = getchar()) != EOLN) {
        if (c >= 'a' && c <= 'z') {
            putchar(PRED_MALE);
            putchar(c - POSUN);    // malé písmeno zmení na veľké
        } else {
            putchar(c);            // inak vypíše načítaný znak
        }
    }
    return 0;
}
```

> **Poznámka:** Ak je symbolickou konštantou výraz, je vhodné uzavrieť ho do zátvoriek (napr. `('a' - 'A')`).

---

### Kedy sa makro nerozvinie

Makro sa **nerozvinie**, ak je uzatvorené v **úvodzovkách**:

```c
#define MENO "Katka"

printf("Volam sa MENO");          // vypíše: Volam sa MENO
printf("Volam sa %s", MENO);     // vypíše: Volam sa Katka
```

---

### Prekrývanie definícií

Nová definícia prekrýva starú. Ak nie je rovnaká, treba najprv starú **zrušiť**:

```c
#define POCET 10
#undef POCET
#define POCET 20
```

---

### Makro ako skrytá časť programu

```c
#define ERROR { printf("Chyba v datach.\n"); }
```

Pri použití nie je makro ukončené bodkočiarkou:

```c
if (x == 0)
    ERROR
else
    y = y / x;
```

---

### Makrá s parametrami

Krátka a často používaná funkcia vykonávajúca jednoduchý výpočet – namiesto volania funkcie sa makro pri preprocesingu **rozvinie** (inline expanzia).

Rozhodnutie medzi funkciou a makrom:

| Vlastnosť | Funkcia | Makro |
|---|---|---|
| Veľkosť programu | Kratší | Dlhší |
| Rýchlosť | Pomalší | Rýchlejší |

#### Definícia a použitie

```c
#define je_velke(c) ((c) >= 'A' && (c) <= 'Z')

// V zdrojovom súbore:
ch = je_velke(ch) ? ch + ('a' - 'A') : ch;

// Po rozvinutí:
ch = ((ch) >= 'A' && (ch) <= 'Z') ? ch + ('a' - 'A') : ch;
```

> **Dôležité:** Zátvorka s argumentmi musí byť **hneď za názvom makra** (bez medzery).

#### Dôležitosť zátvoriek v tele makra

```c
// CHYBNE:
#define sqrt(x) x * x
sqrt(f + g);              // po rozvinutí: f + g * f + g  (zlé!)

// SPRÁVNE:
#define sqrt(x) ((x) * (x))
sqrt(f + g);              // po rozvinutí: ((f + g) * (f + g))
```

<details>
<summary>🖼️ Makrá s parametrami</summary>

![Makrá s parametrami](images/img-027.png)
![Chyby v makrách](images/img-028.png)

</details>

---

### Preddefinované makrá

#### `getchar()` a `putchar()` (v `stdio.h`)

```c
#define getchar()    getc(stdin)
#define putchar(c)   putc(c, stdout)
```

#### Makrá v `ctype.h` – určenie typu znaku

| Makro | Vráti 1, ak je znak… |
|---|---|
| `isalnum` | číslica alebo písmeno |
| `isalpha` | malé alebo veľké písmeno |
| `isascii` | ASCII znak (0 – 127) |
| `iscntrl` | riadiaci znak (1 – 26) |
| … | (viac v Herout: Učebnice jazyka C) |

#### Makrá v `ctype.h` – konverzia znaku

| Makro | Účel |
|---|---|
| `tolower` | Konverzia na malé písmeno |
| `toupper` | Konverzia na veľké písmeno |
| `toascii` | Prevod na ASCII (len najnižších 7 bitov) |

---

### Vkladanie súborov

```c
#include <stdio.h>            // systémový súbor
#include <ctype.h>            // systémový súbor
#include "KONSTANTY.H"        // súbor v aktuálnom adresári
```

---

### Podmienený preklad

Používa sa u väčších programov – napr. ladiace časti, pomocné výpisy.

#### Riadenie hodnotou konštantného výrazu

```c
#if konstantny_vyraz
    // časť 1 – ak je výraz nenulový
#else
    // časť 2 – inak
#endif
```

Šikovný trik na vynechanie časti programu pri testovaní:

```c
#if 0
    // časť programu, čo má byť vynechaná
    // (lepšie ako /* */ – problém s vhniezdené komentármi)
#endif
```

#### Riadenie hodnotou konštantného makra

```c
#define PCAT 1

#if PCAT
    #include <conio.h>        // ak na PC/AT → PCAT = 1
#else
    #include <stdio.h>        // inak PCAT = 0
#endif
```

#### Riadenie definíciou makra

```c
#define PCAT                  // stačí, že je konštanta definovaná

#ifdef PCAT
    #include <conio.h>
#else
    #include <stdio.h>
#endif

#ifndef PCAT                  // ak NIE JE definovaná
    // ...
#endif

#undef PCAT                   // zrušenie definície makra
```

---

### Operátory `defined`, `#elif` a `#error`

- `#ifdef` / `#ifndef` zisťujú existenciu len **jedného** symbolu
- Pre **kombináciu viacerých** podmienok sa používa `defined`:

```c
#if defined TEST            // ekvivalent #ifdef TEST
#if !defined TEST           // ekvivalent #ifndef TEST
```

Príklad s `#elif` a `#error`:

```c
#if defined(ZAKLADNY) && defined(DEBUG)
    #define VERZIA_LADENIA 1
#elif defined(STREDNY) && defined(DEBUG)
    #define VERZIA_LADENIA 2
#elif !defined(DEBUG)
    #error Ladiacu verziu nie je mozne pripravit!
#else
    #define VERZIA_LADENIA 3
#endif
```

---

### Oddelený preklad

Program sa delí na menšie časti – **moduly**:
- Logicky sa program delí na časti
- Je veľký / pracuje na ňom viac programátorov
- Aby bol prehľadný

Moduly:
- Oddelené – zvlášť súbory
- Obsahujú premenné a funkcie, ktoré môžu povoliť alebo zakázať používať inými modulmi

---

## Príklady

<details>
<summary>🖼️ Titulný obrázok – Príklady</summary>

![Príklady](images/img-039.png)

</details>

### Príklad 1: súčet prvých N čísel

Program vypíše súčet prvých N čísel, kde N je symbolická konštanta.

```c
#include <stdio.h>
#define N 5

int main() {
    int i, suma = 0;

    for (i = 1; i <= N; i++)
        suma += i;

    printf("Sucet prvych %d cisel je %d\n", N, suma);
    return 0;
}
```

---

### Príklad 2: makro na tretiu mocninu

Program použije makro `na_tretiu(x)` na počítanie tretej mocniny.

```c
#include <stdio.h>
#define na_tretiu(x) ((x) * (x) * (x))

int main(void) {
    int i = 2, j = 3;

    printf("%d^3 = %d\n", 3, na_tretiu(3));         // 3^3 = 27
    printf("%d^3 = %d\n", i, na_tretiu(i));           // 2^3 = 8
    printf("%d^3 = %d\n", 2+3, na_tretiu(2+3));       // 5^3 = 125
    printf("%d^3 = %d\n", i*j+1, na_tretiu(i*j+1));   // 7^3 = 343
    return 0;
}
```

> **Dôležité:** Bez zátvoriek v makre (`x * x * x`) by `na_tretiu(2+3)` dalo nesprávny výsledok: `2+3*2+3*2+3 = 19` namiesto `125`.

---

### Príklad 3: makro citaj_int

Program zistí, či bola načítaná nula – pomocou makra `citaj_int(x)`.

```c
#include <stdio.h>
#define citaj_int(i) (scanf("%d", &i), i)

int main() {
    int j, k;

    printf("Zadajte cele cislo: ");
    if ((j = citaj_int(k)) == 0)
        printf("Bola nacitana nula.\n");

    printf("Bolo nacitane cislo %d\n", k);
    return 0;
}
```

---

### Príklad 4: ladiace výpisy

Program vynásobí dve čísla len pomocou sčitovania, v cykle použijeme ladiace výpisy.

```c
#include <stdio.h>
#define LADENIE

int main() {
    int x, y, nasobok = 0;

    printf("Zadajte dve cisla: ");
    scanf("%d %d", &x, &y);

    printf("%d * %d = ", x, y);
    for (; y > 0; y--) {
        nasobok += x;

#ifdef LADENIE
        printf("\n(y: %d, nasobok: %d)\n", y, nasobok);
#endif

    }
    printf("%d\n", nasobok);
    return 0;
}
```

> **Poznámka:** Ak zakomentujeme (`//`) alebo vymažeme riadok `#define LADENIE`, ladiace výpisy sa nebudú prekladať.

---

[← Prednáška 10](../10-smernikovy-deep-dive/) | [Hlavná stránka](../../README.md) | [Prednáška 11 →](../11-typova-konverzia-preprocesor/)
