#include<stdio.h>//standard input output library header
#include<stdlib.h>//standard library header(malloc, calloc, free, exit)
#include<unistd.h>//includes function like sleep
#include<pthread.h>// thread library

void *thread_function()
{
    printf("Inside Thread\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\n",i);
        sleep(1);
    }
    printf("Thread Finished\n");
    pthread_exit(NULL);//exit thread cleanly
}
int main()
{
    pthread_t a_thread;// thread variable a_thread

    pthread_create(&a_thread,NULL, thread_function,NULL);
    //&a_thread = address of thread(thread variable)
    //NULL =thread attribute
    //thread_function = the name of the thread function is thread_function
    //NULL = passing arguments to the function\
    
    printf("Thread created");

    pthread_join(a_thread,NULL);
    //when joined first the thread is executed
    printf("The thread is joined");

    printf("Inside main function:\n");
    for(int i=20;i<25;i++)
    {
        printf("%d\n",i);
        sleep(1);
    }
    return 0;

     
}
