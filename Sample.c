  /*
  Test File Plz Ignore
*/

#include <stdlib.h>
#include <stdio.h>
#include "Polynomials/Poly.h"

int main() {
  Polynomial* poly = make_polynomial(5);
  poly->Coefficient_Array[0] = 5;

  printf("if this number -> %d <- is five it means it works!<\n", poly->Coefficient_Array[0]);
  return 0;
}
