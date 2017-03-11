#include <stdio.h>
#include <string.h>

void int2chars(int n,char tmp[]);

int len(char *origin){
	int len = 0;
	while(origin[len]!='\0'){
		len++;
	}
	return len;
}

int getSingleMap(char p){
	if(p<='9'&&p>='0'){
		return p - '0';
	}else if('A'<=p&&p<='F'){
		return 10+p-'A';
	}else{
		return 0;
	}
}

void hexdecimal(char *origin){
	int length = len(origin);
	if(origin[0]!='0'||origin[1]!='x'){
		return ;
	}else{
		int res = 0;
		for (int i = 2; i < length; ++i)
		{
			res *= 16;
			int t = getSingleMap(origin[i]);
			res += t;
		}
		int2chars(res,origin);
	}
}

void int2chars(int n,char tmp[]){
	int i = 0;
	while(n){
		int t = n%10;
		n /= 10;
		tmp[i++] = t + '0';
	}
	for (int j = 0; j < i/2; j++)
	{
		char p = tmp[j];
		tmp[j] = tmp[i-1-j];
		tmp[i-1-j] = p;  
	}
	tmp[i] = '\0';
}

int main(){
	char buf[100];
	// int2chars(109,buf);
	scanf("%s",buf);
	hexdecimal(buf);
	printf("%s\n",buf);
	return 0;
}