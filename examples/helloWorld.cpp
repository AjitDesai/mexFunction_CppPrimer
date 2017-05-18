/*==========================================================
 * hello.cpp - simplest example to use MexFunction with C++
 *
 * To compile the code:
 *                     mex helloWorld.cpp
 * To run the code: 
 *                 helloWorld('yourName')  
 * Output:
 *       Hello yourName from mexFunction's C++ world!
 *
 * Date: May 8, 2017: Ajit Desai
 *========================================================*/

# include "mex.h" 

// // Basic MexFunction Arguments :: lhs = functions(rhs)
// nlhs : Number of expected outputs
// plhs : Array of pointers to the output mxArrays
// nrhs : Number of expected inputs
// prhs : Array of pointers to the input mxArrays

// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    
// Parameter Definitions
   char *input, *output;
    
// To check if one input argument is provided
   if (nrhs != 1) { mexErrMsgIdAndTxt("MexPrimer:rhs",
            "This function requires 1 input sting"); }
    
// Process Matlab input in C++ and send back  
   input = mxArrayToString(prhs[0]);
    
// Hello World
   mexPrintf ("Hello ");
   mexPrintf (input);
   mexPrintf (" from mexFunction's C++ world!\n" );  
   
}



