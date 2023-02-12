#ifndef GRADDESCENT_H
#define GRADDESCENT_H

class gradDescent
{
public:
    gradDescent(const double (*f)(const double *x), double *x0, const int &n);
    ~gradDescent();

    void setEps(const double &eps) { this->eps = eps; }
    void setLearningRate(const double &lambda) { this->alpha = 1/lambda; };
    void setStepSize(const double &step_size) { this->step_size = step_size; };
    void setAlphaRange(const double &min_alpha, const double &max_alpha)
    {
        this->min_alpha = min_alpha;
        this->max_alpha = max_alpha;
    };
    void enableAdaptiveRate() { enableAlphaUpdate = true; }// enable the update of alpha
    void disableAdaptiveRate() { enableAlphaUpdate = false; }// disable the update of alpha

    const double *getGrad() { return g;}
    const double *getX() { return x; }
    const double getMin() { return f(x);}
    const double getGradQuadNorm() { return gradQuadNorm;}
    const unsigned int getCount() { return count;}

    const unsigned int getN() {return n;}
    const int iterate();
    const bool isF_ok() {return f_ok;}
    

private:
    void updateAlpha();// update the learning rate alpha
    void calcGrad();// calculate the gradient and its norm

    // parameter or varialbles for gradient computation
    double *g, *g_prev;                 // gradient
    double gradQuadNorm;                // norm of the gradient
    double step_size = 1e-6;            // step_size for the finite difference method
    
    //parameter or variables for optimization
    unsigned int n;                     // number of variable (dimension)
    const double (*f)(const double *x); // function to minimize
    double *x, *x_prev;                 // vector of variable

    // parameter for control of the optimization
    double dx_max = 1e60;               // maximum step size (to avoid divergent)
    double eps = 1e-6;                  // stop condition (when the norm of the gradient is smaller than eps)
    bool enableAlphaUpdate = true;      // enable the update of alpha 
    double alpha = 1;                   // learning rate
    double min_alpha = 1e-10;            // minimum value for alpha
    double max_alpha = 1e10;             // maximum value for alpha
    unsigned int max_count = 1000;      // maximum number of iteration
    unsigned int count = 0;             // number of iteration
    bool f_ok = true;                   // flag to check if the function is divergent or invalid
   
    
};
#include "gradDescent.cpp"

#endif // GRADDESCENT_H