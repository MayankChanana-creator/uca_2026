#include <stdio.h>
int findNumber(int arr[],int n){
	int result = 0;
	for(int i = 0;i < 32;i++){
		int count = 0;
		for(int j = 0;j < n;j++){
			if(arr[j] & (1 << i)){
				count++;
			}
		}
		if(count % 3 != 0){
			result = result | (1 << i);
		}
	}
	return result;
}
int main(){
	int n;
	scanf("%d\n",&n);
	int arr[n];
	for(int i = 0;i < n;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d\n",findNumber(arr,n));
	return 0;
}
