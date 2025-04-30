#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct Tree{
int Val;
struct Tree* Left;
struct Tree* Right;
}Tree;

Tree* NewTree(int Val){
    Tree* head=(Tree*)malloc(sizeof(Tree));
    head->Val=Val;
    head->Left=NULL;
    head->Right=NULL;
    return head;
}
void BinarySearchInsertion(int Val,Tree* head){
    if (head==NULL){return;}
    if (head->Val>Val){
        if (head->Left==NULL){
        head->Left=NewTree(Val);
    }else{BinarySearchInsertion(Val,head->Left);}
    }else{
        if (head->Right==NULL){
        head->Right=NewTree(Val);
    }else{BinarySearchInsertion(Val,head->Right);}
    }
}
void PrintSorted(Tree* head){
    if (head==NULL){return;}
    PrintSorted(head->Left);
    printf("%d ",head->Val);
    PrintSorted(head->Right);
    
}
void FreeTree(Tree* head){
    if (head==NULL){return;}
    FreeTree(head->Left);
    FreeTree(head->Right);
    free(head);
}
