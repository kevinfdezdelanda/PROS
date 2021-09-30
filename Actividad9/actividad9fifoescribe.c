#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main (void)
{
	int fp;
	int p;
	char saludo[] = "Un saludo !!!!!\n";

    fp = open ("FIFO2", 1);//abro el Fifo

    if(fp == -1){ // Si el fifo no existe devuelve -1 y se crea de nuevo
        p=mknod("FIFO2", S_IFIFO|0666, 0); /// permiso de lectura y escritura
        
        fp = open ("FIFO2", 1); // una vez creado se abre en modo escritura
        if (fp == -1) {
            printf("Error al abrir el fichero... \n");
            exit (1);//sale si da un error
        }
    }

	printf("Mandando información al FIFO...\n");
	write (fp, saludo, sizeof(saludo));  // se manda la informacion
    close(fp);	
	return(0);
}