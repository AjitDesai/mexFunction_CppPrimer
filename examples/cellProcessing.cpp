/*==========================================================
 * Primer for Matlab's mexFunction for C++
 * simple example to run C++ functions in Matlab
 *
 * To compile the code:
 *                     mex cellProcessing.cpp
 * To run the code: 
 *                cellProcessing(array,cell_array)
 *
 * Outputs:
 *        index & arrayElement
 *
 * Date: May 8, 2017: Ajit 
 *
 * Steps for input data::
 * for i = 1:5; mycell{i,1} = (100*i); end;
 *========================================================*/

# include "mex.h" 
# include "string.h"
# include "matrix.h"
# include <stdio.h>

// // MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    // Parameter Definitions
    double *output;
    int input_cell_len, index;
    mxArray *cell_element_ptr;
            
    // number of input/output arguments variafication
    if (nrhs != 1) { mexErrMsgIdAndTxt("MexPrimer:lhs",
            "This function need 2 input arrays"); }
    
    // Process and print the input cell 
    input_cell_len = mxGetNumberOfElements(prhs[0]);
    for (index=0; index<input_cell_len; index++) {
        cell_element_ptr = mxGetCell(prhs[0],index);
        output = mxGetPr(cell_element_ptr);
        printf("The content at %d is %g\n",index,*output);
    }
}

        
        

