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
  int Coefficient_Array;   //Array for coefficients
} Polynomial;

// //Coefficients Data Type
// //Used to store coefficients of a polynomial
// typedef struct {
//   int No_of_coefficients; //Number of coefficients in the Polynomial
//   int* Values;    //Array for coefficients
// } Coefficients;

//Declaring Functions
Polynomial make_polynomial(int n);

#endif
