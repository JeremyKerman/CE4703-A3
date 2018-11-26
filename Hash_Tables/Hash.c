//////////////////////////////////////////////////
//
//  comments comments comments
//  C file for Polynomials module
//  comments comments comments
//
///////////////////////////////////////////////////

//include system headers
#include <stdlib.h>
#include <stdio.h>
//include custom headers
#include "../Polynomials/Poly.h"
#include "Hash.h"
//Functions

void initialize() {
  hash_table* new = make_hash_table();

}

hash_table* make_hash_table() {
  int default_size = 15;
  hash_table* new_hash_table = malloc(sizeof(hash_table) + default_size*sizeof(hash_item*));
  if (!new_hash_table) {
    perror("malloc make_polynomial");
    exit(EXIT_FAILURE);
  }
  new_hash_table->size = default_size;
  for (int i=0; i<default_size; i++) {
    hash_item* ht_item = new_hash_table->hash_item_array[i]
    ht_item = NULL;
  }
  return new_hash_table;
}

void del_hash_table(hash_table* ht) {
  free(ht->size);
  free(ht->hash_item_array);
  free(ht);
}

int new_hash_item(hash_table* ht) {
  for(int i=0; i<ht->size; i++) {
    if((ht->hash_item_array[i]) != NULL) {
      hash_item new_hash_item = malloc(sizeof(hash_item));
      new_hash_item->index = i;
      ht->hash_item_array[i] = new_hash_item;
      return 0;
    }
  )
  ht* = realloc(ht*, sizeof(hash_table) + (ht->size+1)*sizeof(hash_item*));
  hash_item new_hash_item = malloc(sizeof(hash_item));
  new_hash_item->index = ht->size;
  ht->hash_item_array[i] = new_hash_item;
  ht->size++;
  return 0;
}
