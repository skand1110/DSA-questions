//Approach 1: Simple linear traversal
//Time Complexity: O(m + n). To merge both the arrays O(m+n) time is needed.
//Space Complexity: O(1). No extra space is required.
/*
algo:
-> Given two arrays are sorted. So they can be merged in O(m+n) time. 
-> Create a variable count to have a count of elements in the output array.
-> If the value of (m+n) is odd then there is only one median else the median is the average of elements at index (m+n)/2 and ((m+n)/2 – 1).
-> To merge the both arrays, keep two indices i and j initially assigned to 0. 
-> Compare the ith index of 1st array and jth index of second, increase the index of the smallest element and increase the count.
Store (m+n)/2 and (m+n)/2-1 in two variables (In the below C++ code, m1 and m2 are used for this purpose).
-> Check if the count reached (m+n) / 2. If (m+n) is odd return m1, If even return (m1+m2)/2.
*/
//-------------------------------------------------------

//Approach 2: calculate the median of both the arrays and discard one half of each array. 
//Time Complexity: O((n+m) Log (n+m))
//Space Complexity: O(n+m). Since we are creating a new array of size n+m.
/*
Algorithm: 
Create a recursive function that takes two arrays and the sizes of both the arrays.
-> Take care of the base cases for the size of arrays less than 2. Note: The first array is always the smaller array.
-> Find the middle elements of both the arrays. i.e element at (n – 1)/2 and (m – 1)/2 of first and second array respectively. 
Compare both the elements.
-> If the middle element of the smaller array is less than the middle element of the larger array 
then the first half of the smaller array is bound to lie strictly in the first half of the merged array. 
-> It can also be stated that there is an element in the first half of the larger array and 
the second half of the smaller array which is the median. 
-> So, reduce the search space to the first half of the larger array and the second half of the smaller array.
-> Similarly, If the middle element of the smaller array is greater than the middle element of the larger array 
then reduce the search space to the first half of the smaller array and second half of the larger array.
*/

// A C++ program to find median of two sorted arrays of
// unequal sizes
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to find median of two integers
float MO2(int a, int b)
{ return ( a + b ) / 2.0; }
 
// A utility function to find median of three integers
float MO3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c))
                     - min(a, min(b, c));
}
 
// A utility function to find a median of four integers
float MO4(int a, int b, int c, int d)
{
    int Max = max( a, max( b, max( c, d ) ) );
    int Min = min( a, min( b, min( c, d ) ) );
    return ( a + b + c + d - Max - Min ) / 2.0;
}
 
// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
   if (n == 0)
      return -1;
   if (n%2 == 0)
        return (double)(arr[n/2] + arr[n/2-1])/2;
   return arr[n/2];
}
 
// This function assumes that N is smaller than or equal to M
// This function returns -1 if both arrays are empty
float findMedianUtil( int A[], int N, int B[], int M )
{
    // If smaller array is empty, return median from second array
    if (N == 0)
      return medianSingle(B, M);
 
    // If the smaller array has only one element
    if (N == 1)
    {
        // Case 1: If the larger array also has one element,
        // simply call MO2()
        if (M == 1)
            return MO2(A[0], B[0]);
 
        // Case 2: If the larger array has odd number of elements,
        // then consider the middle 3 elements of larger array and
        // the only element of smaller array. Take few examples
        // like following
        // A = {9}, B[] = {5, 8, 10, 20, 30} and
        // A[] = {1}, B[] = {5, 8, 10, 20, 30}
        if (M & 1)
            return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );
 
        // Case 3: If the larger array has even number of element,
        // then median will be one of the following 3 elements
        // ... The middle two elements of larger array
        // ... The only element of smaller array
        return MO3( B[M/2], B[M/2 - 1], A[0] );
    }
 
    // If the smaller array has two elements
    else if (N == 2)
    {
        // Case 4: If the larger array also has two elements,
        // simply call MO4()
        if (M == 2)
            return MO4(A[0], A[1], B[0], B[1]);
 
        // Case 5: If the larger array has odd number of elements,
        // then median will be one of the following 3 elements
        // 1. Middle element of larger array
        // 2. Max of first element of smaller array and element
        //    just before the middle in bigger array
        // 3. Min of second element of smaller array and element
        //    just after the middle in bigger array
        if (M & 1)
            return MO3 ( B[M/2],
                         max(A[0], B[M/2 - 1]),
                         min(A[1], B[M/2 + 1])
                       );
 
        // Case 6: If the larger array has even number of elements,
        // then median will be one of the following 4 elements
        // 1) & 2) The middle two elements of larger array
        // 3) Max of first element of smaller array and element
        //    just before the first middle element in bigger array
        // 4. Min of second element of smaller array and element
        //    just after the second middle in bigger array
        return MO4 ( B[M/2],
                     B[M/2 - 1],
                     max( A[0], B[M/2 - 2] ),
                     min( A[1], B[M/2 + 1] )
                   );
    }
 
    int idxA = ( N - 1 ) / 2;
    int idxB = ( M - 1 ) / 2;
 
     /* if A[idxA] <= B[idxB], then median must exist in
        A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB] )
      return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA );
 
    /* if A[idxA] > B[idxB], then median must exist in
       A[...idxA] and B[idxB....] */
    return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}
 
// A wrapper function around findMedianUtil(). This function
// makes sure that smaller array is passed as first argument
// to findMedianUtil
float findMedian( int A[], int N, int B[], int M )
{
    if (N > M)
       return findMedianUtil( B, M, A, N );
 
    return findMedianUtil( A, N, B, M );
}

//---------------------------------------------------------------------
//Approach 3: Binary Search
//Time Complexity: O(min(log m, log n)) : Since binary search is being applied on the smaller of the 2 arrays
//Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;
 
// Method to find median
double Median(vector<int>& A, vector<int>& B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A); // Swapping to make A smaller
 
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? A[leftAsize - 1]
                  : INT_MIN; // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? B[leftBsize] : INT_MAX;
 
        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}
 