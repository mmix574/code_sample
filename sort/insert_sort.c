#include <stdio.h>


void insertSort(int A[],int n){
	for (int i = 1; i < n; ++i)
	{
		int t = A[i];
		for (int j = 0; j < i; ++j)
		{
			if(t<A[j]){
				for (int k = i; k>j; k--)
				{
					A[k]=A[k-1];
				}
				A[j] = t;
				break;
			}
		}
	}
}

void print(int A[],int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",A[i]);
	}
}

int main(){
	int A[10] = {3,6,9,1,2,12,23};
	int n = 7;
	print(A,n);
	printf("\n");
	insertSort(A,n);
	print(A,n);
	return 0;
}