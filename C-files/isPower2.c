#include <stdio.h>

int isPower2(int x){
	if(x <= 0){
		return 0;
	}
	return !(x & (x + ~0));
}
int main(){
	int x;
	scanf("%d",&x);
	printf("%d\n",isPower2(x));
}
