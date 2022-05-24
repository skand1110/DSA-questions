//Approach 1: Dynamic programming
//for max size square sub matrix
//time Complexity: O(m*n); space complexity: O(m*n)
/*
1) Construct a sum matrix S[R][C] for the given M[R][C].
     a) Copy first row and first columns as it is from M[][] to S[][]
     b) For other entries, use following expressions to construct S[][]
        If M[i][j] is 1 then
            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
        Else If M[i][j] is 0
            S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print 
   sub-matrix of M[][]
*/
// C++ code for Maximum size square
// sub-matrix with all 1s
#include <bits/stdc++.h>
#define bool int
#define R 6
#define C 5
using namespace std;
 
 
void printMaxSubSquare(bool M[R][C])
{
    int i,j;
    int S[R][C];
    int max_of_s, max_i, max_j;
     
    /* Set first column of S[][]*/
    for(i = 0; i < R; i++)
        S[i][0] = M[i][0];
     
    /* Set first row of S[][]*/
    for(j = 0; j < C; j++)
        S[0][j] = M[0][j];
         
    /* Construct other entries of S[][]*/
    for(i = 1; i < R; i++)
    {
        for(j = 1; j < C; j++)
        {
            if(M[i][j] == 1)
                S[i][j] = min({S[i][j-1], S[i-1][j],
                                S[i-1][j-1]}) + 1; //better of using min in case of arguments more than 2
            else
                S[i][j] = 0;
        }
    }
     
    /* Find the maximum entry, and indexes of maximum entry
        in S[][] */
    max_of_s = S[0][0]; max_i = 0; max_j = 0;
    for(i = 0; i < R; i++)
    {
        for(j = 0; j < C; j++)
        {
            if(max_of_s < S[i][j])
            {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }            
    }
 
    cout<<"Maximum size sub-matrix is: \n";
    for(i = max_i; i > max_i - max_of_s; i--)
    {
        for(j = max_j; j > max_j - max_of_s; j--)
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}
//-------------------------------------
//space optimization on the above approach
//In order to compute an entry at any position in the matrix we only need the current row and the previous row.
//space complexity: O(n)

#include <bits/stdc++.h>
 
using namespace std;
 
#define R 6
#define C 5
 
void printMaxSubSquare(bool M[R][C])
{
    int S[2][C], Max = 0;
   
    // set all elements of S to 0 first
    memset(S, 0, sizeof(S));
 
    // Construct the entries
    for (int i = 0; i < R;i++)
        for (int j = 0; j < C;j++){
 
            // Compute the entrie at the current position
            int Entrie = M[i][j];
            if(Entrie)
                if(j)
                    Entrie = 1 + min(S[1][j - 1], min(S[0][j - 1], S[1][j]));
 
            // Save the last entrie and add the new one
            S[0][j] = S[1][j];
            S[1][j] = Entrie;
 
            // Keep track of the max square length
            Max = max(Max, Entrie);
        }
     
    // Print the square
    cout << "Maximum size sub-matrix is: \n";
    for (int i = 0; i < Max; i++, cout << '\n')
        for (int j = 0; j < Max;j++)
            cout << "1 ";
}

//----------------------------------------------------------


//Approach 2: using histogram
//for max size rectangle

// C++ program to find largest
// rectangle with all 1s
// in a binary matrix
#include <bits/stdc++.h>
using namespace std;
 
// Rows and columns in input matrix
#define R 4
#define C 4
 
// Finds the maximum area under
// the histogram represented
// by histogram.  See below article for details.
 
 
int maxHist(int row[])
{
    // Create an empty stack.
    // The stack holds indexes of
    // hist[] array/ The bars stored
    // in stack are always
    // in increasing order of their heights.
    stack<int> result;
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current
    // row (or histogram)
 
    int area = 0; // Initialize area with current top
 
    // Run through all bars of given histogram (or row)
    int i = 0;
    while (i < C) {
        // If this bar is higher than the bar on top stack,
        // push it to stack
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            // If this bar is lower than top of stack, then
            // calculate area of rectangle with stack top as
            // the smallest (or minimum height) bar. 'i' is
            // 'right index' for the top and element before
            // top in stack is 'left index'
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
 
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}
 
// Returns area of the largest rectangle with all 1s in
// A[][]
int maxRectangle(int A[][C])
{
    // Calculate area for first row and initialize it as
    // result
    int result = maxHist(A[0]);
 
    // iterate over row to find maximum rectangular area
    // considering each row as histogram
    for (int i = 1; i < R; i++) {
 
        for (int j = 0; j < C; j++)
 
            // if A[i][j] is 1 then add A[i -1][j]
            if (A[i][j])
                A[i][j] += A[i - 1][j];
 
        // Update result if area with current row (as last
        // row) of rectangle) is more
        result = max(result, maxHist(A[i]));
    }
 
    return result;
}