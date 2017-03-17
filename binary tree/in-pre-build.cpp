#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(){
		left = right = NULL;
	}
}TreeNode;

int find(int k,int A[],int start,int end){
	int i = start;
	while(i<=end){
		if(A[i]==k){
			return i;
		}
		i++;		
	}
	return -1;
}

TreeNode *build_tree(int pre[],int n,int in[],int istart,int iend){
	if(istart>iend) return NULL;
	int pos = -1;
	for(int i=0;i<n;i++){
		if((pos = find(pre[i],in,istart,iend))!=-1){
			break;
		}
	}
	if(pos==-1) return NULL;
	else{
		TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
		root->val = in[pos];
		root->left = build_tree(pre,n,in,istart,pos-1);
		root->right = build_tree(pre,n,in,pos+1,iend);
		return root;
	}
}

void preOrderTraverse(TreeNode *root){
	if(!root) return;
	printf("%d ",root->val);
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}

void postOrderTraverse(TreeNode *root){
	if(!root) return;
	postOrderTraverse(root->left);
	postOrderTraverse(root->right);
	printf("%d ",root->val);
}

int main(){
	int pre[100] = {1,2,4,8,9,5,3,6,7};
	int in[100] = {8,4,9,2,5,1,6,3,7};
	TreeNode *root = build_tree(pre,9,in,0,8);
	if(root){
		printf("get some thing\n");
	}else{
		printf("there is nothing\n");
	}
	postOrderTraverse(root);
	return 0;
}