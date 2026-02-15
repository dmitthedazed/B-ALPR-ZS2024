# Cvičenie 1: Úvod — prvý program v C

> 📚 **Súvisiaca prednáška:** [Prednáška 1](../../lectures/01-uvod/)

Ahoj milý študent. Cvičenie na prvý týždeň je pomerne nenáročné, tak na zoznámenie sa.
Cvičenie je dôležité, aby ste poľahky získali maximum bodov na malých písomkách neskôr v
semestri. Prosím, než čokoľvek začnete fyzicky robiť, je dobré si zadanie raz prečítať celé až do
konca a až potom ho rozoberať a realizovať.

V tomto popise je uvedená možnosť programovania a spúšťania programov bez použitia projektu.
Podstatné je, že v každom prípade buď pracujete s osamoteným súborom typu C alebo
s projektom v ktorom je znova len jeden súbor typu C. Projekt má výhody pokiaľ ide o ladenie
programu, ale nastavenie je zložitejšie pre začiatočníka.

## Postup – krok za krokom

1. Nainštalujte si prostredie CODEBLOCKS (postup v MSTeams)
2. Spustite prostredie.
3. Najkratšia cesta ako začať je cez HLAVNE MENU.
4. Zvoľte File + New + Empty File
5. Otvorí sa Vám v editore prázdny súbor.
6. Hneď ho preuložte na disk. Menu – File + Save File
7. Vyberte adresár a MENO súboru napríklad `priezvisko_cv1.c` (dôležitá je prípona `.c`)

Pauza. Sme na dobrej ceste. Teraz budeme dychtivo písať svoj prvý program.
Tak píšem.

```c
/* priezvisko meno cislo */
/* cvicenie 1            */
/* 16.02.2020            */

#include <stdio.h>

int main()
{
    printf("Ahoj studenti ALPRE!\n");
    return 0;
}
```

Huh. A čo teraz?
Menu Build + Build and RUN. Alebo klávesová skratka F9.

V dolnej časti prostredia sledujem, ako kompilátor pracuje. Či som náhodou neurobil chybu.

Neurobil som a spustí sa program. Nečakajte nič svetoborné. Nedokáže to riadiť letovú prevádzku,
dokonca ani na letisku v Bratislave.

**Čo sme sa naučili?**

1. Otvoriť prostredie a založiť v ňom súbor. Vyplniť ho a spustiť.
2. Pri pohľade do menu File asi každý dokáže súbor po zmene vždy ULOŽIŤ (skúste si to, napríklad skratkou CTRL+S)
3. Tiež by ste vedeli si už existujúci súbor s príponou C otvoriť (Open alebo CTRL+O).
4. Program sa dá kontrolovať na správny preklad aj bez spúšťania (Build alebo CTRL+F9)

Výborne! Teraz sa pochváľte rodičom, na FB alebo Instagrame. Už ste programátor začiatočník
(poznámka pre tých ktorí majú za sebou roky programovania – snažím sa to odľahčiť, majte
prosím pochopenie, ďakujem).

Keď budete písať program, snažte sa v tom udržiavať poriadok. Je to Vaša vizitka.

> **Motivačná vsuvka:** Mám overené, že vždy sú študenti ktorí prišli na FEI a nevedia
> o programovaní alebo jazyku C NIČ. Mám overené, že časť s tých študentov sa naozaj naučí
> programovať a základy jazyka C. To je dobrá správa. Zlá správa je táto: BEZ TEBA TO NEJDE!
> Len pravidelná príprava a ideálne aj samostatné precvičovanie aj nad rámec zadaní vedie
> k cieľu. Čím ste v tejto téme slabší (alebo úplný začiatočník), tým viac sa musíte snažiť
> a pracovať. Budem to opakovať stále, niekto počúvne, niekto nie a končí to často známkou FX.

Skúste naozaj dodržať zadanie presne. Prečítajte si ho viackrát, ak treba. Pre lepšiu
zrozumiteľnosť používame pri ukážkach vstupu a výstupu znak konca riadku, ktorý je na vstupe
a výstupe neviditeľný.

---

## Príklad prvý: Špeciálne znaky

Upravte svoj prvý program. Vytvorte funkciu pre prvé zadania (príklad štruktúry kódu je
v MSTeams). Napíšte do neho príkaz `printf` tak, aby vypísal nasledujúci reťazec:

> Je tam *, &, dve lomítka, dolár, percento a jednoduchý apostróf.

