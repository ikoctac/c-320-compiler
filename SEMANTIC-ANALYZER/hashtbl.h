#ifndef HASHTBL_H_INCLUDE_GUARD
#define HASHTBL_H_INCLUDE_GUARD

#include <stdlib.h>

typedef size_t hash_size;

struct hashnode_s {
	char *key;	//hash key
	void *data;	//associated data with key
	int scope;	//scope of the hashnode 
	struct hashnode_s *next;	//pointer to next hashnode
};

typedef struct hashtbl {
	hash_size size;		//hashtbl size
	struct hashnode_s **nodes;	//array of hashnode pointers
	hash_size (*hashfunc)(const char *);	//function pointer to hash function
} HASHTBL;


HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *)); //create new hashtable
void hashtbl_destroy(HASHTBL *hashtbl);	//destroy hashtable
int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data, int scope); //insert data into hashtable
int hashtbl_remove(HASHTBL *hashtbl, const char *key,int scope); //remove data from hashtable
void *hashtbl_get(HASHTBL *hashtbl, const char *key, int scope);


#endif