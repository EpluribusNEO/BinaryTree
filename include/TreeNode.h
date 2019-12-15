#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

struct TreeNode{ //typedef struct{
    unsigned int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

extern void push(unsigned int data, TreeNode **node);
extern void printTree(TreeNode *node, int u);

extern void preorderPrint(TreeNode *node);
extern void inorderPrint(TreeNode *node);

extern TreeNode* insertElement(TreeNode **node, unsigned int x);
extern void insertInRoot(TreeNode **node, unsigned int x);
#endif // TREENODE_H_INCLUDED
