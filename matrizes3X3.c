/*
    PROGRAMA:       matrizes3X3.C
    AUTOR:          URIEL EDUARDO ROBLES NAVA
    FECHA:          18/03/17
    PROPOSITO:      Resolver un sistema de ecuaciones lineales y matriz inversa
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

void capDatos(int m[MAX][MAX + 1]);
void impDatos(int m[MAX][MAX + 1]);
void Proceso(int m[MAX][MAX + 1], int t[MAX][MAX + 1]);
void inversa(int mq[MAX][MAX + 3], int mr[MAX][MAX + 3]);
int menu(void);
int opcion, tipo, pant;
int Mt[MAX][MAX + 1];
int Mo[MAX][MAX + 1];
int Mq[MAX][MAX + 3];
int Mr[MAX][MAX + 3];

int main(int argc, char const *argv[]) {

    do {

      system("cls");
      opcion = menu();

      switch (opcion)
      {
        case 1:{
          capDatos(Mo);
          impDatos(Mo);
          system("PAUSE");
          Proceso(Mo, Mt);
          impDatos(Mo);
          system("PAUSE");
          break;
        }
        case 2:{
          inversa(Mq, Mr);
          system("PAUSE");
          break;
        }
      }
    } while(opcion <= 2);
  return 0;
}

int menu()
{
  int op;
  printf("\n\n\n");
  printf("\t\t\t MATRIZES 3X3 \n");
  printf("\t\t\t MENU\n");
  printf("\t\t\t==================\n");
  printf("\t\t\t1 - Sistema de Ecuaciones\n");
  printf("\t\t\t2 - Matriz Inversa\n");
  printf("\t\t\t3 - Salir\n");
  scanf("%d", &op );
  return op;
}

//Captura de Datos
void capDatos(int m[MAX][MAX + 1]) {
     int i, j;
     system("cls");
     printf("\n\n\n");
     printf("\t\t Captura de Datos\n");
     printf("\t\t==================\n");
     for( i = 0; i < MAX; i++ ) {
        for( j = 0; j < MAX + 1; j++ ) {
           printf("\t\t Dato[%d][%d]-> ", i + 1, j + 1);
           scanf("%d", &m[i][j]);
        }
     }
     return;
}

//impresion de  Datos
void impDatos( int m[MAX][MAX + 1] ) {
     int i, j;
     system("cls");
     printf("\n\n\n");
     printf("\t\t Sistema de Ecuaciones Lineales\n");
     printf("\t\t================================\n");
     for( i = 0; i < MAX; i++ ) {
        printf("\t\t Ec(%d) ", i + 1);
        for( j = 0; j < MAX; j++ ) {
           printf("%d%c + ", m[i][j], 88 + j);
        }
        printf("\b\b= %d", m[i][MAX]);
        printf("\n");
     }
     return;
}
//metodo para sistema de ecuaciones
void Proceso(int m[MAX][MAX + 1], int t[MAX][MAX + 1]) {
     int i, j, pant = 1, pact, iteracion = 0;
     while( iteracion < MAX ) {
          pact = m[iteracion][iteracion];
          // todo el renglon pasa igual
          for( j = 0; j < MAX + 1; j++) {
            t[iteracion][j] = m[iteracion][j];
          }
          // elementos de columna clave en ceros
          for(i = 0; i < MAX; i++) {
            if(i != iteracion) {
              t[i][iteracion] = 0;
            }
          }
          for(i = 0; i < MAX; i++) {
           if( i != iteracion ) {
            for( j = 0; j < MAX + 1; j++ ) {
             if( j != iteracion ) {
              t[i][j] = ((pact * m[i][j]) - (m[iteracion][j] * m[i][iteracion])) / pant;
             }
            }
           }
          }
          for(i = 0; i < MAX; i++) {
           for( j = 0; j < MAX + 1; j++ ) {
             m[i][j] = t[i][j];
           }
          }
          iteracion++;
          pant = pact;
     }
     for(i = 0; i < MAX; i++) {
       for( j = 0; j < MAX + 1; j++ ) {
         m[i][j] = m[i][j] / pant;
       }
     }
     return;
}

void inversa(int mq[MAX][MAX + 3], int mr[MAX][MAX + 3])
{
  int i, j, pant = 1, pact, iteracion = 0, aux = 3;
  system("cls");
  printf("\n\n\n");
  printf("\t\t Captura de Datos\n");
  printf("\t\t==================\n");

  //Captura de Datos
  for( i = 0 ; i < MAX ; i ++){
    for( j = 0 ; j < MAX; j++){
      printf("\t\t Dato[%i][%i] ->", i + 1, j + 1);
      scanf("%d", &mq[i][j] );
    }
  }
  //añade matriz identidad
  for( i = 0 ; i < MAX ; i ++){
    for( j = 3 ; j < MAX + 3; j++){
      if (aux == j) {
        mq[i][j] = 1;
      }else mq[i][j] = 0;
    }
    aux++;
  }
  while( iteracion < MAX ) {
       pact = mq[iteracion][iteracion];
       // todo el renglon pasa igual
       for( j = 0; j < MAX + 3; j++) {
         mr[iteracion][j] = mq[iteracion][j];
       }
       // elementos de columna clave en ceros
       for(i = 0; i < MAX; i++) {
         if(i != iteracion) {
           mr[i][iteracion] = 0;
         }
       }
       for(i = 0; i < MAX; i++) {
        if( i != iteracion ) {
         for( j = 0; j < MAX + 3; j++ ) {
          if( j != iteracion ) {
           mr[i][j] = ((pact * mq[i][j]) - (mq[iteracion][j] * mq[i][iteracion])) / pant;
          }
         }
        }
       }
       for(i = 0; i < MAX; i++) {
        for( j = 0; j < MAX + 3; j++ ) {
          mq[i][j] = mr[i][j];
        }
       }
       iteracion++;
       pant = pact;
  }
  system("cls");
  printf("\n\n\n");
  printf("\t\t================================\n");
  printf("\t\t      La Matriz Inversa es \n\n\t A^-1 =   1 / %i   ", pant);

  for( i = 0 ; i < MAX ; i++)
  {
    for(j = 3; j < MAX + 3; j++ )
    {
      printf("|  %i  |", mq[i][j]);
    }
    printf("\n\n");
    if(i >= 0) printf("\t\t\t   ");
  }
}
