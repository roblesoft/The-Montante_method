#include <stdio.h>
#include <stdlib.h>
#include "Montante.h"

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
