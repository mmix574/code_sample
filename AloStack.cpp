#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 10

typedef struct LinkedNode{
	int data;
	LinkedNode *next;
}LinkedNode;

class Stack{
private:	
	int _size;
	LinkedNode *head;
public:
	Stack(){
		_size = 0;
		head = (LinkedNode *)malloc(sizeof(LinkedNode));
		head->next = NULL;
		head->data = 9999;
	}
	int push(int data){
		LinkedNode *p = (LinkedNode *)malloc(sizeof(LinkedNode));
		p->data = data;
		p->next = head->next;
		head->next = p;
		_size++;
		return 0;
	}
	int pop(){
		if(head->next==NULL){
			return 0;
		}else{
			LinkedNode *p = head->next;
			head->next = p->next;
			int data = p->data;
			free(p);
			_size--;
			return data;			
		}
	}
	int top(){
		if(head->next==NULL){
			return -9999;
		}else{
			LinkedNode *p = head->next;
			return p->data;			
		}
	}
	int size(){
		return this->_size;
	}

};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	while(s.size()){
		int e = s.top();
		printf("e = %d \n",e);
		s.pop();
	}
	return 0;
}