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
 * Date: May 8, 2017: Ajit 
 *========================================================*/

# include "mex.h" 
# include "string.h"
# include "matrix.h"
    
// // C++ function to sort trasaction in <1mil and >1mil
void procTrans(double *output1, int lenInput1, double *input1) {
    for(int i=0; i<lenInput1; i++) {
        output1[i] = input1[i];
    }
}


// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{ 
    int lenInput1;
    double *input1, *output1;
    
    char *input2, *output2;
    mxArray *cell_element_ptr;
    
    int lenInput2, buflen, nsubs=2, subs[]={0,1};

    int status, index;
    const mxArray *mycell;
    
     if (nrhs != 2) { mexErrMsgIdAndTxt("MexPrimer:rhs",
    "This function takes 1 input doubles"); }
    
    if (nlhs != 2) { mexErrMsgIdAndTxt("MexPrimer:lhs",
    "This function need 1 output doubles"); }
    
    // Pointers to input arguments
    lenInput1 = mxGetM(prhs[0]);
    input1 = mxGetPr(prhs[0]);
    
    // Initialize the Output1        
    plhs[0] = mxCreateDoubleMatrix(lenInput1, 1, mxREAL);
    output1 = mxGetPr(plhs[0]);
    
    // Initialize the output2
    lenInput2 = mxGetNumberOfElements(prhs[1]);
    plhs[1] = mxCreateCellMatrix(lenInput2, 1);
    mexPrintf("total num of cells = %d\n", lenInput2);
    
    for (index=0; index<lenInput2; index++) {
        cell_element_ptr = mxGetCell(prhs[1], index);
        mxSetCell(plhs[1], index, cell_element_ptr);
    }
    
    procTrans(output1, lenInput1, input1);
}

/*
  //    plhs[1] = mxCreateCellMatrix(lenInput2, 1);
//     for (i=0; i<lenInput2; i++) {
//     mycell = mxGetCell(prhs[1],i);
//     mxSetCell(plhs[1], i, mxCreateString(mycell) );
//     }

   //index = mxCalcSingleSubscript(prhs[0], nsubs, subs); 
    //cell_element_ptr = mxGetCell(prhs[0], index);
    //  buflen = mxGetNumberOfElements(string_array_ptr) + 1;
    //  buf = mxCalloc(buflen, sizeof(char));
    //status = mxGetString(cell_element_ptr, buf, buflen); 

//     for(i=0;i<lenInput2;i++)
//     {
//     cell_element_ptr = mxGetCell(prhs[1],i);
//     buflen = mxGetN(cell_element_ptr)*sizeof(mxChar)+1;
//     input2 = mxMalloc(buflen);
//     status = mxGetString(cell_element_ptr,input2,buflen);
//     mexPrintf("The length of cell element %d is: %d \n", i, strlen(input2));
//     mxFree(input2);
//     }       
        
        */
        
        

