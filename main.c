#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 100

typedef struct{
    char nombre[MAX_CHAR];
    int posicion;
    int vel_max;
    char escuderia[MAX_CHAR];
}Piloto;


int main() {
    FILE *f;
    char nombre_fichero[100];
    char nombre_aux[30];
    int num_pilotos,posicion,velocidad;
    char *parte1,*linea,*linea2,*linea3,*linea4,*linea5;

    printf("Introduce el nombre del fichero: ");
    scanf("%s", nombre_fichero);

    f = fopen(nombre_fichero, "r");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        exit(1);
    }

    fscanf(f, "%d\n", &num_pilotos);
    Piloto* pilotos = (Piloto*) malloc(num_pilotos * sizeof(Piloto));

    for (int i = 0; i < num_pilotos; i++) {
        linea = malloc(sizeof(char*));
        fgets(linea,MAX_CHAR,f);
        parte1 = strtok(linea,":");
        parte1 = strtok(NULL,":");
        strcpy(pilotos[i].nombre,parte1);
        free(linea);

        linea2 = malloc(sizeof(char*));
        fgets(linea2,MAX_CHAR,f);
        parte1 = strtok(linea2,":");
        parte1 = strtok(NULL,":");
        parte1[strlen(parte1) - 1] = '\0';
        posicion = atoi(parte1);
        pilotos[i].posicion = posicion;
        free(linea2);

        linea3 = malloc(sizeof(char*));
        fgets(linea3,MAX_CHAR,f);
        parte1 = strtok(linea3,":");
        parte1 = strtok(NULL,":");
        parte1[strlen(parte1) - 1] = '\0';
        velocidad = atoi(parte1);
        pilotos[i].vel_max = velocidad;
        free(linea3);

        linea4 = malloc(sizeof(char*));
        fgets(linea4,MAX_CHAR,f);
        parte1 = strtok(linea4,":");
        parte1 = strtok(NULL,":");
        strcpy(pilotos[i].escuderia,parte1);
        free(linea4);

        linea5 = malloc(sizeof(char*));
        fgets(linea5,MAX_CHAR,f);
        free(linea5);
    }

    fclose(f);

    for(int i = 0; i < num_pilotos; i++){
        printf("El piloto%s de la escuderia%s ha acabado en la posicion %d.\n",pilotos[i].nombre,pilotos[i].escuderia,pilotos[i].posicion);
        printf("Y ha alcanzado una velocitat maxima de %dkm/h.\n\n",pilotos[i].vel_max);
    }

    free(pilotos);

    return 0;
}