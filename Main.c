///////////////////////////////////////////////////////
// Main file for group assignment 3
// Polynomial function manipulator with user input
//
// Date: 22.11.2018
// Authors:  Dominik Przychodni - 17204658
//           Bryan McSweeney    - 17223962
//
// Useless fucks:
//          Matas Mockus       - G4Y80Y
//          Eoghan McGrath     - 1DKL0L
//          Jeremy Pili        - WEARSFAKEGLASSES
///////////////////////////////////////////////////////

//include system headers
#include <stdlib.h>
#include <stdio.h>
//include custom headers
#include "Main.h"
#include "Polynomials/Poly.h"
#include "Polynomials/PolyList.h"

/////////////////////////////////////////////////////////
//  Main Function
//
//  provides an interface for the user to input values
//  and use the software functions
///////////////////////////////////////////////////////////
int main()
{
  llist *polyList = listCreate();  //creates list to store the polynomials

  menu(polyList);
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

void menu(llist *polyList)
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
  fprintf(stdout, "\n\t[8] Print all polynomials");
  fprintf(stdout, "\n\t[9] EXIT");                            
  fprintf(stdout, "\n\n\tSelection: ");                       
  scanf("%d", &option);

  switch(option) {
    case 1: menu_new_polynomial(polyList); break;
    case 2: menu_delete_polynomial(polyList); break;
    case 3: menu_add_polynomials(polyList); break;
    case 4: menu_multiply_polynomial(polyList); break;
    case 5: menu_divide_polynomial(polyList); break;
    case 6: menu_normalise_polynomial(polyList); break;
    case 7: menu_get_order(polyList); break;
    case 8: menu_print(polyList); break;
    case 9: menu_exit(polyList); break;
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

void menu_new_polynomial(llist *polyList)
{
  //Clear the screen
  clrscr();
  int new_order;
  //print the instructions
  fprintf(stdout, "\n\tYou have chosen to make a new polynomial");
  fprintf(stdout, "\n\nPlease enter the order of the polynomial");
  scanf("%d", &new_order);

  Polynomial *p = make_polynomial(new_order);
  
  /////////////////////////////////////////////////////////////////////////////////
  //add code here to request the coefficients and set them (p->coefficient[0] = )
  /////////////////////////////////////////////////////////////////////////////////

  if (polyList != NULL) {

	// call insertAfter
	if (insertAfter(p, polyList) == ok)
	  printf("\nadded polynomial to list\n");
	else 
	  printf("\nInsuffient ressources, operation cancelled\n");
  }
  else {
	printf("list to store polynomials not created\n");  //just for debugging
  }

  //Go back to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void delete_polynomial();
//
// function call which deletes a given polynomial
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_delete_polynomial(llist *polyList)
{
  //clear the screen
  clrscr();

  /* PRINT THE POLYNOMIALS AVAILABLE*/
  /*DELETE THE CHOSEN POLYNOMIAL FROM THE HEAP*/

  //Go back to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void add_polynomials();
//
// function call which adds two polynomials and stores the
// sum as a new polynomial
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_add_polynomials(llist *polyList)
{
  //clear the screen
  clrscr();

  /* PRINT THE POLYNOMIALS AVAILABLE*/
  /*ALLOW THE USER TO CHOSE THE POLYNOMIALS THEY WANT TO ADD*/

  //Go back to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void menu_multiply_polynomial()
//
// function call which multiplies a polynomial by a scalar
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_multiply_polynomial(llist *polyList)
{
  //clear the screen
  clrscr();

  /* PRINT THE POLYNOMIALS AVAILABLE*/
  /*ALLOW THE USER TO CHOSE THE POLYNOMIAL AND
    SCALAR THEY WANT TO MULYIPLY BY*/

  //Go back to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void add_polynomials();
//
// function call which divides a polynomial bt a scalar
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_divide_polynomial(llist *polyList)
{
  //clear the screen
  clrscr();

  /* PRINT THE POLYNOMIALS AVAILABLE*/
  /*ALLOW THE USER TO CHOSE THE POLYNOMIAL AND
    SCALAR THEY WANT TO DIVIDE BY*/

  //Go back to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void menu_normalise_polynomial();
//
// function call which normalises a polynomial
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_normalise_polynomial(llist *polyList)
{
  //clear the screen
  clrscr();

  /* PRINT THE POLYNOMIALS AVAILABLE*/
  /*ALLOW THE USER TO CHOSE THE POLYNOMIAL THEY WANT TO NORMALISE*/

  //Go back to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void menu_get_order();
//
// function call which prints the order of a polynomial
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_get_order(llist *polyList);
{
  //clear the screen
  clrscr();

  /* PRINT THE POLYNOMIALS AVAILABLE*/
  /*ALLOW THE USER TO CHOSE THE POLYNOMIAL THEY WANT TO GET THE ORDER OF*/

  //Go back to the menu
  menu(polyList);

}



///////////////////////////////////////////////////////
// void menu_print();
//
// function to print all stored polynomials
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_print(llist *polyList);
{
  if (polyList != NULL) {

    polyList->current = polyList->head->after;
    
    if (polyList->current == NULL){
      fprintf(stdout,"\nNo Polynomials to show\n");
    }
    else{
      while(polyList->current != NULL){
	
	print_polynomial(accessPoly(polyList));
	gotoNextNode(polyList);
	
      }
    }
    
  }
  else {
	printf("list to store polynomials not created\n");  //just for debugging
  }

  menu(polyList);
}

///////////////////////////////////////////////////////
// void menu_exit();
//
// function to delete the list and close the program.
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_exit(llist *polyList);
{
  listDelete(polyList);
  fprintf(stdout,"\nGoodbye!\n")
  exit(0);
}
