#include <stdio.h>

void clearbuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

char read_char_non_newline(void) {
    int ch;
    do {
        ch = getchar();
    } while (ch == '\n' || ch == '\r');
    return (char)ch;
}

void cv2_prva(void) {
    int a, b;
    int mensie;

    printf("Uloha 1 - zadajte 2 cele cisla: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Neplatny vstup.\n");
        clearbuffer();
        return;
    }

    printf("Vacsie cislo: %d\n", (a > b) ? a : b);

    if (a < b) {
        mensie = a;
    } else {
        mensie = b;
    }
    printf("Mensie cislo: %d\n", mensie);
}

void cv2_druha(void) {
    char c;

    printf("Uloha 2 - zadajte 1 znak: ");
    c = read_char_non_newline();

    if (c >= 'a' && c <= 'z') {
        printf("Typ znaku: Male pismeno\n");
    } else if (c >= 'A' && c <= 'Z') {
        printf("Typ znaku: Velke pismeno\n");
    } else if (c >= '0' && c <= '9') {
        printf("Typ znaku: Cislo\n");
    } else {
        printf("Typ znaku: Iny znak\n");
    }
}

void cv2_tretia(void) {
    char c;

    printf("Uloha 3 - zadajte 1 znak: ");
    c = read_char_non_newline();

    printf("ASCII '%c': dec=%d, hex=0x%X\n", c, (unsigned char)c, (unsigned char)c);

    if (c >= 'a' && c <= 'z') {
        char upper = (char)(c - ('a' - 'A'));
        printf("Prevod na velke '%c': dec=%d, hex=0x%X\n",
               upper,
               (unsigned char)upper,
               (unsigned char)upper);
    }
}

void cv2_stvrta(void) {
    double f, c;

    printf("Uloha 4 - zadajte teplotu F: ");
    if (scanf("%lf", &f) != 1) {
        printf("Neplatny vstup.\n");
        clearbuffer();
        return;
    }

    c = (f - 32.0) * 5.0 / 9.0;
    printf("Teplota v stupnoch celzia: %.2f\n", c);

    if (c < 0.0) {
        printf("Mrzne\n");
    }
    if (c >= 100.0) {
        printf("Vrie\n");
    }
}

void cv2_piata(void) {
    int a, b, c;
    int min;

    printf("Uloha 5 - zadajte 3 cisla: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Neplatny vstup.\n");
        clearbuffer();
        return;
    }

    if (a < b) {
        if (a < c) {
            min = a;
        } else {
            min = c;
        }
    } else {
        if (b < c) {
            min = b;
        } else {
            min = c;
        }
    }

    printf("Najmensie cislo z %d %d %d je: %d\n", a, b, c, min);
}

void cv2_siesta(void) {
    int a, b, c;
    int t;

    printf("Uloha 6 - zadajte 3 cele cisla: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Neplatny vstup.\n");
        clearbuffer();
        return;
    }

    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    if (b > c) {
        t = b;
        b = c;
        c = t;
    }
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }

    printf("Usporiadany vysledok: %d %d %d\n", a, b, c);
}

void cv2_siedma(void) {
    char a, b, c;

    printf("Uloha 7 - zadajte 3 pismena: ");
    if (scanf(" %c %c %c", &a, &b, &c) != 3) {
        printf("Neplatny vstup.\n");
        clearbuffer();
        return;
    }

    if (a == b && b == c) {
        printf("Hodnotenie: Vsetky pismena su rovnake\n");
    } else if (a == b || a == c || b == c) {
        printf("Hodnotenie: Dve pismena su rovnake\n");
    } else {
        printf("Hodnotenie: Vsetky pismena su rozne\n");
    }
}

void cv2_osma(void) {
    double vyska_cm, hmotnost_kg;
    double vyska_m, bmi;

    printf("Uloha 8 - zadajte vysku v CM a hmotnost v KG: ");
    if (scanf("%lf %lf", &vyska_cm, &hmotnost_kg) != 2 || vyska_cm <= 0.0) {
        printf("Neplatny vstup.\n");
        clearbuffer();
        return;
    }

    vyska_m = vyska_cm / 100.0;
    bmi = hmotnost_kg / (vyska_m * vyska_m);

    printf("BMI je: %.3f\n", bmi);

    if (bmi <= 18.5) {
        printf("Podvaha\n");
    } else if (bmi < 25.0) {
        printf("Normalna hmotnost\n");
    } else if (bmi < 30.0) {
        printf("Nadvaha\n");
    } else {
        printf("Obezita\n");
    }
}

int main(void) {
    cv2_prva();
    clearbuffer();

    cv2_druha();
    clearbuffer();

    cv2_tretia();
    clearbuffer();

    cv2_stvrta();
    clearbuffer();

    cv2_piata();
    clearbuffer();

    cv2_siesta();
    clearbuffer();

    cv2_siedma();
    clearbuffer();

    cv2_osma();

    return 0;
}
