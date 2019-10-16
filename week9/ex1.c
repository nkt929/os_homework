#include <stdio.h> 
#include <stdbool.h>

#define MAXINT 16777216;
int pages_amount;
int main(){
	scanf("%d", &pages_amount);
	int pages[pages_amount];
	int age[pages_amount];
	int hit = 0, miss = 0;
	for (int i = 0; i < pages_amount; i++)
	{
		pages[i]=0;
		age[i]= 0;
	}
	FILE *input = fopen("Lab 09 input.txt", "r");
	int pagenum = 0;
	while (!feof(input)){
		fscanf(input, "%d", &pagenum);
		int j = 0;
		for (int i = 0; i < pages_amount; i++){
			if (pages[i]==pagenum)
				j = 1;
		}
		if (j == 1){
			hit++;
			for (int i = 0; i < pages_amount; i++) {
        		if (pages[i] == pagenum){
        			age[i] = MAXINT;
        		}
        		else {
            		age[i] = age[i]>>1;
        		}
   			}
		}
		else {
			miss++;
			int min = MAXINT;
    		int i = 0;
    		int index = 0;
    		for (i = 0; i < pages_amount; i++) {
        		if (age[i] < min) {
            		min = age[i];
            		index = i;
        		}
    		}
    		pages[index] = pagenum;
    		age[index] = 0;
    		for (int i = 0; i < pages_amount; i++) {
        		if (pages[i] == pagenum) {
        			age[i] = MAXINT;
        		}
        		else{
            		age[i] = age[i]>>1;
        		}
    		}
		}
	}
	hit--;
	printf("Hits:%d\n", hit);
	printf("Miss:%d\n", miss);
	fclose(input);
	return 0;
}