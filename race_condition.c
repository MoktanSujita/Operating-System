#include<pthread.h>
#include<stdio.h>
#include<unistd.h>  //includes functions like sleep

int shared=2;

void *fun1()
{
    int x;
    x = shared;  //value assignment
    printf("Thread1 reads the value of the shared %d\n", x);

    x++;  //increment by one
    printf("Value updation!");
    sleep(1); //skip execution for one sec
    shared = x;
    printf("Value of the shared variable:%d\n", shared);
}

void *fun2()
{
    int y;
    y = shared;
    printf("Thread2 reads the value of the shared %d\n" ,y);
    y--;
    sleep(1);  //skip execution for 1 sec
    shared = y;
    printf("Value of the shared variable :%d\n",shared);
}

int main()
{
    pthread_t thread1, thread2;

    //creation of each thread with build in function pthread_create
    pthread_create(&thread1, NULL, fun1, NULL);

    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL); //here NULL is the location where the exit status of the thread will be stored
    pthread_join(thread2, NULL);
    
    printf("Final value of the shared variable is %d\n", shared);
} 