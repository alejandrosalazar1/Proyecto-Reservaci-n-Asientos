#include <stdio.h>
#include <stdlib.h>

int main(){
  int opcion;
  char numero_vuelo[5];
  bienvenida:
  printf("Bienvenido, ingrese numero de vuelo:\n");
  scanf("%c", &numero_vuelo);
  
  if ((strlen(numero_vuelo)==5)){
    goto bienvenida; 
    
  } else { 
    while(opcion !=4){
    printf("====================\n");
    printf("1. Reservar asientos \n 2. Ver asientos disponibles \n 3. Ver Resumen \n 4. Salir \n ¿Que desea realizar? \n-> ");
  }
  }
  
}

