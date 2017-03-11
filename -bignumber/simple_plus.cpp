#include <stdio.h>

#define MAX 100

int len(char * c){
	int len = 0;
	while(c[len]!='\0'){
		len++;
	}
	return len;
}
char * add(char * A,char * B){
	int lenA = len(A);
	int lenB = len(B);
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
	int i = 0;
	int advance = 0;
	while(i<lenA||i<lenB){
		if(i<lenA&&i<lenB){
			int a = A[i] - '0';
			int b = B[i] - '0';
			int sum = a+b+advance;
			if(sum>=10){
				advance = 1;
			}else{
				advance = 0;
			}
			A[i] = '0'+(sum)%10;
		}else if(i<lenA){
			int a = A[i] - '0';
			int sum = a+advance;
			if(sum>=10){
				advance = 1;
			}else{
				advance = 0;
			}
			A[i] = '0'+(sum)%10;
		}else{
			int a = B[i] - '0';
			int sum = a+advance;
			if(sum>=10){
				advance = 1;
			}else{
				advance = 0;
			}
			A[i] = '0'+(sum)%10;
		}
		i++;
	}
	if(advance){
		A[i++] = '1';
	}
	A[i] = '\0';
	int nl = len(A);
	for (int i = 0; i < nl/2; ++i)
	{
		A[i] ^= A[nl-1-i];
		A[nl-1-i]^=A[i];
		A[i] ^= A[nl-1-i];
	}	
	return A;
}
int main(){
	char A[MAX];
	char B[MAX];
	scanf("%s",A);
	scanf("%s",B);
	char * C = add(A,B);
	printf("%s\n",C);
	return 0;
}