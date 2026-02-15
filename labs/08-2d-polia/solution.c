#include <stdio.h>

int NacitajMaticu(char *subor, int matica[10][10]) {
  FILE *f;

  if ((f = fopen(subor, "r")) == NULL) return 0;

  int r,s;
  for (r=0; r<10; r++) {
    for (s=0; s<10; s++) {
        if (fscanf(f, "%d", &matica[r][s]) != 1) {
          fclose(f);
          return 0;
        }
    }
  }
  fclose(f);
  return 1;
}

int AnalyzujMaticu(int m[10][10], int *zaporne, int *neparne) {
  int r,s, max;
  *zaporne = 0; *neparne = 0;
  max = m[0][0];
  for (r=0; r<10; r++) {
    for (s=0; s<10; s++) {
        if (m[r][s] > max) max = m[r][s];
        if (m[r][s] < 0) (*zaporne)++;
        if (m[r][s] %2 == 1) (*neparne)++;
    }
  }
  return max;
}

int VypisMaticu(int m[10][10]) {
    int r,s;
    for (r=0; r<10; r++) {
        for (s=0; s<10; s++) {
            printf("%5d", m[r][s]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
  int m[10][10], zaporne, neparne, max;
  if (NacitajMaticu("matica.txt", m)) {
      max = AnalyzujMaticu(m, &zaporne, &neparne);
      VypisMaticu(m);
      printf("zaporne: %d, neparne: %d, maximum: %d", zaporne, neparne, max);
  }
  else printf("citanie sa nepodarilo");
  return 0;
}
