#ifndef GRADDESCENT_H
#define GRADDESCENT_H


/*
this class is a gradient descent algorithm
It can be use to find the vector x that minimize a function f(x)
So the definition domain R^n->R (n is the dimension of the vector x)

author : robinAZERTY
date : 2023-02-13

*/
class gradDescent
{
public:
    gradDescent(const double (*f)(const double *x), double *x, const unsigned int &num_dimensions);
    ~gradDescent();

    // setters 
    void set_learning_rate(double *learning_rate) { this->learning_rate = learning_rate; }
    void set_learning_rate(const double &learning_rate) { for (unsigned int i=0; i<num_dimensions; i++) this->learning_rate[i] = learning_rate; }
    void set_stop_grad_norm(const double &stop_grad_norm) { this->stop_squared_grad_norm = stop_grad_norm*stop_grad_norm; }
    void set_step_size(const double &step_size) { this->step_size = step_size; this->half_step_size = step_size/2;}
    void set_max_iterations(const unsigned int &max_iterations) { this->max_iterations = max_iterations; }

    // accessors
    const double *get_grad() { return grad;}
    const double *get_x() { return x; }
    const double get_f_x() { return f(x);}
    const double get_squared_gradient_norm() { return squared_gradient_norm;}
    const unsigned int get_iteration_count() { return iteration_count;}
    const unsigned int get_num_dimensions() {return num_dimensions;}
    const double get_f_defined() {return f_defined;}

    // methods
   const int iterate();
    

private:

    int find_gradient();// calculate the gradient and its norm in same time

    // variables and parameters
    const double (*f)(const double *x);// function to minimize
    double *x;// //reference to a list of double (the variable to optimize)
    double *grad;// gradient of f
    double *learning_rate;// learning rate (can be different for each variable)


    // there are references
    double stop_squared_grad_norm;// precision
    double step_size;// step size of The central difference for derivative calculation
    double squared_gradient_norm;// squared norm of the gradient

    unsigned int iteration_count;// number of iteration
    unsigned int max_iterations;// maximum number of iteration
    unsigned int num_dimensions;// number of variable (dimension)

    bool f_defined;// true if the function is well defined

    // theses variables can be temporary used in methods but to avoid memory assignation, they are declared here, only once
    double grad_part;
    double x_i_save;
    double half_step_size;
};
#include "gradient_descent.cpp"

#endif // GRADDESCENT_H