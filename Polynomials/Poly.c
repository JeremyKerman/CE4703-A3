//////////////////////////////////////////////////
//
//  C file for Polynomials module
//
//////////////////////////////////////////////////

//include system headers
#include <stdlib.h>
#include <stdio.h>
//include custom headers
#include "Poly.h"

//Declare macros


//Functions

////////////////////////////////////////////////////
// Polynomial make_polynomial(n)
// A function to make a variable size Polynomial
// which allocates the needed memory
//
// Parameters: int n - Order of the polynomial
//
// Returns:    Polynomial p of order n
//////////////////////////////////////////////////////
Polynomial* make_polynomial(int n) {
    Polynomial* p = malloc((sizeof(Polynomial)+n*sizeof(int*)));
    if (!p) { perror("malloc make_polynomial"); exit(EXIT_FAILURE);};
    p->Order_of_polynomial = n;
    for (int i=0; i<n; i++) p->Coefficient_Array[i] = NULL;
    return p;
}
