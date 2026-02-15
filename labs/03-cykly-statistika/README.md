# Cvičenie 3: Cykly a štatistika

> 📚 **Súvisiaca prednáška:** [Prednáška 3](../../lectures/03-cykly/)

## Základné požiadavky

- Už naozaj spracujte zadania do jediného C súboru
- Používajte výhradne ANSI C podľa prednášok
- Programy musia komunikovať. Ak program očakáva vstup, musí oznamovať
  aký vstup sa očakáva. Ak vypisuje výsledok, musí vypisovať zrozumiteľný
  oznam (napr. čo za hodnotu to vypisuje).
- Dodržujte formátovanie zdrojového kódu

> **Upozornenie:** Na riešenie žiadneho príkladu nie je povolené použiť pole! Sme sa to neučili, ale
> hlavne to nie je POTREBNÉ.

---

## Úloha prvá: Štatistika zoznamu čísel

Napíšte funkciu, ktorá načíta z klávesnice celé číslo `n`. Potom načíta `n` reálnych čísel
(pomôcka: načítavate čísla v cykle, v každej otočke cyklu máte práve jedno načítané
číslo a toto číslo si VHODNE započítate do štatistiky, pole nepotrebujete). Z tých
zadaných čísel vypočítate tieto parametre:

- Priemer záporných čísel (< 0), ak žiadne záporné, priemer je nula.
- Najväčšie z kladných čísel (>= 0), ak nebolo zadané žiadne kladné číslo, tak
  výsledok nech je nula.
- Počet čísel, ktoré sú v rozsahu −5.5 až 5.5.

Pri výpočte priemeru ošetrite delenie nulou.

**Príklad vstupu:**
```
Zadajte počet realnych cisel: 4
Zadajte 1.: 5.5
Zadajte 2.: -2.78
Zadajte 3.: 15.451
Zadajte 4.: 6
```

**Výstupom sú tieto 3 riadky:**
```
Priemer zapornych: -2.78
Maximum z kladnych: 15.45
Pocet v rozsahu -5.5 a 5.5: 2
```

---

## Úloha druhá: Štatistika na zadanom reťazci znakov

Napíšte funkciu, ktorá načíta znaky, kým nezadám enter (pomôcka: jednoducho čítate
v cykle znaky pomocou `getchar()`, znak po znaku, podobný cyklus v prednáške). Na
obrazovku vypíšem:

- Počet malých písmen (a–z)
- Počet veľkých písmen (A–Z)
- Počet číslic (0–9)

**Príklad:**
```
Zadajte retazec: abCDtzd3c

Male: 6
Velke: 2
Cisla: 1
```

---

## Úloha tretia: Zoznam deliteľov

Napíšte funkciu, ktorý načíta tri celé čísla `F`, `G` a `D` oddelené medzerou. Výstupom
je riadok obsahujúci všetky celé čísla od čísla `F` do čísla `G` deliteľné číslom `D`. Čísla
na výstupe sú usporiadané od najmenšieho po najväčšie a sú oddelené vždy jednou
medzerou. Výstup je ukončený koncom riadku.

```
Zadajte hranice interalu a delitel: 5 22 5
V intervale <5, 22> su delitelne cislom 5 cisla: 5 10 15 20
```

---

## Ďalšie úlohy

### Štvorec

Napíšte funkciu ktorá získa číslo `N` a nakreslí štvorec hviezdičiek N×N.

Pre N=3 napr.:
```
* * *
* * *
* * *
```

### Iný štvorec

Napíšte funkciu ktorá získa číslo `N` a nakreslí štvorec hviezdičiek N×N s okrajom
so znakom plus.

Pre N=4 napr.:
```
+ + + +
+ * * +
+ * * +
+ + + +
```

### Čudo

Napíšte funkciu ktorá získa číslo `N` a nakreslí štvorec hviezdičiek N×N ako na
obrázku pre N=7:

```
* + * + * + *
+ * + * + * +
* + * + * + *
+ * + * + * +
* + * + * + *
+ * + * + * +
* + * + * + *
```

---

## 💡 Riešenie

Kompletné riešenie nájdete v súbore [solution.c](solution.c).

---

[← Cvičenie 2](../02-podmienky/) | [Hlavná stránka](../../README.md) | [Cvičenie 4 →](../04-subory/)
