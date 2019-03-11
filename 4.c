#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int n,m;
pthread_mutex_t lock;
int string_read=FALSE;

pthread_cond_t cond;

void * thread1()
{
        while(1){
                while(string_read);
                pthread_mutex_lock(&lock);
                printf("Enter 2 values into the main thread: ");
                scanf("%d%d",&n,&m);
                string_read=TRUE;
                pthread_mutex_unlock(&lock);
                pthread_cond_signal(&cond);
        }
}

void * thread2()
{
        while(1){
                pthread_mutex_lock(&lock);
                int o;
                while(!string_read)
                        pthread_cond_wait(&cond,&lock);
                        o=m*n;
                        printf("Printing product from other thread 2: %d\n",o);
                        string_read=FALSE;
                        pthread_mutex_unlock(&lock);
        }
}
int main()
{
        int status;
        pthread_t t1, t2;

        pthread_create(&t1,NULL,thread1,NULL);
        pthread_create(&t2,NULL,thread2,NULL);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
        pthread_exit((void *)NULL);
        return 0;
}
