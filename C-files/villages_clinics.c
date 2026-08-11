#include <stdio.h>

typedef struct {
	int population;
	int clinics;
	double currentLoad;
} Village;

void swap(Village *a, Village *b){
	Village temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(Village heap[],int size,int i){
	while(1){
		int parent = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if(left < size && heap[left].currentLoad > heap[parent].currentLoad){
			parent = left;
		}
		if(right < size && heap[right].currentLoad > heap[parent].currentLoad){
			parent = right;
		}
		if(parent == i){
			break;
		}
		swap(&heap[i],&heap[parent]);
		i = parent; 
	}
}

void buildHeap(Village heap[],int size){
	for(int i = size / 2 - 1;i >= 0;i--){
	       heapify(heap,size,i);
	}
}	

double Load(int population[],int n,int k){
	Village heap[n];
	for(int i = 0;i < n;i++){
	       heap[i].population = population[i];
	       heap[i].clinics = 1;
	       heap[i].currentLoad = population[i];
	}
	buildHeap(heap,n);
	int remaining = k - n;
	while(remaining > 0){
		Village *v = &heap[0];
		v->clinics++;
		v->currentLoad = (double)v->population / v->clinics;
		heapify(heap,n,0);
		remaining--;
	}
	return heap[0].currentLoad;
}	
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int population[n];
	for(int i = 0;i < n;i++){
		scanf("%d",&population[i]);
	}
	double maxLoad = Load(population,n,k);
	printf("%.2f\n",maxLoad);
	return 0;
}
