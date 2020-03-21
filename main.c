#include <stdio.h>
#include <stdlib.h>

int main(){
char asientos[32][6];
int getMenuOption();
void initializeSeats();
void showSeats();

int main
{
  int option = getMenuOption();
  printf("%d\n", option);
}

int getMenuOption(){
  int op;
  printf("Bienvenido a la aerolinea \n");
  printf("1. Reservar asiento \n");
  printf("2. Ver disponibilidad de asientos \n")
  printf("3. Salir \n")
  printf("Elija una opcion: \n");

  scanf_s("%d", &op);
  return op;
}

