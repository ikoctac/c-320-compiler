/* hashtbl.c - Fixed */
#include "hashtbl.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *mystrdup(const char *s) {
    char *b;
    if (!(b = malloc(strlen(s) + 1))) return NULL;
    strcpy(b, s);
    return b;
}

static hash_size def_hashfunc(const char *key) {
    hash_size hash = 0;
    while (*key) hash += (unsigned char)*key++;
    return hash;
}

HASHTBL *hashtbl_create(size_t size, void (*free_data)(void *)) {  // Keep this consistent with the header
    HASHTBL *hashtbl;
    if (!(hashtbl = malloc(sizeof(HASHTBL)))) return NULL;
    if (!(hashtbl->nodes = calloc(size, sizeof(struct hashnode_s*)))) {
        free(hashtbl);
        return NULL;
    }
    hashtbl->size = size;
    hashtbl->hashfunc = def_hashfunc;  // Default hash function
    return hashtbl;
}

void hashtbl_destroy(HASHTBL *hashtbl) {
    hash_size n;
    struct hashnode_s *node, *oldnode;
    for (n = 0; n < hashtbl->size; ++n) {
        node = hashtbl->nodes[n];
        while (node) {
            free(node->key);
            oldnode = node;
            node = node->next;
            free(oldnode);
        }
    }
    free(hashtbl->nodes);
    free(hashtbl);
}

int hashtbl_insert(HASHTBL *hashtbl, const char *key, void *data, int scope) {
    struct hashnode_s *node;
    hash_size hash = hashtbl->hashfunc(key) % hashtbl->size;
    node = hashtbl->nodes[hash];
    while (node) {
        if (!strcmp(node->key, key) && (node->scope == scope)) {
            node->data = data;
            return 0;
        }
        node = node->next;
    }
    if (!(node = malloc(sizeof(struct hashnode_s)))) return -1;
    if (!(node->key = mystrdup(key))) {
        free(node);
        return -1;
    }
    node->data = data;
    node->scope = scope;
    node->next = hashtbl->nodes[hash];
    hashtbl->nodes[hash] = node;
    return 0;
}

void *hashtbl_get(HASHTBL *hashtbl, int scope) {
    struct hashnode_s *node;
    for (hash_size i = 0; i < hashtbl->size; ++i) {
        node = hashtbl->nodes[i];
        while (node) {
            if (node->scope == scope) {
                return node->data;  // Return the data for matching scope
            }
            node = node->next;
        }
    }
    return NULL;
}

int hashtbl_lookup_type(HASHTBL *hashtbl, const char *typeName) {
    for (size_t i = 0; i < hashtbl->size; ++i) {
        struct hashnode_s *node = hashtbl->nodes[i];
        while (node) {
            if (strcmp(node->key, typeName) == 0) {
                return *(int *)(node->data);  // Return the type associated with the key
            }
            node = node->next;
        }
    }
    return 0;  // Return 0 (or another value) if not found
}

// New function to check if an identifier is declared in the specified scope
int isDeclaredInScope(HASHTBL *hashtbl, const char *id, int scope) {
    hash_size hash = hashtbl->hashfunc(id) % hashtbl->size;
    struct hashnode_s *node = hashtbl->nodes[hash];
    
    while (node) {
        if (!strcmp(node->key, id) && node->scope == scope) {
            return 1; // The identifier is declared in the scope
        }
        node = node->next;
    }
    
    return 0; // The identifier is not declared in the scope
}




