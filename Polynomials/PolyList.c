/////////////////////////////////////////////////////////
//
//  C file for dynamic double-linked list of polynomials
//
//  Author: B mc
//  last modified: 28.11.18
////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#include "PolyList.h"
#include "Poly.h"

///////////////////////////////////////////////////////
// listCreate()
// creates an empty double linked list, head points to tail
// which is implemented as NULL
//
// parameter: none
// return: pointer to list if success
//         pointer to NULL on failure
///////////////////////////////////////////////////////

llist *listCreate()
{
  llist *list;
  list = (llist *) malloc(sizeof(llist));
  // check for allocation success
  if (list != NULL) {
    // attempt to allocate memory for head
    list->head = (llnode *) malloc(sizeof(llnode));
    if (list->head != NULL) {
      // allocation successfull, satisfy condition
      // that head points to tail (NULL) and current is head
      list->head->after = NULL;
      list->current = list->head;
      list->head->before = NULL; // nothing comes before the head so before is NULL
    } else {
      // need to de-allocate list and set it to NULL
      free(list);
      list = NULL;
    }
  }
  // returned value is as desired, failure of malloc()
  // will return NULL which indicates also invalid
  // linked list
  return list;
  }


///////////////////////////////////////////////////////
// listDelete(list)
// deletes the entire list of which head is head-node
//
// parameter:	head - head of a valid list
// return:		void
///////////////////////////////////////////////////////
void listDelete(llist *list)
{
  llnode *next;

  // delete all nodes until list is empty
  // start at beginning of list
  list->current = list->head;
  // iterate through all nodes in list and delete them
  while (list->head->after != NULL) {
    next = list->head->after;
    free(next->p);
    list->head->after = list->head->after->after;
    free(next);
  }

  // delete head
  // and list itself
  free(list->head);
  free(list);
}


///////////////////////////////////////////////////////
// insertAfter(p, list)
// creates a new node newnode, associates data d with
// newnode and inserts newnode in linse as successor of
// current node
//
// parameter: d - data to be associated with newnode
//            list - list into which to insert d
// return: ok - insertion successful
//         noMemory - no memory available to create newnode
///////////////////////////////////////////////////////
llError insertAfter(Polynomial *p, llist *list)
{
  llError returnvalue = ok;
  llnode *newnode;

  // create new node
  newnode = (llnode *) malloc(sizeof(llnode));
  // allocation successful?
  if (newnode == NULL) {
    // allocation failure
    returnvalue = noMemory;
  } else {
    // allocation successful
    // associate data d with newnode
    newnode->p = p;
    // link newnode into linked list
    // 1. set succcessor of newnode to current nodes's successor
    newnode->after = list->current->after;
    // 2. set predeccessor of new node to be current node.
    newnode->before = list->current;
    // 3. set successor of current node to newnode
    list->current->after = newnode;

    // increment number of nodes by 1.
    list->nodes++;
  }
  return returnvalue;
}

///////////////////////////////////////////////////////
// deleteNext(list)
// removes successor of node from linked list
//
// parameter: list - pointer to list from which node is
//                   to be removed
// return: ok - node has been removed
//         illegalNode - cannot remove as successor
//                       of current is tail
///////////////////////////////////////////////////////
llError deleteCurrent(llist *list)
{
  llError result = ok;
  if (list->current->before == NULL) {
    // current node is head. cannot remove.
    result = illegalNode;
  } else {
    list->current->before->after = list->current->after;//link previous node to next node
    if (list->current->after != NULL){
      list->current->after->before = list->current->before;
    }
    free(list->current); // delete current node
  }
  return result;
}

///////////////////////////////////////////////////////
// gotoHead(list)
// sets current node of list to head
//
// parameter: list - list to be reset
// return: void
///////////////////////////////////////////////////////
void gotoHead(llist *list)
{
  // reset curren to head
  list->current = list->head;
}

///////////////////////////////////////////////////////
// gotoNextNode(list)
// sets current node of list to its successor
//
// parameter: list - list to be traversed
// return: ok - current has been set to successor
//         illegalNode - successor of current it tail
///////////////////////////////////////////////////////
llError gotoNextNode(llist *list)
{
  llError result = ok;
  // is successor of current tail?
  if (list->current->after != NULL) {
    // no -> move forward
    list->current = list->current->after;
  } else {
    // reached end of list, cannot move any further
    result = illegalNode;
  }
  return result;
}


///////////////////////////////////////////////////////
// gotoPrevNode(list)
// sets current node of list to its predeccessor
//
// parameter: list - list to be traversed
// return: ok - current has been set to pre
//         illegalNode - current it head
///////////////////////////////////////////////////////
llError gotoPrevNode(llist *list)
{
  llError result = ok;
  // this node the head?
  if (list->current->before != NULL) {
    // no -> move backward
    list->current = list->current->after;
  } else {
    // reached head, cannot move any further
    result = illegalNode;
  }
  return result;
}


///////////////////////////////////////////////////////
// accessData
// returns polynomial * of current node
//
// parameter: list - list to be accessed
// return: if current is head or tail: NULL
//         otherwise, data of current node
///////////////////////////////////////////////////////
Polynomial *accessPoly(llist *list)
{
  // is current head or tail?
  if ((list->current != list->head) && (list->current != NULL)) {
    // no, return data
    return list->current->p;
  }
  else {
    // yes, return NULL
    return NULL;

  }
}
