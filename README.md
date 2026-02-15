# 🎓 Algoritmizácia a programovanie (B-ALPR)

> **Zimný semester 2024/2025** · FEI STU Bratislava  
> **Prednášajúci:** Mgr. Ján Grman, PhD.  
> **Jazyk:** C (ANSI C)

Kompletný archív kurzu — prednášky, cvičenia so zadaniami a riešeniami.

---

## 📋 Obsah

- [Prednášky](#-prednášky)
- [Cvičenia](#-cvičenia)
- [Pôvodné materiály](#-pôvodné-materiály)
- [Ako používať tento repozitár](#-ako-používať-tento-repozitár)
- [Náplň predmetu](#-náplň-predmetu)
- [Odporúčaná literatúra](#-odporúčaná-literatúra)

---

## 📖 Prednášky

| # | Téma | Kľúčové pojmy |
|:-:|------|---------------|
| 1 | [Úvod do algoritmizácie a programovania](lectures/01-uvod/) | algoritmus, prvý program, `printf`, dátové typy, premenné |
| 2 | [Konštanty, operátory a formátovaný I/O](lectures/02-konstanty-operatory/) | konštanty, aritmetické operátory, `scanf`/`printf`, `if-else` |
| 3 | [Cykly a mnohonásobné vetvenie](lectures/03-cykly/) | `while`, `do-while`, `for`, `switch`, `break`, `continue` |
| 4 | [Práca so súbormi](lectures/04-subory/) | `fopen`, `fclose`, `fprintf`, `fscanf`, textové a binárne súbory |
| 5 | [Funkcie, pamäť a statické polia](lectures/05-funkcie-polia/) | funkcie, deklarácia vs definícia, jednorozmerné polia, rekurzia |
| 6 | [Reťazce a úvod do ukazovateľov](lectures/06-retazce-ukazovatele/) | `char[]`, `strlen`, `strcpy`, `strcmp`, smerníky, `&`, `*` |
| 7 | [Ukazovatele, vyhľadávanie a usporiadanie](lectures/07-ukazovatele-vyhladavanie/) | pointer arithmetic, BubbleSort, QuickSort, binárne vyhľadávanie |
| 8 | [Dynamická pamäť a viacrozmerné polia](lectures/08-dynamicka-pamat/) | `malloc`, `calloc`, `realloc`, `free`, 2D polia, `argc`/`argv` |
| 9 | [Štruktúry, spájané zoznamy a bitové operácie](lectures/09-struktury-zoznamy/) | `struct`, `typedef`, `union`, linked list, `&`, `\|`, `^`, `<<`, `>>` |
| 10 | [Smerníky — hlboký ponor](lectures/10-smernikovy-deep-dive/) | smerníky na smerníky, parametre funkcií, polia a smerníky |
| 11 | [Typová konverzia a preprocesor](lectures/11-typova-konverzia-preprocesor/) | implicitná/explicitná konverzia, `#define`, `#include`, makrá |
| 12 | [Záverečné opakovanie](lectures/12-opakovanie/) | časté chyby, opakovanie celého semestra |

---

## 🔬 Cvičenia

Každé cvičenie obsahuje zadanie a kompletné riešenie v jazyku C.

| # | Téma | Súvisiaca prednáška | Riešenie |
|:-:|------|:-------------------:|:--------:|
| 1 | [Úvod — prvý program v C](labs/01-uvod/) | [P1](lectures/01-uvod/) | [solution.c](labs/01-uvod/solution.c) |
| 2 | [Podmienky a vetvenie](labs/02-podmienky/) | [P2](lectures/02-konstanty-operatory/) | [solution.c](labs/02-podmienky/solution.c) |
| 3 | [Cykly a štatistika](labs/03-cykly-statistika/) | [P3](lectures/03-cykly/) | [solution.c](labs/03-cykly-statistika/solution.c) |
| 4 | [Práca so súbormi](labs/04-subory/) | [P4](lectures/04-subory/) | [solution.c](labs/04-subory/solution.c) |
| 5 | [Súbory a polia](labs/05-subory-polia/) | [P5](lectures/05-funkcie-polia/) | [solution.c](labs/05-subory-polia/solution.c) |
| 6 | [Reťazce](labs/06-retazce/) | [P6](lectures/06-retazce-ukazovatele/) | [solution.c](labs/06-retazce/solution.c) |
| 7 | [Substitučná šifra](labs/07-sifrovanie/) | [P7](lectures/07-ukazovatele-vyhladavanie/) | [solution.c](labs/07-sifrovanie/solution.c) |
| 8 | [Dvojrozmerné polia](labs/08-2d-polia/) | [P8](lectures/08-dynamicka-pamat/) | [solution.c](labs/08-2d-polia/solution.c) |
| 9 | [Dynamické polia](labs/09-dynamicke-polia/) | [P8](lectures/08-dynamicka-pamat/) | [solution.c](labs/09-dynamicke-polia/solution.c) |
| 10 | [Štruktúry](labs/10-struktury/) | [P9](lectures/09-struktury-zoznamy/) | [solution.c](labs/10-struktury/solution.c) |
| 11 | [Spájané zoznamy](labs/11-spajane-zoznamy/) | [P9](lectures/09-struktury-zoznamy/) | [solution.c](labs/11-spajane-zoznamy/solution.c) |

---

## 📁 Pôvodné materiály

Originálne súbory z prednášok (PDF prezentácie) sú archivované v priečinku [`assets/`](assets/):

```
assets/
├── lectures/          # PDF/PPTX prezentácie prednášok
│   ├── 01_prednaska.pdf
│   ├── 02_prednaska.pdf
│   ├── ...
│   └── 12_prednaska_zaverecna.pptx
```

---

## 🚀 Ako používať tento repozitár

### Štruktúra projektu

```
B-ALPR-ZS2024/
├── README.md                          ← si tu
├── lectures/                          # 📖 Prednášky (12)
│   ├── 01-uvod/
│   │   ├── README.md                  # Konspekt prednášky
│   │   └── images/                    # Obrázky zo slajdov
│   ├── 02-konstanty-operatory/
│   ├── ...
│   └── 12-opakovanie/
├── labs/                              # 🔬 Cvičenia (11)
│   ├── 01-uvod/
│   │   ├── README.md                  # Zadanie
│   │   └── solution.c                 # Riešenie
│   ├── 02-podmienky/
│   ├── ...
│   └── 11-spajane-zoznamy/
└── assets/                            # 📁 Originálne PDF/PPTX
```

### Odporúčaný postup štúdia

1. **Prečítaj si prednášku** — otvor `lectures/NN-tema/README.md`
2. **Vyskúšaj si zadanie** — otvor `labs/NN-tema/README.md`
3. **Porovnaj s riešením** — pozri `labs/NN-tema/solution.c`
4. **Opakuj!** — kľúč k úspechu je pravidelné precvičovanie

---

## 📚 Náplň predmetu

1. Základné konštrukcie programovacieho jazyka C
2. Vstup a výstup, podmienky, cykly
3. Premenné, pamäť, funkcie a základné údajové štruktúry
4. Práca so súbormi
5. Práca s jednorozmernými poliami a reťazcami
6. Smerníky, štruktúry a zoznamy
7. Preprocesor jazyka C

---

## 📖 Odporúčaná literatúra

- **Kernighan, B. W. – Ritchie, D. M.** *Programovací jazyk C.* Brno: Computer Press, 2006. ISBN 80-251-0897-X.
- **Herout, P.** *Učebnice jazyka C: 1. díl.* České Budějovice: KOPP, 2009. ISBN 978-80-7232-383-8.
- **Virius, M.** *Jazyky C a C++: Kompletní průvodce.* Praha: Grada Publishing, 2011. ISBN 978-80-247-3917-5.
- **Wirth, N.** *Algoritmy a štruktúry údajov.* Bratislava: Alfa, 1989. ISBN 80-05-00153-3.
- **Prokop, J.** *Algoritmy v jazyku C a C++.* Praha: Grada Publishing, 2012.

---

<div align="center">

**B-ALPR · ZS 2024/2025 · FEI STU Bratislava**

</div>
