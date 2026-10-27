<div align="center">

# B-ALPR

**Algorithms and programming: lectures, lab assignments and solutions in C**

Winter semester 2024/2025, FEI STU Bratislava. Lecturer: Mgr. Ján Grman, PhD.

[![Build](https://img.shields.io/github/actions/workflow/status/dmitthedazed/B-ALPR-ZS2024/build.yml?style=flat-square&label=Build)](https://github.com/dmitthedazed/B-ALPR-ZS2024/actions/workflows/build.yml)
![C99](https://img.shields.io/badge/C-C99-A8B9CC?logo=c&logoColor=white&style=flat-square)
![Lectures](https://img.shields.io/badge/Lectures-12-blue?style=flat-square)
![Labs](https://img.shields.io/badge/Labs-11-blue?style=flat-square)
[![License: MIT](https://img.shields.io/badge/License-MIT-lightgrey?style=flat-square)](LICENSE)

<p align="center"><b>English</b> · <a href="README.sk.md">Slovenčina</a></p>

</div>

> [!NOTE]
> Archived. The course is over, so this repository is read-only and kept for reference.
>
> The lecture notes and assignments are written in Slovak. CI compiles every solution with `gcc -std=c99` whenever `labs/**/*.c` changes.

## Lectures

Notes in Markdown, with the original slides in [`assets/lectures/`](assets/lectures/).

| # | Topic | Key terms |
|:-:|---|---|
| 1 | [Introduction to algorithms and programming](lectures/01-uvod/prednaska-01.md) | algorithm, first program, `printf`, data types, variables |
| 2 | [Constants, operators and formatted I/O](lectures/02-konstanty-operatory/prednaska-02.md) | constants, arithmetic operators, `scanf`/`printf`, `if-else` |
| 3 | [Loops and multiway branching](lectures/03-cykly/prednaska-03.md) | `while`, `do-while`, `for`, `switch`, `break`, `continue` |
| 4 | [Working with files](lectures/04-subory/prednaska-04.md) | `fopen`, `fclose`, `fprintf`, `fscanf`, text and binary files |
| 5 | [Functions, memory and static arrays](lectures/05-funkcie-polia/prednaska-05.md) | functions, declaration vs definition, 1D arrays, recursion |
| 6 | [Strings and an introduction to pointers](lectures/06-retazce-ukazovatele/prednaska-06.md) | `char[]`, `strlen`, `strcpy`, `strcmp`, pointers, `&`, `*` |
| 7 | [Pointers, searching and sorting](lectures/07-ukazovatele-vyhladavanie/prednaska-07.md) | pointer arithmetic, BubbleSort, QuickSort, binary search |
| 8 | [Dynamic memory and multidimensional arrays](lectures/08-dynamicka-pamat/prednaska-08.md) | `malloc`, `calloc`, `realloc`, `free`, 2D arrays, `argc`/`argv` |
| 9 | [Structs, linked lists and bit operations](lectures/09-struktury-zoznamy/prednaska-09.md) | `struct`, `typedef`, `union`, linked list, `&`, `\|`, `^`, `<<`, `>>` |
| 10 | [Pointers in depth](lectures/10-smernikovy-deep-dive/prednaska-10.md) | pointers to pointers, function parameters, arrays and pointers |
| 11 | [Type conversion and the preprocessor](lectures/11-typova-konverzia-preprocesor/prednaska-11.md) | implicit/explicit conversion, `#define`, `#include`, macros |
| 12 | [Final review](lectures/12-opakovanie/prednaska-12.md) | common mistakes, review of the whole semester |

## Labs

Each lab has an assignment (`zadanie-NN.md`) and a solution (`riesenie-NN.c`).

| # | Topic | Related lecture | Solution |
|:-:|---|:-:|:-:|
| 1 | [Introduction: first C program](labs/01-uvod/zadanie-01.md) | [P1](lectures/01-uvod/prednaska-01.md) | [riesenie-01.c](labs/01-uvod/riesenie-01.c) |
| 2 | [Conditions and branching](labs/02-podmienky/zadanie-02.md) | [P2](lectures/02-konstanty-operatory/prednaska-02.md) | [riesenie-02.c](labs/02-podmienky/riesenie-02.c) |
| 3 | [Loops and statistics](labs/03-cykly-statistika/zadanie-03.md) | [P3](lectures/03-cykly/prednaska-03.md) | [riesenie-03.c](labs/03-cykly-statistika/riesenie-03.c) |
| 4 | [Working with files](labs/04-subory/zadanie-04.md) | [P4](lectures/04-subory/prednaska-04.md) | [riesenie-04.c](labs/04-subory/riesenie-04.c) |
| 5 | [Files and arrays](labs/05-subory-polia/zadanie-05.md) | [P5](lectures/05-funkcie-polia/prednaska-05.md) | [riesenie-05.c](labs/05-subory-polia/riesenie-05.c) |
| 6 | [Strings](labs/06-retazce/zadanie-06.md) | [P6](lectures/06-retazce-ukazovatele/prednaska-06.md) | [riesenie-06.c](labs/06-retazce/riesenie-06.c) |
| 7 | [Substitution cipher](labs/07-sifrovanie/zadanie-07.md) | [P7](lectures/07-ukazovatele-vyhladavanie/prednaska-07.md) | [riesenie-07.c](labs/07-sifrovanie/riesenie-07.c) |
| 8 | [Two-dimensional arrays](labs/08-2d-polia/zadanie-08.md) | [P8](lectures/08-dynamicka-pamat/prednaska-08.md) | [riesenie-08.c](labs/08-2d-polia/riesenie-08.c) |
| 9 | [Dynamic arrays](labs/09-dynamicke-polia/zadanie-09.md) | [P8](lectures/08-dynamicka-pamat/prednaska-08.md) | [riesenie-09.c](labs/09-dynamicke-polia/riesenie-09.c) |
| 10 | [Structs](labs/10-struktury/zadanie-10.md) | [P9](lectures/09-struktury-zoznamy/prednaska-09.md) | [riesenie-10.c](labs/10-struktury/riesenie-10.c) |
| 11 | [Linked lists](labs/11-spajane-zoznamy/zadanie-11.md) | [P9](lectures/09-struktury-zoznamy/prednaska-09.md) | [riesenie-11.c](labs/11-spajane-zoznamy/riesenie-11.c) |

## Tests

`tests/run.sh` builds labs 1, 3, 4 and 7 to 11 with AddressSanitizer and UBSan, runs them on the fixtures in `tests/NN-name/` (`stdin` plus input files) and compares stdout with `expected`. Labs 2, 5 and 6 are not covered yet.

```sh
tests/run.sh
```

## Layout

```text
lectures/NN-topic/   prednaska-NN.md, images/
labs/NN-topic/       zadanie-NN.md, riesenie-NN.c
assets/lectures/     original PDF/PPTX slides
```

## How to study

1. Read the lecture in `lectures/NN-topic/prednaska-NN.md`.
2. Solve the assignment in `labs/NN-topic/zadanie-NN.md`.
3. Compare with `labs/NN-topic/riesenie-NN.c`.

Build and run a solution:

```sh
gcc -std=c99 -Wall -o riesenie labs/01-uvod/riesenie-01.c && ./riesenie
```

## Course syllabus

1. Basic constructs of the C language
2. Input and output, conditions, loops
3. Variables, memory, functions and basic data structures
4. Working with files
5. One-dimensional arrays and strings
6. Pointers, structs and lists
7. The C preprocessor

## Literature

- **Kernighan, B. W. – Ritchie, D. M.** *Programovací jazyk C.* Brno: Computer Press, 2006. ISBN 80-251-0897-X.
- **Herout, P.** *Učebnice jazyka C: 1. díl.* České Budějovice: KOPP, 2009. ISBN 978-80-7232-383-8.
- **Virius, M.** *Jazyky C a C++: Kompletní průvodce.* Praha: Grada Publishing, 2011. ISBN 978-80-247-3917-5.
- **Wirth, N.** *Algoritmy a štruktúry údajov.* Bratislava: Alfa, 1989. ISBN 80-05-00153-3.
- **Prokop, J.** *Algoritmy v jazyku C a C++.* Praha: Grada Publishing, 2012.

## License

[MIT](LICENSE) © Dmytrii Savin
