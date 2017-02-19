#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode * create(int array[],int len){
	ListNode * r,*p;
	for (int i = 0; i < len; ++i)
	{
		if(i==0){
			r=p=(ListNode *)malloc (sizeof(ListNode));
			p->val = array[i];
			p->next = NULL;
		}else{
			p->next = (ListNode *)malloc (sizeof(ListNode));
			p=p->next;
			p->val = array[i];
			p->next = NULL;
		}
	}
	return r;
}

void print(ListNode *r){
	while(r){
		printf("%d->",r->val);
		r=r->next;
	}
}