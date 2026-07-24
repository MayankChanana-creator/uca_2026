#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int merge(int arr[],int left, int mid,int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int leftArr[n1];
	int rightArr[n2];
	for(int i = 0;i <n1;i++){
		leftArr[i] = arr[left + i];
	}
	for(int j = 0;j < n2;j++){
		rightArr[j] = arr[mid + 1 + j];
	}
	int count = 0;
	int l = 0;
	for(int p = 0;p < n1;p++){
		while(l < n2 && leftArr[p] > rightArr[l]){
			l++;
		}
		count += l;
	}
	int i = 0,j = 0,k = left;
	while(i < n1 && j < n2){
		if(leftArr[i] < rightArr[j]){
			arr[k++] = leftArr[i++];
		}
		else{
			arr[k++] = rightArr[j++];
		}
	}
	while(i < n1){
		arr[k++] = leftArr[i++];
	}
	while(j < n2){
		arr[k++] = rightArr[j++];
	}
	return count;	
}
int mergeSort(int arr[], int left, int right){
	int count = 0;
	if(left >= right){
		return 0;
	}
	int mid = left + (right - left)/2;
	count += mergeSort(arr,left,mid);
	count += mergeSort(arr,mid+1,right);
	count += merge(arr,left,mid,right);
	return count;
}
int main(){
	int n;
	scanf("%d\n",&n);
	int arr[n];
	for(int i = 0;i < n;i++){
		scanf("%d",&arr[i]);
	}
	int count = 0;
	count = mergeSort(arr,0,n-1);
	printf("%d\n",count);
}
