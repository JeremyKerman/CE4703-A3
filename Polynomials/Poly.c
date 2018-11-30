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
#include "Poly.h"

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
    n++; // x^0 also counted
    Polynomial* p = malloc((sizeof(Polynomial)+n*sizeof(double*)));
    if (!p) { perror("malloc make_polynomial"); exit(EXIT_FAILURE);};
    p->Order = n;
    for (int i=0; i<n; i++) p->Coefficient[i] =  0.0;
    return p;
}

////////////////////////////////////////////////////
// void del_polynomial(p)
// A function to delete a polynomial by freeing the
// memory allocated to it
//
// Parameters: Polynomial p
//
// Returns:    void
//////////////////////////////////////////////////////
void del_polynomial(Polynomial* p) {
  free(p);
}

////////////////////////////////////////////////////
// Polynomial add_polynomials(p1, p2)
// A function to add two polynomials together
//
// Parameters: Polynomial p1 - first polynomial
//             Polynomial p2 - second polynomial
//
// Returns:    Polynomial sum of p1 & p2
//////////////////////////////////////////////////////
Polynomial* add_polynomials(Polynomial* p1, Polynomial* p2) {
  int highest_order = MAX(p1->Order, p2->Order);
  Polynomial* p3 = make_polynomial(MAX(p1->Order, p2->Order));

  for(int i=0; i<highest_order; i++) {
      p3->Coefficient[i] = p1->Coefficient[i] + p2->Coefficient[i]; //if a coefficient is NULL
  }                                                                 //it will be treated as 0
  return p3;
}

////////////////////////////////////////////////////
// void multiply_polynomial(p, d)
// A function to multiply a Polynomial by a double
//
// Parameters: Polynomial p  - Polynomial to be multiplied
//             double d      - number to multiply by
//
// Returns:    void
//////////////////////////////////////////////////////
void multiply_polynomial(Polynomial* p, double d) {
  for(int i=0; i<p->Order; i++) {
    p->Coefficient[i] *= d;
  }
}

////////////////////////////////////////////////////
// void divide_polynomial(p, d)
// A function to divide a Polynomial by a double
//
// Parameters: Polynomial p  - Polynomial to be divided
//             double d      - number to divide by
//
// Returns:    void
//////////////////////////////////////////////////////
void divide_polynomial(Polynomial* p, double d) {
  for(int i=0; i<p->Order; i++) {
    p->Coefficient[i] /= d;
  }
}

////////////////////////////////////////////////////
// int get_order(p)
// A function which returns the highest order of a polynomial
//
// Parameters: Polynomial p  - Polynomial
//
// Returns:    int - the highest order of the polynomial
//////////////////////////////////////////////////////
int get_order(Polynomial* p) {
  for(int i=p->Order; i>=1; i--) {
    if(p->Coefficient[i])
      return i;
  }
  return 0;
}

////////////////////////////////////////////////////
// int normalise(p)
// A function which normalises a polynomial to make the
// highest order coefficient a 1
//
// Parameters: Polynomial p  - Polynomial
//////////////////////////////////////////////////////
int normalise(Polynomial* p) {
  printf("order = %d",p->Order);
  double divisor;
  for (int j= (p->Order-1); j>=0; j--) {
    if(p->Coefficient[j]) { //checking if divisor is 0
      divisor = p->Coefficient[j];
      printf("%.2f",divisor);
      for (int i=0; i<p->Order; i++) {
        p->Coefficient[i] /= divisor;
      }
      return 1;
    }
  }
  fprintf(stdout, "\nCan't normalise polynomial\n"); // no non-zero coefficient was found
  return 0;
}
