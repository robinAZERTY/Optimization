Optimization
============
find the best $\vec{v}$ wich minimize the cost function $f(\vec{v})$.

3 types of optimization
-----------------------
1. Gradient descent
2. Stochastic gradient descent
3. Adaptive moment estimator


Gradient descent
----------------
Gradient descent is the most basic optimization algorithm. The idea is to modify a component of $\vec{v}$ one by one. For each modification, we see how the cost function changes. In fact, we build the gradient of $f(\vec{v})$. Knowing it, we are able to slightly modify $\vec{v}$ in the opposite direction of the gradient and approach the minimum of the cost function.

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

why ?
-----
Imagine you have a function that has to be configured with a lot of parameters. There is only one combination of parameters that will give you the best result. The problem is that you don't know what the best combination of parameters is. You can try a lot of combinations and see which one is the best. But it will take a lot of time. So you can use an optimization algorithm to find the best combination of parameters.

One real example
----------------
I built these libraries with one goal in mind: to build an inertial navigation system (INS) using several sensors, including accelerometers, gyroscopes, and magnetometers. One part of this process involves calibrating the sensors.

For magnetometers, we know that the magnetic field vector is constant at a fixed location, so we must be able to measure a vector with the same length each time, regardless of the sensor's orientation. This means that if we plot a lot of points constructed by x, y, and z components, we should get a sphere.

However, the sensors are not perfect and are affected by distortions in the environment (e.g., electronics). For the X axis, the gain may be different from 1 and the offset may be different from 0. This causes the sphere to be off-center and not perfectly spherical, resembling an ellipsoid. Additionally, the X, Y, and Z sensors are not perfectly orthogonal, so the rotation matrix (a 3x3 matrix) quantifies these misalignments. As a result, the ellipsoid is rotated.

In total, we have 15 parameters to find every time we want to calibrate the sensor. It would be challenging to find the best combination of parameters by hand, so we can use the least square method or gradient descent, which is a versatile and useful optimization algorithm that can be applied to many different problems.
