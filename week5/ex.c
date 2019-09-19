#include <stdio.h>
#include <pthread.h>
#include <zconf.h>

void *threadFunc(void *arg)
{
    char *str;
    int i = 0;

    str=(char*)arg;

    sleep(1);
    printf("\nThread says: %s",str);
    printf("my id is %s",str);
    printf("%d", pthread_threadid_np);

    sleep(1);
    printf("\nThread %s",str);
    printf("%d", pthread_threadid_np);
    printf(" exits %s",str);

    return NULL;
}

int main(void)
{
    pthread_t pth;
    int i = 0;

    while(i < 10) {
        sleep(1);
        printf("\nThread ");
        printf("%d", i);
        printf(" is created");
        pthread_create(&pth,NULL,threadFunc, "");
        pthread_join(pth, NULL);
        ++i;
    }

    return 0;
}
