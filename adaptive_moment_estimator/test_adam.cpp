#include "adam_optimizer.h"
#include <iostream>

//linear regression test

//generate data
const unsigned int num_observations = 100;

double slope_estimate = 1;
double intercept_estimate = 0;
double noise_estimate = 0;

double *x= new double[3]{ slope_estimate, intercept_estimate,noise_estimate};


double points[num_observations][3];

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
    //(distance between the line and the point+distance between the distance and the std variation estimation) each squared
 double dist_error = x[0] * points[index_observation][0] + x[1] - points[index_observation][1];
 if (dist_error < 0)
     dist_error = -dist_error;
 double std_dev_error = x[2]-2*dist_error;
 if (std_dev_error < 0)
     std_dev_error = -std_dev_error;
 return std_dev_error*std_dev_error + dist_error*dist_error;
};


double gradient[3];
const double *analytic_grad(double *x,const unsigned int index_observation)
{
    //use this instead of the central difference
    //partial derivate of the distance between the line and the point squared 
    //by the slope and the intercept

    const double dist_error = (x[0] * points[index_observation][0] + x[1] - points[index_observation][1]);
    gradient[0] = 2 * dist_error * points[index_observation][0];
    gradient[1] = 2 * dist_error;
    gradient[2] = -2 * fabs(dist_error);
    //return gradient as const

    return (const double*)gradient;
};

const double step_size = 1e-6;
const double half_step_size = step_size / 2.0;
double x_i_save;
double grad_part;


const double *find_gradient(double *x,const unsigned int index_observation)
{
    // this methode will be called many times and fastly.
    // it have to be as fast as possible

    for (unsigned int i = 0; i < 3; i++)// calculate the gradient
    {   
        // The central difference : f'(x) = lim h->0 (f(x+h/2)-f(x-h/2))/h
        x_i_save = x[i];// save the value of x[i]
        x[i] = x_i_save+half_step_size;//x+h/2
        grad_part = f(x,index_observation);// f(x+h/2)
        x[i] = x_i_save-half_step_size;// x-h/2
        grad_part -= f(x,index_observation);// f(x+h/2)-f(x-h/2)
        x[i] = x_i_save;
        gradient[i] = grad_part / step_size;// f'(x)
    }
    return (const double*)gradient;
}


int main()
{   
    std::cout << "slope: " << x[0] << " intercept: " << x[1] <<"noise : "<< x[2]<< std::endl;
    // generate data
    generate_data(2.5, 1, 2);
    adamOptimizer sgd(find_gradient,x,3, num_observations);
    sgd.set_stop_criteria(1,2000);
    sgd.set_hyperparameters(0,0,1e-8,0.05);
    int status=1;
    while (status)
    { 
        status=sgd.iterate();  
        std::cout <<"status : "<<status<<" iteration : "<<sgd.get_iteration_count()<< " slope: " << sgd.get_x()[0] << " intercept: " << sgd.get_x()[1]<<" noise : "<<sgd.get_x()[2] << " grad : "<< sgd.get_grad()[0]<< " , "<< sgd.get_grad()[1]<<" , "<<sgd.get_grad()[2]<<std::endl;
    }

    return 0;
}