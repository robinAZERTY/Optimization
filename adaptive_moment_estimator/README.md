Adam Optimizer
==============

Adam is an optimization algorithm that can be used instead of the classical stochastic gradient descent procedure to update network weights iterative based on training data.

Installation
------------

Simply include the `adam_optimizer.h` file in your project.

Usage
-----

Create an instance of the `AdamOptimizer` class and pass a pointer to a GradientDerivativeFunction which will be used to calculate the gradient, the start position `x`, the number of parameters and the number of observations. You also have access to some parameters you can tune for better results:

*   `Learning Rate`: The learning rate is used to adjust the weights of the network
*   `Beta1`: Exponential decay rate for the first moment estimates
*   `Beta2`: Exponential decay rate for the second-moment estimates
*   `Epsilon`: Small value used to avoid zero denominator

You can also set the maximum number of iterations this class will run before stopping.

Contributing
------------

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

License
-------

[MIT](https://choosealicense.com/licenses/mit/)