/*==========================================================
 * Primer for Matlab's MexFunction for C++
 * simple examplea to run C++ functions in Matlab
 *
 * To compile the code:
 *                     mex basicMath_classCall.cpp
 * To run the code: 
 *                 [add,multy] = basicMath_classCall(a,b)
 *
 * Outputs:
 *       add = a+b
 *       multy = a*b
 *
 * Date: May 8, 2017: Ajit 
 *========================================================*/

# include "mex.h" 
# include <iostream>
# include <math.h>


// Simple class to do basic arithmetic operations 
struct BasicMath
{
    void add(double *input1, double *input2, double *output1)
    {
        output1[0] = input1[0] + input2[0];
    };
    
    void multy(double *input1, double *input2, double *output2)
    {
        output2[0] = input1[0] * input2[0];
    };
};
    

// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    double *input1, *input2;
    double *output1, *output2;
    
    if (nrhs != 2) { mexErrMsgIdAndTxt("MexPrimer:rhs",
    "This function takes 2 input doubles"); }
        
    if (nlhs != 2) { mexErrMsgIdAndTxt("MexPrimer:lhs",
    "This function need 2 output doubles"); }
    
    // Pointers to input arguments
    input1 = mxGetPr(prhs[0]);      // first input :: in c++ start with zero
    input2 = mxGetPr(prhs[1]);
    
    // Initialize the Output        // addition of two inputs
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    plhs[1] = mxCreateDoubleMatrix(1, 1, mxREAL);
    
    // Pointers to the output arguments
    output1 = mxGetPr(plhs[0]);
    output2 = mxGetPr(plhs[1]);
    
    // Calling Struct : Create object
    BasicMath operate;
    
    // calling methods from object
    operate.add(input1, input2, output1);
    operate.multy(input1, input2, output2);
}


