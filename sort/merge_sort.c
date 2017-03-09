# include <stdio.h>
# include <stdlib.h>

#define ELEMENT_SIZE 10
#define MAX_ARRAY_SIZE 100

void msort(int A[],int start,int end,int tmp[]);
void merge(int A[],int start,int mid,int end,int tmp[]);
void print(int A[],int len);

void merge_sort(int A[],int len){
	int *tmp = (int *)malloc(sizeof(int)*len);
	msort(A,0,len-1,tmp);
}
void msort(int A[],int start,int end,int tmp[]){
	int mid = (start+end)/2;
	// printf("start:%d,mid:%d,mid+1:%d,end:%d,\n",start,mid,mid+1,end);
	if(start>=end){
		// printf("return \n");
		return ;
	}else{
		// print(A,8);
		msort(A,start,mid,tmp);
		msort(A,mid+1,end,tmp);
		merge(A,start,mid,end,tmp);
	}
}
void merge(int A[],int start,int mid,int end,int tmp[]){
	// print(A,8);
	// printf("start:%d,mid:%d,end:%d,\n",start,mid,end);

	for (int i = start; i <= end; ++i)
	{
		tmp[i]=A[i];
	}
	int p1 = start;
	int p2 = mid+1;

	int i = start;
	while(p1<=mid&&p2<=end){
		if(tmp[p1]<tmp[p2]){
			A[i++]=tmp[p1];
			p1++;
		}else{
			A[i++]=tmp[p2];
			p2++;
		}
	}
	while(p1<=mid){
		A[i++]=tmp[p1++];
	}
	while(p2<=end){
		A[i++]=tmp[p2++];
	}
	// print(A,8);
	// printf("\n");

}
void print(int A[],int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
int main(){
	int A[MAX_ARRAY_SIZE] = {3,7,6,1,2,10,23,12};
	int len = 8;
	merge_sort(A,len);
	print(A,len);
	return 0;
}