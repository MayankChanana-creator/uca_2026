#include <stdio.h>
#include <string.h>


struct Student{
	char name[50];
	int marks;
};
void swap(void *a,void *b,size_t size){
	char temp[size];
	memcpy(temp,a,size);
	memcpy(a,b,size);
	memcpy(b,temp,size);
}
int compare(void *a,void *b){
	int *x = a;
	int *y = b;
	if(*x == *y){
		return 0;
	}
	else if(*x > *y){
		return 1;
	}
	return -1;
}
int compareStudent(void *a,void *b){
	struct Student *s1 = a;
	struct Student *s2 = b;
	if(s1->marks > s2->marks){
		return 1;
	}
	if(s1->marks < s2->marks){
		return -1;
	}
	return 0;
}

void heapify(void *arr,int n,int i,size_t size,int (*compare)(void *,void *)){
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	void *largestElement = (char *)arr + largest * size;
	if(left < n){
		void *leftElement = (char *)arr + left * size;
		if(compare(leftElement,largestElement) > 0){
			largest = left;
		}
	}
	largestElement = (char *)arr + largest * size;
	if(right < n){
		void *rightElement = (char *)arr + right * size;
		if(compare(rightElement,largestElement) > 0){
			largest = right;
		}
	}
	if(largest != i){
		void *currentElement = (char *)arr + i * size;
		void *largestElement = (char *)arr + largest * size;
		swap(currentElement,largestElement,size);
		heapify(arr,n,largest,size,compare);
	}
}
void heapSort(void *arr,int n,size_t size,int(*compare)(void *,void *)){
	for(int i = n / 2 - 1;i >= 0;i--){
		heapify(arr,n,i,size,compare);
	}
	for(int i = n - 1;i > 0;i--){
		void *first = arr;
		void *last = (char *)arr + i *size;
		swap(first,last,size);
		heapify(arr,i,0,size,compare);
	}
}
int main(){
	int n;
	scanf("%d\n",&n);
	int arr[n];
	for(int i = 0;i < n;i++){
		scanf("%d",&arr[i]);
	}
	heapSort(arr,n,sizeof(int),compare);
	for(int i = 0;i < n;i++){
		printf("%d %s",arr[i]," ");
	}
	printf("\n");
	struct Student students[] = {
		{"A",85},
		{"B",72},
		{"C",95},
		{"D",60}
	};
	int n1 = sizeof(students) / sizeof(students[0]);
	heapSort(students,n1,sizeof(struct Student),compareStudent);
	for(int i = 0;i < n1;i++){
		printf("%s %d\n",
               students[i].name,
               students[i].marks);
	}
	return 0;
}

