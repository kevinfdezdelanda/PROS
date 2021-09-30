#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main (void)
{
	int fp;
	int p, bytesleidos;
	char saludo[] = "Un saludo !!!!!\n", buffer [10];

	while (1) {
		fp = open ("FIFO2", 0); // abro el fifo en lectura
		bytesleidos = read(fp, buffer, 1);//leo un byte del fifo
		printf("Obteniendo información...\n"); 
		while (bytesleidos != 0) { //voy leyendo byte a byte
			printf("%s", buffer); // escribo el byte
			bytesleidos = read (fp, buffer, 1); // leo otro byte
	}
	close (fp);//cierro el fifo
}
return(0);
}