#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <pthread.h>

int main(){
	int p[2];
	char s1[20] = "abcd";
	char s2[20] = "";
	int pid;
	//printf("%d\n", pipe(p));
	if (pipe(p) < 0) 
        exit(1);
    if (pid = fork() != 0){
    	write(p[1], s1, strlen(s1)+1);
		close(p[1]);
    	
    }
   	else {
		 read(p[0], s2, strlen(s1)+1); 
		 printf("%s\n", s2);
    	 close(p[0]);
	}
	return 0;
}