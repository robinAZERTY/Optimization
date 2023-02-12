#include "gradDescent.h"

gradDescent::gradDescent(const double (*f)(const double *x), double *x0, const int &n)
{
    this->f = f;
    this->n = n;
    this->x = new double[n];
    this->g = new double[n];
    this->x_prev = new double[n];
    this->g_prev = new double[n];
    for (unsigned int i = 0; i < n; i++)
    {
        this->x[i] = x0[i];
    }

    //test if the function works
    if(f(x) == 1.0/0.0 || f(x) == -1.0/0.0 || f(x) != f(x))
        f_ok = false;
}

gradDescent::~gradDescent()
{
    delete[] x;
    delete[] g;
    delete[] x_prev;
    delete[] g_prev;
}

void gradDescent::calcGrad()
{   // calculate the gradient and its norm
    // the gradient of a function f is a vector of partial derivatives
    // f is the function to minimize
    // n is the number of variable (dimension)
    // x is the vector of variable

    // opptimization: use the finite difference method to calculate the partial derivatives
    // 

    gradQuadNorm = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        // change the i-th variable
        x[i] += step_size / 2.0;
        const double f1 = f(x);
        x[i] -= step_size;
        const double f2 = f(x);
        x[i] += step_size / 2.0;
        const double diff = f1 - f2;
        g[i] = diff / step_size; // calculate the partial derivative as the limit of (f(x-h) - f(x+h))/2h
        gradQuadNorm += g[i] * g[i];
    }
}
void gradDescent::updateAlpha()
{
    // update the learning rate (step size) alpha
    // alpha is the step size that minimizes the quadratic approximation of the function
    // f is the function to minimize
    // n is the number of variable (dimension)
    // x is the vector of variable
    // g is the gradient
    // x_prev is the vector of variable at the previous iteration
    // g_prev is the gradient at the previous iteration

    double alpha_num = 0;
    double alpha_den = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        alpha_num += (x[i] - x_prev[i]) * (g[i] - g_prev[i]);
        alpha_den += (x[i] - x_prev[i]) * (x[i] - x_prev[i]);
        x_prev[i] = x[i];
        g_prev[i] = g[i];
    }
    alpha = alpha_num / alpha_den;

    if (alpha < min_alpha)
        alpha = min_alpha;
    else if (alpha > max_alpha|| alpha != alpha)
        alpha = max_alpha;
       
}


const int gradDescent::iterate()
{
    if (count >= max_count)
        return 0;// stop (maximum number of iteration reached)
    else if (f_ok == false)
        return -1;// stop with error (the function is not defined

    // calculate the gradient and its norm
    calcGrad();

    // check if the gradient is small enough
    if (gradQuadNorm < eps*eps)
        return 0;// stop

    if(enableAlphaUpdate) 
        updateAlpha();
        
        
    // update the variable
    for (unsigned int i = 0; i < n; i++)
    {   
        const double dx = -g[i]/alpha;
        if (dx*dx > dx_max)
        {
            // the i-th variable is divergent 
            x[i] = (x[i]<0) ? -1.0/0.0 : 1.0/0.0;
            return -2;// stop with error (the i-th variable is divergent)
        }
        x[i] += dx;
    }
    count++;
    return 1;// continue
}