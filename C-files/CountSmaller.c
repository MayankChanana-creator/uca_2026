#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int val;
	int index;
} Pair;

void merge (Pair arr[], Pair temp[],int left,int mid,int right,int ans[]){
	int i = left;
	int j = mid + 1;
	int k = left;
	int rightCount = 0;
	while(i <= mid && j <= right){
		if(arr[j].val < arr[i].val){
			temp[k++] = arr[j++];
			rightCount++;
		}
		else{
			ans[arr[i].index] += rightCount;
			temp[k++] = arr[i++];
		}
	}
	while(i <= mid){
		ans[arr[i].index] += rightCount;
		temp[k++] = arr[i++];
	}
	while(j <= right){
		temp[k++] = arr[j++];
	}
	for(int p = left;p <= right;p++){
		arr[p] = temp[p];
	}
}
void mergeSort(Pair arr[],Pair temp[],int left,int right,int ans[]){
	if(left >= right){
		return;
	}
	int mid = left + (right - left)/2;
	mergeSort(arr,temp,left,mid,ans);
	mergeSort(arr,temp,mid+1,right,ans);
	merge(arr,temp,left,mid,right,ans);
}
int main(){
	int n;
	scanf("%d\n",&n);
	int nums[n];
	for(int i = 0;i < n;i++){
		scanf("%d",&nums[i]);
	}
	Pair arr[n];
	Pair temp[n];
	int ans[n];
	for(int i = 0;i < n;i++){
		arr[i].val = nums[i];
		arr[i].index = i;
		ans[i] = 0;
	}
	mergeSort(arr,temp,0,n-1,ans);
	for(int i = 0;i < n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
