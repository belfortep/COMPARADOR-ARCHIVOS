#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NOMBRE_ARCHIVO 100
#define MAX_LINEA_CARACTERES 1000

int main()
{
        char nombre_primer_archivo[MAX_NOMBRE_ARCHIVO];
        char nombre_segundo_archivo[MAX_NOMBRE_ARCHIVO];

        printf("Nombre primer archivo\n");
        scanf("%s", nombre_primer_archivo);
        printf("Nombre segundo archivo\n");
        scanf("%s", nombre_segundo_archivo);

        FILE *primer_archivo = fopen(nombre_primer_archivo, "r");
        FILE *segundo_archivo = fopen(nombre_segundo_archivo, "r");

        if(!primer_archivo)
                return 0;
        if(!segundo_archivo)
                return 0;

        char linea_primer_archivo[MAX_LINEA_CARACTERES];
        char linea_segundo_archivo[MAX_LINEA_CARACTERES];
        bool error = false;        

        while((!feof(primer_archivo) || !feof(segundo_archivo)) && !error)
        {
                fgets(linea_primer_archivo, MAX_LINEA_CARACTERES, primer_archivo);
                fgets(linea_segundo_archivo, MAX_LINEA_CARACTERES, segundo_archivo);
                
                if(strcmp(linea_primer_archivo, linea_segundo_archivo) != 0)
                {
                        error = true;
                }
        }

        if(error)
                printf("no son iguales");
        if(!error)
                printf("Son iguales");

        fclose(primer_archivo);
        fclose(segundo_archivo);

        return 0;
}