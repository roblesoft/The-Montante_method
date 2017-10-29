#include <stdio.h>

#define max 3

int main(int argc, char const *argv[]) {
    int m[max][max + 3];
    int t[max][max + 3];
    int i,j, aux = 3,  pant = 1, pact, iteracion = 0;

//Captura de Datos
    for( i = 0 ; i < max ; i ++){
      for( j = 0 ; j < max; j++){
        printf("valor [%i][%i] \n", i + 1, j + 1);
        scanf("%d", &m[i][j] );
      }
    }
//añade matriz identidad
    for( i = 0 ; i < max ; i ++){
      for( j = 3 ; j < max + 3; j++){
        if (aux == j) {
          m[i][j] = 1;
        }else m[i][j] = 0;
      }
      aux++;
    }
//metodo montante
    while( iteracion < max ) {
         pact = m[iteracion][iteracion];
         // todo el renglon pasa igual
         for( j = 0; j < max + 3; j++) {
           t[iteracion][j] = m[iteracion][j];
         }
         // elementos de columna clave en ceros
         for(i = 0; i < max; i++) {
           if(i != iteracion) {
             t[i][iteracion] = 0;
           }
         }
         for(i = 0; i < max; i++) {
          if( i != iteracion ) {
           for( j = 0; j < max + 3; j++ ) {
            if( j != iteracion ) {
             t[i][j] = ((pact * m[i][j]) - (m[iteracion][j] * m[i][iteracion])) / pant;
            }
           }
          }
         }
         for(i = 0; i < max; i++) {
          for( j = 0; j < max + 3; j++ ) {
            m[i][j] = t[i][j];
          }
         }
         iteracion++;
         pant = pact;
    }
    system("cls");


//impresion de Datos
    printf("La matriz inversa es \n\n\t A^-1 =   1 / %i   ", pant);

    for( i = 0 ; i < max ; i++)
    {
      for(j = 3; j < max + 3; j++ )
      {
        printf("|  %i  |", m[i][j]);
      }
      printf("\n\n");
      if(i >= 0) printf("\t\t\t   ");
    }
    system("PAUSE");

    return 0;
}
