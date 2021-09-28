#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
//Programa C que genere una estructura de procesos que cada proceso genere 
//un hijo (cada hijo crea un hijo) hasta 5 nietos del proceso padre

void main ()
{ 
    __pid_t pid, pidNieto;
    printf ("Proceso Padre %d.\n", getpid());
    pid = fork();
    for (int i = 1; i <= 5; i++){
        
        if (pid == -1){
            printf("No se ha podido crear el proceso hijo...");
            exit(0);
        }
        if (pid == 0) {////////// Nos encontramos en el proceso hijo
            printf ("Soy el hijo %d, Mi Padre es %d y mi PID es %d.\n",i,  getppid(), getpid());
            pid = fork(); //proceso hijo crea nieto   
        }else{ //nos encontramos en el padre del proceso actual
            //hacemos esperar al padre 
            wait(NULL);
        } 

    }
    
}


