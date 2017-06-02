/*==========================================================
 * hello.cpp - simplest example to use MexFunction with C++
 *
 * To compile the code:
 *                     mex vectorProcessing.cpp
 * To run the code: 
 *                 vectorProcessing(array)  
 * Output:
 *       array
 *
 * Date: May 8, 2017: Ajit Desai
 * myArray = [1000; 2000; 3000; 4000];
 * vectorProcessing(myArray)
 *========================================================*/


#include "mex.h"
#include <vector>

mxArray *getMexArray(const std::vector<double>& v){
    mxArray *mx = mxCreateDoubleMatrix(1,v.size(), mxREAL);
    std::copy(v.begin(), v.end(), mxGetPr(mx));
    return mx;
}

// MAIN FUNCTION : standard format of mexFunction to call c++ functions
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
{
    std::vector<double> v;
    
    if (nrhs != 1) { mexErrMsgIdAndTxt("MexPrimer:lhs",
    "This function need 1 input array"); }
    
    int input_len = mxGetM(prhs[0]);
    double *input = mxGetPr(prhs[0]);
    
    for (int i=0; i<input_len; i++) {
        v.push_back(i);
        v[i] = input[i];
    }
    
    plhs[0] = getMexArray(v);

}



