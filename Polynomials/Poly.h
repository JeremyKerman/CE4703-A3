//////////////////////////////////////////////////
//
//  Header file for Polynomials module
//
//////////////////////////////////////////////////

//Include guard
#ifndef POLY_H
#define POLY_H

//Preprocessor macros


//Custom data types

//Polynomial Data Type
//Used to store data on Polynomials
typedef struct {
  int Order_of_polynomial; //Amount of coefficients
  int Coefficient_Array[]; //Array for coefficients
} Polynomial;

//Declaring Functions
Polynomial* make_polynomial(int n);

#endif
