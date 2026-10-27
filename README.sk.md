<div align="center">

# B-ALPR

**Algoritmizácia a programovanie: prednášky, zadania cvičení a riešenia v jazyku C**

Zimný semester 2024/2025, FEI STU Bratislava. Prednášajúci: Mgr. Ján Grman, PhD.

[![Build](https://github.com/dmitthedazed/B-ALPR-ZS2024/actions/workflows/build.yml/badge.svg)](https://github.com/dmitthedazed/B-ALPR-ZS2024/actions/workflows/build.yml)
![C99](https://img.shields.io/badge/C-C99-A8B9CC?logo=c&logoColor=white)
![Prednášky](https://img.shields.io/badge/Predn%C3%A1%C5%A1ky-12-blue)
![Cvičenia](https://img.shields.io/badge/Cvi%C4%8Denia-11-blue)
[![License: MIT](https://img.shields.io/badge/License-MIT-lightgrey)](LICENSE)

<p align="center"><a href="README.md">English</a> · <b>Slovenčina</b></p>

</div>

> [!NOTE]
> Riešenia sa kompilujú v CI (`gcc -std=c99`) pri každej zmene súborov `labs/**/*.c`.

## Prednášky

Konspekty v Markdown, k nim pôvodné slajdy v [`assets/lectures/`](assets/lectures/).

| # | Téma | Kľúčové pojmy |
|:-:|------|---------------|
| 1 | [Úvod do algoritmizácie a programovania](lectures/01-uvod/prednaska-01.md) | algoritmus, prvý program, `printf`, dátové typy, premenné |
| 2 | [Konštanty, operátory a formátovaný I/O](lectures/02-konstanty-operatory/prednaska-02.md) | konštanty, aritmetické operátory, `scanf`/`printf`, `if-else` |
| 3 | [Cykly a mnohonásobné vetvenie](lectures/03-cykly/prednaska-03.md) | `while`, `do-while`, `for`, `switch`, `break`, `continue` |
| 4 | [Práca so súbormi](lectures/04-subory/prednaska-04.md) | `fopen`, `fclose`, `fprintf`, `fscanf`, textové a binárne súbory |
| 5 | [Funkcie, pamäť a statické polia](lectures/05-funkcie-polia/prednaska-05.md) | funkcie, deklarácia vs definícia, jednorozmerné polia, rekurzia |
| 6 | [Reťazce a úvod do ukazovateľov](lectures/06-retazce-ukazovatele/prednaska-06.md) | `char[]`, `strlen`, `strcpy`, `strcmp`, smerníky, `&`, `*` |
| 7 | [Ukazovatele, vyhľadávanie a usporiadanie](lectures/07-ukazovatele-vyhladavanie/prednaska-07.md) | pointer arithmetic, BubbleSort, QuickSort, binárne vyhľadávanie |
| 8 | [Dynamická pamäť a viacrozmerné polia](lectures/08-dynamicka-pamat/prednaska-08.md) | `malloc`, `calloc`, `realloc`, `free`, 2D polia, `argc`/`argv` |
| 9 | [Štruktúry, spájané zoznamy a bitové operácie](lectures/09-struktury-zoznamy/prednaska-09.md) | `struct`, `typedef`, `union`, linked list, `&`, `\|`, `^`, `<<`, `>>` |
| 10 | [Smerníky, hlbší pohľad](lectures/10-smernikovy-deep-dive/prednaska-10.md) | smerníky na smerníky, parametre funkcií, polia a smerníky |
| 11 | [Typová konverzia a preprocesor](lectures/11-typova-konverzia-preprocesor/prednaska-11.md) | implicitná/explicitná konverzia, `#define`, `#include`, makrá |
| 12 | [Záverečné opakovanie](lectures/12-opakovanie/prednaska-12.md) | časté chyby, opakovanie celého semestra |

## Cvičenia

Každé cvičenie má zadanie (`zadanie-NN.md`) a riešenie (`riesenie-NN.c`).

| # | Téma | Súvisiaca prednáška | Riešenie |
|:-:|------|:-------------------:|:--------:|
| 1 | [Úvod — prvý program v C](labs/01-uvod/zadanie-01.md) | [P1](lectures/01-uvod/prednaska-01.md) | [riesenie-01.c](labs/01-uvod/riesenie-01.c) |
| 2 | [Podmienky a vetvenie](labs/02-podmienky/zadanie-02.md) | [P2](lectures/02-konstanty-operatory/prednaska-02.md) | [riesenie-02.c](labs/02-podmienky/riesenie-02.c) |
| 3 | [Cykly a štatistika](labs/03-cykly-statistika/zadanie-03.md) | [P3](lectures/03-cykly/prednaska-03.md) | [riesenie-03.c](labs/03-cykly-statistika/riesenie-03.c) |
| 4 | [Práca so súbormi](labs/04-subory/zadanie-04.md) | [P4](lectures/04-subory/prednaska-04.md) | [riesenie-04.c](labs/04-subory/riesenie-04.c) |
| 5 | [Súbory a polia](labs/05-subory-polia/zadanie-05.md) | [P5](lectures/05-funkcie-polia/prednaska-05.md) | [riesenie-05.c](labs/05-subory-polia/riesenie-05.c) |
| 6 | [Reťazce](labs/06-retazce/zadanie-06.md) | [P6](lectures/06-retazce-ukazovatele/prednaska-06.md) | [riesenie-06.c](labs/06-retazce/riesenie-06.c) |
| 7 | [Substitučná šifra](labs/07-sifrovanie/zadanie-07.md) | [P7](lectures/07-ukazovatele-vyhladavanie/prednaska-07.md) | [riesenie-07.c](labs/07-sifrovanie/riesenie-07.c) |
| 8 | [Dvojrozmerné polia](labs/08-2d-polia/zadanie-08.md) | [P8](lectures/08-dynamicka-pamat/prednaska-08.md) | [riesenie-08.c](labs/08-2d-polia/riesenie-08.c) |
| 9 | [Dynamické polia](labs/09-dynamicke-polia/zadanie-09.md) | [P8](lectures/08-dynamicka-pamat/prednaska-08.md) | [riesenie-09.c](labs/09-dynamicke-polia/riesenie-09.c) |
| 10 | [Štruktúry](labs/10-struktury/zadanie-10.md) | [P9](lectures/09-struktury-zoznamy/prednaska-09.md) | [riesenie-10.c](labs/10-struktury/riesenie-10.c) |
| 11 | [Spájané zoznamy](labs/11-spajane-zoznamy/zadanie-11.md) | [P9](lectures/09-struktury-zoznamy/prednaska-09.md) | [riesenie-11.c](labs/11-spajane-zoznamy/riesenie-11.c) |

## Štruktúra

```
lectures/NN-tema/   prednaska-NN.md, images/
labs/NN-tema/       zadanie-NN.md, riesenie-NN.c
assets/lectures/    pôvodné PDF/PPTX prezentácie
```

## Ako študovať

1. Prečítaj prednášku v `lectures/NN-tema/prednaska-NN.md`.
2. Vyrieš zadanie z `labs/NN-tema/zadanie-NN.md`.
3. Porovnaj s `labs/NN-tema/riesenie-NN.c`.

Preloženie a spustenie riešenia:

```bash
gcc -std=c99 -Wall -o riesenie labs/01-uvod/riesenie-01.c && ./riesenie
```

## Náplň predmetu

1. Základné konštrukcie jazyka C
2. Vstup a výstup, podmienky, cykly
3. Premenné, pamäť, funkcie a základné údajové štruktúry
4. Práca so súbormi
5. Jednorozmerné polia a reťazce
6. Smerníky, štruktúry a zoznamy
7. Preprocesor jazyka C

## Literatúra

- **Kernighan, B. W. – Ritchie, D. M.** *Programovací jazyk C.* Brno: Computer Press, 2006. ISBN 80-251-0897-X.
- **Herout, P.** *Učebnice jazyka C: 1. díl.* České Budějovice: KOPP, 2009. ISBN 978-80-7232-383-8.
- **Virius, M.** *Jazyky C a C++: Kompletní průvodce.* Praha: Grada Publishing, 2011. ISBN 978-80-247-3917-5.
- **Wirth, N.** *Algoritmy a štruktúry údajov.* Bratislava: Alfa, 1989. ISBN 80-05-00153-3.
- **Prokop, J.** *Algoritmy v jazyku C a C++.* Praha: Grada Publishing, 2012.

---

<div align="center">

Dmytrii Savin ([@dmitthedazed](https://github.com/dmitthedazed)). Licensed under the [MIT License](LICENSE).

</div>
