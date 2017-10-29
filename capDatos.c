#include <stdio.h>
#include <stdlib.h>
#include "Montante.h"

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
