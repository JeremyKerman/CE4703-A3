//////////////////////////////////////////////////
//
//  Header file for Polynomials module
//
//////////////////////////////////////////////////

//Include guard
#ifndef POLY_H
#define POLY_H

//Min and Max macros
#define MIN(a, b) ((a)<(b))?(a):(b)
#define MAX(a, b) ((a)>(b))?(a):(b)

//Custom data types

//Polynomial Data Type
//Used to store data on Polynomials
typedef struct {
  int Order; //Amount of coefficients
  double Coefficient[]; //Array for coefficients
} Polynomial;

//Declaring Functions in Poly.c
Polynomial* make_polynomial(int n);
void del_polynomial(Polynomial* p);
Polynomial* add_polynomials(Polynomial* p1, Polynomial* p2);
void multiply_polynomial(Polynomial* p, double d);
void divide_polynomial(Polynomial* p, double d);
int get_order(Polynomial* p);

//Declaring Functions in PolyList.c


//Include guard
#endif
