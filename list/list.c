#include <stdlib.h>
#include <stdio.h>
typedef struct List{
int Val;
struct List* Next;
}List;

List* CreateList(int Val){
    List* Head=(List*)malloc(sizeof(List));
    Head->Val=Val;
    Head->Next=NULL;
    return Head;
}
//TIME COMPLEXITY O(1) SPACE COMPLEXITY O(1)
List* AddNode(int Val,List* head){
List* NewHead=CreateList(Val);
NewHead->Next=head;
return NewHead;
}
//TIME COMPLEXITY O(N)(O(N/2)) SPACE COMPLEXITY O(1)
List* FindNode(int Val,List* head){
List* fast=head;
List* slow=head;
for(;fast!=NULL && fast->Next!=NULL;){
        if (fast->Val==Val){
            return fast;
        }
        if (slow->Val==Val){
            return slow;
        }
        slow=slow->Next;
        fast=fast->Next->Next;
    }
return NULL;
}
//TIME COMPLEXITY O(N)(O(N/2)) SPACE COMPLEXITY O(1)
List* RemoveNode(int Val,List* head){
    if (head->Val==Val){
        List* temp=head->Next;
        free(head);
        return temp;
    }
    List* fast=head;
    List* slow=head;
    for(;fast!=NULL && fast->Next!=NULL;){
            if (slow->Next->Val==Val){
                List* temp=slow->Next->Next;
                free(slow->Next);
                slow->Next=temp;
                return head;
            }
            if (fast->Next->Val==Val){
                List* temp=fast->Next->Next;
                free(fast->Next);
                fast->Next=temp;
                return head;
            }
            slow=slow->Next;
            fast=fast->Next->Next;
        }
    return head;
    }

void FreeList(List* head){
    List* DopelGanger=head;
for (;head!=NULL;){
head=head->Next;
free(DopelGanger);
DopelGanger=head;
}
}
void PrintPointers(List* head){
    for (;head!=NULL;){
        printf("pointer is %p, Value is %d\n",head,head->Val);
        head=head->Next;
    }
}
