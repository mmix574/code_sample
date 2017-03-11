#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_LEN 1000

typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
}TreeNode;

TreeNode** Q[QUEUE_MAX_LEN] = {0};
int front=0,rear=0;
bool empty(){
	if(front==rear){
		return true;
	}else{
		return false;
	}
}
bool full(){
	if((rear+1+QUEUE_MAX_LEN)&QUEUE_MAX_LEN==front){
		return true;
	}else{
		exit(-1);
		return false;
	}
}
void clear(){
	rear=front = 0;
}



int len(char *p){
	if(!p){
		return -1;
	}else{
		int length = 0;
		while(p[length]!='\0'){
			length++;
		}
		return length;
	}
}

TreeNode * createByNums(int A[],int n){
	TreeNode *root=NULL;
	for(int i = 0;i < n;i++){
		if(A[i]==0){
			front++;
		}else{
			if(!root){
				root = (TreeNode *)malloc(sizeof(TreeNode));
				root->val = A[i];
				root->left=root->right = NULL;			
				if(!full()) Q[rear++] = &(root->left);
				if(!full()) Q[rear++] = &(root->right);
			}else{
				if(!empty()){
					TreeNode **t = Q[front++];
					TreeNode * p = (TreeNode *)malloc(sizeof(TreeNode));
					*t = p;
					p->val = A[i];
					p->left = p->right = NULL;
					if(!full()) Q[rear++] = &(p->left);
					if(!full()) Q[rear++] = &(p->right);
				}
			}
		}

	}	
	return root;
}

TreeNode * createByChars(char A[]){
	
}

void InOrderTraverse(TreeNode *root){
	if(root->left){
		InOrderTraverse(root->left);
	}	
	printf("%d ",root->val);
	if(root->right){
		InOrderTraverse(root->right);
	}
}

char * dumps(TreeNode *root){
	//to implements;
	
//	char *res = (char*)malloc(sizeof(char)*1000);
//	int i = 0;
//	if(!root) return NULL;
//	clear();
//	if(!full()) Q[rear++] = root;
//	while(!empty()){
//		TreeNode* t = Q[front++];
//		if(!t){
//			res[i++] = '#';
//		}else{
//			res[i++] = t->val;
//			if(!full()) Q[rear++] = t->left;
//			if(!full()) Q[rear++] = t->right;
//		}
//	}
}

int main(){
//	if(!full()){
//		Q[rear++] = 1;
//	}	
//	if(!empty()){
//		int a = Q[front++];
//		printf("%d\n",a);
//	}
//	if(!empty()){
//		int a = Q[front++];
//		printf("%d\n",a);
//	}
	int A[10] = {1,2,0,3,5,6};
	TreeNode *root = createByNums(A,6);
	InOrderTraverse(root);
	return 0;
}
