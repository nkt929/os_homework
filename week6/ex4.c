#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <pthread.h>

void pr_kill(){
	printf("The process was killed");
	exit(0);
}


void pr_stop(){
	printf("The process was stopped");
	exit(0);
}

void pr_usr(){
	printf("The process was userred");
	exit(0);
}
int main(){
	signal(SIGKILL, pr_kill);
	signal(SIGSTOP, pr_stop);
	signal(SIGKILL, pr_usr);
	while(1){
		pause;
	}
	return 0;
}