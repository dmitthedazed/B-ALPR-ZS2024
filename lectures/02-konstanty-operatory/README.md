# Prednáška 2: Konštanty, operátory a formátovaný vstup-výstup

> **Predmet:** Algoritmizácia a programovanie  
> **Prednášajúci:** Ján Grman  
> **Semester:** ZS 2024/2025

---

## Obsah

1. [Konštanty](#konštanty)
   - [Celočíselné konštanty](#celočíselné-konštanty)
   - [Reálne konštanty](#reálne-konštanty)
   - [Znakové konštanty](#znakové-konštanty)
   - [Escape sekvencie](#escape-sekvencie)
   - [Reťazcové konštanty](#reťazcové-konštanty)
2. [Operátory](#operátory)
   - [Špeciálne unárne operátory (++, --)](#špeciálne-unárne-operátory)
   - [Operátory priradenia](#operátory-priradenia)
   - [Operátor čiarky](#operátor-čiarky)
3. [Formátovaný vstup a výstup](#formátovaný-vstup-a-výstup)
   - [Terminálový vstup a výstup](#terminálový-vstup-a-výstup)
   - [Špecifikácie riadiaceho reťazca](#špecifikácie-riadiaceho-reťazca)
   - [Príklady formátovaného výstupu](#príklady-formátovaného-výstupu)
4. [Booleovské výrazy a logické operátory](#booleovské-výrazy-a-logické-operátory)
   - [Porovnávacie a logické operátory](#porovnávacie-a-logické-operátory)
   - [Priradenie vs. porovnanie](#priradenie-vs-porovnanie)
   - [Skrátené vyhodnocovanie](#skrátené-vyhodnocovanie)
   - [Priority operátorov](#priority-operátorov)
5. [Podmienený výraz (ternárny operátor)](#podmienený-výraz-ternárny-operátor)
6. [Príkazy vetvenia (if-else)](#príkazy-vetvenia-if-else)
   - [Príkaz if](#príkaz-if)
   - [Rozšírený príkaz if-else](#rozšírený-príkaz-if-else)
7. [Formátovací štýl](#formátovací-štýl)
8. [Príklady](#príklady)

---

## Konštanty

### Celočíselné konštanty

Celočíselné konštanty sa v jazyku C dajú zapísať v troch číselných sústavách:

| Sústava | Pravidlo | Príklady |
|---|---|---|
| **Desiatková** | Postupnosť číslic, na prvom mieste nesmie byť `0` (iba ak je samotná nula) | `15`, `1`, `0` |
| **Osmičková (oktálová)** | Začína číslicou `0`, nasledujú osmičkové číslice (0–7) | `065`, `00`, `017`, `01` |
| **Šestnástková (hexadecimálna)** | Začína `0x` alebo `0X`, nasledujú hexadecimálne číslice (0–9, a–f, A–F) | `0x12`, `0x0`, `0XAA` |

#### Typ a znamienko konštanty

- **Implicitný typ** – určený podľa veľkosti konštanty
- **Explicitný typ `long`** – prípona `L` (alebo `l`), napr. `12345678L`
- **Unsigned** – prípona `U` (alebo `u`), napr. `129u`, `123456LU`
- **Záporné konštanty** – znamienko mínus, napr. `-56`

#### Príklad: celočíselné konštanty

```c
int main()
{
    int i, j = 0xAA;       // konštanta: 170
    unsigned int u;

    i = 017;               // konštanta: 15 (osmičková)
    j = j + 2 * i;
    u = 145u;              // konštanta: 145 (ako unsigned)

    return 0;
}
```

<details><summary>📊 Slide</summary><img src="images/img-002.png"></details>

### Reálne konštanty

Reálne konštanty sa zapisujú podľa bežných zvyklostí a môžu obsahovať desatinnú bodku na začiatku aj na konci:

| Zápis | Hodnota |
|---|---|
| `15.` | `15.0` |
| `56.8` | `56.8` |
| `.84` | `0.84` |
| `3.14` | `3.14` |
| `5e6` | $5 \times 10^6$ |
| `7E23` | $7 \times 10^{23}$ |

#### Typ reálnej konštanty

- **`float`** – prípona `F` (alebo `f`), napr. `3.14f`
- **`long double`** – prípona `L` (alebo `l`), napr. `12e3L`
- Bez prípony je konštanta typu `double`

#### Príklad: reálne konštanty

```c
int main()
{
    long i = 25L;
    float f_1, f_2;

    f_1 = .25;    // konštanta: 0.25
    f_2 = 80.;    // konštanta: 80.0

    return 0;
}
```

### Znakové konštanty

- Znak uzatvorený v apostrofoch, napr. `'a'`, `'*'`, `'4'`
- Hodnota (ordinárne číslo) je odvodená od **ASCII tabuľky**
- Veľkosť znakovej konštanty je typu `int`, nie `char`!
- Znaková konštanta neviditeľného znaku:
  - Oktálový kód: `'\ddd'`, napr. `'\012'`, `'\007'`
  - Hexadecimálny kód: `'\0xHH'`, napr. `'\0x0A'`, `'\0XD'`
- Znak `\` (escape character) mení význam nasledujúceho znaku

#### Príklad: znakové konštanty

```c
int main()
{
    long i = 25L;
    float f_1 = .25, f_2 = 92E-1;
    char c, ch;

    c = 'a';       // konštanta: znak 'a'
    ch = '\n';     // konštanta: nový riadok

    return 0;
}
```

### Escape sekvencie

Niektoré escape sekvencie majú okrem numerického kódu aj znakový ekvivalent:

| Sekvencia | Hex kód | Význam |
|---|---|---|
| `\n` | `0x0A` | Nový riadok (new line, line feed) |
| `\r` | `0x0D` | Návrat na začiatok riadku (carriage return) |
| `\f` | `0x0C` | Nová stránka (formfeed) |
| `\t` | `0x09` | Tabulátor (tab) |
| `\b` | `0x08` | Posun doľava (backspace) |
| `\a` | `0x07` | Písknutie (alert) |
| `\\` | `0x5C` | Spätné lomítko (backslash) |
| `\'` | `0x2C` | Apostrof (single quote) |
| `\0` | `0x00` | Nulový znak (null character) |

<details><summary>📊 Slide</summary><img src="images/img-008.png"></details>

### Reťazcové konštanty

- Reťazec uzatvorený do úvodzoviek, napr. `"Toto je retazcova konstanta"`
- ANSI C umožňuje **zreťazovanie** dlhých reťazcových konštánt (kvôli sprehľadneniu):

```c
"Takto vyzera velmi dlhy retazec"

// je to isté ako:
"Takto vyzera " "velmi dlhy retazec"

// alebo:
"Takto vyzera " "velmi "
    "dlhy retazec"
```

---

## Operátory

### Špeciálne unárne operátory

Operátory **inkrement** (`++`) a **dekrement** (`--`) zvyšujú/znižujú hodnotu o 1.

| Forma | Syntax | Správanie |
|---|---|---|
| **Prefix** | `++vyraz` / `--vyraz` | Najprv sa zmení hodnota, potom sa použije |
| **Postfix** | `vyraz++` / `vyraz--` | Najprv sa použije pôvodná hodnota, potom sa zmení |

> **Dôležité:** Výraz musí byť **l-hodnota** (premenná). Konštanty ako `45++` alebo výrazy ako `--(i + j)` nie sú povolené.

#### Príklad: inkrement a dekrement

```c
int i = 5, j = 1, k;

i++;           // i bude 6
j = ++i;       // j bude 7, i bude 7
j = i++;       // j bude 7, i bude 8
k = --j + 2;   // k bude 8, j bude 6, i bude 8
```

<details><summary>📊 Slide</summary><img src="images/img-011.png"></details>

### Operátory priradenia

Okrem jednoduchého priradenia `=` existujú **rozšírené priraďovacie operátory**. Namiesto `x = x operátor výraz` sa použije skrátený zápis:

| Operátor | Ekvivalent |
|---|---|
| `x += vyraz` | `x = x + vyraz` |
| `x -= vyraz` | `x = x - vyraz` |
| `x *= vyraz` | `x = x * vyraz` |
| `x /= vyraz` | `x = x / vyraz` |
| `x %= vyraz` | `x = x % vyraz` |

> **Pozor:** Nedávajte medzeru medzi operátor a `=` (napr. `+=`, nie `+ =`).

### Operátor čiarky

Operátor čiarky (`,`) vyhodnotí ľavý operand, jeho výsledok zahodí a vráti hodnotu pravého operandu.

```c
int i = 2, j = 4;      // toto nie je operátor čiarky (deklarácia)

j = (i++, i - j);       // i bude 3 a j bude -1
```

> **Poznámka:** Operátor čiarky je vhodné používať len v riadiacich príkazoch `for` a `while`.

---

## Opakovanie: operátory v praxi

```c
int main()
{
    int i, j = 1, k;

    j++;                 // j = 2
    ++j;                 // j = 3
    k = i = 2 * j;       // k = 6, i = 6
    j = --i;             // i = 5, j = 5
    k = i++;             // k = 5, i = 6
    k = --i + 2;         // i = 5, k = 7
    j += i++;            // j = 10, i = 6
    k *= 3;              // k = 21

    return 0;
}
```

```c
int main()
{
    int i;
    float r = .25;
    char c;

    c = 'a';     // c = 'a'
    c++;          // c = 'b'
    c = '\n';    // c = '\n'

    i = 2;       // i = 2
    r *= i;      // r = 0.5

    return 0;
}
```

---

## Formátovaný vstup a výstup

### Terminálový vstup a výstup

#### Načítanie a výpis znaku

Funkcie pracujú s premennými typu `int`:

```c
int getchar();           // načíta jeden znak zo vstupu
void putchar(int c);     // vypíše jeden znak na výstup
```

#### Formátovaný vstup a výstup

```c
scanf("formátovací reťazec", &premenné...);    // vstup
printf("formátovací reťazec", výrazy...);      // výstup
```

### Špecifikácie riadiaceho reťazca

Za znakom `%` sa uvádza špecifikácia formátu:

| Špecifikátor | Typ | Poznámka |
|---|---|---|
| `%c` | `char` / `int` | Jeden znak |
| `%d` | `signed int` | Desiatkové číslo |
| `%ld` | `signed long` | Desiatkové číslo (long) |
| `%u` | `unsigned int` | Desiatkové číslo bez znamienka |
| `%lu` | `unsigned long` | Desiatkové číslo bez znamienka (long) |
| `%f` | `float` | Reálne číslo (pre `printf()` aj `double`) |
| `%lf` | `double` | Dvojitá presnosť |
| `%Lf` | `long double` | Rozšírená presnosť (`L` musí byť veľké) |
| `%x` | `unsigned int` | Hexadecimálne (malé písmená) |
| `%X` | `unsigned int` | Hexadecimálne (veľké písmená) |
| `%o` | `unsigned int` | Osmičkové číslo |
| `%s` | `char *` | Reťazec |

> **Tip:** Ak načítavame len jeden znak, `c = getchar();` je lepšie ako `scanf("%c", &c);`.

<details><summary>📊 Slide</summary><img src="images/img-017.png"></details>

### Príklady formátovaného výstupu

```c
// Pre c = 'A':
printf("Znak '%c' ma ASCII kod %d (%XH)", c, c, c);
// Vypíše: Znak 'A' ma ASCII kod 65 (41H)

printf("Znak '%c' ma ASCII kod %d (%XH)\n", '*', '*', '*');
// Vypíše: Znak '*' ma ASCII kod 42 (2AH)
```

#### Formátovanie šírky poľa

```c
printf("Je presne %2d:%2d\n", hodiny, minuty);
// Vypíše napr.: Je presne  1:12
// alebo:        Je presne 13: 3

printf("Utratili sme: %6.2f SKK.\n", pocet * cena);
// Vypíše: Utratili sme:  13.60 SKK.

printf("Kolko stalo %s pivo?\n", "jedno");
// Vypíše: Kolko stalo jedno pivo?
```

---

## Booleovské výrazy a logické operátory

V jazyku C **neexistuje** špeciálny booleovský typ — používa sa `int`:
- **FALSE:** `0`
- **TRUE:** nenulová hodnota (najčastejšie `1`)

### Porovnávacie a logické operátory

| Operátor | Význam |
|---|---|
| `==` | Rovnosť |
| `!=` | Nerovnosť |
| `<` | Menší |
| `<=` | Menší alebo rovný |
| `>` | Väčší |
| `>=` | Väčší alebo rovný |
| `&&` | Logický súčin (AND) |
| `\|\|` | Logický súčet (OR) |
| `!` | Negácia (NOT) |

#### Príklady booleovských výrazov

```c
int x = 10, y = 5;

(x == 10)               // 1 (TRUE)
(y < x)                 // 1 (TRUE)
(x != 10)               // 0 (FALSE)
(y <= x) && (y > 2)     // 1 (TRUE)
(x < 10) || (y == 20)   // 0 (FALSE)
```

> **Pozor:** `=` je priradenie, `==` je porovnanie!

<details><summary>📊 Slide</summary><img src="images/img-025.png"></details>

### Priradenie vs. porovnanie

```c
x = 10     // priradenie — x zmení pôvodnú hodnotu na 10

x == 10    // porovnanie — ak má x hodnotu 10, výsledok je 1 (TRUE), inak 0 (FALSE)
```

### Skrátené vyhodnocovanie

V jazyku C sa logický súčet a súčin vyhodnocujú v **skrátenom vyhodnocovaní** (*short-circuit evaluation*) — argumenty sa vyhodnocujú zľava a hneď ako je zrejmý konečný výsledok, vyhodnocovanie sa skončí.

**Logický súčin (`&&`):** ak je ľavý podvýraz `0`, celý výraz je `0`:

```c
// ak y == 0, hodnota výrazu je FALSE a delenie nulou nenastane
(y != 0) && (x / y < z)
```

**Logický súčet (`||`):** ak je ľavý podvýraz `1`, celý výraz je `1`:

```c
// ak x > 10, hodnota výrazu je TRUE a x % 5 sa nevyhodnotí
(x > 10) || (x % 5)
```

#### Výhody skráteného vyhodnocovania

```c
// Ak prvý podvýraz zisťuje, či je drahý výpočet potrebný:
int a = 0;
if (a && funkcia(b)) {
    // ...
}

// Ak prvý podvýraz zabezpečuje, že druhý neskončí s chybou:
int delitel = 0;
if (delitel && delenec / delitel) {
    // ...
}
```

### Priority operátorov

| Operátor | Smer vyhodnocovania | Poznámka |
|---|---|---|
| `!  ++  --  -  +  (typ)` | Zprava doľava | Unárne operátory + pretypovanie |
| `*  /  %` | Zľava doprava | Multiplikatívne |
| `+  -` | Zľava doprava | Aditívne |
| `<  <=  >=  >` | Zľava doprava | Porovnávacie |
| `==  !=` | Zľava doprava | Rovnosťové |
| `&&` | Zľava doprava | Logický súčin |
| `\|\|` | Zľava doprava | Logický súčet |
| `? :` | Zprava doľava | Ternárny operátor |
| `=  +=  -=  *=  ...` | Zľava doprava | Priradenie |
| `,` | Zľava doprava | Operátor čiarky |

> **Pravidlo:** Aritmetické operátory a operátory porovnania majú väčšiu prioritu ako logické operátory. Ak si nie ste istí, radšej dajte zátvorky!

> **Pozor:** Nezamieňajte `&&` za `&` a `||` za `|` — `&` a `|` sú **bitové** operácie!

<details><summary>📊 Slide</summary><img src="images/img-029.png"></details>

#### Príklady priorít

Pre všetky príklady platí: `int i = 1, j = 1;`

```c
j = j && (i = 2);          // i bude 2, j bude 1 (pretože j == 1 a výraz (i = 2) má hodnotu 2)
j = j && (i == 3);         // j bude 0 (pretože i == 1)
j = j || (i / 2);          // j bude 1 (pretože j je TRUE, (i / 2) sa nevyhodnocuje)
j = !j && (i = i + 1);     // j bude 0, i bude 1 (!j je FALSE, i sa neinkrementuje)
```

### Poradie vyhodnocovania

Len operátory `&&`, `||`, `? :` a `,` zaručujú poradie vyhodnocovania. Ostatné operátory **nezaručujú** žiadne poradie:

```c
int j, i = 1;

j = ++i - (i = 3);   // NEDEFINOVANÉ SPRÁVANIE!
// Ak sa najprv vyhodnotí ľavý operand: i = 3, j = -1
// Ak sa najprv vyhodnotí pravý operand: i = 4, j = 1
```

> **Upozornenie:** Vyhnite sa výrazom, kde záleží na poradí vyhodnocovania vedľajších efektov!

---

## Podmienený výraz (ternárny operátor)

Ternárny operátor `? :` umožňuje jednoduchú podmienku vo výraze:

```c
podmienka ? vyraz_1 : vyraz_2
```

Ak podmienka je pravdivá, výsledkom je `vyraz_1`, inak `vyraz_2`.

```c
int i, k, j = 2;

i = (j == 2) ? 1 : 3;     // i bude 1, pretože j == 2
k = (i > j) ? i : j;       // k bude maximum z i a j
```

#### Konverzia na malé písmeno

```c
MALE = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
```

> **Poznámka:** Ternárny operátor sa používa len na jednoduché výrazy. Pre zložitejšie prípady je čitateľnejšia konštrukcia `if-else`.

#### Príklad: zmena veľkosti písmen

Program načíta znak z klávesnice — ak je to veľké písmeno, zmení ho na malé a naopak:

```c
#include <stdio.h>

int main()
{
    int c;

    c = getchar();
    c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c + 'A' - 'a';
    putchar(c);

    return 0;
}
```

<details><summary>📊 Slide</summary><img src="images/img-034.png"></details>

---

## Príkazy vetvenia (if-else)

### Príkaz if

Jeden z najpoužívanejších príkazov:

```c
if (podmienka)
    prikaz;
```

Ak platí podmienka, vykoná sa `prikaz`.

> **Poznámka:** Zátvorky okolo podmienky sú **nevyhnutné**, odporúča sa dať za `if` medzeru.

#### Príklad: výpis ordinálneho čísla

Program načíta znak a ak je to veľké písmeno, vypíše jeho ordinálne číslo:

```c
#include <stdio.h>

int main()
{
    int c;

    c = getchar();
    if (c >= 'A' && c <= 'Z')
        printf("%d\n", c);

    return 0;
}
```

#### C-štýl: priradenie vo výraze

Využívame skutočnosť, že aj priradenie je výraz:

```c
#include <stdio.h>

int main()
{
    int c;

    if ((c = getchar()) >= 'A' && c <= 'Z')
        printf("%d\n", c);

    return 0;
}
```

> **Pozor:** Ak neuzátvorkujeme `c = getchar()`, výraz sa vyhodnotí inak — `getchar()` sa porovná s `'A'`, výsledok (0 alebo 1) sa priradí do `c`, a potom sa `c` porovnáva s `'Z'`.

<details><summary>📊 Slide</summary><img src="images/img-040.png"></details>

### Rozšírený príkaz if-else

Príkaz `if` sa dá rozšíriť o vetvu `else`, ktorá sa vykoná ak podmienka nie je splnená:

```c
if (podmienka)
    prikaz_1;
else
    prikaz_2;
```

> **Pravidlo:** Ak je v sebe vnorených viac príkazov `if`, `else` patrí vždy k **najbližšiemu** `if`-u.

#### Príklady if-else

```c
// Jednoduchý príkaz
if (i > 3)
    j = 5;
else
    j = 1;    // ak i > 3, j bude 5, inak 1

// Zložený príkaz (blok)
if (i > 3) {
    j = 5;
    i = 7;    // viac príkazov je uzatvorených v { }
}
else
    j = 1;    // ak i > 3: j = 5, i = 7; inak: j = 1
```

<details><summary>📊 Slide</summary><img src="images/img-044.png"></details>

---

## Formátovací štýl

- Dobré formátovanie **výrazne napomáha čitateľnosti** programu
- Kompilátor ignoruje biele znaky — dobrý štýl je výhodný pre ľudí
- Na prvý pohľad sa dá programu rozumieť

#### Dobrý štýl ✅

```c
#include <stdio.h>

int main() /* hlavny program */
{
    double x, y, z, max;

    printf("Zadaj tri realne cisla: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    if (x > y) {      /* max ak x > y */
        if (x > z)
            max = x;
        else
            max = z;
    }
    else {             /* max ak x <= y */
        if (y > z)
            max = y;
        else
            max = z;
    }

    printf("Najvacsie cislo je %lf\n", max);
    return 0;
}
```

#### Zlý štýl ❌

```c
#include <stdio.h>
int main() /* hlavny program */ {double x, y, z, max;
printf
("Zadaj dve realne cisla: ");
scanf("%lf %lf", &x, &y);if (x > y) {
/* max ak x > y */
if (x > z) max = x; else
max = z;}
else {/* max ak x <= y */
if (y > z)
max = y;
else max = z;}
printf
("Najvacsie cislo je %lf \n", max);return 0;}
```

<details><summary>📊 Slide</summary><img src="images/img-051.png"></details>

---

## Príklady

### Príklad 1: Jednoduchý výpočet

Program načíta číslo, vynásobí výrazom a vypíše výsledok:

```c
#include <stdio.h>

int main()
{
    int i, j = 2;

    printf("Zadajte cislo: ");
    scanf("%d", &i);
    i *= 5 * (j + 1);
    printf("\nVysledok: %d\n", i);

    return 0;
}
```

Pre vstup `i = 1` je výsledok: **15**

### Príklad 2: Načítanie znaku a reálneho čísla

Program načíta oddeľovač (znak) a reálne číslo, potom ich vypíše:

```c
#include <stdio.h>

int main()
{
    char c;
    float f;

    printf("Zadajte oddelovac (znak): ");
    c = getchar();              /* nacitanie znaku */
    printf("Zadajte realne cislo: ");
    scanf("%f", &f);            /* nacitanie realneho cisla */
    printf("cislo %c %.2f %c\n", c, f, c);

    return 0;
}
```

### Príklad 3: Konverzia malého písmena na veľké

```c
#include <stdio.h>

int main()
{
    int c;

    printf("Zadajte male pismeno: ");
    c = getchar() - 'a' + 'A';
    printf("Velke pismeno: %c\n", c);

    return 0;
}
```

### Príklad 4: Priemer troch čísel

```c
#include <stdio.h>

int main()
{
    double x, y, z;

    printf("Zadajte 3 realne cisla: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("Priemer: %.2f\n", (x + y + z) / 3);

    return 0;
}
```

### Príklad 5: Menší z dvoch znakov

Program načíta dva znaky a vypíše znak s menším ordinálnym číslom:

```c
#include <stdio.h>

int main()
{
    int c, d;

    c = getchar();
    d = getchar();
    putchar(c < d ? c : d);

    return 0;
}
```

Alternatívny zápis v C-štýle (načítanie priamo vo výraze):

```c
#include <stdio.h>

int main()
{
    int c, d;

    c = getchar();
    putchar(c < (d = getchar()) ? c : d);

    return 0;
}
```

### Príklad 6: Milionárska daň

```c
#include <stdio.h>

int main()
{
    double prijem;

    printf("Zadaj prijem: ");
    scanf("%lf", &prijem);

    if (prijem >= 1000000)
        printf("Milionarska dan: %lf", prijem * 0.3);
    else
        printf("Z prijmu sa neplati milionarska dan.");

    return 0;
}
```

### Príklad 7: Párne / nepárne čísla

```c
#include <stdio.h>

int main()
{
    int i;

    printf("Zadajte cislo: ");
    scanf("%d", &i);

    if ((i % 2) == 0)
        printf("Parne.\n");
    else
        printf("Neparne.\n");

    return 0;
}
```

To isté pomocou ternárneho operátora:

```c
printf("%s.\n", (i % 2) ? "Neparne" : "Parne");
```

<details><summary>📊 Slide</summary><img src="images/img-047.png"></details>

### Príklad 8: Jednoduchá kalkulačka

Program zistí, akú operáciu má vykonať, a podľa toho sčíta, odčíta, vynásobí alebo vydelí 2 čísla:

```c
#include <stdio.h>

int main()
{
    int a, b;
    char c;

    printf("Vyber:\n");
    printf("(+) Scitaj, (-) Odcitaj, (*) Nasob, (/) Del?\n");
    c = getchar();
    printf("Zadaj prve cislo: ");
    scanf("%d", &a);
    printf("Zadaj druhe cislo: ");
    scanf("%d", &b);

    if (c == '+') printf("%d", a + b);
    else if (c == '-') printf("%d", a - b);
    else if (c == '*') printf("%d", a * b);
    else if (c == '/')
        if (b != 0) printf("%d", a / b);
        else printf("Nulou sa nedeli.");
    else printf("Zadali ste nespravny znak.");

    return 0;
}
```

### Príklad 9: Magické číslo

Program náhodne vyberie magické číslo a zistí, či ho používateľ tipol správne:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int magicke;
    int tip;

    magicke = rand();   // vráti náhodné číslo

    printf("Vas tip na magicke cislo: ");
    scanf("%d", &tip);

    if (tip == magicke) {
        printf("*** BINGO! ***");
        printf(" %d je magicke cislo.\n", magicke);
    }
    else {
        printf("Nespravne, ");
        if (tip > magicke) printf("tip je prilis vysoky.\n");
        else printf("tip je prilis nizky.\n");
    }

    return 0;
}
```

### Príklad 10: Maximum z troch čísel

```c
#include <stdio.h>

int main()
{
    double x, y, z, max;

    printf("Zadaj tri realne cisla: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    if (x > y) {
        if (x > z)
            max = x;
        else
            max = z;
    }
    else {
        if (y > z)
            max = y;
        else
            max = z;
    }

    printf("Najvacsie cislo je %lf\n", max);
    return 0;
}
```

---

[← Prednáška 1](../01-uvod/) | [Hlavná stránka](../../README.md) | [Prednáška 3 →](../03-cykly/)
