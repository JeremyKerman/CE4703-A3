///////////////////////////////////////////////////////
// Main file for group assignment 3
// Polynomial function manipulator with user input
//
// Date: 22.11.2018
// Authors:  Dominik Przychodni - 17204658
//           Bryan McSweeney    - 17223962
//           Matas Mockus       - 17203813
//           Jeremy Pili        - 17216052
//           Eoghan McGrath     - 17220106
//
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
//
// paramaters: void
// returns: void
//////////////////////////////////////////////////////
void clrscr()
{
  system("clear");
}

///////////////////////////////////////////////////////
// void print_polynomial();
//
// prints a single polynomial to the screen
// including its position in the list.
//
// parameters: Polynomial *p , int node (position in list)
// returns:    void
//////////////////////////////////////////////////////////////
void print_polynomial(Polynomial *p, int node)
{
  // prints polynomials position in the list
  fprintf(stdout, "\nPolynomial [%d] =  ",node);
  fprintf(stdout, "%g", p->Coefficient[0]); // prints the first constant coefficient.

  for (int i = 1; i < p->Order; i++){  // loops through the polynomial
    if(p->Coefficient[i])
      fprintf(stdout, " + %gx^%d", p->Coefficient[i], i); // prints the coefficient and the power on the variable.
    }

  fprintf(stdout, "\n");  //newline
}

//////////////////////////////////////////////////////////////////////////////////
// void menu();
//
// Main menu for the program. Allows the user to make a selection on their action.
//
// parameters: llist *polyList (pointer to the current linked list of polynomials)
// returns:    void
/////////////////////////////////////////////////////////////////////////////////
void menu(llist *polyList)
{
  int option; // variable to store the user's selection

  fprintf(stdout, "\n\tWhat would you like to do?");
  fprintf(stdout, "\n\t[1] Make a new polynomial");
  fprintf(stdout, "\n\t[2] Delete a Polynomial");
  fprintf(stdout, "\n\t[3] Add polynomials");
  fprintf(stdout, "\n\t[4] Multiply a polynomial by a scalar"); // prints menu to stdout
  fprintf(stdout, "\n\t[5] Divide a polynomial by a scalar");
  fprintf(stdout, "\n\t[6] Normalise a polynomial");
  fprintf(stdout, "\n\t[7] Get the order of a polynomial");
  fprintf(stdout, "\n\t[8] Print all polynomials");
  fprintf(stdout, "\n\t[9] TEST EVERYTHING");
  fprintf(stdout, "\n\t[0] EXIT");
  fprintf(stdout, "\n\n\tSelection: ");

  scanf("%d", &option); // assign user input to 'option'
  clrscr(); // clears the screen

  // switch statement to run function chosen by user.
  switch(option) {
    case 1: menu_new_polynomial(polyList); break;
    case 2: menu_delete_polynomial(polyList); break;
    case 3: menu_add_polynomials(polyList); break;
    case 4: menu_multiply_polynomial(polyList); break;
    case 5: menu_divide_polynomial(polyList); break;
    case 6: menu_normalise_polynomial(polyList); break;
    case 7: menu_get_order(polyList); break;
    case 8: menu_print(polyList); break;
    case 9: poly_test();break;
    case 0: menu_exit(polyList); break;
    default: break;
  }
}

///////////////////////////////////////////////////////////////////
// void make_new_polynomial(llist *polylist);
//
// function call which allows the user to make a polynomial
// and set custom coefficients
//
// parameters: llist *polylist (pointer to the current linked list)
// returns:    void
///////////////////////////////////////////////////////////////////

