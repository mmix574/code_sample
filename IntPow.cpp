#include <stdio.h>

int pow(int a,int b){
	int result=1;
	for (int i = 0; i < b; ++i)
	{
		result*=a;
	}
	return result;
}
//最大为2^30 
int main(){
	for (int i = 0; i < 32; ++i)
	{
		printf("%d\n",pow(2,i));
	}
	return 0;
}