#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <pthread.h>

void pr_term(){
	printf("The child process was stopped");
	exit(0);
}

int main(){
	signal(SIGTERM, pr_term);
	int pid = fork();
    if (pid == 0){
        while (1){
            printf ("I'm alive\n");
            sleep(1);
        }
    }
    else {
        sleep(10);
        kill(pid,SIGTERM);
    }
    return 0;
}