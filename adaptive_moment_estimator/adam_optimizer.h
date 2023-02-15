/*
adam : adaptive moment estimation
Adam is an optimization algorithm that can be used instead of the classical stochastic gradient descent procedure to update network weights iterative based in training data.
Adam is an extension to the stochastic gradient descent method that calculates adaptive learning rates for each parameter. In addition to storing an exponentially decaying average of past squared gradients like Adadelta and RMSprop, Adam also keeps an exponentially decaying average of past gradients m_t, similar to momentum.

parameters :
- beta1 : exponential decay rate for the first moment estimates
- beta2 : exponential decay rate for the second-moment estimates
- epsilon : small value to avoid zero denominator

*/
#ifndef ADAM_OPTIMIZER_H
#define ADAM_OPTIMIZER_H

//definition of function type to be clear
//pointer to a function that return a const double * and take a const double * and a const unsigned int as input
typedef const double *(GradientDerivativeFunction)(double *x, const unsigned int index_observation);

class adamOptimizer
{
public:
    adamOptimizer(GradientDerivativeFunction gradient_function,double *x,const unsigned int &num_parameters, const double &num_observations);
    ~adamOptimizer();
    // setters
    void set_beta1(const double &beta1) { this->beta1 = beta1; }
    void set_beta2(const double &beta2) { this->beta2 = beta2; }
    void set_epsilon(const double &epsilon) { this->epsilon = epsilon; }
    void set_learning_rate(const double &learning_rate) {this->learning_rate = learning_rate; }
    void set_hyperparameters(const double &beta1,const double &beta2,const double &epsilon,const double &learning_rate)
    {
        this->beta1=beta1;
        this->beta2=beta2;
        this->epsilon=epsilon;
        this->learning_rate=learning_rate;
    }
    void set_max_iterations(const unsigned int &max_iterations) { this->max_iterations = max_iterations; }
    void set_max_absolute_variation(const double &max_absolute_variation) { this->max_absolute_variation = max_absolute_variation; }
    void set_stop_criteria(const double &max_absolute_variation, const unsigned int &max_iterations)
    {
        this->max_absolute_variation = max_absolute_variation;
        this->max_iterations = max_iterations;
    }
    // getters
    const double *get_x() const { return this->x; }
    const unsigned int get_iteration_count() const { return this->iteration_count; }
    const unsigned int get_index_observation(){return this->index_observation;}// return the index of the observation
    const double *get_grad(){return this->grad;}// return the gradient
    // methods
    const int iterate();//use middle finite difference to compute de gradient
private:
    // variables and parameters
    double *x;// parameters
    double *grad;// gradient
   
    unsigned int num_parameters;// number of parameters
    unsigned int num_observations;// number of observations
    unsigned int index_observation;// index of the observation
    unsigned int iteration_count;// iteration count
    unsigned int max_iterations;// maximum number of iterations
    GradientDerivativeFunction *grad_function;// pointer to the gradient function

    double *m; // first moment vector
    double *v; // second moment vector
    //hyperparameters
    double learning_rate=0.001;// learning rate
    double beta1=0.9; // exponential decay rate for the first moment estimates
    double beta2=0.99; // exponential decay rate for the second-moment estimates
    double epsilon=1e-8; // small value to avoid zero denominator

    //stopping criteria
    double max_absolute_variation=0.5;// maximum absolute variation of x_i between two consecutive iterations
    //double m_hat;
    //double v_hat;
    double last_x_i;
};
#include "adam_optimizer.cpp"
#endif // ADAM_OPTIMIZER_H