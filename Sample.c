  /*
  Test File Plz Ignore
*/

#include <stdlib.h>
#include <stdio.h>
#include "Polynomials/Poly.h"

int main() {
  Polynomial* poly = make_polynomial(5);
  Polynomial* poly2 = make_polynomial(9);
  Polynomial* poly3;
  poly->Coefficient[0] = 5;
  poly2->Coefficient[6] = 9;
  poly3 = add_polynomials(poly,poly2);

  printf("if this number -> %g <- is five it means it works!<\n", poly->Coefficient[0]);
  printf("if this number -> %g <- is 9 it means it works!<\n", poly2->Coefficient[0]);
  divide_polynomial(poly3, 3);
  printf("if this number -> %g <- is 3 it means it works!<\n", poly3->Coefficient[6]);
  printf("if this number -> %i <- is 6 it means it works!<\n", get_order(poly2));
  return 0;
}
