#include <stdio.h>
int my_strlen(const char *str){
	int len = 0;
	while(*str != '\0'){
		len++;
		str++;
	}
	return len;
}

void url_encode(char *str,int true_length){
	int spaces = 0;
	for(int i = 0;i <true_length;i++){
		if(str[i] == ' '){
			spaces++;
		}
	}
	int new_length = true_length + (spaces*2);
	str[new_length] = '\0';
	int i = true_length - 1;
	int j = new_length - 1;
	while(i >= 0){
		if(str[i] == ' '){
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else{
			str[j--] = str[i];
		}
		i--;
	}
}
int main(){
	char str[100];
	fgets(str,sizeof(str),stdin);
	int len = my_strlen(str) - 1;
	url_encode(str,len);
	printf("%s\n",str);
	return 0;


}
