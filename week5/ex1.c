#include <stdio.h>
#include <pthread.h>

void *thread(void *arg){
	char *s;
	s =(char*)arg;
	sleep(1);
	printf("Thread: ", s);
	printf("'my id is %s", s);
	printf("%d'\n", pthread_threadid_np);
	return NULL;
}

int main(){
	pthread_t tid;
	for (int i = 0; i<10; i++){
		printf("Thread %d is created:\n", i);
		pthread_create(&tid,NULL,thread, "");
        pthread_join(tid, NULL);
	}

}