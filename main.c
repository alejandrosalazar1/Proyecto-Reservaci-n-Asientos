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
void waitEnter();
void makeReservation();
int *interpretSeat(char*);
char *getReservationSeat();
int checkSeat(int, int);
void reserveSeat(int, int);
int validateSeat(char*);


int main(){
    clrScreen();
    readFlightNumber();

    int option=0;
    while (option !=4){

      option = getMenuOption();
      switch (option){
        case 1: 
        // Reservar asiento
          clrScreen();
          makeReservation();
          waitEnter();
          break;

        case 2:
        // Ver asientos disponibles
          clrScreen();
          waitEnter();
          break;
        
        case 3:
        // Ver resumen
          clrScreen();
          waitEnter();
          break;

        case 4:
        // Salir
          clrScreen();
          printf("Gracias por usar el programa! \n");
          break;

        default:
        //Opcion incorrecta
          printf("La opcion es invalida. Por favor ingrese una opcion valida. \n");
          printf("Presione Enter \n");
          getchar();

          break;
      }
  }
}

int getMenuOption(){
  clrScreen();
  int op;
  printf("Bienvenido a la aerolinea.  Vuelo#%s \n",flight_number);
  printf("1. Reservar asiento \n");
  printf("2. Ver disponibilidad de asientos. \n");
  printf("3. Ver resumen. \n");
  printf("4. Salir. \n");
  printf("Elija una opcion: \n");
  scanf("%d", &op);
  getchar();
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
      waitEnter();
    } else {
      //printf("Vuelo aceptado\n\n");
      initializeSeats();
    }
  }
}

void clrScreen() {
  system("@cls||clear");
}

void waitEnter(){
  printf("Presione Enter para continuar...\n");
  getchar();
}

void makeReservation(){
  int reservado = 1;
  int selectedRow;
  int selectedColumn;
  while (reservado ==1){
    clrScreen();
    char *selectedSeat = getReservationSeat();
    if (!strcmp(selectedSeat,"menu")){
      printf("Va a regresar al menu\n");
      break;
    }
    int* numberSeats = interpretSeat(selectedSeat);
    selectedRow = numberSeats[0];
    selectedColumn = numberSeats[1];
    if (checkSeat(selectedRow,selectedColumn) == 0) {
      reservado= 0;
      reserveSeat(selectedRow,selectedColumn);
    }
  }
  
}

char *getReservationSeat(){
  char* seat = malloc(3*sizeof(char));
  int valid =1;
  while (valid==1){
    clrScreen();
    printf("Ingrese el numero de asiento que desea reservar: \n");
    gets(seat);
    valid = validateSeat(seat);
    if(valid==1){
      printf("Asiento invalido, por favor ingrese otro asiento. \n");
      waitEnter();
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

int checkSeat(int fila, int columna){
  if (asientos[fila][columna]=='0'){
    return 0;
  } else {
    printf("El asiento esta reservado. Por favor ingrese otro asiento:");
    waitEnter();
    return 1;
  }
}

void reserveSeat(int fila, int columna){
  asientos[fila][columna]= 'X';
}

int validateSeat(char* selectedSeat){
  int columna =0;
  int fila=0;
  char letra;
  char numbers[2];

  if (strlen(selectedSeat)==2 || strlen(selectedSeat)==3){
    if (strlen(selectedSeat)==2){
      letra = selectedSeat[0];
      numbers[0] = selectedSeat[1];
      if ((letra >='A' && letra <= 'F')|| (letra >='a' && letra <= 'f')){
        fila= atoi(numbers);
    if (fila >=1 && fila<=32){
      return 0;
      }
    }
    return 1;
  }
  else{
    letra = selectedSeat[0];
    numbers[0] = selectedSeat[1];
    numbers[1] = selectedSeat[2];
    if ((letra >= 'A' && letra <= 'F') || (letra >= 'a' && letra <= 'f')){
      fila = atoi(numbers);
      if (fila >=1 && fila <=32){
        return 0;
      }
    }
    return 1;
  }
  }
  else {
    return 1;
  }
}


