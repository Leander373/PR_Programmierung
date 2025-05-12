#include <stdio.h>
#include <stdlib.h>

struct Rakete {
  double masse_leer;
  double geschwindigkeit_rakete;

  double masse_treibstoff;
  double geschwindigkeit_treibstoff;
  double massenverlustrate_treibstoff;
};

void masseschritt(struct Rakete *rocket, double delta_masse);
void zeitschritt(struct Rakete *rocket, double delta_t);

int main(int argc, char **argv) {

  if (argc != 5) {
    printf("Fehler: Falsche Anzahl an Parametern.\nVerwendung: %s <masse_leer> <masse_treibstoff> <geschwindigkeit_treibstoff> <massenverlustrate_treibstoff>\n", argv[0]);
    return 1;
  }

  struct Rakete prototyp = {
      .masse_leer = atof(argv[1]),
      .geschwindigkeit_rakete = 0,
      .masse_treibstoff = atof(argv[2]),
      .geschwindigkeit_treibstoff = atof(argv[3]),
      .massenverlustrate_treibstoff = atof(argv[4])};

  struct Rakete rakete = prototyp;

  while (rakete.masse_treibstoff > 0) {
    masseschritt(&rakete, 1e-5);
  }

  printf("Endgeschwindigkeit: %f\n", rakete.geschwindigkeit_rakete);

  /*
    Berechnen Sie hier wann und wo die Endgeschwindigkeit erreicht wurde
  */
  // printf("Endgeschwindigkeit erreicht nach: t=%f, x=%f\n", ...);
  return 0;
}

void masseschritt(struct Rakete *rakete, double delta_masse) {
  /*
    Berechnen Sie hier wie sich die Raketengeschwindigkeit ändert,
    wenn eine kleine Masse delta_masse ausgestoßen wird.
    Vergessen Sie nicht die obige Fehlermeldung und den exit-Befehl zu entfernen.
  */
}

void zeitschritt(struct Rakete *rakete, double delta_t) {
  /*
    Berechnen Sie hier wie sich die Raketengeschwindigkeit und die
    zurückgelegte Strecke ändert, wenn eine kleine Masse gemäß des
    Massenverlusts ausgestoßen wird.
    Vergessen Sie nicht die obige Fehlermeldung und den exit-Befehl zu entfernen.
  */
}