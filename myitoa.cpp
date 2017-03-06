#include <stdio.h>
#include <stdlib.h>

int bitlen(int n){
	int i = 0;
	while(n>>i){
		i++;
	}
	return i;
}
int get(int n,int pos){
	if((n>>pos)&1){
		return 1;
	}else{
		return 0;
	}
}

int swap(int n,int pos){
	if(get(n,pos)){
		int c = 1;
		c = ~(c<< pos);
		return n&c;
	}else{
		int c = 1;
		c = c<<pos;
		return n|c;
	}
}
char *myitoa(int n){
	int len = bitlen(n);
	char *res =(char *)malloc(sizeof(len));
	for (int i = 0; i < len; ++i)
	{
		if(get(n,i)){
			res[len-i-1] = 1;
		}else{
			res[len-i-1] = 0;
		}
	}
	return res; 
}
int main(){
	// int i = 10;
	// i = swap(i,3);
	// printf("%d\n",i);
	swap(100,2,3);
	return 0;
}