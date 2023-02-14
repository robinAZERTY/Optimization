#include "adam_optimizer.h"
#include <iostream>

//linear regression test

//generate data
const unsigned int num_observations = 100;

double slope_estimate = 1;
double intercept_estimate = 0;

double *x= new double[2]{ slope_estimate, intercept_estimate};


double points[num_observations][2];

void generate_data(const double slope, const double intercept, const double noise)
{   
    for (unsigned int i = 0; i < num_observations; i++)
    {
        points[i][0] = (double)i/(double)num_observations;
        points[i][1] = slope * points[i][0] + intercept + noise * (rand() / (double)RAND_MAX - 0.5);
    }
}


const double f(const double *x, const unsigned int index_observation)
{
    //distance between the line and the point squared
 return (x[0] * points[index_observation][0] + x[1] - points[index_observation][1]) * (x[0] * points[index_observation][0] + x[1] - points[index_observation][1]);
};


double gradient[2],gradient_prime[2];
const double *analytic_grad(const double *x,const unsigned int index_observation)
{
    //use this instead of the central difference
    //partial derivate of the distance between the line and the point squared 
    //by the slope and the intercept

    gradient[1] = 2 * (x[0] * points[index_observation][0] + x[1] - points[index_observation][1]);//intercept
    gradient[0] = gradient[1] * points[index_observation][0];//slope
    //return gradient as const

    return (const double*)gradient;
};


int main()
{   
    std::cout << "slope: " << x[0] << " intercept: " << x[1] << std::endl;
    // generate data
    generate_data(2.5, 1, 0.2);
    adamOptimizer sgd(analytic_grad,x,2, num_observations);
    sgd.set_max_iterations(50);
    sgd.set_hyperparameters(0.9,0.9999,1e-8,1e-1);
    while (sgd.iterate()==1)
    {   
        std::cout << "slope: " << sgd.get_x()[0] << " intercept: " << sgd.get_x()[1] << " grad : "<< sgd.get_grad()[0]<< " , "<< sgd.get_grad()[1]<<std::endl;
        //std::cout << "slope: " << sgd.get_x()[0] << " intercept: " << sgd.get_x()[1] << " index_observation : "<< sgd.get_index_observation()<< " get_squared_gradient_norm : "<< sgd.get_squared_gradient_norm()<<std::endl;
    }
    return 0;
}