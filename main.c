#include <stdio.h>
#include <stdlib.h>


char asientos[32][6];
int getMenuOption();
void initializeSeats();
void showSeats();
char flight_number[256];
void readFlightNumber();


int main(){
  int option = getMenuOption();
  printf("%d\n", option);
}

int getMenuOption(){
  int op;
  printf("Bienvenido a la aerolinea: \n");
  printf("1. Reservar asiento \n");
  printf("2. Ver disponibilidad de asientos \n");
  printf("3. Salir \n");
  printf("Elija una opcion: \n");

  scanf("%d", &op);
  return op;
}

void initializeSeats(){
  for(int i = 0; i<32;i++){
    for(int j = 0; j<6;j++){
      asientos[i][j]= '0';
    }
  }
}

void showSeats() {
  printf("|     | A | B | C | E | F |\n");
  printf("___________________________\n");
  for(int i=0; i<32; i++){
    printf("| %2d | %c | %c | %c | %c | %c | %c |\n", i+1,asientos[i][0],asientos[i][1],asientos[i][2],asientos[i][3],asientos[i][4],asientos[i][5]);
    
  }
}

void readFlightNumber(){
  while (strlen(flight_number)!= 6){
    printf("Ingrese numero de vuelo: ");
    fgets(flight_number,sizeof(flight_number),stdin);
    if (strtlen(flight_number)!=6){
      printf("Numero invalido \n");
    } else {
      printf("Vuelo aceptado\n");
    }
  }
}

void clrScreen() {
  system("@cls||clear");
}

void waitEnter(){
  printf("Presione Enter\n");
  getchar();
}
