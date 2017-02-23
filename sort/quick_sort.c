#include <stdio.h>


int partition(int A[],int start, int end){
	int pivit = A[start];
	int c = 0;
	while(start<end){
		while(start<end){
			if(A[end]<pivit){
				A[start] = A[end];
				c++;
				break;
			}else{
				end--;
			}
		}
		while(start<end){
			if(A[start]>pivit){
				A[end] = A[start];
				c++;
				break;
			}else{
				start++;
			}
		}
	}
	A[start] = pivit;

	if(c){
		return start;
	}else{
		return -1;
	}
}
void quick_sort(int A[],int start,int end){
	int pos = partition(A,start,end);
	if(pos!=-1){
		quick_sort(A,start,pos-1);
		quick_sort(A,pos+1,end);
	}
}

int main(){
	int sort[20] = {14,3,6,9,1,10,8,7,2,2,81,12,11,15};
	for (int i = 0; i < 14; ++i)
	{
		printf("%d ",sort[i]);
	}
	printf("\n");
	quick_sort(sort,0,14-1);
	for (int i = 0; i < 14; ++i)
	{
		printf("%d ",sort[i]);
	}
	return 0;
}