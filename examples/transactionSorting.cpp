/*==========================================================
 * Primer for Matlab's MexFunction for C++
 * simple examplea to run C++ functions in Matlab
 *
 * To compile the code:
 *                     mex transactionSorting.cpp
 * To run the code: 
 *                [JumboQ NormalQ] = transactionSorting
 *
 * Outputs:
 *         > 1 million => Jumbo Que
 *         < 1 million => Normal Que
 *
 * Date: May 8, 2017: Ajit Desai
 *========================================================*/

# include "mex.h" 
# include <math.h>
    
// // C++ function to sort trasaction in <1mil and >1mil
void sortTrans(double *output1, double *output2, int input1, double *input2) {
    for(int i=0; i<input1; i++) {
        if (input2[i] >= 1000000) {
            output1[i] = input2[i];
        } else {
            output2[i] = input2[i];
        }
    }
}


// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{ 
    int input1;
    double *input2;
    double *output1, *output2;
    mxArray *lhs[1]; // to read data from inputT.txt file using readInput.m
            
    if (nlhs != 2) { mexErrMsgIdAndTxt("MexPrimer:lhs",
    "This function need 2 output doubles"); }
    
    // Calling userDefined function "readInput.m" to read transactions
    mexCallMATLAB(1, lhs, 0, NULL, "readInputT");
    
    // Pointers to input arguments
    input1 = mxGetM(lhs[0]);
    input2 = mxGetPr(lhs[0]);    
    
    // Initialize the Output        
    plhs[0] = mxCreateDoubleMatrix(input1, 1, mxREAL);
    plhs[1] = mxCreateDoubleMatrix(input1, 1, mxREAL);
    
    // Pointers to the output arguments
    output1 = mxGetPr(plhs[0]);
    output2 = mxGetPr(plhs[1]);
    
    // Fibonacci Series upto nth:input
    sortTrans(output1, output2, input1, input2);
}


