Gradient Descent class
==========================

This class is a gradient descent algorithm which can be used to find the vector x which minimizes a given function, f(x), where the domain is R^n->R (where n is the dimensionality of the vector x).

Public Members
--------------

The public members of the class include:

*   **`gradDescent()`** constructor which takes a pointer to a function and an initial value for the vector x, as well as the number of dimensions
*   **`set_stop_grad_norm()`** a method for setting the precision of the calculation
*   **`set_learning_rate()`** a method for setting the learning rate for the calculation
*   **`set_step_size()`** a method for setting the step size of the central difference, used in the derivative calculation
*   **`set_max_iterations()`** a method for specifying the maximum number of iterations of the algorithm
*   **`get_grad()`** a method for accessing the calculated gradient
*   **`get_x()`** a method for accessing the calculated vector x
*   **`get_f_x()`** a method for accessing the value of the function, f(x)
*   **`get_squared_gradient_norm()`** a method for accessing the squared norm of the gradient
*   **`get_iteration_count()`** a method for accessing the number of iterations performed during the calculation
*   **`get_num_dimensions()`** a method for accessing the dimensionality of the vector x
*   **`get_f_defined()`** a method for checking if the given function is well-defined
*   **`iterate()`** a method used to run the calculation

Private Members
---------------

The private members of the class include:

*   a pointer to the function
*   the initial value for the vector x
*   the reference for the function's arguments
*   the reference for the stop criterion (i.e. the accuracy of the result)
*   the reference for the learning rate for the calculation
*   the reference for the step size of the central difference, used in the derivative calculation
*   the reference for the maximum number of iterations
*   the dimensionality of the vector x
*   a boolean for checking if the given function is well-defined
*   temporary variables used in calculations