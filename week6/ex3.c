#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <pthread.h>

void pr(){
	printf("The process was stopped");
	exit(0);
}

int main(){
	signal(SIGINT, pr);
	while(1){
		pause;
	}
	return 0;
}