void menu_new_polynomial(llist *polyList)
{
  // Clear the screen
  clrscr();
  // variable to store the chosen order
  int new_order;
  // print the instructions
  fprintf(stdout, "\n\tYou have chosen to make a new polynomial"); 
  fprintf(stdout, "\n\nPlease enter the order of the polynomial: ");
  
  scanf("%d", &new_order);  // assigns user input to 'new_order'

  Polynomial *p = make_polynomial(new_order);  // calls make_polynomial in Poly.c
                                               // to create the polynomial of the chosen order
                                               // and return a pointer
  fprintf(stdout, "\n");

  // requests coefficients from user for each power of 'x' until
  // chosen order is reached
  for(int i=0; i<= new_order; i++)
  {
    fprintf(stdout, "Enter coefficient of x^%i: ", i);
    scanf("%le", &p->Coefficient[i]);
  }

  // checks if the list has been created (just for debugging)
  if (polyList != NULL) {

    // calls insertAfter to insert the new polynomial to the list.
    while(polyList->current->after != NULL){
      polyList->current = polyList->current->after; // goes to last polynomial in list
    }
    if (insertAfter(p, polyList) == ok) // tries to insert the polynomial
      printf("\nadded polynomial to list\n"); //success
    else
      printf("\nInsuffient ressources, operation cancelled\n"); //failure
  }
  else {
	printf("list to store polynomials not created\n");  //just for debugging
  }

  //Go back to the menu
  menu(polyList);

}

/////////////////////////////////////////////////////////////
// void menu_delete_polynomial(llist *polyList);
//
// function to allow the user to delete a chosen polynomial
//
// parameters: llist *polyList (pointer to current list)
// returns:    void
//////////////////////////////////////////////////////////////
void menu_delete_polynomial(llist *polyList)
{
  // clear the screen
  clrscr();
  // variable to store which node to delete
  int toDelete;
  fprintf(stdout, "\n\tYou have chosen to delete a polynomial");
  if (polyList->head->after != NULL){ // checks if list is empty
    
    fprintf(stdout, "\n\nPlease choose a polynomial to delete: \n");
    print_all(polyList); // prints all polynomials
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &toDelete);  // assigns user selection to 'toDelete'
    polyList->current = polyList->head; //goes to start of list
    for(int i = 0; i<toDelete; i++){
      polyList->current = polyList->current->after;  //loops until 'toDelete' is reached
    }
    deleteCurrent(polyList); //deletes the selected node
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO DELETE\n\n");
  }


  //Go back to the menu
  menu(polyList);

}

//////////////////////////////////////////////////////////////////
// void add_polynomials(llist *polyList);
//
// function call which adds two polynomials and stores the
// sum as a new polynomial
//
// parameters: llist *polyList (pointer to the list od polynomials)
// returns:    void
///////////////////////////////////////////////////////////////////

void menu_add_polynomials(llist *polyList)
{
  // clears screen
  clrscr();
  
  int add1; // number in list of first polynomial
  int add2; // number in list of second ""
  Polynomial *p1; // pointer for 1st polynomial
  Polynomial *p2; // pointer for second polynomial

  fprintf(stdout, "\n\tYou have chosen to add two polynomials");
  // checks if list is empty
  if (polyList->head->after != NULL){
    
    fprintf(stdout, "\n\nPlease choose the first polynomial: \n");
    print_all(polyList); //prints all polynomials
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &add1); // gets number of first poly from user
    
    fprintf(stdout, "\n\nPlease choose the second polynomial: \n");
    print_all(polyList);
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &add2); // gets number of 2nd poly from user
    
    polyList->current = polyList->head;  // goes to head of list
    for(int i = 0; i<add1; i++){
      polyList->current = polyList->current->after;  // loops through list until 1st poly is reached
    }
    p1 = polyList->current->p; // stores pointer to first poly as 'p1'
    
    polyList->current = polyList->head; // goes back to head
    for(int i = 0; i<add2; i++){
      polyList->current = polyList->current->after;  //loops to find 2nd poly
    }
    p2 = polyList->current->p; // stores pointer to 2nd poly as 'p2'
    
    Polynomial *answer = add_polynomials(p1,p2);  // calls function to return a pointer to the sum of p1 and p2
    fprintf(stdout, "\n\n\tANSWER: %g", answer->Coefficient[0]); // prints first coefficient of the sum
    for (int i = 1; i < ((answer->Order)-1); i++){
      fprintf(stdout, " + %gx^%d", answer->Coefficient[i], i); // prints the other coefficients
    }
    fprintf(stdout, "\n\n");
    // asks user if they want to store the sum polynomial
    fprintf(stdout, "Would you like to add this new polynomial to the list? (Y/N): "); 
    char store; // variable to store the users choice
    scanf(" %c", &store); // gets choice
    if ((store == 'y') | (store == 'Y')){ // stores polynomial if user chose 'y'
      while(polyList->current->after != NULL){ 
	polyList->current = polyList->current->after; //moves to end of list
      }
      if (insertAfter(answer, polyList) == ok) // tries to insert the new polynomial
	printf("\nadded polynomial to list\n");  //success
      else
	printf("\nInsuffient ressources, operation cancelled\n");  //failure
    }
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO ADD\n\n");  // prints if list is empty
  }


  //Go back to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////////////////
