/*==========================================================
 * Primer for Matlab's mexFunction for C++
 * simple example to run C++ functions in Matlab
 *
 * To compile the code:
 *                     mex cell_stringProcessing.cpp
 * To run the code: 
 *                cell_stringProcessing(cellOfStrings)
 * Outputs:
 *        array
 *
 * Date: May 19, 2017: Ajit Desai
 *
 * Steps for input data::
 * myStringCell = readInputS;
 * cell_stringProcessing(myStringCell)
 *========================================================*/

# include "mex.h" 
# include <string>

// // MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{
    // Parameter Definitions
    // std::string str("Hellooo");
    const char *cstr; // = str.c_str();
    const mxArray *cell_element_ptr;

    // number of input/output arguments variafication
    if (nrhs != 1) { mexErrMsgIdAndTxt("MexPrimer:lhs",
            "This function need 1 input array"); }
    
    // Get the number of elements in the cell 
    int input_cell_len = mxGetNumberOfElements(prhs[0]);
    
    // initialize the cell matrix to read and store inputs
    mxArray *mxarr = mxCreateCellMatrix(input_cell_len, 1);
    
    // Process one cell element at a time 
    for (mwIndex i=0; i<input_cell_len; i++) {
        cell_element_ptr = mxGetCell(prhs[0],i);
        cstr = mxArrayToString(cell_element_ptr);
        mxSetCell(mxarr, i, mxCreateString(cstr));
    }
    
    // Insert processed inputs (array of strings) to output 
    plhs[0] = mxarr;

}

        


