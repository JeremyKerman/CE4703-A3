//////////////////////////////////////////////////
//
//  Header file for Main Module
//
//////////////////////////////////////////////////

#ifndef Main_H
#define Main_H
#include "Polynomials/PolyList.h"
#include "Polynomials/Poly.h"

void menu(llist *polyList);
void menu_new_polynomial(llist *polyList);
void menu_delete_polynomial(llist *polyList);
void menu_add_polynomials(llist *polyList);
void menu_multiply_polynomial(llist *polyList); 
void menu_divide_polynomial(llist *polyList);
void menu_normalise_polynomial(llist *polyList);
void menu_get_order(llist *polyList); 
void menu_print(llist *polyList); 
void menu_exit(llist *polyList);

#endif
