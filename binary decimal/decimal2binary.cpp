#include <stdio.h>
#include <stdlib.h>

int len (char *origin){
	int len = 0;
	while(origin[len]!='\0'){
		len++;
	}
	return len;
}


int charArrayToInt(char *origin){
	int size = len(origin);
	int z = 0;
	for (int i = 0; i <size; i++)
	{
		z*=10;
		z+=(origin[i]-'0');
	}
	return z;
}

char *decimal2binary(char *origin){
	int size = len(origin);
	char *res = (char *)malloc(sizeof(char)*32);
	int t = charArrayToInt(origin);
	int i = 0;

	while(t>>i){
		if((t>>i)&1){
			res[i] = '1';
		}else{
			res[i] = '0';
		}
		i++;
	}	

	for (int j = 0; j < i/2; j++)
	{
		char t = res[j];
		res[j] = res[i-1-j];
		res[i-1-j] = t;
	}
	return res;
}

int main(){
	char buf[100];
	scanf("%s",buf);

	// int t = charArrayToInt(buf);
	// printf("%d\n",t);

	char *p =  decimal2binary(buf);
	printf("%s\n",p);
	return 0;
}