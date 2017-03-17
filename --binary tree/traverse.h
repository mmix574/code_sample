#include <stdio.h>
#include "TreeNode.h"

InOrderTraverse(TreeNode *root){
	if(root->left){
		InOrderTraverse(root->left);
	}
	printf("%d ",root->val);
	if(root->right){
		InOrderTraverse(root->right);
	}
}
