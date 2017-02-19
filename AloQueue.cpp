#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode{
	int data;
	struct LinkedNode *next;
}LinkedNode;

class AloQueuq{
private:
	int _size;
	LinkedNode *_front;
	LinkedNode *_back;
public:
	AloQueuq(){
		this->_size=0;
		_front=_back=NULL;		
	}
	int push_back(int data){
		LinkedNode *p = (LinkedNode *)malloc(sizeof(LinkedNode));
		p->data = data;
		p->next=NULL;
		if(!size()){
			_front=_back = p;
		}else{
			_back->next =p;
			_back = p;
		}
		_size++;
	}
	void pop(){
		if(!this->size()){
			return ;
		}else{
			int data = _front->data;
			_front=_front->next;
			_size--;
		}
	}
	int front(){
		if(!this->size()){
			return -9999;
		}else{
			return _front->data;
		}
	}
	int size(){
		return _size;
	}
};

int main(){
	AloQueuq Q;
	Q.push_back(1);
	Q.push_back(2);
	Q.push_back(3);
	Q.push_back(4);
	while(Q.size()){
		printf("%d\n", Q.front());
		Q.pop();
	}
	return 0;
}