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
  llist *polyList = listCreate();//creates list to store the polynomials
  polyList->nodes = 0; //initializes the nodes in the list to 0

  //clear the screen from compilation messages
  clrscr();
  //go to the menu
  menu(polyList);
  return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////
// function clrscr()
// Clears the screen
//////////////////////////////////////////////////////
void clrscr()
{
  system("clear");
}

void print_polynomial(Polynomial *p, int node)
{

  fprintf(stdout, "\n\tPolynomial %d =  ",node);
  fprintf(stdout, "%g", p->Coefficient[0]);
    for (int i = 1; i < p->Order; i++){
      if(p->Coefficient[i])
        fprintf(stdout, " + %gx^%d", p->Coefficient[i], i);
    }
    fprintf(stdout, "\n\n");
}

///////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////

void menu(llist *polyList)
{
  int option;
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
  clrscr();

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
  fprintf(stdout, "\n\nPlease enter the order of the polynomial: ");
  scanf("%d", &new_order);

  Polynomial *p = make_polynomial(new_order);

  fprintf(stdout, "\n");
  for(int i=0; i<= new_order; i++)
  {
    fprintf(stdout, "Enter coefficient of x^%i: ", i);
    scanf("%le", &p->Coefficient[i]);
  }

  if (polyList != NULL) {

	// call insertAfter
    polyList->current = polyList->head;
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
  int toDelete;
  fprintf(stdout, "\n\tYou have chosen to delete a polynomial");
  if (polyList->head->after != NULL){
    fprintf(stdout, "\n\nPlease choose a polynomial to delete: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &toDelete);
    polyList->current = polyList->head;
    for(int i = 0; i<toDelete; i++){
      polyList->current = polyList->current->after;
    }
    deleteCurrent(polyList);
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO DELETE\n\n");
  }


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
  clrscr();
  int add1;
  int add2;
  Polynomial *p1;
  Polynomial *p2;

  fprintf(stdout, "\n\tYou have chosen to add two polynomials");
  if (polyList->head->after != NULL){
    fprintf(stdout, "\n\nPlease choose the first polynomial: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &add1);
    fprintf(stdout, "\n\nPlease choose the second polynomial: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &add2);
    polyList->current = polyList->head;
    for(int i = 0; i<add1; i++){
      polyList->current = polyList->current->after;
    }
    p1 = polyList->current->p;
    polyList->current = polyList->head;
    for(int i = 0; i<add2; i++){
      polyList->current = polyList->current->after;
    }
    p2 = polyList->current->p;
    Polynomial *answer = add_polynomials(p1,p2);
    fprintf(stdout, "\n\n\tANSWER: %g", answer->Coefficient[0]);
    for (int i = 1; i < ((answer->Order)-1); i++){
      fprintf(stdout, " + %gx^%d", answer->Coefficient[i], i);
    }
    fprintf(stdout, "\n\n");
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO ADD\n\n");
  }


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

  int p1;
  double s;

  fprintf(stdout, "\n\tYou have chosen to multiply a polynomial by a scalar");
  if (polyList->head->after != NULL){
    fprintf(stdout, "\n\nPlease choose the polynomial: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &p1);

    fprintf(stdout, "\n\nPlease enter the scalar: ");
    scanf("%lf", &s);

    polyList->current = polyList->head;
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after;
    }

    multiply_polynomial(polyList->current->p, s);

    fprintf(stdout, "\n\n\tANSWER: %g", polyList->current->p->Coefficient[0]);
    for (int i = 1; i < (polyList->current->p->Order); i++){
      fprintf(stdout, " + %gx^%d", polyList->current->p->Coefficient[i], i);
    }
    fprintf(stdout, "\n\n\tNew polynomial has been saved.\n\n");
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO MULTIPLY\n\n");
  }

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

  int p1;
  double s;

  fprintf(stdout, "\n\tYou have chosen to divide a polynomial by a scalar");
  if (polyList->head->after != NULL){
    fprintf(stdout, "\n\nPlease choose the polynomial: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &p1);

    fprintf(stdout, "\n\nPlease enter the scalar: ");
    scanf("%lf", &s);

    polyList->current = polyList->head;
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after;
    }

    divide_polynomial(polyList->current->p, s);

    fprintf(stdout, "\n\n\tANSWER: %g", polyList->current->p->Coefficient[0]);
    for (int i = 1; i < (polyList->current->p->Order); i++){
      fprintf(stdout, " + %gx^%d", polyList->current->p->Coefficient[i], i);
    }
    fprintf(stdout, "\n\n\tNew polynomial has been saved.\n\n");
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO DIVIDE\n\n");
  }

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

  int p1;

  fprintf(stdout, "\n\tYou have chosen to normalise a polynomial");
  if (polyList->head->after != NULL){
    fprintf(stdout, "\n\nPlease choose the polynomial to normalise: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &p1);

    polyList->current = polyList->head;
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after;
    }

    if ( normalise(polyList->current->p) == 1){

      fprintf(stdout, "\n\n\tNormalised polynomial: %g", polyList->current->p->Coefficient[0]);
      for (int i = 1; i < (polyList->current->p->Order); i++){
	fprintf(stdout, " + %gx^%d", polyList->current->p->Coefficient[i], i);
      }
      fprintf(stdout, "\n\n\tNew polynomial has been saved.\n\n");

    }
    else{
      fprintf(stdout, "\n\n\tPOLYNOMIAL COULD NOT BE NORMALISED.\n\n");
    }

  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO NORMALISE\n\n");
  }
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

void menu_get_order(llist *polyList)
{
  //clear the screen
  clrscr();

  int p1;
  int order;

  fprintf(stdout, "\n\tYou have chosen to get the order of a polynomial");
  if (polyList->head->after != NULL){
    fprintf(stdout, "\n\nPlease choose the polynomial to get the order of: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &p1);

    polyList->current = polyList->head;
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after;
    }

    order = (polyList->current->p->Order)-1;

    fprintf(stdout, "\n\n\tThis polynomial is of order: %d\n\n", order);

  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE\n\n");
  }
  //Go back to the menu
  menu(polyList);

}



///////////////////////////////////////////////////////
// void menu_print(llist polyList);
//
// function to print all stored polynomials and return to menu
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////
void menu_print(llist *polyList)
{
  print_all(polyList);

  menu(polyList);

}

///////////////////////////////////////////////////////
// void print_all(llist polyList);
//
// function to print all stored polynomials
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void print_all(llist *polyList)
{
  if (polyList != NULL) {

    polyList->current = polyList->head->after;

    if (polyList->current == NULL){
      fprintf(stdout,"\n\tNo Polynomials to show\n");
    }
    else{
      int i = 1;
      do{
	print_polynomial(accessPoly(polyList),i);
	i++;
	polyList->current = polyList->current->after;//   <----- fix this to use
      }while(polyList->current != NULL);             //           gotoNextNode()
      polyList->current = polyList->head->after;
    }
  }
  else {
	printf("list to store polynomials not created\n");  //just for debugging
  }

}

///////////////////////////////////////////////////////
// void menu_exit();
//
// function to delete the list and close the program.
//
// parameters: void
// returns:    void
//////////////////////////////////////////////////////////////

void menu_exit(llist *polyList)
{
  listDelete(polyList);
  fprintf(stdout,"\nGoodbye!\n\n");
  exit(0);
}
