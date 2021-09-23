#include<stdio.h>
#include<malloc.h>
#include"treeNode.h"

TreeNode* _procurarComPai(TreeNode* root , int searchValue , pNode* pai){
  pNode aux = root;
  *pai = NULL;

  while(aux != NULL){
    if(searchValue == aux->value) return aux;
    *pai = aux;

    if(searchValue < aux->value)
      aux = aux->nEsq;
    else
      aux = aux->nDir;
  }
  return NULL;
}

TreeNode* constructorTreeNode(int value){
  TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));

  newNode->value = value;
  newNode->nEsq = NULL;
  newNode->nDir = NULL;

  return newNode;
}

TreeNode* addTreeNode(TreeNode* root , TreeNode* newNode){
  if(root == NULL) 
    return newNode;

  if(newNode->value < root->value) {
    root->nEsq = addTreeNode(root->nEsq , newNode);
  } else {
    root->nDir = addTreeNode(root->nDir , newNode);
  }

  return root;
}

int countTreeNode(TreeNode* root){
  if(root == NULL) 
    return 0;

  return 1 + countTreeNode(root->nEsq) + countTreeNode(root->nDir);
}

void printTreeNode(TreeNode* root){
  if(root != NULL) {
    printf("%d" , root->value);
    printf("(");
    printTreeNode(root->nEsq);
    printTreeNode(root->nDir);
    printf(")");
  }
}

TreeNode* searchTreeNode(TreeNode* root , int searchValue){
  if(root == NULL) 
    return NULL;

  if(root->value == searchValue)
    return root;

  if(searchValue < root->value)
    return searchTreeNode(root->nEsq , searchValue);

  return searchTreeNode(root->nDir , searchValue);
}

TreeNode* removeTreeNode(TreeNode* root , int value){
  pNode pai , cara;
  int isFilhoEsquerda = 0;
  if(root == NULL) 
    return NULL;

  cara = _procurarComPai(root , value , &pai);
  
  if(pai != NULL) {
    isFilhoEsquerda = cara->value < pai->value ? 1 : 0;
  }

  // 0 Filhos
  if(cara->nDir == NULL && cara->nEsq == NULL) {
    if(pai != NULL){
      if(isFilhoEsquerda == 1) 
        pai->nEsq = NULL;
      else 
        pai->nDir = NULL;
    }

    free(cara);
    return pai != NULL ? root : NULL;
  }

  // 1 Filho à Direita
  if(cara->nDir != NULL && cara->nEsq == NULL) {
    if(pai != NULL){
      if(isFilhoEsquerda == 1) 
        pai->nEsq = cara->nDir;
      else 
        pai->nDir = cara->nDir;

    } else {
      root = cara->nDir;
    }

    free(cara);
    return root;
  }

  // 1 Filho à Esquerda
  if(cara->nEsq != NULL && cara->nDir == NULL) {
    if(pai != NULL){
      if(isFilhoEsquerda == 1) 
      pai->nEsq = cara->nEsq;
    else 
        pai->nDir = cara->nEsq;
            
    } else {
      root = cara->nEsq;
    }

    free(cara);
    return root;
  }

  // 2 Filhos
  pNode promovido = cara->nEsq;
  pNode paiPromovido = cara;

  while(promovido->nDir != NULL) {
    paiPromovido = promovido;
    promovido = promovido->nDir;
  }

  if(paiPromovido != cara) {
    paiPromovido->nDir = promovido->nEsq;
    promovido->nEsq = cara->nEsq;
  }

  promovido->nDir = cara->nDir;

  if(pai != NULL) {
    if(isFilhoEsquerda == 1) 
      pai->nEsq = promovido->nDir;
    else 
      pai->nDir = promovido->nDir;

  } else {
    root = promovido;
  }

  free(cara);
  return root;
}
