#ifndef LIST_H
#define LIST_H
typedef struct List {
    int Val;
    struct List* Next;
} List;

List* CreateList(int Val);
List* AddNode(int Val, List* head);
List* FindNode(int Val, List* head);
List* RemoveNode(int Val, List* head);
void FreeList(List* head);
void PrintPointers(List* head);

#endif