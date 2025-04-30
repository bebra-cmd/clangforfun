#ifndef TREE_H
#define TREE_H
typedef struct Tree{
    int Val;
    struct Tree* Left;
    struct Tree* Right;
    }Tree;
    Tree* NewTree(int Val);
    void BinarySearchInsertion(int Val,Tree* head);
    void PrintSorted(Tree* head);
    void FreeTree(Tree* head);
#endif