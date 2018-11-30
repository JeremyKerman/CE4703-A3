//////////////////////////////////////////////////////////
// PolyTest.C
// Test function for Polynomials module
//
// Goes through a series of tests and compares them to expected values
////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "PolyList.h"
#include "Poly.h"

void poly_test()
{
  ////////////////////////////////////////////////////////////
  // test make_polynomial()
  ////////////////////////////////////////////////////////////
  Polynomial* poly = make_polynomial(5);
  poly->Coefficient[1] = 9;
  poly->Coefficient[3] = 6;
  poly->Coefficient[5] = 3;
  // poly = 9x^1 + 6x^3 + 3x^5

  if(poly) {
    printf("Polynomial made.\nSuccess!\n");
  } else {
    printf("\nPolynomial not made.\nFailure\n");
  }
  printf("\n=======================================\n");

  ///////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////
  // test add_polynomials()
  ////////////////////////////////////////////////////////////
  Polynomial* poly2 = make_polynomial(5);
  poly2->Coefficient[0] = 12;
  poly2->Coefficient[2] = 18;
  poly2->Coefficient[4] = 21;
  // poly2 = 12 + 18x^2 + 21x^4

  Polynomial* poly3 = add_polynomials(poly, poly2);
  int add_result = 0; //set the result of the test 0 = pass, 1 = fail

  printf("\nPolynomial Addition Test\n");
  for(int i=0; i<6; i++) {
    printf("\n%gx^%i + %gx^%i = %gx^%i", poly->Coefficient[i], i,
                                       poly2->Coefficient[i], i,
                                       poly3->Coefficient[i], i);
    if (((poly->Coefficient[i] + poly2->Coefficient[i]) != (poly3->Coefficient[i])));
      add_result = 1;
  }
  if(!add_result) {
    printf("\n\nTest Passed!");
  } else {
    printf("\n\nTest Passed!");
  }
  printf("\n=======================================\n");

  printf("\n");

}
