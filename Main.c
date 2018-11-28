///////////////////////////////////////////////////////
// Main file for group assignment 3
// Polynomial function manipulator with user input
//
// Date: 22.11.2018
// Author:  Dominik Przychodni - 17204658
//
// Useless fucks:
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
int main()
{

  menu();
  return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
// function clrscr()
// Clears the screen
//////////////////////////////////////////////////////
void clrscr()
{
  system("@cls||clear");
}

void print_polynomial(Polynomial* p)
{
  int order = get_order(p);

  fprintf(stdout, "\nPolynomial = ");
  if(p->Coefficient[0])
    fprintf(stdout, "%g + ", p->Coefficient[0]);

  for(int i=1; i<order; i++) {
    if(p->Coefficient[i])
      fprintf(stdout, "%gx^%i + ", p->Coefficient[i], i);
  }
  if(p->Coefficient[order]) {
    fprintf(stdout, "%gx^%i\n", p->Coefficient[order], order);
  } else {
    fprintf(stdout, "\n");
  }
}

void menu()
{
  Polynomial* po = make_polynomial(6);
  po->Coefficient[1] = 2;
  po->Coefficient[3] = 6;
  po->Coefficient[6] = 3;
  po->Coefficient[3] = 12;
  int option;
  clrscr();
  fprintf(stdout, "\n\tWhat would you like to do?");
  fprintf(stdout, "\n\t[1] Make a new polynomial");
  fprintf(stdout, "\n\t[2] Delete a Polynomial");
  fprintf(stdout, "\n\t[3] Add polynomials");
  fprintf(stdout, "\n\t[4] Multiply a polynomial by a scalar");
  fprintf(stdout, "\n\t[5] Divide a polynomial by a scalar");
  fprintf(stdout, "\n\t[6] Normalise a polynomial");
  fprintf(stdout, "\n\t[7] Get the order of a polynomial");
  fprintf(stdout, "\n\t[8] EXIT");
  fprintf(stdout, "\n\n\tSelection: ");
  scanf("%d", &option);

  switch(option) {
    case 1: normalise(po);print_polynomial(po);
    case 2:
    case 3:
    case 4:
    case 5:
    case 6: break;
    case 7: fprintf(stdout, "\n\tGoodbye.\n"); exit(0);
    default: break;
  }
}

///////////////////////////////////////////////////////
// void make_new_polynomial();
//
// function call which allows the user to make a polynomial
// and set custom coefficients
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void make_new_polynomial()
{

}
