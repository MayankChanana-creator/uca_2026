#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 8
#define START_SIZE 8000
#define STEP_SIZE 4000
double currentTimeMillis(){
	return (double)clock()*1000.0 / CLOCKS_PER_SEC;
}
void generateRandom(int arr[], int size){
	for(int i = 0;i<size;i++){
		arr[i] = rand() % 100000;
	}
}
void generateAscending(int arr[], int size){
	for(int i = 0;i<size;i++){
		arr[i] = i;
	}
}
void generateDescending(int arr[], int size){
	for(int i = 0;i<size;i++){
		arr[i] = size - i;
	}
}
void selectionSort(int arr[], int n){
	for(int i = 0;i<n-1;i++){
		int minIndex = i;
		for(int j = i+1;j<n;j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}
void benchmarkRandom(){
	printf("\n============== Random Input ==============\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateRandom(arr,size);
		double start = currentTimeMillis();
		selectionSort(arr,size);
		double end = currentTimeMillis();
		printf("%-10d %-15.3f\n",size,end-start);
		free(arr);
	}
}
void benchmarkAscending(){
	printf("\n================ Ascending Input ==========\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateAscending(arr,size);
		double start = currentTimeMillis();
		selectionSort(arr,size);
		double end = currentTimeMillis();
		printf("%-10d %-15.3f\n",size,end-start);
		free(arr);
	}
}
void benchmarkDescending(){
	printf("\n============== Descending Input =============\n");
	for(int i = 0;i<ITERATIONS;i++){
		int size = START_SIZE + i*STEP_SIZE;
		int *arr = (int *)malloc(size * sizeof(int));
		generateDescending(arr,size);
		double start = currentTimeMillis();
		selectionSort(arr,size);
		double end = currentTimeMillis();
		printf("%-10d %-15.3f\n", size, end - start);
		free(arr);
	}
}
int main(){
	srand(time(NULL));
	benchmarkRandom();
	benchmarkAscending();
	benchmarkDescending();
	return 0;
}

