#ifndef HASHTBL_H_INCLUDE_GUARD
#define HASHTBL_H_INCLUDE_GUARD

#include <stdlib.h>

typedef size_t hash_size;

struct hashnode_s {
    char *key;   //hash key
    void *data;  //associated data with key
    int scope;   //scope of the hashnode
    struct hashnode_s *next;   //pointer to next hashnode
};

typedef struct hashtbl {
    hash_size size;      //hashtbl size
    struct hashnode_s **nodes;  //array of hashnode pointers
    hash_size (*hashfunc)(const char *);  //function pointer to hash function
} HASHTBL;

HASHTBL *hashtbl_create(size_t size, void (*free_data)(void *));
void hashtbl_destroy(HASHTBL *hashtbl);
int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data, int scope);
void *hashtbl_get(HASHTBL *hashtbl, int scope);  // Update the function signature to match the changes
int hashtbl_lookup_type(HASHTBL *hashtbl, const char *typeName);
// hashtbl.h
int isDeclaredInScope(HASHTBL *hashtbl, const char *id, int scope);


#endif
