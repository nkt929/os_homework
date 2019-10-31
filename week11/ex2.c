#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>


int main() {
	char* s ="Hello"; 																
	char b[5]; 									
	setvbuf(stdout, b, _IOLBF, 5); 	
	for (int i=0; i<5; i++){							
		printf("%c", s[i]);								
		sleep(1);											
	}
	printf("\n");											
	return 0;
}