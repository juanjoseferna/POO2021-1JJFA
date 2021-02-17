#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 100

typedef struct contacto contacto;

struct contacto{
   char name[ 20 ];
   char lastname[ 20 ];
   int numero;
};

void menu(){
   printf( "AGENDA\n"
           "=========\n"
           "1. add\n"
           "2. report\n"
           "3. list\n"
           "0. exit\n"
           "opc: " );
   return;
}

int main( int argc, char * argv[] ){
   FILE *f;
   contacto agenda[ CAP ], temp;
   int opc, n = 0, i, found,  j, val, total;
   int numero;
   char name[ 10 ];
   do{
      menu();
      scanf( "%d", &opc );
      switch( opc ){
         case 1:
            printf( "name= " ); scanf( "%s", agenda[ n ].name );
            printf( "lastname= " ); scanf( "%s", agenda[ n ].lastname );
            printf( "numero= " ); scanf( "%d", &agenda[ n ].numero );
            n++;
            break;
         case 2:
            for( i = 0; i < n; i++ )
               for( j = 0; j < n - 1; j++ )
                  if( agenda[ j ].numero > agenda[ j + 1 ].numero ){
                     temp = agenda[ j ];
                     agenda[ j ] = agenda[ j + 1 ];
                     agenda[ j + 1 ] = temp;
                  }
            f = fopen( "reporte.txt", "w" );
            fprintf( f, "DIRECTORIO\n" );
            for( i = 0; i < n; i++ ){
               fprintf( f, "%s - ", agenda[ i ].name);
               fprintf( f, "%s - ", agenda[ i ].lastname);
               fprintf( f, "%i", agenda[ i ].numero );
               fprintf( f, "\n");
            }
            fprintf( f, "\n" );
            fclose( f );
            system( "notepad reporte.txt" );
            break;
         case 3:
            for( i = 0; i < n; i++ )
               printf( "(%s, %s, %i) ", agenda[ i ].name,agenda[ i ].lastname, agenda[ i ].numero );
            printf( "\n" );
            break;
      }
   }while( opc != 0 );
   return 0;
}

