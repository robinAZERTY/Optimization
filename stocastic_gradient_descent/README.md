Stochastic Gradient Descent
===========================

A basic implementation of the stochastic gradient descent algorithm.

What is Stochastic Gradient Descent?
------------------------------------

Stochastic gradient descent (SGD) is an iterative optimization algorithm used to minimize a given function. It is a type of gradient descent which uses randomly selected data points to compute the gradient. This results in faster convergence, as it reduces computation time, making it suitable for use on large datasets, or when dealing with data that is generated in real-time.

Usage
-----

### Initialization

The class is initialized by passing a pointer to an objective function, a pointer to an array of variables to optimize, the number of parameters, and the total number of observations.

```cpp
stochasticGradDescent(const double *(grad_function)(const double *x, const unsigned int index_observation),double *x,const unsigned int &num_parameters, const double &num_observations);
```

### Setting the Learning Rate

The learning rate can be set for all parameters at once or separately.

```cpp
void set_learning_rate(double *learning_rate);

void set_learning_rate(const double &learning_rate);
```

### Set Maximum Iterations

The maximum number of iterations that should be run can be set.

```cpp
void set_max_iterations(const unsigned int &max_iterations);
```

### Iterating

Once everything is initialized, the `iterate()` function can be called to start the optimization. The function will return an `int` indicating the result of the optimization process: 0 indicates successful optimization, and non-zero values indicate an error occured during optimization.

```cpp
const int iterate();
```

Once the optimization process is finished, the optimized variables and other important parameters can be accessed using the accessor functions.

```cpp
// accessors
const double *get_x() { return x; }
const double get_squared_gradient_norm() { return squared_gradient_norm; }
const unsigned int get_iteration_count() { return iteration_count; }
const unsigned int get_index_observation() { return index_observation; }//get the index of the current observation (there are randomly selected during the iterations)
```