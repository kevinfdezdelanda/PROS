#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

//Programa que un padre genere dos procesos hijos
//y que solo el segundo hijo genere a su vez otro proceso hijo

void main()
{
    __pid_t pid;
    
    for (size_t i = 1; i <= 2; i++)
    {
        pid = fork(); 
        if (pid == -1)
        {
            printf("No se ha podido crear el proceso hijo...");
            exit(0);
        }
        if (pid == 0)
        { ////////// Nos encontramos en el proceso hijo
            printf("Yo soy el hijo %d, Mi Padre es %d y mi PID es %d.\n", i, getppid(), getpid());
            if (i == 2)
            {
                pid = fork();
                if (pid == -1)
                {
                    printf("No se ha podido crear el proceso hijo...");
                    exit(0);
                }
                if (pid == 0)
                { ////////// Nos encontramos en el proceso hijo
                    printf("Yo soy el hijo 3, Mi Padre es %d y mi PID es %d.\n", getppid(), getpid());
                }
                else
                {
                    wait(NULL);
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            wait(NULL);
        }
    }
}