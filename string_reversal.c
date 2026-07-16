#include <stdio.h>


int my_strlen(const char *str){
	int len = 0;
	while(*str != '\0'){
		len++;
		str++;
	}
	return len;
}

void reverse_string(char *str){
	int i = 0;
	int j = my_strlen(str)-1;
	while(i < j){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int main(){
	char str[100];
	fgets(str,sizeof(str),stdin);
	reverse_string(str);
	printf("%s\n",str);
	return 0;
}
