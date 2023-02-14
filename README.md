Optimization
============
find the best $\vec{v}$ wich minimize the cost function $f(\vec{v})$.

why ?
-----
Imagine you have a function that have to be configured with a lot of parameters. There is only one combination of parameters that will give you the best result. The problem is that you don't know what is the best combination of parameters. You can try a lot of combinations and see which one is the best. But it will take a lot of time. So you can use an optimization algorithm to find the best combination of parameters.

one real example
----------------
I buid theses libraries with one goal in mind. One of my projects is to build inertial navigation system (INS) with several sensors : accelerometers, gyroscopes, [...] and magnetometers. One part consist of calibrating the sensors.
For the magnetometers, we know the magnetic field vector is constant at a constant place. So we must be able to aquire mesurements of a vector wich have the same lenght at each time. In other words, no mater in what direction the sensor is pointing, the vector must have the same lenght. If we plot a lot of points constructed by x, y and z composants, we must have a sphere. 
However, the sensor is not perfect and they are distortions blamming the environment (electronics). For the X axis, the gain can be diferent to 1 and the offset can be deferent to 0. The effect is that the sphere is not centered on the origin and it is not a perfect sphere. It looks like a ellipsoid. But that's not it. X, Y and Z sensors are not perfectly orthogonal. The rotation matrix (3 by 3) quantify these disalignment. The ellispoid is turned.
Finaly, we have 3*2+3*3=15 parameters to find each time we want to calibrate the sensor. Good lock for find the best combination of parameters by hand. We can also use the least square method. But gradient descent is very interesting and polyvalent. It can be used for a lot of different problems.


3 types of optimization
-----------------------
1. Gradient descent
2. Stochastic gradient descent
3. Adaptive moment estimator


Gradient descent
----------------
The gradient descent is the most basic optimization algorithm.
The idea is to modify a composant of $\vec{v}$ one by one. For each modification, we seed how the cost function change. In fact, we buid the gradient of $f(\vec{v})$. Knowing it, we are able to slitly modify $\vec{v}$ in the opposit direction of the gradient and approch the minimum of the cost function.

Stochastic gradient descent
---------------------------
Stochastic gradient descent (SGD) is a variant of gradient descent that is commonly used for large datasets or when the computation of the full gradient is expensive. The idea of SGD is to randomly select a subset of the data (a mini-batch) and use this mini-batch to compute an estimate of the gradient of the cost function. This estimate is then used to update the parameters in the same way as in standard gradient descent. The process is repeated multiple times with different mini-batches until convergence.

Adaptive moment estimator
-------------------------
Adaptive moment estimation (Adam) is another variant of gradient descent that adapts the learning rate for each parameter based on estimates of the first and second moments of the gradient. The algorithm maintains a decaying average of past gradients and their squares, and uses these estimates to scale the learning rate for each parameter. Adam is generally considered to be more robust and efficient than standard gradient descent and its variants, especially in the presence of sparse gradients or noisy data.

How to use optimization algorithms
----------------------------------
To use optimization algorithms, you need to define a cost function that quantifies the performance of your system with respect to the parameters you want to optimize. This cost function can be based on any criteria that you care about, such as accuracy, speed, or cost. You also need to define the set of parameters you want to optimize (i.e., $\vec{v}$ in the example above).

Once you have defined the cost function and the set of parameters, you can choose an optimization algorithm that suits your problem and your computational resources. Gradient descent and its variants are relatively easy to implement and work well for many problems, but may require a lot of computational resources for large datasets. Adam is more efficient for many problems, but may require more tuning of the hyperparameters. There are many other optimization algorithms available, each with their own advantages and disadvantages.

In practice, you may need to experiment with different optimization algorithms, learning rates, and other hyperparameters to find the combination that works best for your problem. You can also use techniques like early stopping, regularization, and data augmentation to improve the performance of your system.