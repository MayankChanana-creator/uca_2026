#include <stdio.h>
void setZero(int matrix[][100],int m,int n){
	int firstRowZero = 0;
	int firstColZero = 0;
	for(int j = 0;j < n;j++){
		if(matrix[0][j] == 0){
			firstRowZero = 1;
		}
	}
	for(int i = 0;i < m;i++){
		if(matrix[i][0] == 0){
			firstColZero = 1;
		}
	}
	for(int i = 1;i < m;i++){
		for(int j = 1;j < n;j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for(int i = 1; i < m;i++){
		for(int j = 1;j < n;j++){
			if(matrix[i][0] == 0 || matrix[0][j] == 0){
				matrix[i][j] = 0;
			}
		}
	}
	if(firstRowZero){
		for(int j = 0;j < n;j++){
			matrix[0][j] = 0;
		}
	}
	if(firstColZero){
		for(int i = 0;i < m;i++){
			matrix[i][0] = 0;
		}
	}
}
void print(int matrix[][100],int m,int n){
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			printf("%d %s",matrix[i][j]," ");
		}
		printf("\n");
	}
}
int main(){
	int matrix[100][100];
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	setZero(matrix,m,n);
	print(matrix,m,n);
	return 0;
}
