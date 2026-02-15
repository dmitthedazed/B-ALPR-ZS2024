# Cvičenie 10: Štruktúry

> 📚 **Súvisiaca prednáška:** [Prednáška 9](../../lectures/09-struktury-zoznamy/)

## Úvod

Uvažujte záznamy o študentoch, kde sa uchovávajú položky: priezvisko+meno (jedna položka), aktuálny ročník a priemer známok v aktuálnom ročníku. Nepredpokladajte prácu s reťazcami dlhšími ako 100 znakov.

```c
typedef struct student {
    char priezvisko_meno[100];
    int rocnik;
    float priemer;
} STUDENT;
```

---

## Úloha prvá. Štruktúra v poli – načítanie.

Napíšte funkciu `nacitajPole`, ktorá otvorí súbor daný v parametri (v `main()` funkciu volajte tak, že súbor sa bude volať `"vstup.txt"`). Prvý riadok obsahuje počet študentov. Funkcia potom dynamicky alokuje POLE (pomôcky: `malloc`, `sizeof(STUDENT)`) o študentoch a načíta záznamy o študentoch ZO SÚBORU. Každý údaj v súbore bude na samostatnom riadku. Predpokladajte správne formátovanie súboru. V tejto, ani žiadnej funkcii v zadaní nepoužívajte globálne premenné. Funkcia vracia alokované pole zoznam a v parametri aj skutočný počet študentov.

Povinný prototyp funkcie:

```c
STUDENT *nacitajPole(char *subor, int *nacitane)
```

**Príklad súboru:**

```
Jozko Mrkvicka
2.3
Ferko Maly
1.3
Anicka Svarna
1.2
```

Čiže pre každého študenta sú vždy 3 riadky:
- Priezvisko a Meno (`fgets` – nie `fscanf`, lebo ten Vám nenačíta medzeru)
- Ročník
- Priemer

---

## Úloha druhá. Štruktúra v poli – výpis.

Napíšte funkciu `vypisPole`, ktorá vypíše všetky záznamy, každý záznam v jednom riadku, pričom položky sú v riadku oddelené vždy znakom bodkočiarka `";"`.

Povinný prototyp funkcie:

```c
void vypis(STUDENT *studenti, int pocet)
```

**Príklad výpisu:**

```
Jozko Mrkvicka;1;2.3
Ferko Maly;2;1.3
Anicka Svarna;3;1.2
```

---

## Úloha tretia. Štruktúra v poli – analýza.

Napíšte funkciu `najlepsiPole`, ktorá vráti smerník na najlepšieho študenta (najlepší priemer známok) v ročníku (teda nie zo všetkých v zozname, len z ročníka). Ak pre daný ročník nie je študent, funkcia vráti `NULL`.

Povinný prototyp funkcie:

```c
STUDENT *najlepsiPole(STUDENT *studenti, int pocet, int rocnik)
```

---

## Demonštrácia v main()

```c
STUDENT *pole, *naj;
int pocet;
pole = nacitajPole("vstup.txt", &pocet);
if (pole == NULL) {
    printf("nepodarilo sa nacitat a naplnit pole");
    return -1;
}
vypisPole(pole, pocet);
naj = najlepsiPole(pole, pocet, 3);
if (naj == NULL) {
    printf("v rocniku nie je student");
    return -2;
}
printf("najlepsi student je %s", naj->priezvisko_meno);
return 0;
```

---

## 💡 Riešenie

Kompletné riešenie nájdete v súbore [solution.c](solution.c).

---

[⬅️ Späť: Cvičenie 9](../09-dynamicke-polia/) | [Domov](../../) | [Ďalej: Cvičenie 11 ➡️](../11-spajane-zoznamy/)
