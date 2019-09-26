#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 

int main(){
	int p[2];
	char s1[4] = "abcd";
	char s2[5];
	 if (pipe(p) < 0) 
        exit(1);
    write(p[1], s1, 4); 
	read(p[0], s2, 4);
	printf("%s\n", s2);
	return 0;
}