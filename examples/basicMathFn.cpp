/*==========================================================
 * basicMathFn.cpp - simple example to run c++ functions in matlab
 *
 * To compile the code:
 *                     mex basicMathFn.cpp
 * To run the code: 
 *                 c = basicMathFn(a,b);   Note: a,b,c are doubles
 * Output:
 *       c = a+b
 *
 * Date: May 8, 2017: Ajit 
 *========================================================*/

# include "mex.h" 
# include <math.h>

// Simple function: call by value
void addition(double *input1, double *input2, double *output) 
{
    output[0] = input1[0] + input2[0];
};

// // MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    
// Parameter Definitions
	double *input1, *input2;
    double *output;
	
// Check for correct number of input arguments 
     if (nrhs != 2) { mexErrMsgIdAndTxt("MexPrimer:basic:rhs",
                     "This function takes 2 input doubles"); }

// Check for correct number of output arguments 
     if (nlhs != 1) { mexErrMsgIdAndTxt("MexPrimer:basic:lhs",
                     "This function provides 1 output");}
	
	
	// Pointers to input arguments
	input1 = mxGetPr(prhs[0]);      // first input: in c++ start with zero
	input2 = mxGetPr(prhs[1]);
	
    // Initialize the Output        // addition of two inputs 
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);// (1,1=> only one output) 
	
	// Pointers to the output arguments 
    output = mxGetPr(plhs[0]);
	
	// Calling C++ function to add two inputs 
	addition(input1, input2, output);
}


