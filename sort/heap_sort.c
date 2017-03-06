#include <stdio.h>

void adjust_down(int A[],int pos,int n);

void heap_sort(int A[],int len){

}
void build_heap(int A[],int n){
	int p;
	do{
		p = n/2;
		int left = 2*p;
		int right = 2*p+1;
		if(right>n){
			//只有左支
			if(A[p]>A[left]){
				int t = A[p];
				A[p] = A[left];
				A[left] = t;
			}
		}else{
			//左右支
			if(A[p]<A[left]&&A[p]<A[right]){
				continue;
			}else if(A[left]<A[right]){
				int t = A[p];
				A[p] = A[left];
				A[left] = t;
				adjust_down(A,left,n);
			}else{
				int t = A[p];
				A[p] = A[right];
				A[right] = t;
				adjust_down(A,right,n);
			}	
		}
		n-=2;
	}while(p!=1);
	
}
void adjust_down(int A[],int pos,int n){
	int left = 2*pos;
	int right = 2*pos+1;
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
	build_heap(A,11);

	// adjust_down(A,1,11);
	
	print(A,12);
	return 0;
}