Optimization
============

why ?
-----
Imagine you have a function that have to be configured with a lot of parameters. There is only one combination of parameters that will give you the best result. The problem is that you don't know what is the best combination of parameters. You can try a lot of combinations and see which one is the best. But it will take a lot of time. So you can use an optimization algorithm to find the best combination of parameters.

one real example
----------------
I buid theses libraries with one goal in mind. One of my projects is to build inertial navigation system (INS) with several sensors : accelerometers, gyroscopes, [...] and magnetometers. One part consist of calibrating the sensors. For the magnetometers, we know the magnetic field vector is constant at a constant place. So we must be able to aquire mesurements of a vector wich have the same lenght at each time. In other words, no mater in what direction the sensor is pointing, the vector must have the same lenght. If we plot a lot of points constructed by x, y and z composants, we must have a sphere. However, the sensor is not perfect and they are distortions blaming the environment (electronics). For the X axis, the gain can be deferent to 1 and the offset can be deferent to 0. The effect is that the sphere is not centered on the origin and it is not a perfect sphere. It looks like a ellipsoid. But that's not it. X, Y and Z are not perfectly orthogonal. The rotation matrix (3 by 3) quatify these disalignment.
Finaly, we have 3*2+3*3=15 parameters to find each time we want to calibrate the sensor. Good lock for find the best combination of parameters by hand. We can also use the least square method. But gradient descent is very interesting and polyvalent. It can be used for a lot of different problems.


3 types of optimization
-----------------------
1. Gradient descent
2. Stochastic gradient descent
3. Adaptive moment estimator

how to use it
-------------
The first step is to define the cost function of your problem.
The second step is to define the gradient function of your cost function. (it can be done by central difference if you don't know how to do it)
