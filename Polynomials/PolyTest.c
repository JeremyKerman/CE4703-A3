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

void poly_test()//     <----- declared in Main.h
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
    if (((poly->Coefficient[i] + poly2->Coefficient[i]) != (poly3->Coefficient[i])))
      add_result = 1;
  }
  if(!add_result) {
    printf("\n\nTest Passed!");
  } else {
    printf("\n\nTest Passed!");
  }
  printf("\n=======================================\n");

  printf("\n");

  ///////////////////////////////////////////////////////////
  // test multiply_polynomial()
  ////////////////////////////////////////////////////////////
  int multiply_result = 0; //set the result of the test 0 = pass, 1 = fail
  int multiplicand = 3;
  //make a copy of poly3 called poly4
  Polynomial* poly4 = make_polynomial(5);
  poly4->Coefficient[0] = 12;
  poly4->Coefficient[1] = 9;
  poly4->Coefficient[2] = 18;
  poly4->Coefficient[3] = 6;
  poly4->Coefficient[4] = 21;
  poly4->Coefficient[5] = 3;
  printf("\nPolynomial Multiplication Test\n");
  multiply_polynomial(poly4, multiplicand);
  for(int i=0; i<6; i++) {
    printf("\n%gx^%i * %i = %gx^%i", poly3->Coefficient[i], i,
                                      multiplicand, poly4->Coefficient[i], i);
    if (((poly3->Coefficient[i] * multiplicand) != (poly4->Coefficient[i])))
      multiply_result = 1;
  }
  if(!multiply_result) {
    printf("\n\nTest Passed!");
  } else {
    printf("\n\nTest Passed!");
  }
  printf("\n=======================================\n");

  printf("\n");

  ///////////////////////////////////////////////////////////
  // test divide_polynomial()
  ////////////////////////////////////////////////////////////
  //int multiply_result = 0; //set the result of the test 0 = pass, 1 = fail
  int divisor = 3;
  //Polynomial* poly4 = poly3;
  int divide_result = 0;
  printf("\nPolynomial Division Test\n");
  divide_polynomial(poly4, divisor);
  for(int i=0; i<6; i++) {
    printf("\n%gx^%i / %i = %gx^%i", poly4->Coefficient[i] * divisor, i,
                                      multiplicand, poly3->Coefficient[i], i);
    if (((poly4->Coefficient[i] / divisor) != (poly3->Coefficient[i])))
      divide_result = 1;
  }
  if(!divide_result) {
    printf("\n\nTest Passed!");
  } else {
    printf("\n\nTest Passed!");
  }
  printf("\n=======================================\n");

  printf("\n");


///////////////////////////////////////////////////////////
// test get_order()
////////////////////////////////////////////////////////////
//Expected result = 5
  int order = get_order(poly);

  printf("\nOrder of polynomial = 5");
  printf("\nresult of get_order() = %i", order);

  if(order == 5) {
    printf("\n\nTest Passed!");
  } else {
    printf("\n\nTest Failed!");
  }
  printf("\n=======================================\n");

  printf("\n");



///////////////////////////////////////////////////////////
// test normalise()
////////////////////////////////////////////////////////////
//Expected result =
// 4 + 3x + 6x^2 + 2x^3 + 7x^4 + x^5

printf("\nTest to normalise Polynomial");
print_polynomial(poly4, 1);
normalise(poly4);
printf("\n\nAfter Normalising:");
print_polynomial(poly4, 2);

if (poly4->Coefficient[0] == 4 &&
    poly4->Coefficient[1] == 3 &&
    poly4->Coefficient[2] == 6 &&
    poly4->Coefficient[3] == 2 &&
    poly4->Coefficient[4] == 7 &&
    poly4->Coefficient[5] == 1)
    {
      printf("\n\nTest Passed!");
    } else {
      printf("\n\nTest Failed!");
    }

printf("\n=======================================\n");
}
