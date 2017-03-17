#include <stdio.h>


typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(){
		next = NULL;
	}
}TreeNode;

int find(int A[],int satrt,int end,int k){
	int i = start;
	while(i<=end){
		if(A[i]==k){
			return i;
		}
		i++;		
	}
	return -1;
}

TreeNode *build_tree(int pre[],int pstart,int pend,int in[],int istart,int iend){
	int pos = find(in,istart,iend,pre[start]);
	if(pos==-1) return NULL;
	TreeNode * t = (TreeNode *)malloc(sizeof(TreeNode));
	t->val = pre[start];
	t->left = build_tree(pre,)
	
}

void preOrderTraverse(TreeNode *root){
	if(!root) return;
	printf("%d ",root->val);
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}

int main(){
	int pre[100] = {1,2,3,4,5,6,7,8,9};
	int in[100] = {8,4,9,2,5,1,6,3,7};
	TreeNode *root = build_tree(pre,0,8,in,0,8);
	return 0;
}