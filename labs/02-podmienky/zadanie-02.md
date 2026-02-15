# Cvičenie 2: Podmienky a vetvenie

> 📚 **Súvisiaca prednáška:** [Prednáška 2](../../lectures/02-konstanty-operatory/)

## Poznámky

- Programy píšete do jediného C súboru, zvykáme si na procedúry
- Píšeme v jazyku C (ANSI C podľa prednášok)
- Programy musia komunikovať. Ak program očakáva vstup, musí oznamovať
  aký vstup sa očakáva. Ak vypisuje výsledok, musí vypisovať zrozumiteľný
  oznam (napr. čo za hodnotu to vypisuje).
- Formátovanie zdrojového kódu by malo zodpovedať približne príkladom
  z prednášok. Odsadzovanie textov je základ. Príklad dobrého a zlého
  formátovania sú v prednáške číslo dva na konci.
- Tieto požiadavky sú platné až do konca semestra, pre zadania, písomky aj
  skúšku, všade kde sa odovzdáva ucelený program alebo funkcia.

## Klávesnicový buffer

Keď píšete vstup pre programy z klávesnice, používate takzvaný klávesnicový buffer.
Je to taká pomocná pamäť v ktorej sú uložené stlačené klávesy.
Toto cvičenie používa príkaz `getchar()`. Tento príkaz číta prvý znak z tejto pamäte.
Problém je, keď sa kombinujú volania príkazov `scanf()` a `getchar()`. Príkaz `scanf()`
Vám správne načíta vstupy, ale enter ktorým ste z klávesnice vstupy potvrdili
v bufferi nechá. Následné použitie `getchar()` potom načíta ešte tento enter. Toto sa
stáva pri reťazení príkladov. V tomto cvičení napríklad hneď ak by ste za sebou volali
prvý a druhý príklad. Preto si pomôžeme kódom, ktorým buffer vyčistíme.

Tu je funkcia ktorú si dajte do programu:

```c
void clearbuffer() {
    while ((getchar()) != '\n');
}
```

Tu je príklad jej použitia v `main()` medzi volaniami prvej a druhej úlohy:

```c
cv2_prva();
clearbuffer();
cv2_druha();
```

---

## Úloha prvá

Napíšte funkciu ktorá požiada užívateľa o dve celé čísla oddelené medzerou. Funkcia
vytlačí:

- a) Väčšie z čísel – povinne použite ternárny operátor `(podmienka) ? vyraz : vyraz`
- b) Menšie z čísel – povinne použite `if-else`

---

## Úloha druhá

Zložená podmienka. Napíšte funkciu, ktorý načíta 1 znak. Na načítanie znaku
povinne použite funkciu `getchar()`. Výstupom programu je informácia o tom, aký typ
znaku bol načítaný. Možnosti sú:

- Malé písmeno (a až z)
- Veľké písmeno (A až Z)
- Číslo (0 až 9)
- Iný znak

Pomôcka – môžete použiť vnorené podmienky. Demonštrujem na príklade, keď
sa mám tiež rozhodnúť pre 4 možnosti, teda či v premennej `A` je číslo 1, 2, 3
alebo iné číslo (príklad je ilustračný):

```c
if (a == 1) printf("jednotka");
else if (a == 2) printf("dvojka");
else if (a == 3) printf("trojka");
else printf("ine");
```

---

## Úloha tretia

Prevod znaku. Napíšte program, ktorý načíta ľubovoľnou funkciou 1 znak. Pre znak
vypíše jeho ASCII hodnotu v desiatkovej a hexadecimálnej sústave.
Ak bolo zadané malé písmeno (a až z), potom navyše toto prevedie aj na veľké
písmeno a rovnako vypíše jeho ASCII hodnotu v desiatkovej a hexadecimálnej
sústave.

---

## Ďalšie úlohy na precvičenie

Úlohy sú silno odporúčané. Ak získate schopnosť samostatne vypracovať
príklady zo zadaní, nemáte žiadny problém na písomkách a skúške.

4. Napíšte program na prevod stupňov Fahrenheita na stupne Celzia podľa vzorca:
   `c = (f – 32) * 5 / 9`. Vypíšte prevedenú hodnotu s presnosťou na 2 desatinné miesta. V
   prípade, že výsledná teplota je pod bodom mrazu, okrem výslednej teploty vypíšte
   správu `Mrzne`, v prípade teploty od 100 stupňov vypíšte správu: `Vrie`.

   ```
   Zadajte teplotu F: -58
   Teplota v stupňoch celzia: -50.00
   Mrzne
   ```

5. Napíšte program, ktorý načíta tri celé čísla a vypíše najmenšie z nich. Výstupom
   je jeden riadok obsahujúci správu `Najmensie cislo z c1 c2 c3 je: min`
   nasledovaný znakom konca riadku. Nie je povolené nič iné ako použitie podmienky
   `if-else`, žiadne špecializované funkcie.

   ```
   Zadajte 3 čísla: 7 2 9
   Najmensie cislo z 7 2 9 je: 2
   ```

6. Napíšte funkciu, ktorá načíta tri celé čísla a vypíše ich od najmenšieho po
   najväčšie. Výstupom je jeden riadok obsahujúci tri celé čísla oddelené medzerou.
   Riadok je ukončený znakom konca riadku. Len `if-else`, žiadne polia (ak by niekto aj
   vedel použiť)!

   ```
   Zadajte 3 celé čísla: 7 11 -4
   Usporiadaný výsledok: -4 7 11
   ```

7. Napíšte funkciu, ktorá načíta tri písmená nasledované znakom konca riadku.
   Výstupom je jeden riadok obsahujúci jednu zo správ: `Vsetky pismena su rozne`,
   `Dve pismena su rovnake` alebo `Vsetky pismena su rovnake`, v
   závislosti od pravdivosti danej správy. Riadok je ukončený znakom konca riadku.

   ```
   Zadajte 3 písmená: p v p
   Hodnotenie: Dve pismena su rovnake
   ```

8. Doplňte funkciu na výpočet BMI z predchádzajúcich cvičení o zatriedenie do
   kategórie podľa nasledujúcich pravidiel:

   | BMI           | Kategória          |
   |---------------|--------------------|
   | ≤ 18.5        | Podváha            |
   | (18.5, 25)    | Normálna hmotnosť  |
   | ⟨25, 30)      | Nadváha            |
   | ≥ 30          | Obezita            |

   ```
   Zadajte vysku v CM a hmotnost v KG: 170 58
   BMI je: 20.069
   Normalna hmotnost
   ```

---

## 💡 Riešenie

Kompletné riešenie nájdete v súbore [riesenie-02.c](riesenie-02.c).

---

[← Cvičenie 1](../01-uvod/) | [Hlavná stránka](../../README.md) | [Cvičenie 3 →](../03-cykly-statistika/)
