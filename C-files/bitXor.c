#include <stdio.h>
int bitXor(int x,int y){
	return ~(~(~x & y) & ~(x & ~y));
}
int main(){
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	printf("%d\n",bitXor(x,y));
}
