#include <stdio.h>

void select_sort(int A[],int len){
	int k;
	for (int i = 1; i < len; ++i)
	{
		k = 0;
		for (int j = 0; j <= len-i; ++j)
		{
			if(A[j]>A[k]){
				k = j;
			}
		}
		int t = A[len-i];
		A[len-i] = A[k];
		A[k] = t;
	}	

}
#define ELEMENT_SIZE 10
#define MAX_ARRAY_SIZE 100

int main(){
	int A[MAX_ARRAY_SIZE] = {2,3,9,1,0,7,3,2,5,10};
	for (int i = 0; i < ELEMENT_SIZE; ++i)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	select_sort(A,ELEMENT_SIZE);
	for (int i = 0; i < ELEMENT_SIZE; ++i)
	{
		printf("%d ",A[i]);
	}
	return 0;
}