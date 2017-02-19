#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a,const void *b){
	if(*((int *)a)<*((int *)b)){
		return -1;
	}else{
		return 1;
	}
}

int main(){
	int data_set[10] = {5,8,6,1,4,5,2,3};
	qsort(data_set,10,sizeof(int),cmp);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",data_set[i]);
	}
	return 0;
}