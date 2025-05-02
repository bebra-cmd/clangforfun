#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdint.h>
#include "../list/list.h"
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
   int64_t PrimeNumber;
}HashMap;
HashMap* CreateHashMap(DataTypesKey keyType,DataTypes valuesType,int len);
void Add(HashMap* table,Keys Key,Values Value);
int Lookup(HashMap* table,Keys key);
Values Get(HashMap* table,Keys key);
void Change(HashMap* table,Keys key,Values val);
void Delete(HashMap* table,Keys key);
void PurgeHashMap(HashMap* table);
#endif