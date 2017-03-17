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

int find(int k,int in[],int istart,int iend){
	int i = istart;
	while(i<=iend){
		if(in[i]==k){
			return i;
		}
		i++;
	}
	return -1;
}


TreeNode * build_tree(int post[],int n,int in[],int istart,int iend){
	if(istart>iend) return NULL;
	int i;
	int pos = -1;
	for(i=n-1;i>=0;i--){
		pos = find(post[i],in,istart,iend);
		if(pos!=-1){
			break;
		}
	}
	if(i<0) return NULL;
	else{
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
		root->val = in[pos];
		root->left = build_tree(post,n,in,istart,pos-1);
		root->right = build_tree(post,n,in,pos+1,iend);
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
	int post[] = {8,9,4,5,2,6,7,3,1};
	int in[] = {8,4,9,2,5,1,6,3,7};
	TreeNode * root = build_tree(post,9,in,0,8);
	preOrderTraverse(root);
	return 0;
}