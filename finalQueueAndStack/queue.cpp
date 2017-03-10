#include <stdio.h>
// 这里要牺牲一个存储空间
#define QUEUE_SIZE 7

int main(){
	int Queue[QUEUE_SIZE];
	int front = 0;
	int rear = 0;

	int k,e;


	if((rear+1+QUEUE_SIZE)%QUEUE_SIZE!=front){
		k = 1;
		Queue[rear++] = k;
	}
	
	if((rear+1+QUEUE_SIZE)%QUEUE_SIZE!=front){
		k = 2;
		Queue[rear++] = k;
	}
		if((rear+1+QUEUE_SIZE)%QUEUE_SIZE!=front){
		k = 3;
		Queue[rear++] = k;
	}
		if((rear+1+QUEUE_SIZE)%QUEUE_SIZE!=front){
		k = 4;
		Queue[rear++] = k;
	}
		if((rear+1+QUEUE_SIZE)%QUEUE_SIZE!=front){
		k = 5;
		Queue[rear++] = k;
	}
		if((rear+1+QUEUE_SIZE)%QUEUE_SIZE!=front){
		k = 6;
		Queue[rear++] = k;
	}
		if((rear+1+QUEUE_SIZE)%QUEUE_SIZE!=front){
		k = 7;
		Queue[rear++] = k;
	}


	if(front!=rear){
		e = Queue[front++];
		printf("%d\n",e);
	}
		if(front!=rear){
		e = Queue[front++];
		printf("%d\n",e);

	}
		if(front!=rear){
		e = Queue[front++];
		printf("%d\n",e);

	}
		if(front!=rear){
		e = Queue[front++];
		printf("%d\n",e);

	}
		if(front!=rear){
		e = Queue[front++];
		printf("%d\n",e);
	}
		if(front!=rear){
		e = Queue[front++];
		printf("%d\n",e);
	}

	return 0;
}