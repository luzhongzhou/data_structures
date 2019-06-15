#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *a, int n){
	int i, j;
	int temp;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[j]<a[i]){
				swap(&a[i], &a[j]);
			}
		}
	}
}

int main(void){
	int a[]={3, 2, 1, 5, 3};
	bubbleSort(a, 5);
	int i;
	for(i=0; i<5; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
