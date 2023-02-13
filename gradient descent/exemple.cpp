/*
simple exemple of gradient descent

methode 1 : use the class
methode 2 : use the function

with the class you can iterate in a loop and stop when you want and do other stuff in the loop
with the function you can't do that, you have to wait until the function return
*/

#define USE_CLASS
//#define USE_FUNCTION

#include <stdio.h>

const double f(const double *x)// the function to minimize
{
    return x[0]*x[0]+x[1]*x[1];
}


#ifdef USE_CLASS

#include "as_class/gradient_descent.h"




int main()
{   
    // methode 1 : use the class
    double x[2] = { 1,1 };// initial guess
    gradDescent gd(f,x,2);// create the class
    while (gd.iterate() != 0);// iterate until the gradient norm is small enough (or error)
    printf("minimum found at (%f,%f) in %i iteration", x[0], x[1], gd.get_iteration_count());

    return 0;
}

#endif

#ifdef USE_FUNCTION
#include "as_functions/gradient_descent.cpp"

int main()
{
    // methode 2 : use the function
    double x[2] = { 1,1 };// initial guess
    const double *x_min = gradDescent(f, x, 2, 0.0001, 0.1);// find the minimum
    printf("minimum found at (%f,%f) in %i iteration", x_min[0], x_min[1], (int)x_min[2]);
    delete[] x_min;
    return 0;
}

#endif