#include "TreeNode.h"
#include <stdio.h>

void printTree(TreeNode *node, int u){
    if(node==NULL){
        return;}
    else{
        printTree(node->left, ++u);
        for(int i=0; i<u; ++i)
            printf("\t");
        printf("%d\n",node->data);
        u--;
    }
    printTree(node->right, ++u);
}

void preorderPrint(TreeNode *node){
    if(node == NULL){
        return; }
    printf("%d ", node->data);
    preorderPrint(node->left);
    preorderPrint(node->right);
}

void inorderPrint(TreeNode *node){
    if(node == NULL){
        return; }
    inorderPrint(node->left);
    printf("%d ", node->data);
    inorderPrint(node->right);
}

void push(unsigned int value, TreeNode **node){
    if((*node)==NULL){
       (*node) = new TreeNode;
       (*node)->data = value;
       (*node)->left = NULL;
       (*node)->right = NULL;
       return;
    }
    if(value > (*node)->data){
        push(value, &(*node)->right);}
    else{
        push(value, &(*node)->left);
    }
}

void insertInRoot(TreeNode **node, unsigned int x){
   TreeNode *zzz = NULL;
   push(x, &zzz);
   if(x > (*node)->data){
        zzz->left = *node;
        zzz->right = NULL;
   }else{
        zzz->right = *node;
        zzz->left = NULL;
   }
   *node = zzz;
}
