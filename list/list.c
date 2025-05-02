#include <stdlib.h>
#include <stdio.h>
typedef enum DataTypes{
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE
} DataTypes;
typedef union Values{
    int integerValue;
    float floatValue;
    char* stringValue;  
  }Values;
  
typedef struct List{
Values Val;
DataTypes Type;
struct List* Next;
struct List* Prev;
}List;

List* CreateList(Values val,DataTypes type){
    List* Head=(List*)malloc(sizeof(List));
    Head->Type=type;
    Head->Val=val;
    Head->Next=NULL;
    Head->Prev=NULL;
    return Head;
}
//TIME COMPLEXITY O(1) SPACE COMPLEXITY O(1)
List* AddNode(Values val,List* head){
List* NewHead=CreateList(val,head->Type);
NewHead->Next=head;
head->Prev=NewHead;
return NewHead;
}
//TIME COMPLEXITY O(N)(O(N/2)) SPACE COMPLEXITY O(1)
List* FindNode(Values val,List* head){
List* fast=head;
List* slow=head;
switch (head->Type){
    case INT_TYPE:
    for(;fast!=NULL && fast->Next!=NULL;){
        if (fast->Val.integerValue==val.integerValue){
            return fast;
        }
        if (slow->Val.integerValue==val.integerValue){
            return slow;
        }
        slow=slow->Next;
        fast=fast->Next->Next;
    }
    break;
    case FLOAT_TYPE:
    for(;fast!=NULL && fast->Next!=NULL;){
        if (fast->Val.floatValue==val.floatValue){
            return fast;
        }
        if (slow->Val.floatValue==val.floatValue){
            return slow;
        }
        slow=slow->Next;
        fast=fast->Next->Next;
    }
    break;
    case STRING_TYPE:
    for(;fast!=NULL && fast->Next!=NULL;){
        //do not use,add string comparing later and change it
        if (fast->Val.stringValue==val.stringValue){
            return fast;
        }
        if (slow->Val.stringValue==val.stringValue){
            return slow;
        }
        slow=slow->Next;
        fast=fast->Next->Next;
    }
    break;
    default:
    printf("WRONG TYPE FLAG\n");
    break;
}
return NULL;
}
//TIME COMPLEXITY O(1)(purge pointer const,find node n/2) SPACE COMPLEXITY O(1)
List* RemoveNode(Values val,List* head){
    List* rmNode=FindNode(val,head);
    if (rmNode->Prev==NULL){
        head=rmNode->Next;
    }else{
        rmNode->Prev->Next=rmNode->Next;
    }
    free(rmNode);
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
        switch(head->Type){
            case INT_TYPE:
            printf("pointer is %p, Value is %d\n",head,head->Val.integerValue);
            break;
            case FLOAT_TYPE:
            printf("pointer is %p, Value is %f\n",head,head->Val.floatValue);
            break;
            case STRING_TYPE:
            //add realisation to pushing all allocated block to printf or find way in built-in
            printf("pointer is %p, Value is %c\n",head,head->Val.stringValue);
            break;
            default:
            printf("WRONG TYPE FLAG\n");
            break;
        }
        head=head->Next;
    }
}
