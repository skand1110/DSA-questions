//Approach 1:
//consider every element and check if it is present in all rows. If present, then print it. 
//-----------------------------------------------------

//Approach 2: Sort the elements 
//time complexity: O(m*n*logn)
//------------------------------------------------------

//Approach 3: using maps 
//time complexity: O(m*n)
/*
We initially insert all elements of the first row in an map. 
For every other element in remaining rows, we check if it is present in the map. 
If it is present in the map and is not duplicated in current row, we increment count of the element in map by 1, 
else we ignore the element. If the currently traversed row is the last row, we print the element if it has appeared m-1 times before. 
*/

#include <bits/stdc++.h>
using namespace std;
 
// Specify number of rows and columns
#define M 4
#define N 5
 
// prints common element in all rows of matrix
void printCommonElements(int mat[M][N])
{
    unordered_map<int, int> mp;
 
    // initialize 1st row elements with value 1
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;
 
    // traverse the matrix
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // If element is present in the map and
            // is not duplicated in current row.
            if (mp[mat[i][j]] == i)
            {
               // we increment count of the element
               // in map by 1
                mp[mat[i][j]] = i + 1;
 
                // If this is last row
                if (i==M-1 && mp[mat[i][j]]==M)
                  cout << mat[i][j] << " ";
            }
        }
    }
}
 
