#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdint.h>
#include "../list/list.h"
typedef struct Bucket{
    List* Collisions;
    }Bucket;
    typedef struct HashMap{
       Bucket* Buckets;
       int len;
       int64_t PrimeNumber; //seed
    }HashMap;

    int64_t HashGenerator(const char* str,int64_t primeNumber);
    HashMap* CreateHashMap(int len);
    void Add(HashMap* table,const char* key, int val);
    int Lookup(HashMap* table,const char* key);
    int Get(HashMap* table,const char* key);
    void Delete(HashMap* table,const char* key);
    void PurgeHashMap(HashMap* table);

#endif