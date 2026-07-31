#include <stdio.h>
int bitAnd(int x,int y){
	return ~((~x)|(~y));
}
int main(){
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	printf("%d\n",bitAnd(x,y));
}
