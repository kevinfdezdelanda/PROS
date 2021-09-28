#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
//Programa C que genere una estructura de procesos con un padre y 3 hijos. 
//Visualiza por cada hijo su PID y el del padre. Visualiza también el PID del padre de todos.

void main ()
{ 
    __pid_t pid;
    
    for (int i = 1; i <= 3; i++){//bucle que generara 3 hijos
        pid = fork();// el padre genera un hijo
        
        if (pid == -1){
            printf("No se ha podido crear el proceso hijo...");
            exit (-1);
        }
        if (pid == 0) {////////// Nos encontramos en el proceso hijo
            printf ("Soy el hijo %d, Mi Padre es %d y mi PID es %d.\n",i,  getppid(), getpid());
            exit(0);
            
        }
        wait(NULL); //hacemos esperar al hijo
    }
    
    printf ("Proceso Padre %d.\n", getpid());
}


