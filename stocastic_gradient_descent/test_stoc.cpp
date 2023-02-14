#include "stochastic_gradient_descent.h"
#include <iostream>

//linear regression test

//generate data
const unsigned int num_observations = 10;

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


double gradient[2];
const double *analytic_grad(const double *x,const unsigned int index_observation)
{
    //use this instead of the central difference
    //partial derivate of the distance between the line and the point squared 
    //by the slope and the intercept

    gradient[1] = 2 * (x[0] * points[index_observation][0] + x[1] - points[index_observation][1]);//intercept
    gradient[0]= gradient[1] * points[index_observation][0];//slope
    //return gradient as const

    //std::cout<<"gradient[0] : "<<gradient[0]<<" gradient[1] : "<<gradient[1]<<std::endl;
    return (const double*)gradient;
};


int main()
{   
    std::cout << "slope: " << x[0] << " intercept: " << x[1] << std::endl;
    // generate data
    generate_data(2.5, 1, 0);
    stochasticGradDescent sgd(analytic_grad,x,2, num_observations);
    sgd.set_max_iterations(20);
    sgd.set_learning_rate(new double[2]{1,0.3});
    while (sgd.iterate()==1)
    {
        std::cout << "slope: " << sgd.get_x()[0] << " intercept: " << sgd.get_x()[1] << " index_observation : "<< sgd.get_index_observation()<< " get_squared_gradient_norm : "<< sgd.get_squared_gradient_norm()<<std::endl;
    }
    return 0;
}