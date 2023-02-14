#include "adam_optimizer.h"
#include <iostream>
#include <cmath>

adamOptimizer::adamOptimizer(GradientDerivativeFunction gradient_function,double *x,const unsigned int &num_parameters, const double &num_observations)
{
    // set default values

    this->grad_function=gradient_function;
    this->x=x;
    this->num_parameters=num_parameters;
    this->num_observations=num_observations;
    this->learning_rate=learning_rate;
    // create the temporary variables
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
        x[i] = x[i] - learning_rate * m[i] / (1 - beta1) / (sqrt(v[i] / (1 - beta2)) + epsilon);
    }

    // increment the iteration_count
    iteration_count++;
    // check if the maximum number of iterations has been reached
    if (iteration_count >= max_iterations)
        return 0;

    return 1;
}