Prvým znakom a posledným znakom, ktorý máte vytlačiť, je dvojitá uvodzovka. Už to je
špeciálny znak! Potom je tam tabulátor (nie je ho priamo vidieť, ale reťazec je odsadený), na
konci reťazca je ešte ENTER. V strede reťazca sú tiež niektoré znaky špeciálne.

Výsledkom má byť presne uvedený reťazec, znak po znaku rovnaký!
Špeciálne znaky sú uvedené v prednáške.

---

## Príklad druhý: Počítanie s číslami

Napíšte program, ktorý vypočíta objem a povrch kvádra. Vstupom je jeden riadok obsahujúci tri
celé čísla oddelené medzerou. Riadok je ukončený znakom konca riadku.

**Ukážka vstupu:**
```
Zadaj 3 cele cisla: 3 2 1
```

**Ukážka výstupu:**
```
Objem 3 x 2 x 1 je 6
Povrch 2 x 3 x 2 + 2 x 3 x 1 + 2 x 2 x 1 je 22
```
(viete rátať povrch? 6 obdĺžnikov, vždy dva a dva a dva rovnaké)

Pomôcka: Podobný program v prednáškach, len s nezmyselnejším výpočtom.

---

## Príklad tretí: Počítanie s reálnymi číslami

Napíšte program na výpočet obvodu a obsahu kruhu. Vstupom je jeden riadok obsahujúce jedno
reálne číslo predstavujúce polomer kruhu. Riadok je ukončený znakom konca riadku. Výstupom je
jeden riadok obsahujúci správu: `Kruh s polomerom r: obvod = o, obsah = s`, kde `r`
je polomer, `o` je vypočítaný obvod a `s` je vypočítaný obsah kruhu. Všetky reálne čísla na
výstupe vypíšte na 2 desatinné miesta.

**Ukážka vstupu:**
```
Zadaj polomer kruhu (realne cislo): 1.0
```

**Ukážka výstupu:**
```
Kruh s polomerom 1.00: obvod = 6.28, obsah = 3.14
```

---

## Príklady na hĺbkové precvičenie

1. Napíšte program, ktorý načíta tri reálne čísla a vypíše ich aritmetický priemer. Vstupom je
   jeden riadok obsahujúci tri reálne čísla oddelené medzerou. Riadok je ukončený znakom
   konca riadku. Výstupom je jeden riadok obsahujúci správu `Priemer cisel x y z je: p`
   nasledovaný znakom konca riadku. Čísla `x`, `y` a `z` sú načítané čísla a `p` je vypočítaný
   priemer.

   **Ukážka vstupu:**
   ```
   Zadaj 3 realne cisla: 3.5 4.8 7.561
   ```
   **Ukážka výstupu:**
   ```
   Priemer cisel 3.5 4.8 7.561 je: 5.287
   ```

2. Napíšte program, ktorý načíta ľubovoľné číslo a vypíše to isté číslo s 20%-nou daňou.
   Pokúste sa program zapísať bez použitia príkazu priradenia. Na vstupe načítajte celé číslo
   nasledované koncom riadku. Výstup pozostáva z dvoch riadkov, každý nasledovaný
   koncom riadku. V prvom riadku je `Cena bez dane:` nasledovaná načítaným číslom.
   V druhom riadku je `Predajna cena s danou 20%:` nasledovaná cenou s DPH.

   **Ukážkový vstup:**
   ```
   Zadaj cislo: 10
   ```
   **Ukážkový výstup:**
   ```
   Cena bez dane: 10
   Predajna cena s danou 20%: 12.0
   ```

3. Napíšte program, ktorý načíta výšku človeka v cm a hmotnosť v kg (ako reálne čísla)
   a vypočíta body mass index (BMI). BMI sa vypočíta podľa vzorca:

   $$BMI = \frac{hmotnosť\ v\ kg}{(výška\ v\ m)^2}$$

   Na vstupe načítajte 2 reálne čísla predstavujúce výšku a hmotnosť. Program si ich
   postupne načíta. Výstupom je jeden riadok obsahujúci správu `BMI:` nasledovanú
   vypočítanou hodnotou BMI a znakom konca riadku.

   **Príklad konverzácie:**
   ```
   Zadajte vysku v centimetroch: 170
   Zadajte hmotnost v kilogramoch: 58
   ```
   **Výstup:**
   ```
   BMI: 20.069
   ```

---

## 💡 Riešenie

Kompletné riešenie nájdete v súbore [solution.c](solution.c).

---

[Hlavná stránka](../../README.md) | [Cvičenie 2 →](../02-podmienky/)
