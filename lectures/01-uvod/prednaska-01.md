# Prednáška 1: Úvod do algoritmizácie a programovania

> **Predmet:** Algoritmizácia a programovanie  
> **Prednášajúci:** Mgr. Ján Grman, PhD.  
> **Pracovisko:** Ústav elektrotechniky – B322  
> **Kontakt:** jan.grman@stuba.sk  
> **Semester:** Zimný semester 2024

---

## Obsah

- [Informácie o predmete](#informácie-o-predmete)
- [Základné pojmy](#základné-pojmy)
- [Jazyk C](#jazyk-c)
  - [Charakteristika jazyka](#charakteristika-jazyka)
  - [Vývoj jazyka C](#vývoj-jazyka-c)
  - [Spôsob spracovania programu](#spôsob-spracovania-programu)
- [Prvý program v jazyku C](#prvý-program-v-jazyku-c)
  - [Hello World](#hello-world)
  - [Zdrojové a hlavičkové súbory](#zdrojové-a-hlavičkové-súbory)
  - [Funkcie](#funkcie)
  - [Hlavný program – main](#hlavný-program--main)
- [Premenné a dátové typy](#premenné-a-dátové-typy)
  - [Jednoduché dátové typy](#jednoduché-dátové-typy)
  - [Veľkosť dátových typov – sizeof](#veľkosť-dátových-typov--sizeof)
  - [Identifikátory](#identifikátory)
  - [Definície premenných](#definície-premenných)
  - [Globálne a lokálne premenné](#globálne-a-lokálne-premenné)
  - [Priradenie a inicializácia](#priradenie-a-inicializácia)
- [Vstup a výstup](#vstup-a-výstup)
  - [Formátovaný výstup – printf()](#formátovaný-výstup--printf)
  - [Formátovaný vstup – scanf()](#formátovaný-vstup--scanf)
  - [Formátovacie špecifikácie](#formátovacie-špecifikácie)
  - [Špeciálne znaky (escape sekvencie)](#špeciálne-znaky-escape-sekvencie)
  - [Vstup a výstup znaku – getchar() a putchar()](#vstup-a-výstup-znaku--getchar-a-putchar)
- [Operátory a výrazy](#operátory-a-výrazy)
  - [Unárne operátory](#unárne-operátory)
  - [Binárne operátory](#binárne-operátory)
  - [Celočíselné a reálne delenie](#celočíselné-a-reálne-delenie)
- [Komentáre](#komentáre)
- [ASCII tabuľka](#ascii-tabuľka)
- [Príklady s formátovacím reťazcom](#príklady-s-formátovacím-reťazcom)

---

## Informácie o predmete

**Rozvrh:**
- Prednáška — Pondelok 8:00
- Cvičenia — CPU (vstup z 1. poschodia):
  - Pondelok 13:00, 15:00
  - Utorok 10:00, 13:00, 15:00
  - Piatok 10:00, 13:00

**Náplň predmetu:**

1. Základné konštrukcie programovacieho jazyka C
2. Vstup a výstup, podmienky, cykly
3. Premenné, pamäť, funkcie a základné údajové štruktúry
4. Práca so súbormi
5. Práca s jednorozmernými poliami a reťazcami
6. Smerníky, štruktúry a zoznamy
7. Preprocesor jazyka C

**Odporúčaná literatúra:**

- WIRTH, N. *Algoritmy a štruktúry údajov.* Bratislava: Alfa, 1989. ISBN 80-05-00153-3.
- KERNIGHAN, B. W. – RITCHIE, D. M. *Programovací jazyk C.* Brno: Computer Press, 2006. ISBN 80-251-0897-X.
- HEROUT, P. *Učebnice jazyka C: 1. díl.* České Budějovice: KOPP, 2009. ISBN 978-80-7232-383-8.
- VIRIUS, M. *Jazyky C a C++: Kompletní průvodce.* Praha: Grada Publishing, 2011. ISBN 978-80-247-3917-5.
- PROKOP, J. *Algoritmy v jazyku C a C++.* 2. rozšírené vydanie. Praha: Grada Publishing, 2012.
- T. Ward, G. Dodrill: *C Language Tutorial*, 1999. [PDF](http://phy.ntnu.edu.tw/~cchen/ctutor.pdf)

> **Tip:** Prednášky stojí za to sledovať naživo — veľa z povedaného nie je v prezentáciách. Na prednáškach sa riešia príklady a prebieha diskusia so študentami.

**Cvičenia:**

- Úlohy treba riešiť aktívne a samostatne
- Vedieť vyriešiť všetky úlohy = byť pripravený na skúšku
- Aktívna účasť na cvičeniach počas **celého semestra**
- Prostredie: **CodeBlocks** (povolené je ľubovolné prostredie podporujúce ANSI C)

> **Dôležité:** Využite konzultácie už v prípade prvých problémov! Samostatné riešenie zadaní je podstatou získania vedomostí, ktoré sú jedinou cestou ako uspieť na písomkách.


---

## Základné pojmy

| Pojem | Vysvetlenie |
|---|---|
| **Algoritmus** | Postup (recept) na riešenie problému |
| **Počítačový program** | Zápis algoritmu v programovacom jazyku |
| **Procedurálne programovanie** | Programovanie pomocou procedúr a riadiacich štruktúr (cykly, podmienky) |
| **Zdrojový kód** | Textový zápis programu v programovacom jazyku |
| **Programátor** | Autor programu |

Jazyky procedurálneho programovania: **C**, Pascal, Python, C#, Java

- Program je postupnosť príkazov
- Príkazy predpisujú vykonanie operácií


---

## Jazyk C

### Charakteristika jazyka

- Univerzálny programovací jazyk **nízkej úrovne**
  - Pracuje len so štandardnými dátovými typmi (znak, celé číslo, reálne číslo...)
- Úsporné vyjadrovanie
- Pre mnohé úlohy je **efektívnejší a rýchlejší** ako iné jazyky
- Navrhnutý a implementovaný pod operačným systémom UNIX

**Výhody:**
- Jednoduchosť
- Nezávislosť na počítači
- Veľká efektivita kódu

> **Poznámka:** Jazyk C priamo neumožňuje prácu s reťazcami — všetky akcie s reťazcami sa realizujú pomocou funkcií v knižniciach. Nie všetko je súčasťou samotného jazyka, mnohé veci sú definované v knižniciach.

### Vývoj jazyka C

- **Prvý štandard:** Kernighan a Ritchie – *The C Programming Language*, Bell Laboratories (1978) — „vyrástol" z jazyka B
- **Dnešný štandard:** ANSI C — 100% prenositeľný (ANSI = American National Standards Institute)


### Spôsob spracovania programu

Spracovanie programu prebieha vo fázach:

```
.C súbor → Preprocesor → Compiler → .OBJ → Linker → .EXE → Debugger → Spustenie
                ↑                              ↑
              .H súbory                    .LIB knižnice
```

| Fáza | Popis |
|---|---|
| **Editor** | Vytvárame zdrojový `.C` súbor |
| **Preprocesor** | Súčasť prekladača — predspracováva zdrojový súbor |
| **Compiler** | Preklad zdrojového kódu do relatívneho kódu (`.OBJ`) |
| **Linker** | Priradí relatívnemu kódu absolútne adresy, vytvorí spustiteľný súbor (`.EXE`) |
| **Debugger** | Používa sa na ladenie programu |


---

## Prvý program v jazyku C

### Hello World

```c
#include <stdio.h>

int main()
{
    printf("Hello world!");
    return 0;
}
```

Rozbor programu:

| Časť programu | Vysvetlenie |
|---|---|
| `#include <stdio.h>` | Umožní používať funkcie na vstup a výstup |
| `int main()` | Hlavná funkcia – hlavný program |
| `int` | Návratový typ — funkcia vráti celé číslo |
| `()` | Prázdne zátvorky — funkcia nemá žiadne argumenty |
| `{ ... }` | Kučeravé zátvorky uzatvárajú telo funkcie |
| `printf("Hello world!")` | Vypíše správu na obrazovku |
| `return 0` | Funkcia vráti celočíselnú hodnotu 0 |


### Zdrojové a hlavičkové súbory

- **Zdrojový súbor** (`.c`) — obsahuje kód programu, často doplnený o vložené knižnice
- **Hlavičkové súbory** (`.h`) — vkladajú sa, ak program používa funkcie z nejakej knižnice (napr. funkcie na výpis textu na obrazovku)

```c
#include <stdio.h>
```

> Jazyk C je nízkej úrovne — nie všetko je súčasťou samotného jazyka, ale definované v knižniciach.

### Funkcie

Program v jazyku C pozostáva z funkcií. Musí obsahovať aspoň jednu funkciu: `main`.

**Syntax funkcie:**

```c
návratový_typ meno_funkcie(argumenty)
{
    telo_funkcie
}
```

**Kedy vytvárať viac funkcií:**
- Ak je potrebné opakovať nejaký výpočet — vytvorí sa funkcia, ktorá sa potom volá z inej funkcie (napr. `main`)
- Ak je program príliš dlhý — kvôli prehľadnosti ho rozdelíme do menších častí

### Hlavný program – main

Funkcia `main`:
- Vždy musí byť uvedená v programe
- Je volaná ako **prvá** pri spustení programu
- Je funkcia ako každá iná

```c
int main()
{
    // ... kód programu ...
    return 0;
}
```

### Formátovaný výstup – printf()

```c
printf("formátovací reťazec", premenné);
```

- Vo formátovacom reťazci (v úvodzovkách) môžu byť rôzne formátovacie špeciálne znaky
- Špeciálny znak `\n` spôsobí odriadkovanie:

```c
printf("Hello world!\n");
```


---

## Premenné a dátové typy

**Premenné** sú pomenované pamäťové miesta na ukladanie hodnôt. Hodnoty môžu byť celočíselné, reálne, znakové alebo reťazcové.

> **Dôležité:** Jazyk C je **typový** — vopred je nutné určiť typ premennej.

### Jednoduché dátové typy

Rozsahy:
- `unsigned`: $0$ až $2^n - 1$
- `signed`: $-2^{n-1}$ až $2^{n-1} - 1$

| Typ | Popis |
|---|---|
| `int` | Celé číslo |
| `long int` (`long`) | Veľké celé číslo |
| `short int` (`short`) | Malé celé číslo |
| `char` | Znak (ASCII hodnoty: 0–255) |
| `float` | Reálne číslo |
| `double` | Väčšie reálne číslo (presnosť ~20 desatinných miest) |
| `long double` | Veľké reálne číslo |

### Veľkosť dátových typov – sizeof

Operátor `sizeof` vráti počet bajtov typu alebo premennej. Jazyk C zaručuje:

- `sizeof(char)` = 1 bajt
- `sizeof(short int)` ≤ `sizeof(int)` ≤ `sizeof(long int)`
- `sizeof(unsigned int)` = `sizeof(signed int)`
- `sizeof(float)` ≤ `sizeof(double)` ≤ `sizeof(long double)`

> **Poznámka:** C neposkytuje typ `boolean`. Booleovské hodnoty sa reprezentujú pomocou typu `int`:
> - **FALSE:** `0`
> - **TRUE:** nenulová hodnota (najčastejšie `1`)

### Identifikátory

Jazyk C **rozlišuje veľké a malé písmená** — `pom`, `Pom` a `POM` sú tri rôzne identifikátory.

- Kľúčové slová jazyka (`if`, `for`, ...) sa píšu malými písmenami
- Podčiarkovník v názvoch:
  - `_pom` — systémový identifikátor, **nepoužívať**
  - `pom_x` — **správne použitie** ✓
  - `pom_` — nepoužívať, často sa prehliadne

### Definície premenných

Definícia premennej = príkaz, ktorý priradí premennej určitého typu meno a pamäť.

```c
int i;           // definícia premennej i typu int
char c, ch;      // definícia premenných c, ch typu char
float f, g;      // definícia premenných f, g typu float
```

> **Poznámka:** Deklarácia premennej len určuje typ premennej, nepriraďuje pamäť — viac o tom neskôr.

### Globálne a lokálne premenné

```c
int i;              // globálna premenná — dostupná v celom programe

int main()
{
    int j;          // lokálna premenná — dostupná len v tomto bloku
    // ...
    return 0;
}
```

- **Globálna** premenná — môže sa používať v celom programe
- **Lokálna** premenná — môže sa používať len v bloku, v ktorom je definovaná (vymedzenom kučeravými zátvorkami)


### Priradenie a inicializácia

**Priradenie** — na ľavej strane je premenná (l-hodnota), na pravej strane výraz:

```c
j = 5;
d = 'z';
f = f + 3.14 * i;
```

> **Pozor:** Priradenie nie je rovnica! Výraz `i = i + 1` znamená: „vezmi hodnotu `i`, pripočítaj `1` a výsledok ulož späť do `i`."

- **Výraz** — má hodnotu, napr. `i * 2 + 3`
- **Priradenie** — priradenie hodnoty, napr. `j = i * 2 + 3`
- **Príkaz** — priradenie ukončené bodkočiarkou, napr. `j = i * 2 + 3;`

**Inicializácia** — priradenie hodnoty priamo v definícii:

```c
int i = 5;         // inicializácia
i = i + 1;         // i je teraz 6
i = i * 5 - 20;    // i je teraz 10
```

**Príklad — program s premennými:**

```c
int main()
{
    int i, j;

    i = 5;
    j = -1;
    j = j + 2 * i;    // j = -1 + 10 = 9

    return 0;
}
```

---

## Vstup a výstup

Vstupno/výstupné operácie nie sú súčasťou jazyka C — obsahuje ich **štandardná knižnica**. Popis funkcií na vstup a výstup sa nachádza v hlavičkovom súbore `stdio.h`:

```c
#include <stdio.h>
```

> **Poznámka:** Dôvodom oddelenia je, že najviac strojovo závislých akcií je práve vstupno/výstupných — oddeľujú sa tým nezávislé a strojovo závislé časti jazyka.

### Formátovaný výstup – printf()

Výpis jednej celočíselnej premennej:

```c
printf("%d", i);     // %d = dekadické celé číslo
```

> Prečo nie `%i` ako `int`? Pretože celé číslo sa dá vypísať v rôznych sústavách — desiatkovej (dekadickej), dvojkovej atď.

**Výpis viacerých premenných:**

```c
printf("%d %d", i, j);
```

**Výpis aj s textom:**

```c
printf("i: %d, j: %d", i, j);
```

**Kompletný príklad:**

```c
#include <stdio.h>

int main()
{
    int i, j;

    i = 5;
    j = -1;
    printf("i: %d, j: %d\n", i, j);   // vypíše: i: 5, j: -1
    j = j + 2 * i;
    printf("j: %d\n", j);              // vypíše: j: 9

    return 0;
}
```


### Formátovaný vstup – scanf()

Načítanie celočíselnej premennej:

```c
scanf("%d", &i);
```

- `%d` určuje formát čítania (dekadické celé číslo)
- `&` je **nutný** — znamená adresu premennej, kam sa má uložiť hodnota (vynechanie `&` je častá chyba!)

**Načítanie viacerých premenných:**

```c
scanf("%d %d", &i, &j);
```

> **Tip:** Pri zadávaní hodnôt môžete okrem medzery použiť aj `<Enter>`.

**Kompletný príklad:**

```c
#include <stdio.h>

int main()
{
    int i, j;

    scanf("%d %d", &i, &j);
    printf("i: %d, j: %d\n", i, j);
    j = j + 2 * i;
    printf("%d\n", j);

    return 0;
}
```

**Príklad s reálnymi číslami:**

```c
#include <stdio.h>

int main()
{
    float i, j;

    scanf("%f %f", &i, &j);
    printf("%f %f\n", i, j);
    printf("%f je sucet\n", i + j);

    return 0;
}
```

Pre vstup `2.0 3.5` vypíše: `2.000000 3.500000` a `5.500000 je sucet`

**Príklad — načítanie 3 čísel a výpočet priemeru:**

```c
#include <stdio.h>

int main()
{
    float k, l, m;

    scanf("%f %f %f", &k, &l, &m);
    printf("Priemer cisel %f, %f a %f je %f\n",
        k, l, m, (k + l + m) / 3.0);

    return 0;
}
```


### Formátovacie špecifikácie

Formátovací reťazec obsahuje:
- **Formátovacie špecifikácie** — začínajú znakom `%` a určujú formát vstupu/výstupu
- **Znakové postupnosti** — nezačínajú `%` a vypíšu sa tak, ako sú napísané (len v `printf()`)

> **Dôležité:** Počet `%` musí súhlasiť s počtom ďalších parametrov. Ak nesúhlasia, kompilátor nehlási chybu, ale program sa nespráva správne!

| Špecifikácia | Typ | Poznámka |
|---|---|---|
| `%c` | `char` | Znak |
| `%d` | `signed int` | Desiatkové číslo |
| `%ld` | `signed long` | Desiatkové číslo |
| `%u` | `unsigned int` | Desiatkové číslo bez znamienka |
| `%lu` | `unsigned long` | Desiatkové číslo bez znamienka |
| `%f` | `float` | Reálne číslo (pre `printf()` aj `double`) |
| `%lf` | `double` | Reálne číslo s dvojitou presnosťou |
| `%Lf` | `long double` | Veľké reálne číslo (veľké `L`!) |
| `%x` | | Hexadecimálne číslo (malé písmená) |
| `%X` | | Hexadecimálne číslo (veľké písmená) |
| `%o` | | Osmičkové číslo |
| `%s` | | Reťazec |
| `%g` | | Číslo v „najprirodzenejšom" formáte (z *general*) |

**Výpis na daný počet desatinných miest:**

```c
float pi = 3.1415;
printf("Pi: %.2f", pi);     // vypíše: Pi: 3.14
```

**Výpis s `%g`:**

```c
float pi = 3.1415;
printf("Pi: %g", pi);       // vypíše: Pi: 3.1415
```

> **Tip:** Ak nevieme, aké veľké číslo sa bude vypisovať a nie je stanovená presnosť, použite `%g`.

### Špeciálne znaky (escape sekvencie)

Niektoré znaky sú vyhradené na formátovanie. Na ich výpis sa používajú escape sekvencie:

| Znak | Sekvencia | Popis |
|---|---|---|
| `%` | `%%` | Znak percenta |
| `\` | `\\` | Spätné lomítko (backslash) |
| nový riadok | `\n` | Odriadkovanie (Enter) |
| tabulátor | `\t` | Horizontálny tabulátor |
| úvodzovka | `\"` | Dvojitá úvodzovka |
| pípnutie | `\007` | Bell — zvukový signál |


### Vstup a výstup znaku – getchar() a putchar()

```c
int getchar();            // prečíta jeden znak zo vstupu
void putchar(int c);      // vypíše jeden znak
```

- Obe funkcie pracujú s premennými typu `int`
- Pri volaní `getchar()` sa píšu znaky, dokým nestlačíme `<Enter>`. Potom funkcia prečíta prvé písmeno, ostatné ignoruje.

**Príklad:**

```c
#include <stdio.h>

int main()
{
    int c;

    c = getchar();       // načíta znak z klávesnice
    putchar(c);          // vypíše načítaný znak
    putchar('\n');       // odriadkuje

    return 0;
}
```

---

## Operátory a výrazy

Aritmetický výraz ukončený bodkočiarkou sa stáva príkazom:

```c
i = 2       // výraz s priradením
i = 2;      // príkaz
```

> **Poznámka:** Samotná bodkočiarka je tiež príkaz — nazýva sa *prázdny príkaz* a využije sa v cykloch.

### Unárne operátory

- `+` (plus)
- `-` (mínus)

```c
x = +5;
y = -7;
```

### Binárne operátory

| Operátor | Operácia |
|---|---|
| `+` | Sčítanie |
| `-` | Odčítanie |
| `*` | Násobenie |
| `/` | Delenie (celočíselné alebo reálne) |
| `%` | Modulo (zvyšok po delení) |

**Typ delenia závisí od typu operandov:**

| Výraz | Typ delenia |
|---|---|
| `int / int` | Celočíselné |
| `int / float` | Reálne |
| `float / int` | Reálne |
| `float / float` | Reálne |

### Celočíselné a reálne delenie

```c
int i = 5, j = 13;

j = j / 4;      // celočíselné delenie: 13 / 4 = 3
j = i % 3;       // modulo: zvyšok po delení 5 % 3 = 2
```

**Príklad:**

```c
#include <stdio.h>

int main()
{
    int i, j;
    float k, l;

    scanf("%d %d", &i, &j);
    printf("%f\n", (float)i / j);    // celočíselné delenie int/int

    scanf("%f %f", &k, &l);
    printf("%f\n", k / l);           // reálne delenie float/float

    return 0;
}
```


---

## Komentáre

Komentáre slúžia na vysvetlenie častí programu a sprehľadnenie kódu:

```c
/* jednoriadkový komentár */

/*
   viacriadkový
   komentár
*/
```

> **Pozor:** Jazyk C nedovoľuje vnorené komentáre!
> ```c
> /* komentár /* vnorený komentár */ */   // CHYBA!
> ```

**Príklad použitia komentárov:**

```c
/* Reálne a celočíselné delenie */

#include <stdio.h>

int main()
{
    int i, j;       /* celočíselné premenné */
    float k, l;     /* reálne premenné */

    scanf("%d %d", &i, &j);
    printf("%f", i / j);       /* celočíselné delenie */

    scanf("%f %f", &k, &l);
    printf("%f", k / l);       /* reálne delenie */

    return 0;
}
```

---

## ASCII tabuľka

ASCII (American Standard Code for Information Interchange) — znaková sada, kde znakom sú priradené hodnoty od 0 do 255.

| Rozsah | Obsah |
|---|---|
| 0–31 | Riadiace znaky |
| 32 `' '` | Medzera |
| 33–47 `'!'`–`'/'` | Pomocné znaky |
| 48–57 `'0'`–`'9'` | Číslice |
| 58–64 `':'`–`'@'` | Pomocné znaky |
| 65–90 `'A'`–`'Z'` | Veľké písmená |
| 97–122 `'a'`–`'z'` | Malé písmená |
| 123–126 `'{'`–`'~'` | Pomocné znaky |

**Neviditeľné znaky:**
- 7 Bell, 8 BackSpace, 9 Tab, 10 LineFeed, 13 Carriage Return

> **Poznámka:** Bežne sa pracuje so znakmi 0–127. Horná polovica tabuľky (128–255) obsahuje znaky národných abecied.

---

## Príklady s formátovacím reťazcom

Predpokladajme `i = 2` a `j = 3`:

```c
printf("Sucet je: %d", i + j);
// vypíše: Sucet je: 5

printf("Pracovali na 100%%");
// vypíše: Pracovali na 100%

printf("sucet: %d, sucin: %d", i + j, i * j);
// vypíše: sucet: 5, sucin: 6
```

**Príklady s escape sekvenciami:**

```c
printf("\007Chyba, pokus delit nulou");
// pípne a vypíše: Chyba, pokus delit nulou

printf("Toto je \"backslash\": '\\'\n");
// vypíše: Toto je "backslash": '\' a odriadkuje
```

**Opakovanie — komplexný príklad:**

```c
int main()
{
    int i;
    float r = 0.25;
    char c1, c2;

    c1 = 'a';           // c1 = 'a'
    c1 = c1 + 1;        // c1 = 'b'  (posun v ASCII)
    c1 = c2 = '\n';     // obe premenné = '\n'

    i = 2;              // i = 2
    r = r * i;           // r = 0.5

    return 0;
}
```


---

> **Záver:** Choďte a učte sa programovať! 🖥️

---

← Predchádzajúca | [Hlavná stránka](../../README.md) | [Nasledujúca →](../02-konstanty-operatory/README.md)
