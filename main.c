#include <stdio.h>
#include <stdlib.h>
#include "Montante.h"


int Menu(void);

int Menu( void ) {
    int op;
    system("cls"); //S.O. Limpia Pantalla
    printf("\n\n\n");
    printf("\t\t\tMenu Principal\n Matrizes\n");
    printf("\t\t\t===================\n");
    printf("\t\t\t1.- Calcular un sistema de ecuasiones lineales 3x3\n");
    printf("\t\t\t2.- Calcular la matriz inversa 3x3\n");
    printf("\t\t\t3.- Salir\n");
    printf("\t\t\tOpcion --> ");
    scanf("%d", &op);
    return( op );
}

int main(int argc, char *argv[])
{
  int Mo[MAX][MAX + 1], Mt[MAX][MAX + 1];
  int Opcion;

  do{

    Opcion = Menu();

    switch (Opcion) {
      case 1:{
      system("PAUSE");
      capDatos(Mo);
      impDatos(Mo);
      system("PAUSE");
      Proceso(Mo, Mt);
      impDatos(Mo);
      system("PAUSE");
    }

      case 2:{

      }


    }

  }while(Opcion > 2);

  return 0;
}
