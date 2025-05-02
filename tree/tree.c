#include <stdlib.h>
#include <stdio.h>
union ValueInputs{
    int integerValue;
    float floatValue;
    char* stringValue;  
  };
typedef struct Tree{
union ValueInputs* Val;
struct Tree* Left;
struct Tree* Right;
}Tree;

Tree* NewTree(union ValueInputs* Val){
    Tree* head=(Tree*)malloc(sizeof(Tree));
    head->Val=Val;
    head->Left=NULL;
    head->Right=NULL;
    return head;
}
void BinarySearchInsertion(union ValueInputs* Val,Tree* head){
    if (head==NULL){return;}
    //refactor logic here according to input values better idea allocate variable and compare
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
