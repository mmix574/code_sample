#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(){
		left = right = NULL;
	}
}TreeNode;


int find(int k,int in[],int istart,int iend){
	int i = istart;
	while(i<=iend){
		if(in[i] == k){
			return i;
		}
		i++;
	}
	return -1;
}

TreeNode * build_tree(int level[],int n,int in[],int istart,int iend){
	int pos = -1;
	int i;
	for(i=0;i<n;i++){
		pos = find(level[i],in,istart,iend);
		if(pos!=-1) break;
	}
	if(i==n) return NULL;
	else{
		TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
		root->val = in[pos];
		root->left = build_tree(level,n,in,istart,pos-1);
		root->right = build_tree(level,n,in,pos+1,iend);
		return root;
	}
}

void preOrderTraverse(TreeNode *root){
	if(!root) return;
	printf("%d ",root->val);
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}

int main(){
	int level[] = {1,2,3,4,5,6,7,8,9};
	int in[] = {8,4,9,2,5,1,6,3,7};
	TreeNode *root = build_tree(level,9,in,0,8);
	preOrderTraverse(root);
	return 0;
}