#include <stdio.h>

int conditional(int x,int y, int z){
	int mask = !!x;
	mask = ~mask + 1;
	return (mask & y) | (~mask & z);
}
int main(){
	int x,y,z;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	printf("%d\n",conditional(x,y,z));
}

