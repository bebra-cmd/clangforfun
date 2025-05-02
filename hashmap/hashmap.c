#include "../list/list.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
//issue: no string struct
//so many casts from int to int64(is indexing can work with int64? check)
typedef enum DataTypesKey {
    INT_TYPE_KEY,
    STRING_TYPE_KEY
} DataTypesKey;
typedef union Keys{
    int integerValue;
    char* stringValue;  
}Keys;
typedef struct Bucket{
List* Collisions;
}Bucket;
typedef struct HashMap{
    DataTypesKey KeyType;
    DataTypes ValueType;
    Bucket* Buckets;
    int Len;
   int64_t PrimeNumber; //seed,trouble for integer no need
}HashMap;
int64_t HashGenerator(char* Key,int64_t primeNumber){
    int64_t result=0;
        for (size_t i=0;Key[i]!='\0';i++){
            result=result*primeNumber;
            result^=Key[i];
        }
    
    return result;
}
HashMap* CreateHashMap(DataTypesKey keyType,DataTypes valuesType,int len){
    HashMap* table=(HashMap*)malloc(sizeof(HashMap));
    table->KeyType=keyType;
    table->ValueType=valuesType;
    table->Len= len;
    table->Buckets=(Bucket*)malloc(len*sizeof(Bucket));
    table->PrimeNumber=813951179412191; //from random prime number generator, better idea generate always i think
    return table;
}
void Add(HashMap* table,Keys Key,Values Value){
    switch (table->KeyType){
        case INT_TYPE_KEY:
        int trueIndex=Key.integerValue%table->Len;
        table->Buckets[trueIndex].Collisions=CreateList(Value,table->ValueType);
        break;
        case STRING_TYPE_KEY:
        int64_t index=HashGenerator(Key.stringValue,table->PrimeNumber);
        int trueIndex=(int)(index%(int64_t)table->Len);
        table->Buckets[trueIndex].Collisions=CreateList(Value,table->ValueType);
        break;
        default:
        printf("WRONG TYPE FLAG\n");
        break;
    }
}
int Lookup(HashMap* table,Keys key){
    switch (table->KeyType){
        case INT_TYPE_KEY:
        int trueIndex=key.integerValue%table->Len;
        if (table->Buckets[trueIndex].Collisions!=NULL){
            return 1;
        }else {return 0;}
        break;
        case STRING_TYPE_KEY:
        int64_t index=HashGenerator(key.stringValue,table->PrimeNumber);
        int trueIndex=(int)(index%(int64_t)table->Len);
        if (table->Buckets[trueIndex].Collisions!=NULL){
            return 1;
        }else {return 0;}
        break;
        default:
        printf("WRONG TYPE FLAG\n");
        break;
    }
    
}
Values Get(HashMap* table,Keys key){
    switch (table->KeyType){
        case INT_TYPE_KEY:
        int trueIndex=key.integerValue%table->Len;
        if (table->Buckets[trueIndex].Collisions!=NULL){
            return (table->Buckets[trueIndex].Collisions->Val);
        }else{
        switch(table->ValueType){
            case INT_TYPE:
            return (Values)0;
            case FLOAT_TYPE:
            return (Values)0.0f;
            case STRING_TYPE:
            return (Values)"";
            default:
            printf("WRONG FLAG TYPE");
            break;
        }
        }
        break;
        case STRING_TYPE_KEY:
        int64_t index=HashGenerator(key.stringValue,table->PrimeNumber);
        int trueIndex=(int)(index%(int64_t)table->Len);
        if (table->Buckets[trueIndex].Collisions!=NULL){
            return (table->Buckets[trueIndex].Collisions->Val);
        }else{
            switch(table->ValueType){
                case INT_TYPE:
                return (Values)0;
                case FLOAT_TYPE:
                return (Values)0.0f;
                case STRING_TYPE:
                return (Values)"";
                default:
                printf("WRONG FLAG TYPE");
                break;
            }
            }
        break;
        default:
        printf("WRONG TYPE FLAG");
        break;
    }

    
}
void Change(HashMap* table,Keys key,Values val){
    switch (table->KeyType){
        case INT_TYPE_KEY:
        int trueIndex=key.integerValue%table->Len;
        if (table->Buckets[trueIndex].Collisions!=NULL){
            table->Buckets[trueIndex].Collisions->Val=val;
        }else {
            Add(table,key,val);
        }
        break;
        case STRING_TYPE_KEY:
        int64_t index=HashGenerator(key.stringValue,table->PrimeNumber);
        int trueIndex=(int)(index%(int64_t)table->Len);
        if (table->Buckets[trueIndex].Collisions!=NULL){
            table->Buckets[trueIndex].Collisions->Val=val;
        }else {
            Add(table,key,val);
        }
        break;
        default:
        printf("WRONG TYPE FLAG");
        break;
    }

}
void Delete(HashMap* table,Keys key){
    switch (table->KeyType){
        case INT_TYPE_KEY:
        int trueIndex=key.integerValue%table->Len;
        if (table->Buckets[trueIndex].Collisions!=NULL){
            FreeList(table->Buckets[trueIndex].Collisions);
        }
        break;
        case STRING_TYPE_KEY:
        int64_t index=HashGenerator(key.stringValue,table->PrimeNumber);
        int trueIndex=(int)(index%(int64_t)table->Len);
        if (table->Buckets[trueIndex].Collisions!=NULL){
            FreeList(table->Buckets[trueIndex].Collisions);
        }
        break;
        default:
        printf("WRONG TYPE FLAG");
        break;
    }
}
void PurgeHashMap(HashMap* table){
    for (int i=0;i<table->Len;i++){
        if (table->Buckets[i].Collisions!=NULL){
            FreeList(table->Buckets[i].Collisions);
        }
    }
    free(table->Buckets);
    free(table);
    
}


