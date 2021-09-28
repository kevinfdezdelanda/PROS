#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

//Programa que un padre genere dos procesos hijos 
//y que solo el segundo hijo genere a su vez otro proceso hijo

void main ()
{
    __pid_t pid;

    pid = fork();//creo el primer hijo
    if (pid == -1){
            printf("No se ha podido crear el proceso hijo...");
            exit(0);
    }
    if (pid == 0) {////////// Nos encontramos en el proceso hijo
        printf ("Yo soy el hijo 1, Mi Padre es %d y mi PID es %d.\n", getppid(), getpid()); 
    }else{ //nos encontramos en el padre
        //hacemos esperar al padre 
        wait(NULL);
        pid = fork();//creo el segundo hijo
        if (pid == -1){
            printf("No se ha podido crear el proceso hijo...");
            exit(0);
        }
        if (pid == 0) {////////// Nos encontramos en el proceso hijo2
            printf ("Yo soy el hijo 2, Mi Padre es %d y mi PID es %d.\n", getppid(), getpid());
            pid = fork();
            if(pid == -1){
                printf("No se ha podido crear el proceso hijo...");
                exit(0);
            }
            if (pid == 0){
                printf ("Yo soy el hijo 3, Mi Padre es %d y mi PID es %d.\n", getppid(), getpid());
            }else{
                wait(NULL);
            } 
        }else{ //nos encontramos en el padre
            //hacemos esperar al padre 
            wait(NULL);
        }  
    }  
}