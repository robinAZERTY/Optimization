#include "adam_optimizer.h"
#include <iostream>
#include <cmath>

adamOptimizer::adamOptimizer(GradientDerivativeFunction gradient_function,double *x,const unsigned int &num_parameters, const double &num_observations)
{
    // set default values
    std::cout << "adamOptimizer constructor" << std::endl;

    this->grad_function=gradient_function;// set the gradient function pointer
    this->x=x;// set the parameters pointer
    this->num_parameters=num_parameters;// set the number of parameters
    this->num_observations=num_observations;// set the number of observations
    // initialise variables
    this->m = new double[num_parameters];
    this->v = new double[num_parameters];
    for (unsigned int i = 0; i < num_parameters; i++)
    {
        this->m[i] = 0.0;
        this->v[i] = 0.0;
    }

}

adamOptimizer::~adamOptimizer()
{
    delete [] m;
    delete [] v;
}


const int adamOptimizer::iterate()
{
    index_observation = rand() % num_observations;// select a random observation
    grad=(double*)grad_function(this->x,index_observation);// calculate the gradient
    //update X
    for (unsigned int i = 0; i < num_parameters; i++)
    {
        //update the moving averages of the gradient
        m[i] = beta1 * m[i] + (1 - beta1) * grad[i];
        //update the moving averages of the squared gradient
        v[i] = beta2 * v[i] + (1 - beta2) * grad[i]*grad[i];
        //update the bias-corrected estimates
        //this->m_hat = m[i] / (1 - beta1);
        //this->v_hat = v[i] / (1 - beta2);
        //update the parameters
        last_x_i = x[i];// store the last value of x_i for the stopping criteria
        x[i] = x[i] - learning_rate * m[i] / (1 - beta1) / (sqrt(v[i] / (1 - beta2)) + epsilon);// update the parameters
        
        if (fabs(x[i] - last_x_i)>max_absolute_variation)// check if the relative variation is too large
            return -1;// return -1 if the relative variation is too large
    }

    // increment the iteration_count
    this->iteration_count++;
    // check if the maximum number of iterations has been reached
    if (iteration_count >= max_iterations)
        return 0;// return 0 if the maximum number of iterations has been reached

    return 1;
}