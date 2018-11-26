//////////////////////////////////////////////////
//
//  Header file for Hash Tables module
// (I don't know if this counts as a hash table but I didn't quite understand how to make a proper one)
//////////////////////////////////////////////////

//Include guard
#ifndef HASH_H
#define HASH_H

// hash table structs

//hash_item struct, it will hold a polynomial inside the table
typedef struct {
  Polynomial* p;
  int index;
} hash_item;

//table storing its size and hash_item array
typedef struct {
  int size;
  hash_item hash_item_array[];
} hash_table;

//Include guard
#endif
