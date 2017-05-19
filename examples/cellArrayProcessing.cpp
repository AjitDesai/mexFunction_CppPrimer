/*==========================================================
 * Primer for Matlab's mexFunction for C++
 * simple example to run C++ functions in Matlab
 *
 * To compile the code:
 *                     mex cellArrayProcessing.cpp
 * To run the code: 
 *                [double, half, sumOfall] = cellArrayProcessing(array,cell_array)
 *
 * Outputs:
 *
 *
 * Date: May 8, 2017: Ajit 
 *
 * Steps for input data::
 * [array] = [1000, 2000, 3000, 4000];
 * for i = 1:4; cell_array{i,1} = i.*amount; end;
 *========================================================*/

# include "mex.h" 
# include "string.h"
# include "matrix.h"
# include <stdio.h>


// // C++ function to process Array of numbers
void sortTrans(double *output1, double *output2, int input1, double *input2) {
    for(int i=0; i<input1; i++) {
        output1[i] = 2*input2[i];
        output2[i] = input2[i]/2;
    }
}


// // C++ function to process Each cell element (Array of numbers)
void summation(int index, double *output3, int input3, double *input4) {
    for (int j=0; j<input3; j++) {
        output3[index] += input4[j];
    }
}


// // MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    // Parameter Definitions
    int input1, input3;
    double *input2, *input4;
    double *output1, *output2;
    double *output3;
    int input_cell_len, index;
    mxArray *cell_element_ptr;
    
    // number of input/output arguments variafication 
    if (nlhs != 3) { mexErrMsgIdAndTxt("MexPrimer:lhs",
            "This function need 2 output arrays"); }
    
    if (nrhs != 2) { mexErrMsgIdAndTxt("MexPrimer:lhs",
            "This function need 2 input arrays"); }
    
    // Pointers to first input arguments (Array)
    input1 = mxGetM(prhs[0]);
    input2 = mxGetPr(prhs[0]);
    
    // Initialize the Output
    plhs[0] = mxCreateDoubleMatrix(input1, 1, mxREAL);
    plhs[1] = mxCreateDoubleMatrix(input1, 1, mxREAL);
    
    // Pointers to the output arguments
    output1 = mxGetPr(plhs[0]);
    output2 = mxGetPr(plhs[1]);
    
    // sorting of transactions upto nth:input
    sortTrans(output1, output2, input1, input2);
    
    // Initialize the output2
    input_cell_len = mxGetNumberOfElements(prhs[1]);
    // plhs[2] = mxCreateCellMatrix(input_cell_len, 1);
    plhs[2] = mxCreateDoubleMatrix(input_cell_len, 1, mxREAL);
    output3 = mxGetPr(plhs[2]);
    //mexPrintf("total num of cells = %d\n", input_cell_len);
    
    for (index=0; index<input_cell_len; index++)
    {
        cell_element_ptr = mxGetCell(prhs[1], index);
        input4 = mxGetPr(cell_element_ptr);
        input3 = mxGetM(cell_element_ptr);
        summation(index, output3, input3, input4);
    }
}

        
        

