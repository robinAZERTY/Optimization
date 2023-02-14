#include "stochastic_gradient_descent.h"
#include <iostream>

stochasticGradDescent::stochasticGradDescent(const double *(grad_function)(const double *x, const unsigned int index_observation),double *x,const unsigned int &num_parameters, const double &num_observations)
{
    // store information from the constructor
    this->grad_function = grad_function;
    this->x = x;
    this->num_observations = num_observations;
    this->num_parameters = num_parameters;

    // set default values
    this->learning_rate = new double[num_parameters];
    for (unsigned int i = 0; i < num_parameters; i++)
        this->learning_rate[i] = 0.01;

    this->max_iterations = 100;
    this->iteration_count = 0;

    // create the temporary variables
    this->squared_gradient_norm = 0.0;
}

stochasticGradDescent::~stochasticGradDescent()
{
    delete [] learning_rate;
    delete [] grad;
}



const int stochasticGradDescent::iterate()
{
    index_observation = rand() % num_observations;// select a random observation
    grad=(double*)grad_function(this->x,index_observation);// calculate the gradient
    //update X
    squared_gradient_norm=0;// reset the gradient norm
    for(unsigned int i=0;i< num_parameters;i++)//update X (and calculate the gradient norm squared)
    {
        this->x[i]-=learning_rate[i]*grad[i];
        squared_gradient_norm += grad[i] * grad[i];// calculate the gradient norm (squared)
    }
    iteration_count++;//increase the iteration count
    if(iteration_count>=max_iterations) return 0;//stop if the maximum number of iterations is reached
    
    return 1;//continue
}