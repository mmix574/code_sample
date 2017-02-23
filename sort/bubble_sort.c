#include <stdio.h>

void bubble_sort(int A[],int len){

	for (int i = 1; i < len; ++i)
	{
		for (int j = 0; j < len-i; ++j)
		{
			if(A[j]>A[j+1]){
				int t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}
}

#define MAX_ARRAY_SIZE 100
#define ELEMENT_LEN 10
int main(){
	int A[MAX_ARRAY_SIZE] = {3,6,9,1,2,0,8,9,7,5};
	for (int i = 0; i < ELEMENT_LEN; ++i)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	bubble_sort(A,ELEMENT_LEN);
	for (int i = 0; i < ELEMENT_LEN; ++i)
	{
		printf("%d ",A[i]);
	}
	return 0;
}