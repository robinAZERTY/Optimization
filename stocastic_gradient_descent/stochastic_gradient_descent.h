#ifndef STOCHASTIC_GRADIENT_DESCENT_H
#define STOCHASTIC_GRADIENT_DESCENT_H
/*
same thing of gradient descent but with stochastic approach
the function to minimize is like this : f(x) = sum_i f_i(x)
where f_i is a function of x
x is a vector of parameters to optimize

adventage :
- faster than gradient descent
- less memory needed
- can be used for big data
- can be used for online learning (when the data is generated in real time)


we have to store all f_i(x) in a list (or ptr) like this :
const double (**f)(const double *x) we say that f_i is an observer of f and we can access to f_i(x) with f[i](x)
*/


class stochasticGradDescent
{
public:
    stochasticGradDescent(const double *(grad_function)(const double *x, const unsigned int index_observation),double *x,const unsigned int &num_parameters, const double &num_observations);
    ~stochasticGradDescent();

    // setters
    void set_learning_rate(double *learning_rate) { this->learning_rate = learning_rate; }
    void set_learning_rate(const double &learning_rate)
    {
        for (unsigned int i = 0; i < num_parameters; i++)
            this->learning_rate[i] = learning_rate;
    }

    void set_max_iterations(const unsigned int &max_iterations) { this->max_iterations = max_iterations; }

    // accessors
    const double *get_x() { return x; }
    const double get_squared_gradient_norm() { return squared_gradient_norm; }
    const unsigned int get_iteration_count() { return iteration_count; }
    const unsigned int get_index_observation() { return index_observation; }//get the index of the current observation (there are randomly selected during the iterations)

    // methods
    const int iterate();//use middle finite difference to compute de gradient



protected:

    // variables and parameters
    const double *(*grad_function)(const double *x,const unsigned int index_observation); // gradient of f_i 
    double *x;                            // //reference to a list of double (the variable to optimize)
    double *grad;                         // gradient of f_i
    double *learning_rate;                // learning rate (can be different for each variable)

    // there are references
    double squared_gradient_norm;  // squared norm of the gradient

    unsigned int iteration_count;  // number of iteration
    unsigned int max_iterations;   // maximum number of iteration
    unsigned int num_parameters;   // number of variable (parameter)
    unsigned int num_observations; // number of observations to minimize
    unsigned int index_observation;// index of the current observation
};
#include "stochastic_gradient_descent.cpp"

#endif//STOCHASTIC_GRADIENT_DESCENT_H