#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
int c = 0;
printf("Write size of the array\n");
scanf("%d", &n);
int *ar = malloc(n*sizeof(int));
	for (int i = 0; i<n; i++){
		ar[i] = c;
		printf("%d", ar[i]);
		c++;
	}
	free(ar);
	return 0;
}