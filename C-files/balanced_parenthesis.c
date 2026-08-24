#include <stdio.h>
#include <stdbool.h>
#define MAX 30
char stack[MAX];
int top = -1;
void push(char ch){
	if(top == MAX - 1){
		printf("Stack is Full");
		return;
	}
	stack[++top] = ch;
}
bool isEmpty(){
	return top == -1;
}
char pop(){
	if(isEmpty()){
		printf("Stack is Empty");
		return '\0';
	}
	char val = stack[top--];
	return val;
}
char peek(){
	if(isEmpty()){
		printf("Stack is Empty");
		return '\0';
	}
	return stack[top];
}
bool isOpening(char ch){
	if(ch == '(' || ch == '{' || ch == '['){
		return true;
	}
	return false;
}
bool isClosing(char ch){
	if(ch == ')' || ch == '}' || ch == ']'){
		return true;
	}
	return false;
}
bool isMatching(char ch1,char ch2){
	if(ch1 == '(' && ch2 == ')' || ch1 == '{' && ch2 == '}' || ch1 == '[' && ch2 == ']'){
		return true;
	}
	return false;
}
int main(){
	char str[MAX];
	scanf("%s",str);
	for(int i = 0;str[i] != '\0';i++){
		if(isOpening(str[i])){
			push(str[i]);		
		}
		else if(isClosing(str[i])){
			if(isEmpty()){
				printf("Not Balanced\n");
				return 0;
			}
			char top = pop();
			if(!isMatching(top,str[i])){
				printf("Not Balanced\n");
				return 0;
			}
		}
	}
	if(isEmpty()){
		printf("Balanced\n");
	}
	else{
		printf("Not Balanced\n");
	}
	return 0;

}
