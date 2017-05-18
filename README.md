# mexFunction_CppPrimer

A Primer for Matlab's mexFunction for C++

The set of examples contains the simple and easy to understand C++/mexFunction for starters.
If you're looking for how to call simple C++ functions and classes from Matlab's mexFunction then you're at the right place.

# Examples 
A simple and easy to understand examples to get started with.

* helloWorld.cpp
Get started with the simplest code. It takes one string argument, process it and print output on the screen. 

* basicMathFn.cpp 
Calls a simple C++ function to add the two input arguments (doubles) and return addition. 

* basicMath_classCall.cpp
Calls a simple C++ class, creates instances and uses function from the C++ class. 

* fibonacciSeries.cpp
Calls a simple C++ function which takes in index and returns fibonacci Series upto that index

* transactionSorting.cpp
Read transacations (numbers) from a pre-loaded text file using "mexCallMATLAB" which call user-defined Matlab funtion "readInput.m".
Calls a simple C++ function to sort these numbers into <1 million and >1 million. 