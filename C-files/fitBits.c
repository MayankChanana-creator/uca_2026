#include <stdio.h>
int fitBits(int x,int n){
	int shift = 32 + (~n + 1);
	return !(((x << shift) >> shift) ^ x);
}
int main(){
	int x;
	int n;
	scanf("%d",&x);
	scanf("%d",&n);
	printf("%d\n",fitBits(x,n));
}
