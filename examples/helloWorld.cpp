/*==========================================================
 * hello.cpp - simple example to run c++ functions in matlab
 *
 * To compile the code:
 *                     mex helloWorld.cpp
 * To run the code: 
 *                 helloWorld
 * Output:
 *       C++ hello world!
 *
 * Date: May 8, 2017: Ajit 
 *========================================================*/

# include "mex.h" 
//# include <iostream>


// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    
// // Hello World
	mexPrintf ( "C++ hello world!\n" );
	
// // C++ Standard Librara	:: uncomment "iostream"
// std::cout << ( "C++ hello world!\n" );
	
    return;
}


