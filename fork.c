#include <stdio.h>
#include <unistd.h>  //header file in POSIX-compliant os which provides access to the POSIX API

int main()
{
    pid_t pid;
    int x = 1;

    pid = fork();   //creates a new process (child)

    if(pid < 0)     //error in process creation
    { 
        printf("Error in creation of child process.\n");
    }

    else if(pid ==0)   //child Process
    {
        printf("Child process(PID %d) : x = %d\n", getpid(),++x);
    }

    else  //parent process
    {
        printf("Parent process(PID %d) : x = %d\n", getpid(),--x);
    }
}
