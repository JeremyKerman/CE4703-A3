///////////////////////////////////////////////////////
// Main file for group assignment 3
// Polynomial function manipulator with user input
//
// Date: 22.11.2018
// Authors: Dominik Przychodni - 17204658
//          Matas Mockus       - G4Y80Y
//          Eoghan McGrath     - 1DKL0L
//          Brian McSweeney    - WITHAY
//          Jeremy Pili        - WEARSFAKEGLASSES
///////////////////////////////////////////////////////

//include system headers
#include <stdlib.h>
#include <stdio.h>
//include custom headers
#include "Polynomials/Poly.h"

/////////////////////////////////////////////////////////
//  Main Function
//
//  provides an interface for the user to input values
//  and use the software functions
///////////////////////////////////////////////////////////
int main() {
  menu();
  return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
// function clrscr()
// Clears the screen
//////////////////////////////////////////////////////
void clrscr() {
  system("@cls||clear");
}

void menu() {
  int option;
  clrscr();
  fprintf(stdout, "\n\tWhat would you like to do?");
  fprintf(stdout, "\n\t[1] Make a new polynomial");
  fprintf(stdout, "\n\t[2] Delete a Polynomial");
  fprintf(stdout, "\n\t[3] Add polynomials");
  fprintf(stdout, "\n\t[4] Multiply a polynomial by a scalar");
  fprintf(stdout, "\n\t[5] Divide a polynomial by a scalar");
  fprintf(stdout, "\n\t[6] Get the order of a polynomial");
  fprintf(stdout, "\n\t[7] EXIT");
  fprintf(stdout, "\n\n\tSelection: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6: break;
    case 7: fprintf(stdout, "\n\tGoodbye.\n"); exit(0);
    default: break;
  }
}
