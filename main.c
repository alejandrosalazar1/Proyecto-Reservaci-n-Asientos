#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char asientos[32][6];
int getMenuOption();
void initializeSeats();
void showSeats();
char flight_number[256];
void readFlightNumber();
void clrScreen();
void waitforEnter();
void makeReservation();
int *interpretSeat(char*);
char *getReservationSeat();


int main(){
    readFlightNumber();

    int option=0;
    while (option !=4){
      option = getMenuOption();
      switch (option){
        case 1: 
        // Reservar asiento
          break;

        case 2:
        // Ver asientos disponibles
          break;
        
        case 3:
        // Ver resumen
          break;

        case 4:
        // Salir
          printf("Gracias por usar el programa! \n");
          break;

        default:
        //Opcion incorrecta
          printf("La opcion es invalida. Por favor ingrese una opcion valida. \n");
          break;
      }
  }
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
    if (strlen(flight_number)!=6){
      printf("Numero invalido \n");
    } else {
      printf("Vuelo aceptado\n\n");
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

void makeReservation(){
  char *selectedSeat = getReservationSeat();
  int *numberSeats = interpretSeat(selectedSeat);
  printf("Posicion: %d-%d",numberSeats[0],numberSeats[1]);
}

char *getReservationSeat(){
  char* seat = malloc(3*sizeof(char));
  int valid =1;
  while (valid==1){
    clrScreen();
    printf("Ingrese el numero de asieto que desea reservar: \n");
    gets(seat);

    valid = validateSeat(seat);
    if(valid==1){
      printf("Asiento invalido, por favor ingrese otro asiento. \n");
      waitforEnter();
    }
  }
  return seat;
}

int *interpretSeat(char *selectedSeat){
  int columna = 0;
  int fila = 0;
  char letra;
  char numbers[2];
  int position[2];
  if (strlen(selectedSeat)==2){
    letra = selectedSeat[0];
    numbers[0] = selectedSeat[1];
    if (letra >= 'A' && letra <= 'Z'){
      columna = letra - 'A';
    } else if (letra >= 'a' && letra <= 'z'){
      columna = letra - 'a';
    }
    fila = atoi(numbers);
  } else {
    letra = selectedSeat[0];
    numbers[0]= selectedSeat[1];
    numbers[1]= selectedSeat[2];
    if (letra>='A'&& letra<= 'Z'){
      columna = letra - 'A';
    } else if (letra >= 'a'&& letra <= 'z'){
      columna = letra - 'a';
    }
    fila = atoi(numbers);
  }
  fila = fila - 1;
  position[0] = fila;
  position[1] = columna;
  return position;
}


