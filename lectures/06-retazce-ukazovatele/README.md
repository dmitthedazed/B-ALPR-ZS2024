# Prednáška 6: Reťazce a úvod do ukazovateľov

| | |
|---|---|
| **Predmet** | Algoritmizácia a programovanie |
| **Prednášajúci** | Ján Grman |
| **Témy** | Reťazce ako špeciálne polia, Ukazovatele – prvý náhľad |

---

## Obsah

1. [Reťazce](#reťazce)
   1. [Čo sú to reťazce](#čo-sú-to-reťazce)
   2. [Definícia a inicializácia reťazca](#definícia-a-inicializácia-reťazca)
   3. [Rozdiel medzi `"x"` a `'x'`](#rozdiel-medzi-x-a-x)
   4. [Čítanie reťazca z klávesnice](#čítanie-reťazca-z-klávesnice)
   5. [Formátované čítanie – príklad](#formátované-čítanie--príklad)
   6. [Výpis reťazca na obrazovku](#výpis-reťazca-na-obrazovku)
   7. [Prístup k jednotlivým znakom reťazca](#prístup-k-jednotlivým-znakom-reťazca)
2. [Štandardné funkcie pre prácu s reťazcami](#štandardné-funkcie-pre-prácu-s-reťazcami)
   1. [Prehľad funkcií z `<string.h>`](#prehľad-funkcií-z-stringh)
   2. [Príklad: kopírovanie reťazca](#príklad-kopírovanie-reťazca)
   3. [Príklad: porovnávanie reťazcov](#príklad-porovnávanie-reťazcov)
   4. [Príklad: spojenie reťazcov](#príklad-spojenie-reťazcov)
   5. [Práca s obmedzenou časťou reťazca](#práca-s-obmedzenou-časťou-reťazca)
   6. [Práca s reťazcom naopak](#práca-s-reťazcom-naopak)
3. [Prevody reťazcov na čísla](#prevody-reťazcov-na-čísla)
4. [Formátovaný vstup a výstup z/do reťazca](#formátovaný-vstup-a-výstup-zdo-reťazca)
5. [Riadkovo orientovaný vstup a výstup](#riadkovo-orientovaný-vstup-a-výstup)
   1. [Z terminálu: `gets()` / `puts()`](#z-terminálu-gets--puts)
   2. [Zo súboru: `fgets()` / `fputs()`](#zo-súboru-fgets--fputs)
   3. [Príklad: riadkový I/O](#príklad-riadkový-io)
6. [Ukazovatele – prvý náhľad](#ukazovatele--prvý-náhľad)
   1. [Čo sú to ukazovatele](#čo-sú-to-ukazovatele)
   2. [Príklad ukazovateľa v pamäti](#príklad-ukazovateľa-v-pamäti)
   3. [Definícia ukazovateľa](#definícia-ukazovateľa)
   4. [Dereferenčný operátor `*`](#dereferenčný-operátor-)
   5. [Referenčný operátor `&`](#referenčný-operátor-)
   6. [Príklady správneho a nesprávneho použitia](#príklady-správneho-a-nesprávneho-použitia)
   7. [Nulový ukazovateľ `NULL`](#nulový-ukazovateľ-null)
7. [Volanie hodnotou a odkazom](#volanie-hodnotou-a-odkazom)
   1. [Volanie hodnotou](#volanie-hodnotou)
   2. [Volanie odkazom](#volanie-odkazom)
   3. [Príklad: výpočet kruhu](#príklad-výpočet-kruhu)
   4. [Príklad: výmena premenných](#príklad-výmena-premenných)
8. [Dynamická pamäť](#dynamická-pamäť)
   1. [Prideľovanie pamäte: `malloc()`](#prideľovanie-pamäte-malloc)
   2. [Dynamické polia](#dynamické-polia)
   3. [Uvoľňovanie pamäte: `free()`](#uvoľňovanie-pamäte-free)
   4. [Stack vs. Heap](#stack-vs-heap)
   5. [Príklad: ukazovatele krok za krokom](#príklad-ukazovatele-krok-za-krokom)
9. [Zhrnutie](#zhrnutie)

---

## Reťazce

<details><summary>📊 Slide</summary><img src="images/img-002.png"></details>

### Čo sú to reťazce

Reťazce sú **jednorozmerné polia typu `char`**:

- **Dĺžka reťazca** – ľubovoľná, obmedzená veľkosťou pamäte
- Z celkovej pamäte je aktívna len časť od začiatku poľa do znaku `'\0'` → **ukončovací znak** (null terminator)
- Ak reťazec nie je ukončený znakom `'\0'`, považuje sa za reťazec celá pamäť až do najbližšieho znaku `'\0'`

<details><summary>📊 Slide</summary><img src="images/img-003.png"></details>

---

### Definícia a inicializácia reťazca

```c
// Statický reťazec s najviac 6 znakmi:
char s[6] = "ahoj";
// s: ['a', 'h', 'o', 'j', '\0', ?]
//     0     1    2    3     4    5

// Veľkosť podľa inicializátora:
char s[] = "abrakadabra";   // miesta práve pre daný text + '\0'

// Väčšie pole ako potrebné:
char s[15] = "abrakadabra";  // zvyšné bajty sú '\0'
```

> **Pozor!** V C nie je možné priradiť statickému reťazcu konštantu po deklarácii:
> ```c
> char s[10];
> s = "ahoj";   // CHYBA!
> ```

<details><summary>📊 Slide</summary><img src="images/img-004.png"></details>

---

### Rozdiel medzi `"x"` a `'x'`

| Zápis | Typ | Veľkosť | Popis |
|-------|-----|---------|-------|
| `"x"` | reťazec (`char[]`) | 2 bajty | Jeden znak + ukončovací `'\0'` |
| `'x'` | znak (`char`) | 1 bajt | Jeden znak |

---

### Čítanie reťazca z klávesnice

```c
char s[10];
scanf("%s", s);   // sem nepatrí &, pretože s je už adresa
```

- `scanf()` **vynecháva biele znaky** a číta po prvý biely znak
- Ak je na vstupe `"   ahoj Eva!"`, `scanf()` prečíta iba `"ahoj"` a zvyšok zostáva v bufferi klávesnice

---

### Formátované čítanie – príklad

Program vypočíta celkovú sumu peňazí zo súboru, kde jednotlivé sumy sú vždy uvedené znakom `$` a znamienko `+` je pre príjem a `-` pre výdaj.

Príklad súboru:
```
+ $10 -$5-        $8
       +$20
```

```c
#include <stdio.h>

void main() {
    FILE *f;
    int kolko, suma = 0;
    char akcia[2];

    f = fopen("peniaze.txt", "r");
    while (fscanf(f, "%1s", akcia) != EOF) {   // %1s – prečíta 1 znak (nie medzeru)
        fscanf(f, "$%d", &kolko);               // $%d – $ preskočí biele znaky
        suma += (akcia[0] == '+') ? kolko : (-1 * kolko);
    }
    printf("Spolu: %d\n", suma);
    fclose(f);
}
```

> **Poznámka:** Namiesto `%1s` nemôže byť `%c`, pretože `%c` by prečítal aj medzeru, nie len prvý nebiely znak.

---

### Výpis reťazca na obrazovku

```c
#include <stdio.h>

void main() {
    char str[11];

    printf("Zadaj retazec: ");
    scanf("%10s", str);            // obmedzenie na 10 znakov
    printf("Retazec je: %s\n", str);
}
```

> **Tip:** Reťazec `str` má 11 znakov (10 + `'\0'`), preto je vhodné použiť `%10s` na obmedzenie vstupu.

---

### Prístup k jednotlivým znakom reťazca

Reťazec = jednorozmerné pole znakov → pracuje sa s ním ako s jednorozmerným poľom:

```c
char s[10];
int i;

// Naplnenie reťazca hviezdičkami
for (i = 0; i < 10 - 1; i++)
    s[i] = '*';
s[10 - 1] = '\0';   // dôležité: ukončiť reťazec!
```

---

## Štandardné funkcie pre prácu s reťazcami

Funkcie pre prácu s reťazcami **nie sú súčasťou samotného jazyka C** – sú definované v hlavičkovom súbore `<string.h>`.

### Prehľad funkcií z `<string.h>`

#### Základné funkcie

| Funkcia | Signatúra | Popis |
|---------|-----------|-------|
| `strlen` | `int strlen(char *s)` | Vráti dĺžku reťazca (bez `'\0'`) |
| `strcpy` | `char *strcpy(char *s1, char *s2)` | Skopíruje reťazec `s2` do `s1`, vráti ukazovateľ na `s1` |
| `strcat` | `char *strcat(char *s1, char *s2)` | Pripojí reťazec `s2` k `s1`, vráti ukazovateľ na `s1` |
| `strcmp` | `int strcmp(char *s1, char *s2)` | Vráti `0` ak sú rovnaké, záporné ak `s1 < s2`, kladné ak `s1 > s2` |
| `strchr` | `char *strchr(char *s, char c)` | Nájde **prvý** výskyt znaku `c` v reťazci `s`, ak nenájde vráti `NULL` |
| `strstr` | `char *strstr(char *s1, char *s2)` | Nájde **prvý** výskyt reťazca `s2` v `s1`, ak nenájde vráti `NULL` |

#### Varianty s obmedzenou dĺžkou (`n`)

| Funkcia | Signatúra | Popis |
|---------|-----------|-------|
| `strncpy` | `char *strncpy(char *s1, char *s2, int max)` | Kopíruje najviac `max` znakov z `s2` do `s1` |

#### Varianty s reverzným hľadaním (`r`)

| Funkcia | Signatúra | Popis |
|---------|-----------|-------|
| `strrchr` | `char *strrchr(char *s, char c)` | Nájde **posledný** výskyt znaku `c` v reťazci `s`, ak nenájde vráti `NULL` |

---

### Príklad: kopírovanie reťazca

Dva ekvivalentné spôsoby kopírovania:

```c
#include <string.h>

char s1[10], s2[] = "ahoj";
int i;

// Spôsob 1: pomocou strcpy()
strcpy(s1, s2);

// Spôsob 2: ručne, po znakoch
i = 0;
while (s2[i] != '\0') {
    s1[i] = s2[i];
    i++;
}
s1[i] = '\0';
```

---

### Príklad: porovnávanie reťazcov

Časť programu zistí, či sa reťazce rovnajú, prípadne, ktorý je neskôr v abecede:

```c
char x[10], y[10];
int r;

if ((r = strcmp(x, y)) == 0)
    printf("Retazce \"%s\" a \"%s\" sa rovnaju\n", x, y);
else if (r < 0)
    printf("Retazec \"%s\" < retazec \"%s\"\n", x, y);
else
    printf("Retazec \"%s\" < retazec \"%s\"\n", y, x);
```

---

### Príklad: spojenie reťazcov

Časť programu spojí názov súboru s príponou:

```c
char subor[20], nazov[10], pripona[5];

scanf("%s", nazov);
scanf("%s", pripona);

strcpy(subor, nazov);
strcat(subor, ".");
strcat(subor, pripona);
```

---

### Práca s obmedzenou časťou reťazca

Funkcie s **`n`** v názve (zo slova *number*) pracujú s obmedzeným počtom znakov:

```c
char *strncpy(char *s1, char *s2, int max);
// Kopíruje najviac max znakov z reťazca s2 do s1, vráti ukazovateľ na s1
```

---

### Práca s reťazcom naopak

Funkcie s **`r`** v názve (zo slova *reverse*) hľadajú od konca:

```c
char *strrchr(char *s, char c);
// Nájde posledný výskyt znaku c v reťazci s, ak sa nenachádza, vráti NULL
```

---

## Prevody reťazcov na čísla

Konvertovanie reťazca číslic na číslo – funkcie definované v `<stdlib.h>`:

| Funkcia | Signatúra | Popis |
|---------|-----------|-------|
| `atoi` | `int atoi(char *s)` | Prekonvertuje reťazec znakov na `int` |
| `atol` | `long atol(char *s)` | Prekonvertuje reťazec znakov na `long` |
| `atof` | `float atof(char *s)` | Prekonvertuje reťazec znakov na `float` |

> **Poznámka:** Pri vstupe a výstupe nie je konverzia potrebná (`scanf()` a `printf()` ju robia automaticky).

### Príklad: prevod reťazcov na čísla

Ak je prvý načítaný reťazec `"int"`, druhý reťazec sa prekonvertuje na číslo:

```c
char s1[100], s2[100];
int i;

scanf("%s %s", s1, s2);

if (!strcmp(s1, "int")) {
    i = atoi(s2);
    printf("Nacitalo sa cele cislo: %d\n", i);
} else {
    printf("Nacital sa retazec znakov: %s\n", s2);
}
```

---

## Formátovaný vstup a výstup z/do reťazca

Použitie výhod formátovaného vstupu a výstupu bez tlačenia na obrazovku alebo čítania zo vstupu:

| Funkcia | Signatúra | Popis |
|---------|-----------|-------|
| `sprintf` | `int sprintf(char *s, char *format, ...)` | Pracuje ako `fprintf`, ale zapisuje do reťazca `s` |
| `sscanf` | `int sscanf(char *s, char *format, ...)` | Pracuje ako `fscanf`, ale číta z reťazca `s` |

### Príklad 1: konverzia číselných sústav

```c
#include <stdio.h>

void main() {
    int i;
    char s1[5], s2[10];

    printf("Zadaj 4 hexa cislice: ");
    scanf("%s", s1);
    sscanf(s1, "%x", &i);     // načíta hexadecimálne číslo do i
    sprintf(s2, "%o", i);      // zapíše číslo i ako osmičkové do s2
    printf("%s\n", s2);
}
```

### Príklad 2: `sprintf()` vo funkcii

```c
void uradnik(char s[], double r) {
    double obsah, obvod;

    obsah = 3.14 * r * r;
    obvod = 2 * 3.14 * r;
    sprintf(s, "Kruh s polomerom %f ma obsah %f a obvod %f\n",
            r, obsah, obvod);
}

void sef(void) {
    char sprava[100];

    uradnik(sprava, 5.0);
    printf("Sprava o kruhu je:\n%s", sprava);
}
```

---

## Riadkovo orientovaný vstup a výstup

### Z terminálu: `gets()` / `puts()`

| Funkcia | Signatúra | Popis |
|---------|-----------|-------|
| `gets` | `char *gets(char *s)` | Číta celý riadok do `s`, nahradzuje `\n` za `'\0'`. Ak je riadok prázdny, vloží `'\0'` a vráti `NULL` |
| `puts` | `int puts(char *s)` | Vypíše reťazec a odriadkuje (`\n`). Vráti nezáporné číslo pri úspechu, inak `EOF` |

### Zo súboru: `fgets()` / `fputs()`

| Funkcia | Signatúra | Popis |
|---------|-----------|-------|
| `fgets` | `char *fgets(char *s, int max, FILE *fr)` | Číta riadok zo súboru, maximálne `max` znakov (aj s `\n`). Na konci súboru vráti `NULL` |
| `fputs` | `int fputs(char *s, FILE *fw)` | Zapíše reťazec `s` do súboru, **neodriadkuje** ani neukončuje `'\0'`. Vráti nezáporné číslo pri úspechu, inak `EOF` |

---

### Príklad: riadkový I/O

Program načíta riadok zo súboru a riadok zo štandardného vstupu, načítané reťazce vypíše na obrazovku a reťazec zapíše do súboru.

```c
#include <stdio.h>
#include <string.h>

int main() {
    FILE *f;
    char s[100];

    /* === Čítanie === */
    if ((f = fopen("subor.txt", "r")) == NULL) {
        printf("Subor sa nepodarilo otvorit na citanie.\n");
        return 1;
    }
    printf("%s", fgets(s, 100, f));
    printf("%s\n", gets(s));   // pridanie \n
    fclose(f);

    /* === Zápis === */
    if ((f = fopen("subor_zapis.txt", "w")) == NULL) {
        printf("Subor sa nepodarilo otvorit na zapis.\n");
        return 1;
    }
    fputs(s, f);
    fputs("\n", f);   // pridanie \n
    puts(s);

    fclose(f);
    return 0;
}
```

---

## Ukazovatele – prvý náhľad

<details><summary>📊 Slide</summary><img src="images/img-029.png"></details>

### Čo sú to ukazovatele

Ukazovatele (= pointery, smerníky):

- Ukazovateľ **je premenná**
- Jeho hodnota je **adresa v pamäti**
- **Analógia:** v texte článku nie je informácia priamo uvedená, ale je tam odkaz na iný článok, kde sa informácia nachádza

**Na čo sú dobré?**
- Keď je až za behu programu jasné, koľko pamäte budeme potrebovať (napr. ako veľké pole)

---

### Príklad ukazovateľa v pamäti

<details><summary>📊 Slide</summary><img src="images/img-031.png"></details>

| Koncept | Príklad | Vysvetlenie |
|---------|---------|-------------|
| Ukazovateľ `p` | zapísaný na adrese 73 | jeho hodnota je `30` – adresa, kde je uložená skutočná hodnota |
| `*p` (dereferencia) | hodnota na adrese 30 | = `25`, používa sa napr. pri výpočtoch |
| `p` | ukazovateľ | obsahuje adresu |
| `*p` | hodnota | kam ukazuje |

- **Pamäťové miesto pre ukazovateľ** – vznikne vytvorením premennej typu ukazovateľ (`p`)
- **Pamäťové miesto pre dáta** – je potrebné **vyhradiť (alokovať)**

---

### Definícia ukazovateľa

Ukazovateľ je definovaný pomocou `*`:

```c
int i;      // „klasická" celočíselná premenná
int *p_i;   // ukazovateľ na celočíselnú premennú
```

Ekvivalentné zápisy:

```c
int i;          int i,
int *p_i;           *p_i;
```

---

### Dereferenčný operátor `*`

Operátor `*` pristupuje k hodnote, na ktorú ukazovateľ ukazuje:

```c
int i, *p_i;
// ...
*p_i = i;    // obsah pamäte, na ktorú ukazuje p_i, sa prepíše hodnotou premennej i
```

> **Pozor!** Pred použitím `*p_i` treba inicializovať `p_i` – ukazovateľ musí ukazovať na platné miesto v pamäti (napr. vyhradiť/alokovať pamäť pre `p_i`).

<details><summary>📊 Slide</summary><img src="images/img-033.png"></details>

---

### Referenčný operátor `&`

Operátor `&` vráti **adresu premennej**:

```c
int i, *p_i;
p_i = &i;       // p_i teraz ukazuje na premennú i
```

Ekvivalentný zápis – definícia s inicializáciou:

```c
int i, *p_i = &i;
```

Po vykonaní `p_i = &i`:
- Hodnota `p_i` (adresa) sa prepíše **adresou premennej `i`**
- Hodnota `*p_i` je **tá istá** ako hodnota `i`

<details><summary>📊 Slide – pred priradením</summary><img src="images/img-035.png"></details>

<details><summary>📊 Slide – po priradení</summary><img src="images/img-036.png"></details>

---

### Príklady správneho a nesprávneho použitia

```c
p_i = &i;          // ✅ správne
p_i = &(i + 3);    // ❌ chyba: (i + 3) nie je premenná
p_i = &15;         // ❌ chyba: konštanta nemá adresu
p_i = 15;          // ❌ chyba: priraďovanie absolútnej adresy
i = p_i;           // ❌ chyba: priraďovanie adresy do int
i = &p_i;          // ❌ chyba: priraďovanie adresy do int
*p_i = 4;          // ✅ správne, ak p_i bol inicializovaný
```

---

### Nulový ukazovateľ `NULL`

- `NULL` — symbolická konštanta definovaná v `<stdio.h>`:
  ```c
  #define NULL 0
  #define NULL ((void *) 0)
  ```
- Je možné priradiť ho ukazovateľom na **ľubovoľný typ**:
  ```c
  if (p_i == NULL)
      // ukazovateľ neukazuje nikam
  ```

---

## Volanie hodnotou a odkazom

> V C **nie je volanie odkazom** – funkcie sa volajú len hodnotou. Vo funkcii vzniká kópia argumentu (lokálna premenná), ktorá zaniká s ukončením funkcie. Preto sa funkcia nevolá s premennou, ktorú chceme meniť, ale **s jej adresou**.

### Volanie hodnotou

`int A(int i)` — vytvorí sa **kópia** parametra na zásobníku:

<details><summary>📊 Slide – volanie hodnotou</summary><img src="images/img-040.png"></details>

### Volanie odkazom

`int A(int *i)` — predáva sa **adresa** premennej:

<details><summary>📊 Slide – volanie odkazom</summary><img src="images/img-041.png"></details>

---

### Príklad: výpočet kruhu

Funkcia `kruh()` vypočíta obvod a obsah kruhu. Výsledky vracia cez ukazovatele (volanie odkazom):

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

---

### Príklad: výmena premenných

```c
void vymen(int *p_x, int *p_y) {
    int pom;

    pom = *p_x;
    *p_x = *p_y;
    *p_y = pom;
}
```

Volanie funkcie:

```c
vymen(&i, &j);   // ✅ správne
```

> **Časté chyby:**
> - `vymen(i, j);` — ❌ chyba: vymieňa obsah na adresách daných hodnotami `i` a `j`
> - `vymen(*i, *j);` — ❌ chyba: z adries `i` a `j` sa zoberú hodnoty a tie sa použijú ako adresy

---

## Dynamická pamäť

### Prideľovanie pamäte: `malloc()`

Funkcia definovaná v `<stdlib.h>`:

```c
void *malloc(unsigned int pocet_bajtov);
```

- Vráti adresu prvého prideleného bajtu — je vhodné **pretypovať**
- Ak nie je v pamäti dosť miesta, vráti `NULL`

**Testovanie pridelenia pamäte:**

```c
int n, *p_i;

printf("Zadajte velkost pola.\n");
scanf("%d", &n);

if ((p_i = (int *) malloc(n * sizeof(int))) == NULL) {
    printf("Nepodarilo sa pridelit pamat\n");
    exit(1);
}
```

---

### Dynamické polia

Pomocou `malloc()` je možné prideliť blok pamäte – **dynamické pole**. Prístup k prvkom je rovnaký ako u statického poľa (cez indexy):

```c
int n, i, *p_i;

scanf("%d", &n);

if ((p_i = (int *) malloc(n * sizeof(int))) == NULL) {
    printf("Nepodarilo sa pridelit pamat\n");
    exit(1);
}

for (i = 0; i < n; i++)
    p_i[i] = i + 1;
```

<details><summary>📊 Slide – dynamické polia v pamäti</summary><img src="images/img-047.png"></details>

---

### Uvoľňovanie pamäte: `free()`

Nepotrebnú pamäť je vhodné ihneď vrátiť operačnému systému:

```c
char *p_c;

p_c = (char *) malloc(1000 * sizeof(char));
// ... práca s pamäťou ...
free(p_c);
p_c = NULL;   // dobrá prax: nastaviť na NULL po uvoľnení
```

---

### Stack vs. Heap

Prideľovanie pamäte za chodu programu:

| Oblasť | Správca | Popis |
|--------|---------|-------|
| **Zásobník (stack)** | Operačný systém | Automatické prideľovanie pre lokálne premenné |
| **Hromada (heap)** | Programátor | Manuálne prideľovanie cez `malloc()` / uvoľňovanie cez `free()` |

- **Životnosť dynamických dát:** od alokovania po uvoľnenie pamäte

<details><summary>📊 Slide</summary><img src="images/img-050.png"></details>

---

### Príklad: ukazovatele krok za krokom

```c
int i, *p, *q;

i = 5;
p = &i;         // p ukazuje na i
*p = 6;         // i = 6

q = &i;         // q tiež ukazuje na i
*q = 7;         // i = 7

p = (int *) malloc(sizeof(int));   // p ukazuje na nový blok
*p = 8;         // nový blok = 8
*q = *p;        // i = 8  (q stále ukazuje na i)
q = p;          // q teraz ukazuje na ten istý blok ako p
```

<details><summary>📊 Slide – vizualizácia</summary><img src="images/img-051.png"></details>

---

## Zhrnutie

**Ukazovatele – čo treba vedieť:**

- Využitie ukazovateľov na **vrátenie hodnoty z funkcie** prostredníctvom argumentov
- Porozumenie **funkciám na prácu s reťazcami**

---

[← Prednáška 5](../05-funkcie-polia/) | [Hlavná stránka](../../README.md) | [Prednáška 7 →](../07-ukazovatele-vyhladavanie/)
