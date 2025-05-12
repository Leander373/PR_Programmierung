#include <stdio.h>
#include <stdlib.h>

struct reiter
{
  float masse;
  float geschwindigkeit;
};

struct zustand
{
  struct reiter a;
  struct reiter b;
};

struct zustand stosse_reiter(struct zustand vorher);

int main(int argc, char **argv)
{

  if (argc != 5)
  {
    printf("Fehler: Falsche Anzahl an Parametern.\nVerwendung: %s <m1> <v1> <m2> <v2>\n", argv[0]);
    return 1;
  }

  struct reiter r_1 = {atof(argv[1]), atof(argv[2])}; // starting conditions input via command line
  struct reiter r_2 = {atof(argv[3]), atof(argv[4])};

  struct zustand vorher = {r_1, r_2}; // definition of prior state 

  struct zustand nachher = stosse_reiter(vorher);
  printf("Nach dem Stoß: v_1=%f, v_2=%f\n", nachher.a.geschwindigkeit, nachher.b.geschwindigkeit);

  return 0;
}

struct zustand stosse_reiter(struct zustand vorher) // check if collision takes place in the first place with three if-statements; computation of end state with corresponding values
{
  if (vorher.a.geschwindigkeit <= 0 && vorher.b.geschwindigkeit >= 0)
  {
    printf("Kein Stoss!\n");
    return vorher;
  }
  if (vorher.a.geschwindigkeit < 0 && vorher.b.geschwindigkeit < 0 && vorher.a.geschwindigkeit <= vorher.b.geschwindigkeit)
  {
    printf("Kein Stoss!\n");
    return vorher;
  }
  if (vorher.a.geschwindigkeit > 0 && vorher.b.geschwindigkeit > 0 && vorher.a.geschwindigkeit <= vorher.b.geschwindigkeit)
  {
    printf("Kein Stoss!\n");
    return vorher;
  }
  struct zustand nachher = vorher;

  nachher.a.geschwindigkeit = (vorher.a.masse * vorher.a.geschwindigkeit + vorher.b.masse * vorher.b.geschwindigkeit + vorher.b.masse * (vorher.b.geschwindigkeit - vorher.a.geschwindigkeit)) / (vorher.a.masse + vorher.b.masse);
  nachher.b.geschwindigkeit = (vorher.a.masse * vorher.a.geschwindigkeit + vorher.b.masse * vorher.b.geschwindigkeit + vorher.a.masse * (vorher.a.geschwindigkeit - vorher.b.geschwindigkeit)) / (vorher.a.masse + vorher.b.masse);

  return nachher;
}
