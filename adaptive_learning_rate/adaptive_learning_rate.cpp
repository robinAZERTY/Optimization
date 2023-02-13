/*
adam : Adaptive Moment Estimation
    Adam is an optimization algorithm that can be used instead of the classical stochastic gradient descent procedure to update network weights iterative based in training data.
    Adam is an extension to the SGD that calculates adaptive learning rates for each parameter. In addition to storing an exponentially decaying average of past squared gradients like Adadelta and RMSprop, Adam also keeps an exponentially decaying average of past gradients m_t, similar to momentum.
    Adam is a method that computes adaptive learning rates for each parameter. In addition to storing an exponentially decaying average of past squared gradients like Adadelta and RMSprop, Adam also keeps an exponentially decaying average of past gradients m_t, similar to momentum.
*/



#include "../gradient descent/as_class/gradient_descent.h"

class adaptive_learning_rate
{
    public :
        adaptive_learning_rate(gradDescent &gd, const double &initial_learning_rate);
        ~adaptive_learning_rate();
        double *get_learning_rate();

    private:

        gradDescent *gd;
        double *prev_grad;
        double *prev_x;
        double *learning_rate;
        bool first_iteration = true;
        double min_learning_rate = 1e-6;
        double max_learning_rate = 1e-1;
};

adaptive_learning_rate::adaptive_learning_rate(gradDescent &gd, const double &initial_learning_rate)
{
    this->gd = &gd;
    learning_rate = new double[this->gd->get_num_dimensions()];
    prev_grad = new double[this->gd->get_num_dimensions()];
    prev_x = new double[this->gd->get_num_dimensions()];

    for (unsigned int i=0; i<this->gd->get_num_dimensions(); i++)
    {
        learning_rate[i] = initial_learning_rate;
        prev_grad[i] = this->gd->get_grad()[i];
        prev_x[i] = this->gd->get_x()[i];
    }
    
}

adaptive_learning_rate::~adaptive_learning_rate()
{
    delete[] learning_rate;
}

double *adaptive_learning_rate::get_learning_rate()
{
    // compute the learning rate
    for(unsigned int i=0; i<gd->get_num_dimensions(); i++)
    {
        const double conc = (this->gd->get_x()[i]-prev_x[i])/(this->gd->get_grad()[i]-prev_grad[i]);
        if (conc < 1.0)
            learning_rate[i] *= 1.1;
        else if (conc > 1.0)
            learning_rate[i] *= 0.9;        
        
            

        prev_grad[i] = this->gd->get_grad()[i];
        prev_x[i] = this->gd->get_x()[i];
    }
    return learning_rate;
}