// void menu_multiply_polynomial(llist *polylist)
//
// function call which multiplies a polynomial by a scalar
//
// parameters: llist *polyList (pointer to the list of polynomials)
// returns:    void
///////////////////////////////////////////////////////////////////
void menu_multiply_polynomial(llist *polyList)
{
  //clear the screen
  clrscr();

  int p1; // stores number of chosen polynomial
  double s; // stores the chosen scalar

  fprintf(stdout, "\n\tYou have chosen to multiply a polynomial by a scalar");
  if (polyList->head->after != NULL){ //checks if list is empty
    
    fprintf(stdout, "\n\nPlease choose the polynomial: \n");
    print_all(polyList); // prints all polynomials
    fprintf(stdout, "\n\tSelection: "); 
    scanf("%d", &p1); // stores number of user chosen poly

    fprintf(stdout, "\n\nPlease enter the scalar: ");
    scanf("%lf", &s); // stores user chosen scalar

    polyList->current = polyList->head; // goes to head of list
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after; // loops to find the chosen Polynomial
    }

    multiply_polynomial(polyList->current->p, s); // calls function to multiply it by the scalar 's'

    fprintf(stdout, "\n\n\tANSWER: %g", polyList->current->p->Coefficient[0]); //prints first coefficient
    for (int i = 1; i < (polyList->current->p->Order); i++){ 
      fprintf(stdout, " + %gx^%d", polyList->current->p->Coefficient[i], i); //prints the other coefficients
    }
    fprintf(stdout, "\n\n\tNew polynomial has been saved.\n\n"); // tells user it was saved
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO MULTIPLY\n\n");  //prints if list is empty
  }

  // returns to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void add_polynomials(llist *polylist);
//
// function call which divides a polynomial bt a scalar
//
// parameters: llist *polyList
// returns:    void
//////////////////////////////////////////////////////////////
void menu_divide_polynomial(llist *polyList)
{

//clear the screen
  clrscr();

  int p1; // stores number of chosen polynomial
  double s; // stores the chosen scalar

  fprintf(stdout, "\n\tYou have chosen to divide a polynomial by a scalar");
  if (polyList->head->after != NULL){//checks if list is empty
    
    fprintf(stdout, "\n\nPlease choose the polynomial: \n");
    print_all(polyList); // prints all polynomials
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &p1); // stores number of user chosen poly

    fprintf(stdout, "\n\nPlease enter the scalar: ");
    scanf("%lf", &s);  // stores user chosen scalar

    polyList->current = polyList->head; // goes to head of list
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after;  // loops to find user chosen poly
    }

    divide_polynomial(polyList->current->p, s); // calls function to divide the poly by scalar 's'

    fprintf(stdout, "\n\n\tANSWER: %g", polyList->current->p->Coefficient[0]); //prints first coefficient of answer
    for (int i = 1; i < (polyList->current->p->Order); i++){
      fprintf(stdout, " + %gx^%d", polyList->current->p->Coefficient[i], i); //prints the others
    }
    fprintf(stdout, "\n\n\tNew polynomial has been saved.\n\n"); 
  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO DIVIDE\n\n");
  }

  // returns to the menu
  menu(polyList);

}

///////////////////////////////////////////////////////
// void menu_normalise_polynomial(llist *polyList);
//
// function call which normalises a polynomial
//
// parameters: llist *polyList
// returns:    void
//////////////////////////////////////////////////////////////

