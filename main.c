#include<stdio.h>
#include"tree.h"
#include"treeNode.h"

int main() {
    TREE* arvore1 = constructTree();

    addArvore(arvore1 , 15);
    addArvore(arvore1 , 12);
    addArvore(arvore1 , 21);

    printTreeNode(arvore1->raiz);

    return 0;
}
