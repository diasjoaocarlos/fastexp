# fastexp
Fast Implementation of the Exponential Function (e^x)  using a 2nd order polynomial

This is made with the function `float fastexp(float x)`, which uses a approximating function of power of 2 (exactly 2^x-1).

The 2nd order polinomial was generated using the interval [0,1], through the minimization of the integral (numerical) of the square of the differences.

