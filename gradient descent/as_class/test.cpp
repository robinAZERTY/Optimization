#include "gradient_descent.h"
#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

const double f1(const double *x)
{
    return x[0] * x[0] + x[1] * x[1];//simple quadratic function
}

const double f2(const double *x)
{
    return (x[0] - 2) * (x[0] - 2) + (x[1] + 3) * (x[1] + 3);
}

const double f3(const double *x)
{
    return x[0] * x[0] * x[0] + x[1] * x[1] * x[1];
}

const double f4(const double *x)
{
    return -cos(x[0]);
}

const double f5(const double *x)
{
    return -cos(x[0]) + 0.5*cos(x[1]*2);
}


const double Rosenbrock(const double *x)
{
    /*
    this function has a global minimum at (1,1)
    it is a non-convex function and has many local minima
    */
    return (1 - x[0]) * (1 - x[0]) + 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]);
}

const double Rastrigin(const double *x)
{   
    /*
    this function has a global minimum at (0,0) with a lot of local minima around it
    */
    const double n = 2;
    double sum = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        sum += x[i] * x[i] - 10 * cos(2 * PI * x[i]);
    }
    return 10 * n + sum;
}

const double Himmelblau(const double *x)
{
    return (x[0] * x[0] + x[1] - 11) * (x[0] * x[0] + x[1] - 11) + (x[0] + x[1] * x[1] - 7) * (x[0] + x[1] * x[1] - 7);
}


void test(gradDescent &gd, const double *X_expectation)
{   
    int status = 1;
    while (status==1)
    {
        status = gd.iterate();
    }
   std::cout << gd.get_iteration_count() << "\t|f(";
   for(unsigned int i = 0; i < gd.get_num_dimensions(); i++)
   {

        std::cout << gd.get_x()[i];
        if (i < gd.get_num_dimensions() - 1)
            std::cout << ",";
   }
    std::cout << ") = "<<gd.get_f_x()<<"\t|(";
    for (unsigned int i = 0; i < gd.get_num_dimensions(); i++)
    {
        std::cout << X_expectation[i]<<(i<gd.get_num_dimensions()-1?",":"");
    }
    std::cout << ")\t|";
    double quad_diff = 0;
    for (unsigned int i = 0; i < gd.get_num_dimensions(); i++)
    {
        quad_diff += (gd.get_x()[i] - X_expectation[i]) * (gd.get_x()[i] - X_expectation[i]);
    }
    if (quad_diff > 1e-6)
        //change color to red
        std::cout << "\033[1;31m";
    std::cout << quad_diff << std::endl;
    //reset color
    std::cout << "\033[0m";
}

int main()
{   
    std::cout << "iter\t|f(X)=y\t\t\t|X_expectation\t\t|quad_diff" << std::endl;
    gradDescent gd1(f1, new double[2]{ 1, 2 }, 2);
    test(gd1, new double[2]{ 0, 0 });
    gradDescent gd2(f2, new double[2]{ 3, -4 }, 2);
    test(gd2, new double[2]{ 2, -3 });
    gradDescent gd3(f3, new double[2]{ -1, 4 }, 2);
    test(gd3, new double[2]{ -1/0.0, -1/0.0 });
    gradDescent gd4(f4, new double[2]{ -0.4}, 1);
    test(gd4, new double[2]{ 0});
    gradDescent gd5(f5, new double[2]{ -0.4,0.1}, 2);
    test(gd5, new double[2]{ -0,PI/2});
    gradDescent gd6(Rosenbrock, new double[2]{ -1,-1 }, 2);
    test(gd6, new double[2]{ 1, 1});
    gradDescent gd7(Rastrigin, new double[2]{ -0.1,-0.2 }, 2);
    test(gd7, new double[2]{ 0, 0});
    gradDescent gd8(Himmelblau, new double[2]{0,0}, 2);//in this case, the adaptive learning rate is not working
    test(gd8, new double[2]{ 3, 2});
    return 0;
}