#include <stdio.h>

void bubbleSort(int *a, int n){
	int i, j;
	int temp;
	for(i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
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
