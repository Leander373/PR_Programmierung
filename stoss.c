#include <stdio.h>
#include <stdlib.h>

struct reiter {
  float masse;
  float geschwindigkeit;
};

struct zustand {
  struct reiter a;
  struct reiter b;
};

struct zustand stosse_reiter(struct zustand vorher);

int main(int argc, char **argv) {

  if (argc != 5) {
    printf("Fehler: Falsche Anzahl an Parametern.\nVerwendung: %s <m1> <v1> <m2> <v2>\n", argv[0]);
    return 1;
  }

  /*
    Definieren Sie hier die stoßenden Reiter
  */

  struct zustand vorher = {};

  struct zustand nachher = stosse_reiter(vorher);
  printf("Nach dem Stoß: va=%f, vb=%f\n", nachher.a.geschwindigkeit, nachher.b.geschwindigkeit);

  return 0;
}

struct zustand stosse_reiter(struct zustand vorher) {
  /*
    Definieren Sie hier den Stoßprozess
  */
}
