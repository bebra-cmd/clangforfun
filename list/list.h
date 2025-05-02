#ifndef LIST_H
#define LIST_H
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

List* CreateList(Values val,DataTypes type);
List* AddNode(Values val,List* head);
List* FindNode(Values val,List* head);
List* RemoveNode(Values val,List* head);
void FreeList(List* head);
void PrintPointers(List* head);
#endif