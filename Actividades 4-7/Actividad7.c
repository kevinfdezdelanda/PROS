#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

//Programa en C que cree un proceso (tendremos un proceso padre y otro hijo). 
//El programa definirá una variable entera y le dará un valor 6. 
//El proceso padre incrementará dicho valor en 5 y el hijo restará 5. 

void main ()
{   
    int variable = 6;
    printf("Valor inicial de la variable: %d\n", variable);

    __pid_t pid;

    pid = fork();//creo el proceso hijo
    if (pid == -1){
            printf("No se ha podido crear el proceso hijo...");
            exit(0);
    }
    if (pid == 0) {////////// Nos encontramos en el proceso hijo
        //El hijo resta 5 a la variable
        variable -= 5;
        printf("Variable en Proceso Hijo: %d\n", variable);
    }else{ //nos encontramos en el padre
        //El padre suma 5 a la variable
        variable += 5;
        printf("Variable en Proceso Padre: %d\n", variable);
    }  
}