#include <stdio.h>

void bubble_sort(int *arr, int len){
	for (int i = 1; i < len;i++){
		for (int j = 0; j < len - i; j++){
			if (*(arr+j) > *(arr + j + 1)){
				int t = *(arr + j);
				*(arr+j) = *(arr + j + 1);
				*(arr + j + 1) = t;
			}
		}
	}
}
int main(){
	int a[10] = {0,1,2,4,3,5,7,6,8,9};
	int l = 10;
	bubble_sort(a, l);
	for (int i = 0; i < l; i++)
		printf("%d ", a[i]);
	return 0;
}