#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64

int len(char * A){
	int len = 0;
	while(A[len]!='\0'){
		len++;
	}
	return len;
}


print(char *A){
	int i = 0;
	while(A[i]!='\0'){
		printf("%c ",A[i]);
		i++;
	}
	printf("\n");
}

char *create(){
	char * t = (char* )malloc(sizeof(char) *MAX_LEN);
	t[0] = '0';
	t[1] = '\0';
	return t;
}
char *copy(char *A){
	char *res = create();
	strcpy(res,A);
	return res;
}

//malloc return
//正数
char *plus(char *A,char *B){
	if(!A&&!B){
		return create();	
	}		
	if(!A) return B;
	if(!B) return A;
	int lenA = len(A);
	int lenB = len(B);
	int lenC = lenA>lenB?lenA+1:lenB+1;
	char *res = create();
	for (int i = 0; i < lenA/2; ++i)
	{
		A[i]^=A[lenA-1-i];
		A[lenA-1-i]^=A[i];
		A[i]^=A[lenA-1-i];
	}
	for (int i = 0; i < lenB/2; ++i)
	{
		B[i]^=B[lenB-1-i];
		B[lenB-1-i]^=B[i];
		B[i]^=B[lenB-1-i];
	}
	int ad = 0;
	int i = 0;
	while(i<lenA&&i<lenB){
		int a = A[i] - '0';
		int b = B[i] - '0';
		if(a+b+ad>=10){
			res[i] = (a+b+ad)%10 + '0';
			ad = 1;
		}else{
			res[i] = (a+b+ad)%10 + '0';
			ad = 0;
		}
		i++;
	}	
	while(i<lenA){
		int a = A[i] - '0';
		if(a+ad>=10){
			res[i] = (a+ad)%10 + '0';
			ad = 1;
		}else{
			res[i] = (a+ad)%10 + '0';
			ad = 0;
		}
		i++;
	}
	while(i<lenB){
		int b = B[i] - '0';
		if(b+ad>=10){
			res[i] = (b+ad)%10 + '0';
			ad = 1;
		}else{
			res[i] = (b+ad)%10 + '0';
			ad = 0;
		}
		i++;
	}
	if(ad){
		res[i] = '1';
		res[++i] = '\0';
	}else{
		res[i] = '\0';
	}
	for (int j = 0; j < i/2; j++)
	{
		res[j] ^= res[i-1-j];
		res[i-1-j] ^= res[j] ;
		res[j] ^= res[i-1-j];
	}
	return res;
}

char *lr_decimal(char *A){
	char *res = copy(A);
	int i = len(A);
	res[i] = '0';
	res[i+1] = '\0';
	return res;
}
char *lr_decimal(char *A,int time){
	int length = len(A);
	char *res = copy(A);
	for (int i = 0; i < time; ++i)
	{
		res[length++] = '0';
	}
	res[length] = '\0';
	return res;
}


char *single_time(char *A,int time){
	if(time==0) return create();
	else{
		char * res = create();
		for (int i = 0; i < time; ++i)
		{
			res = plus(res,copy(A));
		}
		return res;
	}
}

char *muitipy(char *A,char *B){
	if(!A||!B){
		return NULL;
	}		
	bool minus = 0;
	if(A[0]=='-'){
		minus = !minus;
		A = A+1;
	}
	if(B[0]=='-'){
		minus = !minus;
		B = B+1;
	}
	char *res = create();
	int lenA = len(A);
	int lenB = len(B);
	for (int i = lenB-1; i >=0 ; i--)
	{
		int t = B[i] -'0';
		char *local = single_time(lr_decimal(A,lenB-1-i),t);
		res = plus(res,local);
	}
	return res;
}

int main(){
	char A[100] = "12345678";
	char B[100] = "87654321";
	// char *C = plus (A,copy(A));
	// print(C);
	
	// char *D = single_time(B,123);
	// print(D);

	char *E = muitipy(A,B);
	print(E);
	// 1 0 8 2 1 5 2 0 2 2 3 7 4 6 3 8
	return 0;																																							
}