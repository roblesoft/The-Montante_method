#include <stdio.h>
#include <stdlib.h>
#include "Montante.h"

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
