#include "gradDescent.h"

gradDescent::gradDescent(const double (*f)(const double *x), double *x, const unsigned int &num_dimensions)
{
    // initialize the class

    this->f = f;
    this->x = x;
    this->num_dimensions = num_dimensions;
    grad = new double[num_dimensions];// allocate memory for the gradient

    // default parameters
    stop_squared_grad_norm = 1e-6;
    learning_rate = 0.7;
    step_size = 1e-6;
    max_iterations = 1000;
    iteration_count = 0;

    step_size = 1e-6;
    half_step_size = step_size/2;

    //verify if the function is well defined
    f_defined = !(f(x) != f(x))*!(f(x)==1.0/0.0)*!(f(x)==-1.0/0.0); // if f(x) is nan, inf or -inf, f_defined is false
    }

gradDescent::~gradDescent()
{
    delete[] grad;
}


int gradDescent::find_gradient()
{
    // this methode will be called many times and fastly.
    // it have to be as fast as possible

    squared_gradient_norm=0;// reset the gradient norm
    for (unsigned int i = 0; i < num_dimensions; i++)// calculate the gradient
    {   
        // finite difference : f'(x) = lim h->0 (f(x+h/2)-f(x-h/2))/h
        x_i_save = x[i];// save the value of x[i]
        x[i] = x_i_save+half_step_size;//x+h/2
        this->grad_part = f(x);// f(x+h/2)
        x[i] = x_i_save-half_step_size;// x-h/2
        this->grad_part -= f(x);// f(x+h/2)-f(x-h/2)
        x[i] = x_i_save;
        grad[i] = this->grad_part / step_size;// f'(x)
        squared_gradient_norm += grad[i] * grad[i];// calculate the gradient norm (squared)
    }
    return 0;
}


const int gradDescent::iterate()
{
    
    find_gradient();

    if (squared_gradient_norm < stop_squared_grad_norm || iteration_count>=max_iterations)// if the gradient norm is small enough, stop
        return 0;

    for (unsigned int i = 0; i < num_dimensions; i++)// update the variable
        x[i] -= learning_rate * grad[i];// x = x - learning_rate * grad
    
    iteration_count++;    
    return 1;
}