/*==========================================================
 * Primer for Matlab's MexFunction for C++
 * simple examplea to run C++ functions in Matlab
 *
 * To compile the code:
 *                     mex transactionSorting.cpp
 * To run the code: 
 *            [date, doubleAmt, halfAmt] = transactionPrinting(date,amount)
 * Outputs:
 *        prints: date, amount*2, amount/2
 *
 * Date: May 19, 2017: Ajit Desai
 *
 * Steps for preprocessing:
 * [date amount] = readInputTD;
 *========================================================*/

# include "mex.h" 
# include <string>


// // C++ function to manipulate input transaction amounts 
void sortTrans(double *output1, double *output2, int input1, double *input2) {
    for(int i=0; i<input1; i++) {
            output1[i] = 2*input2[i];
            output2[i] = input2[i]/2;
    }
}


// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
{ 
    int input1;
    double *input2;
    double *output1, *output2;
    
    const char *cstr; 
    const mxArray *cell_element_ptr;
            
    if (nlhs != 3) { mexErrMsgIdAndTxt("MexPrimer:lhs",
    "This function need 2 output arrays"); }
    
    if (nrhs != 2) { mexErrMsgIdAndTxt("MexPrimer:lhs",
    "This function need 2 input arrays"); }
    
    // Pointers to input arguments
    input1 = mxGetM(prhs[1]);
    input2 = mxGetPr(prhs[1]);    
    
    // Initialize the Output        
    plhs[1] = mxCreateDoubleMatrix(input1, 1, mxREAL);
    plhs[2] = mxCreateDoubleMatrix(input1, 1, mxREAL);
    
    // Pointers to the output arguments
    output1 = mxGetPr(plhs[1]);
    output2 = mxGetPr(plhs[2]);
    
    // sorting of transactions upto nth:input
    sortTrans(output1, output2, input1, input2);
    
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
 
    // Insert processed array of string to output
    plhs[0] = mxarr;
    
}


///////////////////////////////////////////////////////////////////////////
////////// MULTIPLE TRIES ////////////
// // // C++ function to sort trasaction in <1mil and >1mil
// void procTrans(double *output1, int lenInput1, double *input1) {
//     for(int i=0; i<lenInput1; i++) {
//         output1[i] = input1[i];
//     }
// }
// 
// 
// // MAIN FUNCTION : standard format of mexFunction to call c++ functions
// void mexFunction ( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )
// { 
//     int lenInput1;
//     double *input1, *output1;
//     
//     char *input2, *output2;
//     mxArray *cell_element_ptr;
//     
//     int lenInput2, buflen, nsubs=2, subs[]={0,1};
// 
//     int status, index;
//     const mxArray *mycell;
//     
//      if (nrhs != 2) { mexErrMsgIdAndTxt("MexPrimer:rhs",
//     "This function takes 1 input doubles"); }
//     
//     if (nlhs != 2) { mexErrMsgIdAndTxt("MexPrimer:lhs",
//     "This function need 1 output doubles"); }
//     
//     // Pointers to input arguments
//     lenInput1 = mxGetM(prhs[0]);
//     input1 = mxGetPr(prhs[0]);
//     
//     // Initialize the Output1        
//     plhs[0] = mxCreateDoubleMatrix(lenInput1, 1, mxREAL);
//     output1 = mxGetPr(plhs[0]);
//     
//     // Initialize the output2
//     lenInput2 = mxGetNumberOfElements(prhs[1]);
//     plhs[1] = mxCreateCellMatrix(lenInput2, 1);
//     mexPrintf("total num of cells = %d\n", lenInput2);
//     
//     for (index=0; index<lenInput2; index++) {
//         cell_element_ptr = mxGetCell(prhs[1], index);
//         mxSetCell(plhs[1], index, cell_element_ptr);
//     }
//     
//     procTrans(output1, lenInput1, input1);
// }


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
//     }         // Process and print the input cell 
//     // input_cell_len = mxGetNumberOfElements(prhs[0]);
//     // printf("number of elements %d\n", input_cell_len);
//     // for (index=0; index<input_cell_len; index++) {
//         buflen = (mxGetN(prhs[0]));
//         printf("number of charecter %d\n", buflen);
//         output = mxCalloc(buflen, sizeof(char));
// //         cell_element_ptr = mxGetCell(prhs[0],index);
// //         output = mxArrayToString(prhs[0]);
// //         printf("The content at %d is\n",index);
// //         mexPrintf(output);
// //    }
// //    mxFree(output);
//           
        
        */
        
        

