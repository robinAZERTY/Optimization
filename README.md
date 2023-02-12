# Gradient Descent Algorithm for Function Minimization

This repository contains a gradient descent algorithm for function minimization implemented in C++. The algorithm is provided both as a class and a standalone function. The implementation also includes an example of how to use the gradient descent algorithm to minimize a simple test function.

## Class-based Implementation

The class-based implementation is located in the `as_class` directory. The class is defined in the file `GradientDescent.hpp` and implements the gradient descent algorithm as a class named `GradientDescent`.

The class has several methods for configuring and running the gradient descent algorithm. The advantage of using the class-based implementation is that the user can do other calculations while the gradient descent algorithm is running. The user can also access the results of the gradient descent algorithm at any time and modify the configuration during the calculation. (possibly to adapt the learning rate)


## Standalone Function

The standalone function is located in the `as_function` directory and is defined in the file `gradient_descent.cpp`. The function is named `gradDescent` and provides a simpler way to use the gradient descent algorithm. The function takes as arguments the function to minimize, the initial point, the number of variables, the stop condition, and the learning rate. The function returns the optimized point and the number of iterations required to reach the optimized point.

## Example

An example of how to use the gradient descent algorithm is provided in the file `exemple.cpp`. The example minimizes a simple test function. The example demonstrates how to use both the class-based implementation and the standalone function.