void menu_normalise_polynomial(llist *polyList)
{
  //clear the screen
  clrscr();

  int p1;  // stores number in list of user chosen polynomial

  fprintf(stdout, "\n\tYou have chosen to normalise a polynomial");
  
  if (polyList->head->after != NULL){ // checks if list is empty  
    fprintf(stdout, "\n\nPlease choose the polynomial to normalise: \n");
    print_all(polyList);  //prints all polynomials
    
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &p1); // gets choice from user and stores in 'p1' 

    polyList->current = polyList->head; // goes to head of list
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after;  // loops to find chosen poly
    }

    if ( normalise(polyList->current->p) == 1){  // tries to mormalize polynomial

      fprintf(stdout, "\n\n\tNormalised polynomial: %g", polyList->current->p->Coefficient[0]); //prints normalised
      for (int i = 1; i < (polyList->current->p->Order); i++){                                  //poly if successfully
	fprintf(stdout, " + %gx^%d", polyList->current->p->Coefficient[i], i);                  //normalised
      }
      fprintf(stdout, "\n\n\tNew polynomial has been saved.\n\n");

    }
    else{
      fprintf(stdout, "\n\n\tPOLYNOMIAL COULD NOT BE NORMALISED.\n\n");   //prints if polynomial failed to be normalised
    }                                                                     // for debugging purposes

  }
  else {
    fprintf(stdout, "\n\n\tNO POLYNOMIALS AVAILABLE TO NORMALISE\n\n");
  }
  //Go back to the menu
  menu(polyList);

}

/////////////////////////////////////////////////////////////
// void menu_get_order(llist *polyList);
//
// function call which prints the order of a chosen polynomial
//
// parameters: llist *polyList
// returns:    void
//////////////////////////////////////////////////////////////
void menu_get_order(llist *polyList)
{
  //clear the screen
  clrscr();

  int p1;  // variable to store number in list of chosen polynomial
  int order; // variable to store the order of the chosen polynomial

  fprintf(stdout, "\n\tYou have chosen to get the order of a polynomial");
  
  if (polyList->head->after != NULL){ // checks if list is empty before proceeding
    fprintf(stdout, "\n\nPlease choose the polynomial to get the order of: \n");
    print_all(polyList); // prints all polynomials 
    fprintf(stdout, "\n\tSelection: ");
    scanf("%d", &p1); //stores user selection

    polyList->current = polyList->head; // goes to start of list
    for(int i = 0; i<p1; i++){
      polyList->current = polyList->current->after; //loops to find user chosen polynomial
    }

    order = (polyList->current->p->Order)-1; // gets correct order of polynomial
                                             // order is one bigger than true order
                                             // for convenience in other functions

    fprintf(stdout, "\n\n\tThis polynomial is of order: %d\n\n", order);  // prints order

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
// parameters: llist *polyList
// returns:    void
//////////////////////////////////////////////////////////////
void menu_print(llist *polyList)
{
  print_all(polyList); //prints all polynomials

  menu(polyList); //returns to menu

}

///////////////////////////////////////////////////////
// void print_all(llist *polyList);
//
// function to print all stored polynomials
//
// parameters: llist *polyList
// returns:    void
//////////////////////////////////////////////////////////////

void print_all(llist *polyList)
{
  if (polyList != NULL) { // checks if polyList has been created (debugging purposes)

    polyList->current = polyList->head->after; // moves to first node in list

    if (polyList->current == NULL){ // checks if list is empty
      fprintf(stdout,"\n\tNo Polynomials to show\n");
    }
    else{
      int i = 1; 
      do{
	print_polynomial(accessPoly(polyList),i); // calls print on the ith polynomial 
	                                          // which is retrieved by accessPoly();
	i++;  // increments i
	polyList->current = polyList->current->after; //moves to next node
      }while(polyList->current != NULL);   // loops until tail is reached

      polyList->current = polyList->head->after; //returns to start of list
    }
  }
  else {
	printf("list to store polynomials not created\n");  //just for debugging
  }

}

///////////////////////////////////////////////////////
// void menu_exit(llist *polyList);
//
// function to delete the list and close the program.
//
// parameters: llist *polyList
// returns:    void
//////////////////////////////////////////////////////////////

void menu_exit(llist *polyList)
{
  listDelete(polyList);   // calls listDelete to free the memory allocated to llist polyList
  fprintf(stdout,"\nGoodbye!\n\n");
  exit(0);  // exits program
}
