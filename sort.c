#include<stdio.h>
#define arraySize 5

void printArray(int a[], int n){
	int i;
	for(i=0;i<n;i++) printf("%d ", a[i]);
	printf("\n");
}

//O(n*n)
//void insertSort(int (*p)[], int n);
void insertSort(int a[], int n){
	int i, j, temp;
	for(j = 1; j < n; j++){
		temp = a[j];
		i = j-1;
		while(i >= 0 && a[i] > temp){
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = temp;
	}
}

void swap(int *numA, int *numB)
{
	int temp;
	temp = *numA;
	*numA = * numB;
	*numB = temp;
}
//大数冒泡到后面
void bubbleSort(int a[], int n)
{
	int j;
	while(n > 1){	
		for(j = 0; j < (n-1); j++){
			if(a[j] > a[j+1])
					swap(&a[j], &a[j+1]);
		}
		n--;	
	}
}

int main(){
	printf("insertSort\n");
	int a[arraySize] = {1, 5, 2, 4, 3};
	printArray(a,arraySize);
	insertSort(a, arraySize);
	printArray(a, arraySize);
	
	printf("bubbleSort\n");
	int b[arraySize] = {1, 5, 2, 4, 3};
	printArray(b,arraySize);
	bubbleSort(b, arraySize);
	printArray(b, arraySize);
	return 0;
}
