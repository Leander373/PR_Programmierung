#include <stdio.h>
#include <stdlib.h>
// Authors: Jakob G., Christoph B., Mario N., Leander D.

// Struct for rocket
typedef struct {
  double masse_leer;
  double geschwindigkeit_rakete;

  double masse_treibstoff;
  double geschwindigkeit_treibstoff;
  double massenverlustrate_treibstoff;

  double time;
  double distance;
} Rakete;

void masseschritt(Rakete *rocket, double delta_masse);
void zeitschritt(Rakete *rocket, double delta_t);

int main(int argc, char **argv) {
    
  if (argc != 5) {
    printf("Fehler: Falsche Anzahl an Parametern.\nVerwendung: %s <masse_leer> <masse_treibstoff> <geschwindigkeit_treibstoff> <massenverlustrate_treibstoff>\n", argv[0]);
    return 1;
  }

  Rakete prototyp = {
      .masse_leer = atof(argv[1]),
      .geschwindigkeit_rakete = 0,
      .masse_treibstoff = atof(argv[2]),
      .geschwindigkeit_treibstoff = atof(argv[3]),
      .massenverlustrate_treibstoff = atof(argv[4])};

  Rakete rakete = prototyp;

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

void masseschritt(Rakete *rakete, double delta_masse) {
  if (delta_masse > rakete->masse_treibstoff) {
    printf("Fehler: Massenverlust größer als Treibstoffmasse.\n");
    return EXIT_FAILURE;
  }

  double dv_r = 0;    // Var for change in velocity
  // Calculate the change in velocity
  dv_r = (rakete->geschwindigkeit_treibstoff * delta_masse) / (rakete->masse_treibstoff + rakete->masse_leer);

  // Update the rocket's mass and velocity
  rakete->masse_treibstoff -= delta_masse;
  rakete->geschwindigkeit_rakete += dv_r;

  return EXIT_SUCCESS;
}

void zeitschritt(Rakete *rakete, double delta_t) {
  /*
    Berechnen Sie hier wie sich die Raketengeschwindigkeit und die
    zurückgelegte Strecke ändert, wenn eine kleine Masse gemäß des
    Massenverlusts ausgestoßen wird.
    Vergessen Sie nicht die obige Fehlermeldung und den exit-Befehl zu entfernen.
  */
  double delta_m = delta_t * rakete->massenverlustrate_treibstoff;
  if (delta_m > rakete->masse_treibstoff) {
    return EXIT_FAILURE;
  }
  // Update the rocket's time and distance
  rakete->distance += rakete->geschwindigkeit_rakete * delta_t;
  rakete->time += delta_t;

  // Compute the new velocity
  masseschritt(rakete, delta_m);

  return EXIT_SUCCESS;
}