#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * thread1()
{
        printf("Hello World\n");
       
}

int main()
{
        int status;
        pthread_t tid1;

        pthread_create(&tid1,NULL,thread1,NULL);
       
        pthread_join(tid1,NULL);
         return 0;
}
