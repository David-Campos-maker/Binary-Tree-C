#ifndef _TREE_NODE_
#define _TREE_NODE_

typedef struct treeNode{
    int value;
    struct treeNode* nDir;
    struct treeNode* nEsq;
}TreeNode;

typedef TreeNode* pNode;

TreeNode* constructorTreeNode(int value);
TreeNode* addTreeNode(TreeNode* root , TreeNode* newNode);
int countTreeNode(TreeNode* root);
void printTreeNode(TreeNode* root);
TreeNode* removeTreeNode(TreeNode* root , int value);
TreeNode* searchTreeNode(TreeNode* root , int searchValue);

#endif
