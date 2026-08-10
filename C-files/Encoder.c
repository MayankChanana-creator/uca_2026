#include <stdio.h>
#include <string.h>

void Encoder(const char *input){
	const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		             "abcdefghijklmnopqrstuvwxyz"
			     "0123456789+/";
	int len = strlen(input);
	for(int i = 0;i < len;i += 3){
		unsigned char byte1 = input[i];
		unsigned char byte2 = (i + 1 < len) ? input[i + 1] : 0;
		unsigned char byte3 = (i + 2 < len) ? input[i + 2] : 0;
		int combined = (byte1 << 16) | (byte2 << 8) | byte3;

		int index1 = (combined >> 18) & 63;
		int index2 = (combined >> 12) & 63;
		int index3 = (combined >>  6) & 63;
		int index4 =  combined & 63;

		printf("%c",table[index1]);
		printf("%c",table[index2]);

		if(i + 1 < len){
			printf("%c",table[index3]);
		}
		else{
			printf("=");
		}
		if(i + 2 < len){
			printf("%c",table[index4]);
		}
		else{
			printf("=");
		}
	}
	printf("\n");
}
int main(){
	char input[1000];
	fgets(input,sizeof(input),stdin);
	input[strcspn(input,"\n")] = '\0';
	Encoder(input);
	return 0;
}
