#include<stdio.h>
#include<malloc.h>
#include"tree.h"
#include"treeNode.h"

TREE* constructTree() {
    TREE* newTree = (TREE*) malloc(sizeof(TREE));
    newTree->raiz = NULL;

    return newTree;
}

void addArvore(TREE* tree , int valor) {
    TreeNode* nodo = constructorTreeNode(valor);
    tree->raiz = addTreeNode(tree->raiz , nodo);
}
