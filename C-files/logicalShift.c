#include <stdio.h>
int logicalShift(int x,int n){
	int mask = ~(((1 << 31) >> n) << 1);
	return (x >> n) & mask;
}
int main(){
	int x;
	int n;
	scanf("%x",&x);
	scanf("%d",&n);
	printf("0x%x\n",logicalShift(x,n));
}
