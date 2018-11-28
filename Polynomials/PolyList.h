// PolyList.h
//
// Header file for PolyList.c
//
// Author: Bryan McSweeney
// last modified: 28.11.18

#ifndef PolyList_H
#define PolyList_H

///////////////////////////////////////////////////////
// define error codes for double linked list
///////////////////////////////////////////////////////

typedef enum {ok, illegalNode, noMemory} llError;


///////////////////////////////////////////////////////////    <----- IMPORTANT
// NOTE: data stored in linked list is of type 'Polynomial'    <----- IMPORTANT
//       and is defined in Polynomials/Poly.h
///////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
// define structure for a node of the douoble linked list
//////////////////////////////////////////////////////////

typedef struct n {
  
  Polynomial p; // store a polynomial in each node 
  struct n *after; // store pointer no node after this one 
  struct n *before; // store pointer to node before this one
  
} llnode;

///////////////////////////////////////////////////////
// define type for double linked list
///////////////////////////////////////////////////////

typedef struct {
  
  llnode *head; // head node
  llnode *current; // current node
  int n; // number of nodes
  
} llist;


///////////////////////////////////////////////////////
// function declarations
///////////////////////////////////////////////////////

llist *listCreate();
void listDelete(llist *list);
data *accessData(llist *list);
llError insertAfter(data *d, llist *list);
llError deleteCurrent(llist *list);
void gotoHead(llist *list);
llError gotoNextNode(llist *list);
llError gotoPrevNode(llist *list);

#endif
