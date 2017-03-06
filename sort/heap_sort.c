#include <stdio.h>

void adjust_down(int A[],int pos,int n);
void build_heap(int A[],int n);

void heap_sort(int A[],int n){
	build_heap(A,n);
	for (int i = 1;i<n;i++)
	{
		 int t = A[1];
		 A[1] = A[n-i+1];
		 A[n-i+1] = t; 
		adjust_down(A,1,n-i);
	}
}
void build_heap(int A[],int n){
	int l = n;
	//小根堆
	int p;
	do{
		p = l/2;
		adjust_down(A,p,n);
		l-=2;
	}while(p!=1);
	
}
void adjust_down(int A[],int pos,int n){
	int left = 2*pos;
	int right = 2*pos+1;
	// printf("down %d,p,l,r:%d %d %d\n",pos,A[pos],A[left],A[right]);

	if(left>n&&right>n){
		return ;
	}else if(right>n){
		//之有left在
		if(A[pos]>A[left]){
			int t = A[pos];
			A[pos] = A[left];
			A[left] = t;
		}

	}else{
		if(A[pos]<A[left]&&A[pos]<A[right]){

			return ;
		}else if(A[left]<A[right]){
			int t = A[pos];
			A[pos] = A[left];
			A[left] = t;
			adjust_down(A,left,n);
		}else{
			int t = A[pos];
			A[pos] = A[right];
			A[right] = t;
			adjust_down(A,right,n);
		}
	}
}
void print(int A[],int len){
	for (int i = 1; i < len; ++i)
	{
		printf("%d ",A[i]);
	}
}

int main(){
	int A[12] = {0,9,2,6,13,25,4,15,7,1,3,19};
	print(A,12);
	printf("\n");
	// adjust_down(A,1,11);
	// build_heap(A,11);
	heap_sort(A,11);
	
	print(A,12);
	return 0;
}