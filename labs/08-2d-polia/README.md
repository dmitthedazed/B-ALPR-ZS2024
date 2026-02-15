# Cvičenie 8: Dvojrozmerné polia

> 📚 **Súvisiaca prednáška:** [Prednáška 8](../../lectures/08-dynamicka-pamat/)

## Základné požiadavky

- JEDEN súbor obsahujúci celý zdrojový kód, v jazyku C (ANSI C podľa prednášok), s názvom a v štruktúre podľa zverejnených inštrukcií (MSTeams)
- Programy musia komunikovať. Ak program očakáva vstup, musí oznamovať aký vstup sa očakáva. Ak vypisuje výsledok, musí vypisovať zrozumiteľný oznam (napr. čo za hodnotu to vypisuje).
- Formátovanie zdrojového kódu by malo zodpovedať približne príkladom z prednášok. Odsadzovanie textov je základ. Príklad dobrého a zlého formátovania sú v prednáške číslo dva na konci.

---

## Úloha prvá. Načítame maticu veľkosti 10x10.

Napíšte funkciu s prototypom:

```c
int NacitajMaticu(char *subor, int matica[10][10])
```

- Funkcia dostane ako parameter názov súboru a maticu (pozri nižšie uvedené odporúčané použitie funkcie).
  - a) Funkcia súbor otvorí (na konci súbor zatvorí) – pozor na testovanie
  - b) Funkcia následne číta zo súboru čísla:
    - Číta 100 celých čísel a ukladá do matice
    - Najľahšie sa použije `fscanf`, ale môžete použiť aj iné čítania
    - Funkcia vráti `0` ak sa nepodarí načítať 100 čísel (súbor sa nepodarilo otvoriť alebo na koniec súboru narazíte skôr ako načítate 100 čísel)
    - Funkcia vráti `1` ak sa čítanie podarí
  - c) Pozor, čísel v súbore môže byť viac (načítanie skončí tým, že počet skutočne načítaných bude rovný maximálnej veľkosti poľa – teda 100 čísel)
  - d) Pokojne predpokladajte, že v súbore sú len čísla, medzery, entery a prípadne tabulátory a nič iné.

---

## Úloha druhá. Analyzujeme maticu veľkosti 10x10.

Prototyp funkcie:

```c
int AnalyzujMaticu(int m[10][10], int *zaporne, int *neparne)
```

Funkcia dostane vyplnenú maticu. Počíta a v parametroch vráti:

- Počet záporných čísel (`< 0`)
- Počet nepárnych čísel

A vo výstupnom parametri funkcia vráti najväčšie číslo v matici.

> **Pozor:** Funkcia teda dostane maticu a počíta 3 čísla (pozri použitie na konci).

---

## Úloha tretia. Vypíšeme maticu veľkosti 10x10.

```c
int VypisMaticu(int m[10][10])
```

Funkcia vypíše maticu. Pekne do 10 riadkov a 10 stĺpcov. Pre každé číslo bude rezervovaných 5 pozícií (pomôcka – formátovanie v `printf`).

**Príklad riadku:**

```
   45   56  145    6   -3
```

Aby to bolo jasné, číslo spolu s medzerami zaberá 5 pozícií. Pomôcka: učili sme sa to prvú, alebo druhú prednášku pri `printf`.

---

## Predpokladané použitie v main()

```c
int m[10][10], zaporne, neparne, max;
if (NacitajMaticu("vstup.txt", m)) {
    max = AnalyzujMaticu(m, &zaporne, &neparne);
    VypisMaticu(m);
    printf("zaporne: %d, neparne: %d, maximum: %d", zaporne, neparne, max);
}
else {
    printf("citanie sa nepodarilo");
}
```

---

## 💡 Riešenie

Kompletné riešenie nájdete v súbore [solution.c](solution.c).

---

[⬅️ Späť: Cvičenie 7](../07-sifrovanie/) | [Domov](../../) | [Ďalej: Cvičenie 9 ➡️](../09-dynamicke-polia/)
