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
           "1. agregar contacto\n"
           "2. reporte\n"
           "3. lista\n"
           "4. contactos predefinidos \n"
           "0. exit\n"
           "opc: " );
   return;
}

int main( int argc, char * argv[] ){
   FILE *f;
   contacto agenda[ CAP ], temp;
   int opc, n = 0, i,  j;
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
               printf( "Nombre : %s %s Numero: %i\n", agenda[ i ].name,agenda[ i ].lastname, agenda[ i ].numero );
            printf( "\n" );
            break;
         case 4:
            strcpy(agenda[ n ].name, "Alberto");
            strcpy(agenda[ n ].lastname, "Lopez");
            agenda[ n ].numero = 227556;
            n++;
            strcpy(agenda[ n ].name, "Camila");
            strcpy(agenda[ n ].lastname, "Perez");
            agenda[ n ].numero = 275175;
            n++;
            strcpy(agenda[ n ].name, "Mariana");
            strcpy(agenda[ n ].lastname, "Caicedo");
            agenda[ n ].numero = 213267;
            n++;
            strcpy(agenda[ n ].name, "Policia");
            strcpy(agenda[ n ].lastname, "Nacional");
            agenda[ n ].numero = 123;
            n++;
      }
   }while( opc != 0 );
   return 0;
}