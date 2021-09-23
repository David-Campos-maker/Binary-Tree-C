#ifndef _TREE_H_
#define _TREE_H_
#include"treeNode.h"

typedef struct {
    TreeNode* raiz;
}TREE;

TREE* constructTree();
void addArvore(TREE* tree , int valor);

#endif
