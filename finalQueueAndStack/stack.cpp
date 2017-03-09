#include <stdio.h>

#define STACK_SIZE  100


int main(){
	int Stack[STACK_SIZE];
	int top = 0;
	int e ;
	if(top<STACK_SIZE){
		Stack[top++] = 10;
	}
	if(top<STACK_SIZE){
		Stack[top++] = 12;
	}
	if(top<STACK_SIZE){
		Stack[top++] = 14;
	}
	if(top<STACK_SIZE){
		Stack[top++] = 16;
	}

	if(top){
		e = Stack[--top];		
		printf("%d\n",e);
	}
		if(top){
		e = Stack[--top];		
		printf("%d\n",e);
	}
		if(top){
		e = Stack[--top];		
		printf("%d\n",e);
	}
		if(top){
		e = Stack[--top];		
		printf("%d\n",e);
	}
		if(top){
		e = Stack[--top];		
		printf("%d\n",e);
	}		if(top){
		e = Stack[--top];		
		printf("%d\n",e);
	}

	return 0;
}

