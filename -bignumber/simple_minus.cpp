#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char *A){
	int i=0;
	if(!A) return -1;
	while(A[i]!='\0'){
		i++;
	}
	return i;
}
char *create(int len){
	return (char *)malloc(sizeof(char)*(len+1));
}
char * copy(char *A){
	int lenA = len(A);
	char *res = create(lenA);
	strcpy(res,A);
	return res;
}

char *substract(char *A,char *B){
	int lenA = len(A);
	int lenB = len(B);
	int borrow = 0;
	int i = lenA-1;
	int j = lenB-1;
	
	while(j>=0){
		int a = A[i]-'0';
		int b = B[j]-'0';
		if(a-b-borrow<0){
			A[i] = 10+a-b-borrow+'0';
			borrow = 1;
		}else{
			A[i] = a-b-borrow+'0';	
			borrow = 0;
		}
		i--;
		j--;
	}
	while(i>=0){
		int a = A[i]-'0';
		if(a-borrow<0){
			A[i] = 10+a-borrow+'0';
			borrow = 1;
		}else{
			A[i] = a-borrow+'0';	
			borrow = 0;
		}
		i--;
	}
	int k = 0;
	while(A[k]=='0'){
		k++;
	}
	return A+k;
}

int main(){
	char data1[100] = "123456";
	char data2[100] =  "123455";
	char * res = substract(data1,data2);
	printf("%s\n",res);
	printf("%d\n",123456-54321);

	return 0;
}