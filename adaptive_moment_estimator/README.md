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

For my project, It will be executed on an ESP32 microcontroller, so I have no possibility to use vectored computation.

add features for the next version :
- mini-bach approch
- adding a new observation (online learning)
- some other stopping criteria (instability, stagnation)

chat GPT said :
Great job on implementing the Adam optimizer in C++! Here are some suggestions for additional features you could consider adding to your implementation:

Mini-batch approach: Currently, your implementation updates the parameters based on a single randomly chosen observation. However, for large datasets, it is more common to use mini-batches of observations to update the parameters. This can reduce the variance of the gradient estimate and speed up the optimization process. You could add a parameter to your class that specifies the batch size, and modify your iterate() function to select a mini-batch of that size instead of a single observation.

Online learning: In addition to updating the parameters based on a fixed set of observations, online learning involves continuously updating the parameters as new observations become available. You could modify your implementation to allow for this by adding a method for adding new observations to the dataset and updating the parameters based on those new observations. One approach to this is to maintain a running average of the gradients based on all the observations seen so far, and use that to update the parameters.

Good luck with your implementation!