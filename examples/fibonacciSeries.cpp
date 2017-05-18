/*==========================================================
 * Primer for Matlab's MexFunction for C++
 * simple examplea to run C++ functions in Matlab
 *
 * To compile the code:
 *                     mex fibonacciSeries.cpp
 * To run the code: 
 *                 fibS = fibonacciSeries(n) //note: max n=1000(hard-coded)
 *
 * Outputs:
 *         fibS = [1 1 2 3 5 8 ... nth fibonacci number]
 *
 * Date: May 8, 2017: Ajit 
 *========================================================*/

# include "mex.h" 
# include <iostream>
# include <math.h>
    
// C++ function to calculate Fibonacci series  
void fibonacci(int input, double *output) 
{
    double n1=1;
    double n2=2;
    double n3;
    double fn[1000];    
    
    for (int i=0; i<=input; i++) {
        if (i <= 1) {
            n3 = 1;
            fn[i] = n3;
            output[i] = fn[i]; 
        } else {
            n3 = n1+n2;
            fn[i] = n3;
            output[i] = fn[i];
        }
        n1=n2;
        n2=n3;
    }
}


// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    
    int input;
    double *output;
    
    if (nrhs != 1) { mexErrMsgIdAndTxt("MexPrimer:rhs",
    "This function takes 2 input doubles"); }
        
    if (nlhs != 1) { mexErrMsgIdAndTxt("MexPrimer:lhs",
    "This function need 2 output doubles"); }
    
    // Pointers to input arguments
    input = mxGetScalar(prhs[0]);     
    
    // Initialize the Output        
    plhs[0] = mxCreateDoubleMatrix(input, 1, mxREAL);
    
    // Pointers to the output arguments
    output = mxGetPr(plhs[0]);

    // Fibonacci Series upto nth:input
    fibonacci(input, output);
}


