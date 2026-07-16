#include<stdio.h>

int my_strlen(const char *str){
	int len = 0;
	while(*str != '\0'){
		len++;
		str++;
	}
	return len;
}

int find_substring(const char *haystack, const char *needle){
	if(*needle == '\0'){
		return 0;
	}
	int hay_len = my_strlen(haystack) - 1;
	for(int i = 0; i< hay_len; i++){
		int j = 0;
		while(needle[j] != '\0' && haystack[i+j] != '\0' && haystack[i+j] == needle[j]){
			j++;
		}
		if(needle[j] == '\0'){
			return i;
		}
	}
	return -1;
}

int main(){
	char haystack[100];
	char needle[100];
	fgets(haystack,sizeof(haystack),stdin);
	fgets(needle,sizeof(needle),stdin);

	int i = 0;
	while(haystack[i] != '\0'){
		if(haystack[i] == '\n'){
			haystack[i] = '\0';
		}
		i++;
	}
	int j = 0;
	while(needle[j] != '\0'){
		if(needle[j] == '\n'){
			needle[j] = '\0';
		}
		j++;
	}
	int index = find_substring(haystack,needle);
	printf("%d\n",index);
	return 0;
}
