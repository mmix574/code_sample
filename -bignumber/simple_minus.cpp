#include <stdio.h>

int len(char* A){
	int i = 0;
	while(A[i]!='\0'){
		i++;
	}
	return i;
}

bool gt0(char *A){

}

char * simple_minus(char* A,char *B){
	
}

int main(){
	char A[100] = "100";
	char B[100] = "45";
	char *C = simple_minus(A,B);

	printf("%s\n",C);
	return 0;
}